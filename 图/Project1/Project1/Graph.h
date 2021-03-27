#pragma once
#pragma once
#define numMAX 20
#define StrMAX 100
#define MAX 1000
#include<iostream>
#include<string>
#include"SqList.h"
#include<vector>
using namespace std;
//�ڵ�ṹ��
struct Vex {
	string code;
	string Name;
};
//�߽ṹ��
struct Edge {
	Vex vex1;
	Vex vex2;
	int weight = -1;
};
class Graph {
private:
	int AdjMatrix[numMAX][numMAX];//�ڽӾ���
	SqList<Vex>Vexs;   //��ļ���
	SqList<Edge>Edges;   //�ߵļ���
	int VexNum;     //��ĸ���
public:
	Graph();
	~Graph();
	bool InsertVex(Vex svex);    //���ӽڵ�
	bool DeleteVex(Vex svex);    //ɾ���ڵ�
	bool UpdateVex(Vex svex);    //���½ڵ�
	bool InsertEdges(Edge sedge);   //���ӱ�
	bool DeleteEdges(Edge sedge);   //ɾ����
	bool UpdateEdges(Edge sedge);   //���±�
	Edge GetEdge(char* vex1Code, char* vex2Code);//�õ���
	Vex GetVex(char*vex1Code);    //�õ���
	void SetVexNum(int);     //���½ڵ���
	int PrimMinTree(Edge aPath[]);   //prim�㷨ʵ����С������
	int KruskalMinTree(Edge aPath[]);  //kruskal�㷨ʵ����С������
	void showMassage();      //��ӡ����ͱߵ���Ϣ
private:
	bool isConnect(Edge b, Edge outEdges[], int n);
};
