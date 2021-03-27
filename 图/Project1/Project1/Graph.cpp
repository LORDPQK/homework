#include"Graph.h"
Graph::Graph() {
	for (int i = 0; i < numMAX; i++) {
		for (int j = 0; j < numMAX; j++) {
			if (i == j)
				this->AdjMatrix[i][j] = 0;
			else
				this->AdjMatrix[i][j] = 10000;
		}
	}
	this->VexNum = 0;
}
Graph::~Graph() {
}

bool Graph::InsertVex(Vex svex) {
	for (int i = 0; i < this->Vexs.GetLength(); i++) {
		Vex a;
		this->Vexs.GetElem(i, a);
		if (a.code == svex.code && a.Name == svex.Name)
			cout << "�������" << endl;
	}
	if (this->VexNum < numMAX) {
		this->Vexs.InsertElem(svex);
		this->VexNum++;
		return 1;
	}
	else {
		cout << "����ﵽ�������" << endl;
		return 0;
	}
}

bool Graph::DeleteVex(Vex svex) {
	int sign = 0;
	Vex a;
	for (int i = 0; i < this->Vexs.GetLength(); i++) {
		this->Vexs.GetElem(i, a);
		if (a.code._Equal(svex.code)) {
			this->Vexs.DeleteElem(i, a);
			this->VexNum--;
			sign = 1;
			break;
		}
	}
	for (int m = 0; m < this->Edges.GetLength(); m++) {
		Edge e;
		this->Edges.GetElem(m, e);
		if (e.vex1.code._Equal(a.code) | a.code._Equal(e.vex2.code)) {
			Edges.DeleteElem(m, e);
			m--;
			int p = (int)(e.vex1.code[1] - '0');
			int n = (int)(e.vex2.code[1] - '0');
			this->AdjMatrix[p][n] = 1000;
			this->AdjMatrix[n][p] = 1000;
		}
	}
	if (sign == 0)
		return 0;
	else
		return 1;
}

bool Graph::UpdateVex(Vex svex) {
	int sign = 0;
	Vex a;
	for (int i = 0; i < this->Vexs.GetLength(); i++) {
		this->Vexs.GetElem(i, a);
		if (a.code == svex.code) {
			this->Vexs.SetElem(i, svex);
			sign = 1;
			break;
		}
	}
	if (sign == 0)
		return 0;
	else
		return 1;
}

bool Graph::InsertEdges(Edge sedge) {
	int sign = 0;
	Edge a;
	for (int i = 0; i < this->Edges.GetLength(); i++) {
		this->Edges.GetElem(i, a);
		if (a.vex1.code == sedge.vex1.code && a.vex2.code == sedge.vex2.code)
			sign = 1;
		if (a.vex1.code == sedge.vex2.code && a.vex2.code == sedge.vex2.code)
			sign = 1;
	}
	if (sign == 0) {
		this->Edges.InsertElem(sedge);
		int m = (int)(sedge.vex1.code[1] - '0');
		int n = (int)(sedge.vex2.code[1] - '0');
		this->AdjMatrix[m][n] = sedge.weight;
		this->AdjMatrix[n][m] = sedge.weight;
		return 1;
	}
	else {
		cout << "�������Ѿ�����" << endl;
		return 0;
	}
}
bool Graph::DeleteEdges(Edge sedge) {
	int sign = 0;
	Edge a;
	for (int i = 0; i < this->Edges.GetLength(); i++) {
		this->Edges.GetElem(i, a);
		if ((a.vex1.code == sedge.vex1.code && a.vex2.code == sedge.vex2.code)
			|| (a.vex1.code == sedge.vex2.code && a.vex2.code == sedge.vex2.code)) {
			Edges.DeleteElem(i, a);
			sign = 1;
		}
	}
	if (sign == 1) {
		int m = (int)(sedge.vex1.code[1] - '0');
		int n = (int)(sedge.vex2.code[1] - '0');
		this->AdjMatrix[m][n] = 1000;
		this->AdjMatrix[n][m] = 1000;
		cout << "ɾ���ɹ�" << endl;
		return 1;
	}
	else {
		cout << "�����߲�����" << endl;
		return 0;
	}
}

bool Graph::UpdateEdges(Edge sedge) {
	int sign = 0;
	Edge a;
	for (int i = 0; i < this->Edges.GetLength(); i++) {
		this->Edges.GetElem(i, a);
		if ((a.vex1.code == sedge.vex1.code && a.vex2.code == sedge.vex2.code)
			|| (a.vex1.code == sedge.vex2.code && a.vex2.code == sedge.vex2.code)) {
			Edges.SetElem(i, sedge);
			sign = 1;
		}
	}
	if (sign == 1) {
		cout << "���³ɹ�" << endl;
		return 1;
	}
	else {
		cout << "����ʧ��" << endl;
		return 0;
	}
}

Edge Graph::GetEdge(char* vex1Code, char* vex2Code) {
	int sign = 0;
	Edge a;
	for (int i = 0; i < this->Edges.GetLength(); i++) {
		this->Edges.GetElem(i, a);
		if ((a.vex1.code[1] == *vex1Code && a.vex2.code[1] == *vex2Code)
			|| (a.vex1.code[1] == *vex2Code && a.vex2.code[1] == *vex2Code)) {
			Edges.GetElem(i, a);
			sign = 1;
		}
	}
	if (sign == 0) {
		return a;
	}
	else {
		cout << "����ʧ��" << endl;
		return a;
	}
}

Vex Graph::GetVex(char* vex1Code) {
	int sign = 0;
	Vex a;
	for (int i = 0; i < this->Vexs.GetLength(); i++) {
		this->Vexs.GetElem(i, a);
		if (a.code[1] == *vex1Code) {
			Vexs.GetElem(i, a);
			sign = 1;
		}
	}
	if (sign == 0) {
		return a;
	}
	else {
		cout << "����ʧ��" << endl;
		return a;
	}
}

void Graph::SetVexNum(int) {
	this->VexNum = Vexs.GetLength();
}
int Graph::PrimMinTree(Edge aPath[]) {
	cout << "prim�㷨ʵ����С������" << endl;
	//�ӵ�һ�������
	int x = 1;
	//��¼�������Ӷ���
	int closest[numMAX];
	//��¼��̱�
	int min;
	//��¼���ӵ��ϵ�Ȩֵ
	int lowcost[numMAX];
	//�����ʼ��
	for (int i = 1; i <= this->VexNum; i++) {
		lowcost[i] = AdjMatrix[x][i];
		closest[i] = x;
	}
	int i = 1;
	int j;
	int k;
	for (j = 2; j <= this->VexNum; j++) {
		min = 10000;
		for (k = 1; k <= this->VexNum; k++) {
			if ((lowcost[k] < min) && (lowcost[k] != 0)) {
				min = lowcost[k];
				i = k;
			}
		}
		lowcost[i] = 0;
		for (k = 1; k <= this->VexNum; k++) {
			if (lowcost[k] > AdjMatrix[k][i]) {
				lowcost[k] = AdjMatrix[k][i];
				closest[k] = i;
			}
		}
	}
	for (j = 2; j <= this->VexNum; j++) {
		cout << "v" << j << "-" << "v" << closest[j] << endl;
	}
	return 0;
}
int Graph::KruskalMinTree(Edge aPath[]) {
	cout << "Kruskal�㷨ʵ����С������" << endl;
	//ȡ����
	Edge mEdges[MAX];
	int numEdges = this->Edges.GetLength();
	for (int i = 0; i < numEdges; i++) {
		Edges.GetElem(i, mEdges[i]);
	}
	//�ѱ߰���С��������
	for (int i = 0; i < numEdges; i++) {
		for (int j = 0; j < numEdges - 1; j++) {
			Edge a;
			if (mEdges[j].weight > mEdges[j + 1].weight) {
				a = mEdges[j];
				mEdges[j] = mEdges[j + 1];
				mEdges[j + 1] = a;
			}
		}
	}
	//����һ��������
	Edge outEdges[MAX];
	//��¼�ϸ�ı�
	int outNumber = 0;
	int numberEdges = 0;
	//ѭ���жϺϸ�߲�����
	while (outNumber < this->VexNum - 1 && numberEdges <= this->Edges.GetLength()) {
		outEdges[outNumber] = mEdges[numberEdges];
		outNumber++;
		if (isConnect(mEdges[numberEdges], outEdges, outNumber)) {
			outNumber--;
		}
		numberEdges++;
	}
	//������������������
	if (outNumber == this->Vexs.GetLength() - 1) {
		for (int i = 0; i < outNumber; i++) {
			cout << outEdges[i].vex1.code << "-" << outEdges[i].vex2.code << "Ȩֵ��" << outEdges[i].weight << endl;
		}
	}
	else {
		cout << "��Щ�߹�����һ����С������" << endl;
	}
	return 0;
}
bool Graph::isConnect(Edge b, Edge outEdges[], int n) {
	typedef struct d {
		Vex a;
		int num = 0;
	}D;
	D d[MAX];
	int sumD = 0;
	//ͳ�ƶ���Ͷ�
	for (int i = 0; i < n; i++) {
		int sign = 0;
		int sign2 = 0;
		for (int j = 0; j < sumD; j++) {
			if (d[j].a.code == outEdges[i].vex1.code) {
				d[j].num++;
				sign = 1;
			}
			if (d[j].a.code == outEdges[i].vex2.code) {
				d[j].num++;
				sign2 = 1;
			}
		}
		if (sign == 0) {
			d[sumD].a.code = outEdges[i].vex1.code;
			d[sumD].a.Name = outEdges[i].vex1.Name;
			d[sumD].num++;
			sumD++;
		}
		if (sign2 == 0) {
			d[sumD].a.code = outEdges[i].vex2.code;
			d[sumD].a.Name = outEdges[i].vex2.Name;
			d[sumD].num++;
			sumD++;
		}
	}

	//�������������ж��Ƿ��л�·
	while (1) {
		//�ж��Ƿ����ѭ��
		int sign = 0;
		for (int i = 0; i < sumD; i++) {
			if (d[i].num == 1)
				sign = 1;
		}
		if (sign == 0) {
			if (sumD == 0 || sumD == 1)
				return 0;
			else
				return 1;
		}
		else {
			for (int j = 0; j < sumD; j++) {
				if (d[j].num == 1) {
					for (int m = 0; m < n; m++) {
						if (outEdges[m].vex1.code == d[j].a.code) {
							for (int p = 0; p < sumD; p++) {
								if (d[p].a.code == outEdges[m].vex2.code)
									d[p].num--;
							}
						}
						if (outEdges[m].vex2.code == d[j].a.code) {
							for (int p = 0; p < sumD; p++) {
								if (d[p].a.code == outEdges[m].vex1.code)
									d[p].num--;
							}
						}
					}
					for (int p = j; p < sumD - 1; p++) {
						d[p] = d[p + 1];
					}
					sumD--;
				}
			}
			//ȥ����Ϊ0�Ķ���
			for (int q = 0; q < sumD; q++) {
				if (d[q].num == 0) {
					for (int k = q; k < sumD - 1; k++) {
						d[k] = d[k + 1];
					}
					sumD--;
				}
			}
		}
	}
}
void Graph::showMassage() {
	cout << "������Ϣ��" << endl;
	for (int i = 0; i < this->Vexs.GetLength(); i++) {
		Vex a;
		this->Vexs.GetElem(i, a);
		cout << a.code << "--" << a.Name << endl;
	}
	cout << "����Ϣ��" << endl;
	for (int j = 0; j < this->Edges.GetLength(); j++) {
		Edge b;
		this->Edges.GetElem(j, b);
		cout << b.vex1.code << "--" << b.vex2.code << "Ȩֵ��" << b.weight << endl;
	}
}