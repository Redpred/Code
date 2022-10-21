#include <stdio.h>
#include <winsock.h>
#include <graphics.h>
#include <iostream>
#include <string>
using namespace std;
#pragma comment(lib,"ws2_32.lib")

SOCKET serverSocket;
SOCKADDR_IN addr = { 0 };
#define SERVER_IP "127.0.0.1"//服务器IP地址
#define SERVER_PORT 7777//端口号
int len = 0;//当前显示位置
char nickName[50];//昵称
char fonttype[10] = "黑体";//字体
char R[4] = "000", G[4] = "000", B[4] = "000";//字体颜色
char FONT[50] = "黑体@000@000@000";//字体信息处理

/*
1.确定网络协议版本
2.创建socket
3.确定服务器协议地址簇
4.连接服务器
5.通信
6.关闭socket
7.清理协议版本信息
*/

//初始化
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

        //7.清理协议版本信息
        WSACleanup();

        system("pause");
        return -1;
    }
    printf("创建Socket成功！\n");

    //3.确定服务器协议地址簇
    addr.sin_family = AF_INET;//与socket保持一致
    addr.sin_addr.S_un.S_addr = inet_addr(SERVER_IP);//IP地址，这里使用本地 inet_addr函数将ip地址转化为二进制
    addr.sin_port = htons(SERVER_PORT);//端口号

    
}
//字体设置
void font() {
    while (1) {
        system("mode con lines=10 cols=40\n");
        printf("字体设置：\n");
        printf("0：退出 1：字体 2：颜色\n");
        int set;
        cin >> set;
        switch (set)
        {
        case 0:
            goto stop;
            break;
        case 1:
            printf("windows默认字体即可，例如 黑体 微软雅黑 楷体 等\n");
            printf("字体：");
            cin >> fonttype;
            break;
        case 2:
            printf("设置字体RGB颜色(0-255)：\n");
            printf("R：\n");
            cin >> R;
            printf("G：\n");
            cin >> G;
            printf("B：\n");
            cin >> B;
            break;
        default:
            printf("输入错误！");
            break;
        }
    }
stop:;
    sprintf_s(FONT, "%s@%s@%s@%s", fonttype, R, G, B);//信息处理
    send(serverSocket, FONT, 50, NULL);
}

//登录系统
void login() {
    system("mode con lines=5 cols=30\n");
    printf("    --欢迎进入聊天室--\n\n");
    printf("        昵称：");
    std::cin >> nickName;

    send(serverSocket, nickName, 50, NULL);
    //字体设置
    font();

    system("mode con lines=10 cols=75\n");
}

//循环接受用户输入，发送给服务器
DWORD WINAPI mySend(LPVOID lp) {
    while (1) {
        char buff[1000] = { 0 };//聊天信息
        char temp[1100] = { 0 };//处理后信息
        std::cin >> buff;
        sprintf_s(temp, "%s >> %s", nickName, buff);//信息处理
        send(serverSocket, temp, 1100, NULL);
    }
}

int main()
{
    initgraph(600, 400,SHOWCONSOLE);//做一个窗口

    printf("--------------------------------------------------------------------\n");
    printf("连接服务器：\n");

    //初始化
    if (!init()) {
        printf("初始化失败！");
    }

    //4.连接服务器
    int r = connect(serverSocket, (sockaddr*)&addr, sizeof(addr));
    if (r == -1) {
        printf("连接服务器失败：%d\n", GetLastError());//返回错误

        //6.关闭socket
        closesocket(serverSocket);

        //7.清理协议版本信息
        WSACleanup();

        system("pause");
        return -1;
    }
    printf("连接服务器成功！\n");
    printf("--------------------------------------------------------------------\n");

    //登录系统
    login();

    //5.通信
    CreateThread(NULL, NULL, mySend, NULL, NULL, NULL);

    while (1) {
        char temp[1200] = { 0 };
        //接受服务器的信息并显示
        r = recv(serverSocket, temp, 1200, NULL);
        if (r > 0) {
            char* ptr = NULL;
            char* font = strtok_s(temp, "@",&ptr);
            char* R = strtok_s(NULL, "@", &ptr);
            char* G = strtok_s(NULL, "@", &ptr);
            char* B = strtok_s(NULL, "@", &ptr);
            char* buff = strtok_s(NULL, "@", &ptr);
            settextstyle(0, 0, _T(font));//设置字体
            settextcolor(RGB(atoi(R), atoi(G), atoi(B)));//设置字体颜色
            outtextxy(1, len * 20, buff);
            len++;
        }
    }

    //6.关闭socket
    closesocket(serverSocket);

    //7.清理协议版本信息
    WSACleanup();

    while (1);
    return 0;
}