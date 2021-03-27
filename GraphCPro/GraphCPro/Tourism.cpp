#define _CRT_SECURE_NO_WARNINGS//����scanf����
#include"Tourism.h"
#include"Graph.h"
#include<iostream>
#include<cstring>
using namespace std;
extern Graph m_Graph;
//����1. ������������
void CreateGraph(void) {
	Init();
	cout << "===== ������������ͼ =====" << endl;
	int num;
	FILE *InVex = fopen("Vex.txt", "r");
	fscanf(InVex, "%d", &num);
	cout << "������Ŀ:" << num << endl;
	cout << "----- ���� -----" << endl;
	for (int i = 0; i < num; i++)
	{
		Vex vex;
		fscanf(InVex, "%d", &(vex.num));
		fscanf(InVex, "%s", &vex.name);
		fscanf(InVex, "%s", &vex.desc);
		cout << vex.num << "-" << vex.name << endl;
		InsertVex(vex);
	}
	fclose(InVex);
	cout << "----- �� -----" << endl;;
	FILE *InEdge = fopen("Edge.txt", "r");
	while (!feof(InEdge))
	{
		Edge edge;
		fscanf(InEdge, "%d %d %d", &edge.vex1, &edge.vex2, &edge.weight);
		cout << "<v" << edge.vex1 << ",v" << edge.vex2 << "> " << edge.weight << endl;
		InsertEdge(edge);
	}
	fclose(InEdge);

}
//����2. ��ѯ������Ϣ ֱ�Ӳ�ѯ
void GetSpotInfo(void)
{
	if (m_Graph.m_nVexNum == 0) {
		cout << "��������Ϣ �����ȴ���������Ϣ" << endl;
		return;
	}
	cout << "===== ��ѯ������Ϣ =====" << endl;
	int i;
	for (i = 0; i < m_Graph.m_nVexNum; i++)
		cout << m_Graph.m_aVexs[i].num << "-" << m_Graph.m_aVexs[i].name << endl;
	cout << "��������Ҫ��ѯ�ľ����ţ�";
	int Num;
	cin >> Num;
	if (Num >= m_Graph.m_nVexNum) {
		cout << "���������� Ĭ���˳�" << endl;
		return;
	}
	Vex vex = GetVex(Num);
	cout << vex.desc << endl;
	cout << "----- ��Χ���� ------" << endl;
	Edge aEdge[100];
	int sum_Edge = FindEdge(Num, aEdge);
	for (i = 0; i < sum_Edge; i++) {
		if (aEdge[i].weight != 32767) {
			cout << m_Graph.m_aVexs[aEdge[i].vex1].name << "->" <<
				m_Graph.m_aVexs[aEdge[i].vex2].name << " " << aEdge[i].weight << "m" << endl;
		}
	}
}

/*
���룺void
�����void
���ܣ�ͨ������ DFSTraverse()������ʵ�����ξ��㵼�����ܣ�����ѯ���ľ��㵼
��·����ʾ�ڽ����ϡ�*/
void TravelPath()
{
	if (m_Graph.m_nVexNum == 0) {
		cout << "��������Ϣ �����ȴ���������Ϣ" << endl;
		return;
	}
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
		cout << m_Graph.m_aVexs[i].num << "-" << m_Graph.m_aVexs[i].name << endl;
	cout << "��������ʼ���ţ� ";
	int Num;
	cin >> Num;
	if (Num < 0 || Num >= m_Graph.m_nVexNum) {
		cout << "���������� Ĭ���˳�" << endl;
		return;
	}
	cout << "����·��Ϊ��" << endl;
	PathList pList = (PathList)malloc(sizeof(Path));
	PathList Head = pList;
	//����DFSTraverse����
	DFSTraverse(Num, pList);
	pList = Head;
	pList = pList->next;
	int i = 1;
	while (pList != NULL) {
		cout << "·��" << i << "��";
		for (int i = 0; i < m_Graph.m_nVexNum; i++) {
			cout << m_Graph.m_aVexs[pList->vexs[i]].name << "    ";
		}
		cout << endl;
		pList = pList->next;
		i++;
	}
	free(pList);
	pList = NULL;
	Head = NULL;
}

/*
���ܣ�ͨ������m_Graph()������ѯ�������������·���;��롣
*/
void FindShortPath(void)
{
	if (m_Graph.m_nVexNum == 0) {
		cout << "��������Ϣ �����ȴ���������Ϣ" << endl;
		return;
	}
	int nStart, nEnd;
	cout << "���������ı�ţ�" << endl;
	cin >> nStart;
	cout << "�������յ�ı�ţ�" << endl;
	cin >> nEnd;
	if (nStart > nEnd || nEnd >= m_Graph.m_nVexNum) {
		cout << "���������� Ĭ���˳�" << endl;
		return;
	}
	if (nStart == nEnd) {
		cout << "��̾���Ϊ��0" << endl;
		return;
	}
	Edge aPath[32767];
	int Num = FindShortPath(nStart, nEnd, aPath);
	cout << "���·��Ϊ��" << endl;
	int Path = 0;
	for (int i = Num - 1; i >= 0; i--) {
		cout << m_Graph.m_aVexs[aPath[i].vex1].name << "->";
		cout << m_Graph.m_aVexs[aPath[i].vex2].name << endl;
		Path += aPath[i].weight;
	}
	cout << "���·��Ϊ��" << Path << endl;
	}

/*
������������·��
���ܣ�ͨ������Graph.cpp�ļ��е�FindMinTree()������ѯ�����·�滮ͼ��
*/
void DesignPath(void)
{
	if (m_Graph.m_nVexNum == 0) {
		cout << "��������Ϣ �����ȴ���������Ϣ" << endl;
		return;
	}
	int n = m_Graph.m_nVexNum - 1;
	cout << "��������Ҫ�����·����ʼ���㣺����(" << 0 << ")" << endl;
	int nStart;
	cin >> nStart;
	if (nStart != 0 && nStart != n) {
		cout << "���������� Ĭ���˳�" << endl;
		return;
	}
	Edge aEdge[20];
	int Num = FindMinTree(nStart, aEdge), Path = 0;
	//���
	cout << "��������������֮�������·��" << endl;
	for (int i = 0; i < Num; i++) {
		cout << m_Graph.m_aVexs[aEdge[i].vex1].name << " - " << m_Graph.m_aVexs[aEdge[i].vex2].name << " "
			<< aEdge[i].weight << "m" << endl;
		Path += aEdge[i].weight;
	}
	cout << "�����·���ܳ���Ϊ��" << Path << "m" << endl;
}


