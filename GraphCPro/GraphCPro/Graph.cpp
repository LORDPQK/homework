#define _CRT_SECURE_NO_WARNINGS//����scanf����
#include"Graph.h"
#include"Tourism.h"
#include<cstring>
#include<iostream>
#define INF 32767;
using namespace std;
Graph m_Graph;
//��ʼ��ͼ��Ϣ
void Init(void)
{
	m_Graph.m_nVexNum = 0;
	int i;
	for (i = 0; i < 20; i++)
	{
		m_Graph.m_aVexs[i].num = -1;
		strcpy(m_Graph.m_aVexs[i].name, "");
		strcpy(m_Graph.m_aVexs[i].desc, "");
		for (int j = 0; j < 20; j++)
			m_Graph.m_aAdjMatrix[i][j] = 0;

	}
}
//�����
bool InsertVex(Vex sVex)
{
	if (m_Graph.m_nVexNum == 32767)
		return false;
	m_Graph.m_aVexs[m_Graph.m_nVexNum++] = sVex;
	return true;
}
//�����
bool InsertEdge(Edge sEdge)
{
	if (sEdge.vex1 < 0 || sEdge.vex1 >= m_Graph.m_nVexNum ||
		sEdge.vex2 < 0 || sEdge.vex2 >= m_Graph.m_nVexNum)
		return false;
	m_Graph.m_aAdjMatrix[sEdge.vex1][sEdge.vex2] = sEdge.weight;
	m_Graph.m_aAdjMatrix[sEdge.vex2][sEdge.vex1] = sEdge.weight;
	return true;
}
Vex GetVex(int nVex) {
	return m_Graph.m_aVexs[nVex];
}
/*
Ѱ����Χ���� �����ߴ����aEdge������
��Χ������Ŀ
*/
int FindEdge(int nVex, Edge aEdge[]) {
	int k = 0;
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
	{
		if (m_Graph.m_aAdjMatrix[nVex][i] != 0)
		{
			aEdge[k].vex1 = nVex;
			aEdge[k].vex2 = i;
			aEdge[k].weight = m_Graph.m_aAdjMatrix[nVex][i];
			k++;
		}
	}
	return k; //������Χ�������Ŀ
}

/*���������int nVex�������š�
���������bVisted[]��bool ���͵����飬������¼ĳ�������Ƿ񱻱�������
���������int &nIndex����¼��������ȡ�
���������PathList &pList�������õ��Ľ����
���ܣ�ʹ��������������㷨����ͼ��*/
void DFS(int nVex, bool bVisted[], int &nIndex, PathList &pList)
{
	bVisted[nVex] = true; //��Ϊ�ѷ���
	pList->vexs[nIndex++] = nVex; //���ʶ���nVex
	int nVexNum = 0;
	for (int i = 0; i < m_Graph.m_nVexNum; i++) {
		if (bVisted[i]) nVexNum++;
	}
	//�ж��Ƿ����ж��㶼���ʹ�
	if (nVexNum == m_Graph.m_nVexNum) {
		pList->next = (PathList)malloc(sizeof(Path));
		for (int i = 0; i < m_Graph.m_nVexNum; i++) {
			pList->next->vexs[i] = pList->vexs[i];
		}
		pList = pList->next;
		pList->next = NULL;//�����ƶ�
	}
	else {
		for (int i = 0; i < m_Graph.m_nVexNum; i++)
		{
			if (!bVisted[i] && (m_Graph.m_aAdjMatrix[nVex][i] > 0) && (m_Graph.m_aAdjMatrix[nVex][i] != 32767)) {
				//�ݹ���õõ�һ��·��
				DFS(i, bVisted, nIndex, pList);
				bVisted[i] = false; //�õ�һ��·���󽫷��ʵ�i����Ϊfalse
				nIndex--;//����
			}
		}
	}
	
}

/*void DFS(int nVex, bool bVisited[], int &nIndex, PathList &pList)

{
	bVisited[nVex] = true; //��Ϊ�Ѿ�����
	pList->vexs[nIndex++] = nVex;//���ʽ��nVex
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
	{
		if (m_Graph.m_aAdjMatrix[nVex][i] != 0 && !bVisited[i])
		{
			DFS(i, bVisited, nIndex, pList);
			bVisted[i] = false; 
				nIndex--;
		}
	}
}

*/

/*
���������int nVex�������š�
���������PathList &pList�������õ��Ľ����
���ܣ�ͨ������ DFS()�������õ���������������������*/
void DFSTraverse(int nVex, PathList &pList)
{
	bool bVisited[32767] = { false };
	int nIndex = 0;
	DFS(nVex, bVisited, nIndex, pList);
}


/*
���룺��ʼ����ı��v1��Ŀ�ľ���ı��v2��
��������·����
���ܣ�ͨ��Dijkstra�㷨���v1��v2�����·��
*/
int FindShortPath(int nVexStart, int nVexEnd, Edge aPath[])
{
	//��ʼ�����·��
	int flag[20], pre[20];
	int dis[20], k;//dis�������ڴ�����ʼ���㵽�����������ľ���
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
	{
		flag[i] = 0;
		pre[i] = 0;
		if (m_Graph.m_aAdjMatrix[nVexStart][i] > 0 || i == nVexStart)
		{
			//��������
			dis[i] = m_Graph.m_aAdjMatrix[nVexStart][i];
			//��������ֱ��������pre��ʼ��Ϊ���
			pre[i] = nVexStart;

		}
		else
		{
			//����ʼ�㲻�����ĵ�ľ����ʼ��ΪINF
			dis[i] = INF;
		}
	}

	flag[nVexStart] = 1;//��һ�������Ӧ����nStartVex��
	int min;
	//�����ڵ���-1�Σ�ÿ���ҳ�һ����������·��
	for (int i = 1; i < m_Graph.m_nVexNum; i++)
	{
		min = INF;
		for (int j = 0; j < m_Graph.m_nVexNum; j++)
		{
			if (flag[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				k = j;
				//k���������������С·���ĵ�
			}
		}
		flag[k] = 1;//��ʾ���k�Ѿ��ҵ����·��
		if (k == nVexEnd)
		{
			break;
		}
		//��k��Ϊ�м�����nVexSart�����ж�������·�����������伯��
		for (int j = 0; j < m_Graph.m_nVexNum; j++)
		{
			int temp;
			//������K����j֮��������
			if (m_Graph.m_aAdjMatrix[k][j] == 0)
			{
				temp = INF;
			}
			else
			{
				temp = min + m_Graph.m_aAdjMatrix[k][j];

			}
			if (flag[j = 0] && (temp < dis[j]))
			{
				dis[j] = temp;
				pre[j] = k;
			}
		}
	}
	
	//·����
	int Num = 0;
	//���յ㿪ʼ����
	int i = nVexEnd;
	while (i != nVexStart)
	{
		aPath[Num].vex2 = i;
		aPath[Num].vex1 = pre[i];
		aPath[Num].weight = m_Graph.m_aAdjMatrix[pre[i]][i];
		i = pre[i];
		Num++;
	}

	return Num;
}

/*
���룺Edge aPath[]
�������С��������
���ܣ�ͨ��Prim�㷨������С��������
*/

int FindMinTree(int nStart,Edge aPath[])
{
	//�ڱ� ǰ�ý�� Ȩֵ
	int flag[20], closest[20], lowcost[20];
	//��ʼ��
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
	{
		flag[i] = 0;
		closest[i] = -1;
		if (m_Graph.m_aAdjMatrix[nStart][i] > 0 || i == nStart)
		{
			lowcost[i] = m_Graph.m_aAdjMatrix[nStart][i];
			closest[i] = nStart;
		}
		else {
			lowcost[i] = INF;
		}
	}
	flag[nStart] = 1;
	int Num = 0;

	int min, k;
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
	{
		min = INF;
		for (int j = 0; j < m_Graph.m_nVexNum; j++)
		{
			if (!flag[j] && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
		}
		flag[k] = 1;
		for (int j = 0; j < m_Graph.m_nVexNum; j++) {
			if (flag[j] == 0 && m_Graph.m_aAdjMatrix[k][j] < lowcost[j] && m_Graph.m_aAdjMatrix[k][j] != 0) {
				lowcost[j] = m_Graph.m_aAdjMatrix[k][j];
				closest[j] = k;
			}
		}
		//������ߵ���Ϣ��aPath������
		flag[closest[k]] = 1;
		aPath[Num].vex1 = closest[k];
		aPath[Num].vex2 = k;
		aPath[Num].weight= m_Graph.m_aAdjMatrix[closest[k]][k];
		Num++;
		
	}
	return Num;//���رߵ���Ŀ
}





















