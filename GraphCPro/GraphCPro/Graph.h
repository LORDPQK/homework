#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
struct Vex
{
	int num;
	char name[20];
	char desc[1024];
};
struct Edge
{
	int vex1;
	int vex2;
	int weight;
};

struct Graph
{
	int m_aAdjMatrix[20][20];//�ڽӾ���
	Vex m_aVexs[20];//������Ϣ �����о����š����֡�����
	int m_nVexNum;//�������
};//Graph�������ڴ洢��������ͼ

typedef struct Path
{
	int vexs[20]; //����һ��·��
	Path *next; //��һ��·��
}*PathList;

void Init(void);
bool InsertVex(Vex sVex);
bool InsertEdge(Edge sEdge);
Vex GetVex(int nVex);
int FindEdge(int nVex, Edge aEdge[]);
void DFS(int nVex, bool bVisted[], int &nIndex, PathList &pList);
void DFSTraverse(int nVex, PathList &pList);
int FindShortPath(int nVexStart, int nVexEnd, Edge aPath[]);
int FindMinTree(int nStart, Edge aPath[]);
#endif //GRAPH_H_INCLUDED
