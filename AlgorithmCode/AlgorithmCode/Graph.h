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

//图的点结构
class GraphNode
{
public:
	GraphNode(int _value);
	int value;//点数据
	int in;//入度点数量
	int out;//出度点数量
	vector<GraphNode*> nexts;//这个点所指向的下一个点的集合
	vector<GraphEdge*> edges;//属于这个点的边的集合
};
//图的边结构
class GraphEdge
{
public:
	int weight;//边的权重
	GraphNode* from;//边的源节点
	GraphNode* to;//边的指向节点

	GraphEdge(int _weight, GraphNode* _from, GraphNode* _to);
};
//图结构
class Graph
{
public:
	unordered_map<int, GraphNode*> nodes;//点结构集
	unordered_set<GraphEdge*> edges;//边结构集
};

Graph* createGraph(int matrix[][3], int nodenums);
void breadthFirstSearch(GraphNode* node);
void depthFirstSearch(GraphNode* node);
list<GraphNode*> topLogicalSort(Graph* graph);

//最小生成树：
//检查图中新添加的节点对现在的图结构有没有形成环
//通过检查新节点在不在现存节点的集合 来判断是否形成环
//整体是一个简单的并查集
class Mysets
{
public:
	unordered_map<GraphNode*, vector<GraphNode*>> setMap;//一个表，初始状态下 一个节点对应一个集合
	//初始化，输入一个集合，这个集合包括所有节点
	Mysets(vector<GraphNode*> nodes);
	//判断两个集合是否一致
	bool isSameSet(GraphNode* from, GraphNode* to);
	//合并集合
	void setUnion(GraphNode* from, GraphNode* to);
};

unordered_set<GraphEdge*> kruskalMST(Graph* graph);
unordered_set<GraphEdge*> primMST(Graph* graph);
unordered_map<GraphNode*, int> dijkstra(GraphNode* head);
GraphNode* getMinDistanceAndUnselectedNodes(unordered_map<GraphNode*, int> distanceMap, unordered_set<GraphNode*> selectedNodes);