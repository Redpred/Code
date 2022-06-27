#include "Graph.h"

using namespace std;

/*
图：有向图、无向图。无向图特殊的有向图，指双向有向图。

图的常见存储方式：
邻接表
邻接矩阵
二维数组：例如：[[_,_,_],[_,_,_],[_,_,_]...]
*/

GraphNode::GraphNode(int _value)
{
	value = _value;
	in = 0;
	out = 0;
}
GraphEdge::GraphEdge(int _weight, GraphNode* _from, GraphNode* _to)
{
	weight = _weight;
	from = _from;
	to = _to;
}

//将其他图结构表达方式转化为我的表达方式
//矩阵matrix是N * 3结构，[from,to,weight]
//相当于描绘了一个边，从一个点到另一个点和权重
Graph* createGraph(int matrix[][3], int nodenums)
{
	Graph* graph = new Graph;

	for (int i = 0; i < nodenums; i++)
	{
		//先将边界结构的三个值收集
		int from = matrix[i][0];
		int to = matrix[i][1];
		int weight = matrix[i][2];
		//如果源点结构不存在，就申请一个新节点
		if (graph->nodes.find(from) == graph->nodes.end())
			graph->nodes[from] = new GraphNode(from);
		//如果出点结构不存在，就申请一个新节点
		if (graph->nodes.find(to) == graph->nodes.end())
			graph->nodes[to] = new GraphNode(to);
		//分别记录结构
		GraphNode* fromNode = graph->nodes[from];
		GraphNode* toNode = graph->nodes[to];
		GraphEdge* newEdge = new GraphEdge(weight, fromNode, toNode);
		//更新结构内容
		fromNode->nexts.push_back(toNode);
		fromNode->out++;
		toNode->in++;
		fromNode->edges.push_back(newEdge);
		graph->edges.insert(newEdge);
	}
	return graph;
}
//宽度优先遍历
void breadthFirstSearch(GraphNode* node)
{
	if (node == NULL)
		return;
	//等待遍历节点的队列
	queue<GraphNode*> queue;
	//已经遍历过的表
	unordered_set<GraphNode*> set;

	queue.push(node);
	set.insert(node);

	while (!queue.empty())
	{
		GraphNode* cur = queue.front();//出队列一个节点
		queue.pop();

		cout << cur->value << " ";//输出

		for (GraphNode* next : cur->nexts)//遍历一个节点的所有下一个节点
		{
			if (set.find(next) == set.end())//如果下一个节点没有遍历过
			{
				set.insert(next);//记录这个节点
				queue.push(next);//将这个节点入等待遍历的队列
			}
		}
	}
	cout << endl;
}
//深度优先遍历
void depthFirstSearch(GraphNode* node)
{
	if (node == NULL)
		return;
	//遍历路径的栈
	stack<GraphNode*> stack;
	//记录已经遍历节点的表
	unordered_set<GraphNode*> set;

	stack.push(node);
	set.insert(node);
	//每入栈一个节点就输出
	cout << node->value << " ";

	while (!stack.empty())
	{
		GraphNode* cur = stack.top();//出栈
		stack.pop();
		for (GraphNode* next : cur->nexts)//遍历所有'下一个'节点
		{
			if (set.find(next) == set.end())//直到遇到一个没有遍历过的'下一个'节点
			{
				stack.push(cur);//先入栈原节点，保留遍历的路径
				stack.push(next);//再入栈'下一个'节点
				set.insert(next);//记录'下一个'节点
				cout << next->value << " ";//输出
				break;//遇到新节点记录之后就返回，因为已经记录遍历路径，所以能形成一路向深处遍历
			}
		}
	}
	cout << endl;
}
//拓扑排序
list<GraphNode*> topLogicalSort(Graph* graph)
{
	//Key:某个node
	//Value:node的剩余入度
	unordered_map<GraphNode*, int> inmap;
	//入度为0的node才能进入队列
	queue<GraphNode*> zeroInQueue;
	for (auto& next : graph->nodes)//遍历图中所有节点
	{
		inmap[next.second] = next.second->in;//将图的所有点及其入度导入入度表中
		if (next.second->in == 0)//当一个节点的入度为0时，收入队列
			zeroInQueue.push(next.second);
	}

	list<GraphNode*> result;//返回一个链表
	while (!zeroInQueue.empty())//遍历队列
	{
		GraphNode* cur = zeroInQueue.front();//出队列
		zeroInQueue.pop();
		result.push_back(cur);//将结果导入链表
		for (GraphNode* next : cur->nexts)//遍历这个节点的所有出度节点，寻找新的入度为0的节点
		{
			inmap[next] = inmap.find(next)->second - 1;//在表中修改入度的值，不能改变图中的数据，不能是：next->in
			if (inmap.find(next)->second == 0)//再判断更新入度后的节点的入度
				zeroInQueue.push(next);
		}
	}
	return result;
}

//最小生成树：
//首先写一个简单的并查集结构Mysets来支持它

//初始化，输入一个集合，这个集合包括所有节点
Mysets::Mysets(vector<GraphNode*> nodes)
{
	for (GraphNode* cur : nodes)//遍历所有节点，将每个节点分装成一个个集合 集体存入setMap中
	{
		vector<GraphNode*> set;
		set.push_back(cur);
		setMap[cur] = set;
	}
}

//判断两个集合是否一致
bool Mysets::isSameSet(GraphNode* from, GraphNode* to)
{
	vector<GraphNode*> fromSet = setMap.find(from)->second;
	vector<GraphNode*> toSet;
	toSet.push_back(to);
	return fromSet == toSet;
}

//合并集合
void Mysets::setUnion(GraphNode* from, GraphNode* to)
{
	vector<GraphNode*> fromSet = setMap.find(from)->second;
	vector<GraphNode*> toSet = setMap.find(to)->second;
	for (GraphNode* toNode : toSet)
	{
		fromSet.push_back(toNode);
		setMap[toNode] = fromSet;
	}
}

struct EdgeComperator
{
	//边的比较器 降序
	bool operator() (GraphEdge* o1, GraphEdge* o2)
	{
		return o1->weight > o2->weight;
	}
};

//最小生成树
unordered_set<GraphEdge*> kruskalMST(Graph* graph)
{
	vector<GraphNode*> nodes;
	for (auto& node : graph->nodes)
		nodes.push_back(node.second);
	Mysets mysets(nodes);//初始化并查集

	priority_queue<GraphEdge*, vector<GraphEdge*>, EdgeComperator> priority_queue;//优先队列，升序排序

	for (GraphEdge* edge : graph->edges)//将所有边导入优先队列
		priority_queue.push(edge);

	unordered_set<GraphEdge*> result;//返回的结果
	while (!priority_queue.empty())//遍历优先队列
	{
		GraphEdge* edge = priority_queue.top();
		priority_queue.pop();//出队列

		if (!mysets.isSameSet(edge->from, edge->to))//如果不形成环  !!这里判断有问题，应该重写
		{
			result.insert(edge);//将新的边加入结果的表中  因为是优先队列，所以已经排好序了
			cout << edge->weight << " ";
			mysets.setUnion(edge->from, edge->to);//将新的边合并到已经遍历的边
		}
	}
	cout << endl;
	return result;
}
//https://www.bilibili.com/video/BV1NU4y1M7rF?p=8&t=6108.3
unordered_set<GraphEdge*> primMST(Graph* graph)
{
	//已经走过的路的点
	unordered_set<GraphNode*> set;
	//返回的结果
	unordered_set<GraphEdge*> result;
	//解锁的边进入优先队列，以升序的方式排列，寻找权值最小的边
	priority_queue<GraphEdge*, vector<GraphEdge*>, EdgeComperator> priority_queue;
	//一个开始的点， 如果存在森林问题，就要遍历图的每一个点
	GraphNode* newnode = graph->nodes.begin()->second;
	set.insert(newnode);
	//将点的所有边放入优先队列
	for (GraphEdge* edges : newnode->edges)
		priority_queue.push(edges);
	while (!priority_queue.empty())
	{
		GraphEdge* edge = priority_queue.top();//出队列一个目前权值最小的边
		priority_queue.pop();
		GraphNode* toNode = edge->to;
		if (set.find(toNode) == set.end())//如果这条边没有走过
		{
			set.insert(toNode);//记录这个新的点
			result.insert(edge);//导入结果
			cout << edge->weight << " ";
			for (GraphEdge* newedges : toNode->edges)//遍历这个新的点衍生的所有边
				priority_queue.push(newedges);
		}
	}
	cout << endl;
	return result;
}
//最短路径问题，dijkstra算法
//https://www.bilibili.com/video/BV1NU4y1M7rF?p=8&t=7170.7
//在DistanceMap中选一个最小距离的点，但是这个点不能是已经选过的
GraphNode* getMinDistanceAndUnselectedNodes(
	unordered_map<GraphNode*, int> distanceMap,
	unordered_set<GraphNode*> selectedNodes)
{
	GraphNode* minNode = NULL;
	int minDistance = INT_MAX;//默认距离head为无穷大
	for (auto& entry : distanceMap)//遍历distanceMap
	{
		GraphNode* node = entry.first;//记录一个点
		int distance = entry.second;//记录点的距离
		if (selectedNodes.find(node) == selectedNodes.end() && distance < minDistance)//如果这个点还没有锁定 且 是表中到head距离最小的点
		{
			minNode = node;//记录点
			minDistance = distance;//记录距离
		}
	}
	return minNode;
}

unordered_map<GraphNode*, int> dijkstra(GraphNode* head)
{
	//从head出发到所有点的最小距离
	//Key:从head出发到Key
	//value:从head出发到达Key最小距离
	//如果在表中没有 T 的记录，含义是 从head 到 T 的距离是正无穷
	unordered_map<GraphNode*, int> distanceMap;
	distanceMap[head] = 0;
	//已经求出最短距离的点，存放到selectedNodes中，以后不会再碰
	unordered_set<GraphNode*> selectedNodes;
	//选出一个最小距离的点
	GraphNode* minNode = getMinDistanceAndUnselectedNodes(distanceMap, selectedNodes);
	while (minNode != NULL)
	{
		int distance = distanceMap.find(minNode)->second;//这个最小距离点的距离
		for (GraphEdge* edge : minNode->edges)//遍历点的所有边
		{
			GraphNode* toNode = edge->to;//记录新点
			if (distanceMap.find(toNode) == distanceMap.end())//如果没有记录head到新点的距离
				distanceMap[toNode] = distance + edge->weight;//记录距离
			distanceMap[toNode] = min(distanceMap.find(toNode)->second, distance + edge->weight);//判断到这个点的距离是否比表中记录的要短
		}
		selectedNodes.insert(minNode);//点锁定
		//重新获得一个距离head最短的点
		minNode = getMinDistanceAndUnselectedNodes(distanceMap, selectedNodes);
	}
	return distanceMap;
}