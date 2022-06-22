#ifndef D_GRAPH_H_
#define D_GRAPH_H_

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <iostream>
#include <list>

#endif // !D_GRAPH_H_

using namespace std;

class GraphEdge;

//ͼ�ĵ�ṹ
class GraphNode
{
public:
	GraphNode(int _value);
	int value;//������
	int in;//��ȵ�����
	int out;//���ȵ�����
	vector<GraphNode*> nexts;//�������ָ�����һ����ļ���
	vector<GraphEdge*> edges;//���������ıߵļ���
};
//ͼ�ı߽ṹ
class GraphEdge
{
public:
	int weight;//�ߵ�Ȩ��
	GraphNode* from;//�ߵ�Դ�ڵ�
	GraphNode* to;//�ߵ�ָ��ڵ�

	GraphEdge(int _weight, GraphNode* _from, GraphNode* _to);
};
//ͼ�ṹ
class Graph
{
public:
	unordered_map<int, GraphNode*> nodes;//��ṹ��
	unordered_set<GraphEdge*> edges;//�߽ṹ��
};

Graph* createGraph(int matrix[][3], int nodenums);
void breadthFirstSearch(GraphNode* node);
void depthFirstSearch(GraphNode* node);
list<GraphNode*> topLogicalSort(Graph* graph);

//��С��������
//���ͼ������ӵĽڵ�����ڵ�ͼ�ṹ��û���γɻ�
//ͨ������½ڵ��ڲ����ִ�ڵ�ļ��� ���ж��Ƿ��γɻ�
//������һ���򵥵Ĳ��鼯
class Mysets
{
public:
	unordered_map<GraphNode*, vector<GraphNode*>> setMap;//һ������ʼ״̬�� һ���ڵ��Ӧһ������
	//��ʼ��������һ�����ϣ�������ϰ������нڵ�
	Mysets(vector<GraphNode*> nodes);
	//�ж����������Ƿ�һ��
	bool isSameSet(GraphNode* from, GraphNode* to);
	//�ϲ�����
	void setUnion(GraphNode* from, GraphNode* to);
};

unordered_set<GraphEdge*> kruskalMST(Graph* graph);
unordered_set<GraphEdge*> primMST(Graph* graph);
unordered_map<GraphNode*, int> dijkstra(GraphNode* head);
GraphNode* getMinDistanceAndUnselectedNodes(unordered_map<GraphNode*, int> distanceMap, unordered_set<GraphNode*> selectedNodes);