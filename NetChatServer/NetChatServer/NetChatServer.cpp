#include <stdio.h>
#include <winsock.h>
#include <Windows.h>
#pragma comment(lib,"ws2_32.lib")

SOCKET serverSocket;
SOCKADDR_IN addr = { 0 };
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 7777
#define clientNUM 1024
SOCKET clientSocket[clientNUM];
int count = 0;

/*
1.确定网络协议版本
2.创建socket
3.确定服务器协议地址簇
4.绑定
5.监听
6.接受客户端连接
7.通信
8.关闭socket
9.清理协议版本信息
*/

bool init() {
    //1.确定网络协议版本
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);//需要动态链接库ws2_32.lib
    //判断
    if (LOBYTE(wsaData.wVersion) != 2 ||
        HIBYTE(wsaData.wVersion) != 2) {
        printf("确定网络协议版本失败：%d\n", GetLastError());//返回错误
        system("pause");
        return -1;
    }
    printf("确定网络协议版本成功！\n");

    //2.创建socket
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //判断
    if (SOCKET_ERROR == serverSocket) {
        printf("创建Socket失败：%d\n", GetLastError());//返回错误

        //9.清理协议版本信息
        WSACleanup();

        system("pause");
        return -1;
    }
    printf("创建Socket成功！\n");

    //3.确定服务器协议地址簇
    addr.sin_family = AF_INET;//与socket保持一致
    addr.sin_addr.S_un.S_addr = inet_addr(SERVER_IP);//IP地址，这里使用本地
    addr.sin_port = htons(SERVER_PORT);//端口号
}

//7.通信
DWORD WINAPI communication(LPVOID Socket) {
    SOCKET cSocket = *(SOCKET*)Socket;//将传参转化
    int r;//recv返回值

    //接收用户昵称
    char nickName[50] = { 0 };//昵称 
    r = recv(cSocket, nickName, 50, NULL);
    if (r > 0) {
        char printNickName[100] = { 0 };
        printf("用户：%s 已上线！\n", nickName);
        sprintf_s(printNickName, "黑体@255@255@255@用户：%s 已上线！\n", nickName);
        //发送给当前连接上服务器的所有客户端
        for (int i = 0; i < count; i++) {
            send(clientSocket[i], printNickName, 100, NULL);
        }
    }
    else {
        printf("客户端连接服务器失败！\n");
    }

    //接收用户字体
    char FONT[50] = "黑体@255@255@255";//字体信息处理
    recv(cSocket, FONT, 50, NULL);

    while (1) {
        char buff[1100] = { 0 };//信息
        char temp[1200] = { 0 };//处理后信息

        r = recv(cSocket, buff, 1100, NULL);
        if (r > 0) {
            printf("%s\n", buff);//在服务器窗口发送信息

            //处理信息
            sprintf_s(temp, "%s@%s", FONT, buff);
            //发送给当前连接上服务器的所有客户端
            for (int i = 0; i < count; i++) {
                send(clientSocket[i], temp, 1200, NULL);
            }
        }
        else {
            printf("用户：%s 断开服务器连接！\n", nickName);
            break;
        }
    }
    return NULL;
}

int main()
{
    //设置窗口
    system("mode con cols=70\n");

    printf("--------------------------------------------------------------------\n");
    printf("服务器建立：\n");

    if (!init()) {
        printf("初始化失败！");
    }

    //4.绑定
    int r = bind(serverSocket, (sockaddr*)&addr, sizeof(addr));
    if (r == -1) {
        printf("绑定失败：%d\n", GetLastError());//返回错误

        //8.关闭socket
        closesocket(serverSocket);

        //9.清理协议版本信息
        WSACleanup();

        system("pause");
        return -1;
    }
    printf("绑定成功！\n");

    //5.监听
    int l = listen(serverSocket, 10);
    if (l == -1) {
        printf("监听失败：%d\n", GetLastError());//返回错误

        //8.关闭socket
        closesocket(serverSocket);

        //9.清理协议版本信息
        WSACleanup();

        system("pause");
        return -1;
    }
    printf("监听成功！\n");
    
    printf("--------------------------------------------------------------------\n");
    
    //6.接受客户端连接
    for (int i = 0; i < clientNUM; i++) {
        clientSocket[i] = accept(serverSocket, (sockaddr*)NULL, NULL);
        if (r == -1) {
            printf("服务器崩溃：%d\n", GetLastError());//返回错误

            //8.关闭socket
            closesocket(serverSocket);

            //9.清理协议版本信息
            WSACleanup();

            system("pause");
            return -1;
        }
        count++;

        //创建多线程运行通信函数
        HANDLE hThread = CreateThread(NULL, NULL, communication, (LPVOID)&clientSocket[i], NULL, NULL);
        
    }

    //8.关闭socket
    closesocket(serverSocket);

    //9.清理协议版本信息
    WSACleanup();

    while (1);
    return 0;
}

