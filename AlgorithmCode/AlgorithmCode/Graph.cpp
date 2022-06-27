#include "Graph.h"

using namespace std;

/*
ͼ������ͼ������ͼ������ͼ���������ͼ��ָ˫������ͼ��

ͼ�ĳ����洢��ʽ��
�ڽӱ�
�ڽӾ���
��ά���飺���磺[[_,_,_],[_,_,_],[_,_,_]...]
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

//������ͼ�ṹ��﷽ʽת��Ϊ�ҵı�﷽ʽ
//����matrix��N * 3�ṹ��[from,to,weight]
//�൱�������һ���ߣ���һ���㵽��һ�����Ȩ��
Graph* createGraph(int matrix[][3], int nodenums)
{
	Graph* graph = new Graph;

	for (int i = 0; i < nodenums; i++)
	{
		//�Ƚ��߽�ṹ������ֵ�ռ�
		int from = matrix[i][0];
		int to = matrix[i][1];
		int weight = matrix[i][2];
		//���Դ��ṹ�����ڣ�������һ���½ڵ�
		if (graph->nodes.find(from) == graph->nodes.end())
			graph->nodes[from] = new GraphNode(from);
		//�������ṹ�����ڣ�������һ���½ڵ�
		if (graph->nodes.find(to) == graph->nodes.end())
			graph->nodes[to] = new GraphNode(to);
		//�ֱ��¼�ṹ
		GraphNode* fromNode = graph->nodes[from];
		GraphNode* toNode = graph->nodes[to];
		GraphEdge* newEdge = new GraphEdge(weight, fromNode, toNode);
		//���½ṹ����
		fromNode->nexts.push_back(toNode);
		fromNode->out++;
		toNode->in++;
		fromNode->edges.push_back(newEdge);
		graph->edges.insert(newEdge);
	}
	return graph;
}
//������ȱ���
void breadthFirstSearch(GraphNode* node)
{
	if (node == NULL)
		return;
	//�ȴ������ڵ�Ķ���
	queue<GraphNode*> queue;
	//�Ѿ��������ı�
	unordered_set<GraphNode*> set;

	queue.push(node);
	set.insert(node);

	while (!queue.empty())
	{
		GraphNode* cur = queue.front();//������һ���ڵ�
		queue.pop();

		cout << cur->value << " ";//���

		for (GraphNode* next : cur->nexts)//����һ���ڵ��������һ���ڵ�
		{
			if (set.find(next) == set.end())//�����һ���ڵ�û�б�����
			{
				set.insert(next);//��¼����ڵ�
				queue.push(next);//������ڵ���ȴ������Ķ���
			}
		}
	}
	cout << endl;
}
//������ȱ���
void depthFirstSearch(GraphNode* node)
{
	if (node == NULL)
		return;
	//����·����ջ
	stack<GraphNode*> stack;
	//��¼�Ѿ������ڵ�ı�
	unordered_set<GraphNode*> set;

	stack.push(node);
	set.insert(node);
	//ÿ��ջһ���ڵ�����
	cout << node->value << " ";

	while (!stack.empty())
	{
		GraphNode* cur = stack.top();//��ջ
		stack.pop();
		for (GraphNode* next : cur->nexts)//��������'��һ��'�ڵ�
		{
			if (set.find(next) == set.end())//ֱ������һ��û�б�������'��һ��'�ڵ�
			{
				stack.push(cur);//����ջԭ�ڵ㣬����������·��
				stack.push(next);//����ջ'��һ��'�ڵ�
				set.insert(next);//��¼'��һ��'�ڵ�
				cout << next->value << " ";//���
				break;//�����½ڵ��¼֮��ͷ��أ���Ϊ�Ѿ���¼����·�����������γ�һ·�������
			}
		}
	}
	cout << endl;
}
//��������
list<GraphNode*> topLogicalSort(Graph* graph)
{
	//Key:ĳ��node
	//Value:node��ʣ�����
	unordered_map<GraphNode*, int> inmap;
	//���Ϊ0��node���ܽ������
	queue<GraphNode*> zeroInQueue;
	for (auto& next : graph->nodes)//����ͼ�����нڵ�
	{
		inmap[next.second] = next.second->in;//��ͼ�����е㼰����ȵ�����ȱ���
		if (next.second->in == 0)//��һ���ڵ�����Ϊ0ʱ���������
			zeroInQueue.push(next.second);
	}

	list<GraphNode*> result;//����һ������
	while (!zeroInQueue.empty())//��������
	{
		GraphNode* cur = zeroInQueue.front();//������
		zeroInQueue.pop();
		result.push_back(cur);//�������������
		for (GraphNode* next : cur->nexts)//��������ڵ�����г��Ƚڵ㣬Ѱ���µ����Ϊ0�Ľڵ�
		{
			inmap[next] = inmap.find(next)->second - 1;//�ڱ����޸���ȵ�ֵ�����ܸı�ͼ�е����ݣ������ǣ�next->in
			if (inmap.find(next)->second == 0)//���жϸ�����Ⱥ�Ľڵ�����
				zeroInQueue.push(next);
		}
	}
	return result;
}

//��С��������
//����дһ���򵥵Ĳ��鼯�ṹMysets��֧����

//��ʼ��������һ�����ϣ�������ϰ������нڵ�
Mysets::Mysets(vector<GraphNode*> nodes)
{
	for (GraphNode* cur : nodes)//�������нڵ㣬��ÿ���ڵ��װ��һ�������� �������setMap��
	{
		vector<GraphNode*> set;
		set.push_back(cur);
		setMap[cur] = set;
	}
}

//�ж����������Ƿ�һ��
bool Mysets::isSameSet(GraphNode* from, GraphNode* to)
{
	vector<GraphNode*> fromSet = setMap.find(from)->second;
	vector<GraphNode*> toSet;
	toSet.push_back(to);
	return fromSet == toSet;
}

//�ϲ�����
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
	//�ߵıȽ��� ����
	bool operator() (GraphEdge* o1, GraphEdge* o2)
	{
		return o1->weight > o2->weight;
	}
};

//��С������
unordered_set<GraphEdge*> kruskalMST(Graph* graph)
{
	vector<GraphNode*> nodes;
	for (auto& node : graph->nodes)
		nodes.push_back(node.second);
	Mysets mysets(nodes);//��ʼ�����鼯

	priority_queue<GraphEdge*, vector<GraphEdge*>, EdgeComperator> priority_queue;//���ȶ��У���������

	for (GraphEdge* edge : graph->edges)//�����бߵ������ȶ���
		priority_queue.push(edge);

	unordered_set<GraphEdge*> result;//���صĽ��
	while (!priority_queue.empty())//�������ȶ���
	{
		GraphEdge* edge = priority_queue.top();
		priority_queue.pop();//������

		if (!mysets.isSameSet(edge->from, edge->to))//������γɻ�  !!�����ж������⣬Ӧ����д
		{
			result.insert(edge);//���µı߼������ı���  ��Ϊ�����ȶ��У������Ѿ��ź�����
			cout << edge->weight << " ";
			mysets.setUnion(edge->from, edge->to);//���µıߺϲ����Ѿ������ı�
		}
	}
	cout << endl;
	return result;
}
//https://www.bilibili.com/video/BV1NU4y1M7rF?p=8&t=6108.3
unordered_set<GraphEdge*> primMST(Graph* graph)
{
	//�Ѿ��߹���·�ĵ�
	unordered_set<GraphNode*> set;
	//���صĽ��
	unordered_set<GraphEdge*> result;
	//�����ı߽������ȶ��У�������ķ�ʽ���У�Ѱ��Ȩֵ��С�ı�
	priority_queue<GraphEdge*, vector<GraphEdge*>, EdgeComperator> priority_queue;
	//һ����ʼ�ĵ㣬 �������ɭ�����⣬��Ҫ����ͼ��ÿһ����
	GraphNode* newnode = graph->nodes.begin()->second;
	set.insert(newnode);
	//��������б߷������ȶ���
	for (GraphEdge* edges : newnode->edges)
		priority_queue.push(edges);
	while (!priority_queue.empty())
	{
		GraphEdge* edge = priority_queue.top();//������һ��ĿǰȨֵ��С�ı�
		priority_queue.pop();
		GraphNode* toNode = edge->to;
		if (set.find(toNode) == set.end())//���������û���߹�
		{
			set.insert(toNode);//��¼����µĵ�
			result.insert(edge);//������
			cout << edge->weight << " ";
			for (GraphEdge* newedges : toNode->edges)//��������µĵ����������б�
				priority_queue.push(newedges);
		}
	}
	cout << endl;
	return result;
}
//���·�����⣬dijkstra�㷨
//https://www.bilibili.com/video/BV1NU4y1M7rF?p=8&t=7170.7
//��DistanceMap��ѡһ����С����ĵ㣬��������㲻�����Ѿ�ѡ����
GraphNode* getMinDistanceAndUnselectedNodes(
	unordered_map<GraphNode*, int> distanceMap,
	unordered_set<GraphNode*> selectedNodes)
{
	GraphNode* minNode = NULL;
	int minDistance = INT_MAX;//Ĭ�Ͼ���headΪ�����
	for (auto& entry : distanceMap)//����distanceMap
	{
		GraphNode* node = entry.first;//��¼һ����
		int distance = entry.second;//��¼��ľ���
		if (selectedNodes.find(node) == selectedNodes.end() && distance < minDistance)//�������㻹û������ �� �Ǳ��е�head������С�ĵ�
		{
			minNode = node;//��¼��
			minDistance = distance;//��¼����
		}
	}
	return minNode;
}

unordered_map<GraphNode*, int> dijkstra(GraphNode* head)
{
	//��head���������е����С����
	//Key:��head������Key
	//value:��head��������Key��С����
	//����ڱ���û�� T �ļ�¼�������� ��head �� T �ľ�����������
	unordered_map<GraphNode*, int> distanceMap;
	distanceMap[head] = 0;
	//�Ѿ������̾���ĵ㣬��ŵ�selectedNodes�У��Ժ󲻻�����
	unordered_set<GraphNode*> selectedNodes;
	//ѡ��һ����С����ĵ�
	GraphNode* minNode = getMinDistanceAndUnselectedNodes(distanceMap, selectedNodes);
	while (minNode != NULL)
	{
		int distance = distanceMap.find(minNode)->second;//�����С�����ľ���
		for (GraphEdge* edge : minNode->edges)//����������б�
		{
			GraphNode* toNode = edge->to;//��¼�µ�
			if (distanceMap.find(toNode) == distanceMap.end())//���û�м�¼head���µ�ľ���
				distanceMap[toNode] = distance + edge->weight;//��¼����
			distanceMap[toNode] = min(distanceMap.find(toNode)->second, distance + edge->weight);//�жϵ������ľ����Ƿ�ȱ��м�¼��Ҫ��
		}
		selectedNodes.insert(minNode);//������
		//���»��һ������head��̵ĵ�
		minNode = getMinDistanceAndUnselectedNodes(distanceMap, selectedNodes);
	}
	return distanceMap;
}