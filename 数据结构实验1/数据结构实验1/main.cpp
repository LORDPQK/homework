#include<iostream>
#include"SqList.h"
#include<string>
#include<cstring>
using namespace std;

typedef struct student {
	student() {
	}
	string name;
	string number;
	double performance;
public:
	void set_student() {
		cout << "����������" << endl;
		cin >> this->name;
		cout << "����ѧ�ţ�" << endl;
		cin >> this->number;
		cout << "���뼨�㣺" << endl;
		cin >> this->performance;
	}
}student;
void print_student(const student& a) {
	cout << "������" << a.name << " ѧ�ţ�" << a.number << " ���㣺" << a.performance << endl;
}
void show_list() {
	cout << "1.��ʾ����ʾ��ǰ����ѧ����Ϣ��¼;" << endl;
	cout << "2.¼�룺�Ӽ�������һ��ѧ����Ϣ��¼�����뵽����ָ����λ�ã�" << endl;
	cout << "3.���ң�����ѧ�Ż��߼�¼��λ�ò���ѧ���ĸ�����Ϣ��" << endl;
	cout << "4.ɾ����ɾ��ָ��λ�õ�ѧ����Ϣ��¼��" << endl;
	cout << "5.���£�����ָ��λ�õ�ѧ����Ϣ��¼��" << endl;
	cout << "6.ͳ�ƣ�ͳ�Ʊ���ѧ��������" << endl;
	cout << "7. ���򣺰���ѧ�Ż��߼����������." << endl;
	cout << "8.��գ���ձ������м�¼." << endl;
	cout << "9.�˳���" << endl;
}
//��ʾ����ʾ��ǰ����ѧ����Ϣ��¼��
void show_student(SqList<student>& a) {
	if (a.IsEmpty())
		cout << "û��ѧ��" << endl;
	else {
		a.Traverse(print_student);
	}
}
//¼�룺�Ӽ�������һ��ѧ����Ϣ��¼�����뵽����ָ����λ�ã�
void set_massage(SqList<student>& a) {
	system("cls");
	int sign = 0;
	cout << "1.��β������" << endl;
	cout << "2.�������λ��" << endl;
	cin >> sign;
	if (sign == 1) {
		student m;
		m.set_student();
		a.InsertElem(m);
	}
	else if (sign == 2) {
		cout << "����λ�ã�(��1-" << a.GetLength() << "֮��)" << endl;
		int i = 0;
		cin >> i;
		if (i<1 && i>a.GetLength()) {
			cout << "�������" << endl;
		}
		else {
			student m;
			m.set_student();
			a.InsertElem(i, m);
		}
	}
	else {
		cout << "�������" << endl;
	}

}
//���ң�����ѧ�Ż��߼�¼��λ�ò���ѧ���ĸ�����Ϣ��
void find(SqList<student>& a) {
	system("cls");
	int sign = 0;
	student s;
	cout << "1.λ�ò���" << endl;
	cout << "2.ѧ�Ų���" << endl;
	cout << "3.��������" << endl;
	cin >> sign;
	if (sign == 1) {
		int m = 0;
		cout << "����λ�ã�(��1-" << a.GetLength() << "֮��)" << endl;
		cin >> m;
		if (m > 0 && m <= a.GetLength()) {
			a.GetElem(m, s);
		}
		else {
			cout << "λ�ò��Ҵ���" << endl;
		}
		print_student(s);
	}
	else if (sign == 2) {
		string m;
		int ok = 0;
		cout << "����ѧ�ţ�" << endl;
		cin >> m;
		for (int i = 1; i <= a.GetLength(); i++) {
			a.GetElem(i, s);
			if (s.number == m) {
				print_student(s);
				ok = 1;
				break;
			}
		}
		if (ok == 0)
			cout << "û�ҵ�" << endl;
	}
	else if (sign == 3) {
		string m;
		int ok = 0;
		cout << "����������" << endl;
		cin >> m;
		for (int i = 1; i <= a.GetLength(); i++) {
			a.GetElem(i, s);
			if (s.name == m) {
				print_student(s);
				ok = 1;
				break;
			}
		}
		if (ok == 0)
			cout << "û�ҵ�" << endl;
	}
	else {
		cout << "��������밴�������" << endl;
	}
}
//ɾ����ɾ��ָ��λ�õ�ѧ����Ϣ��¼��
void delete_him(SqList<student>& a) {
	int sign = 0;
	student s;
	cout << "����λ�ã�(��1-" << a.GetLength() << "֮��)" << endl;
	cin >> sign;
	if (sign > 0 && sign <= a.GetLength()) {
		a.DeleteElem(sign, s);
		cout << "ɾ���ɹ�" << endl;
		cout << "��Ϣ��";
		print_student(s);
	}
	else {
		cout << "λ�ò��Ҵ���" << endl;
	}
}
//���£�����ָ��λ�õ�ѧ����Ϣ��¼��
void change(SqList<student>& a) {
	system("cls");
	int sign = 0;
	student s;
	cout << "����λ�ã�(��1-" << a.GetLength() << "֮��)" << endl;
	cin >> sign;
	if (sign > 0 && sign <= a.GetLength()) {
		a.GetElem(sign, s);
		cout << "ԭѧ����ϢΪ��" << endl;
		print_student(s);
		cout << "����Ϊ��" << endl;
		s.set_student();
		a.SetElem(sign, s);
		cout << "���³ɹ�" << endl;
	}
	else {
		cout << "�������" << endl;
	}
}
//ͳ�ƣ�ͳ�Ʊ���ѧ��������
void sum_student(SqList<student>& a) {
	system("cls");
	cout << "ѧ������Ϊ��" << a.GetLength() << endl;
}
//���򣺰���ѧ�Ż��߼����������
void sort(SqList<student>& a) {
	system("cls");
	if (a.GetLength() < 2) {
		cout << "�������٣��޷�����" << endl;
		return;
	}
	int sign = 0;
	cout << "1.��ѧ������" << endl;
	cout << "2.����������" << endl;
	cin >> sign;
	if (sign < 1 && sign>2) {
		cout << "�������" << endl;
	}
	else {
		for (int i = 0; i < a.GetLength(); i++) {
			for (int j = 1; j < a.GetLength() - i; j++) {
				student s1, s2;
				a.GetElem(j, s1);
				a.GetElem(j + 1, s2);
				if (sign == 2) {
					if (s1.performance > s2.performance)
						a.change_two(j);
				}
				else {
					if (s1.number > s2.number) {
						a.change_two(j);
					}
				}
			}
		}
	}
	cout << "�������" << endl;
}
//��գ���ձ������м�¼
void clear_all(SqList<student>& a) {
	for (int i = a.GetLength(); i > 0; i--) {
		student s;
		a.DeleteElem(i, s);
	}
	cout << "������" << endl;
}
int main() {
	SqList<student>* list = new SqList<student>();
	while (1) {
		system("cls");
		show_list();
		int choise;
		cin >> choise;
		if (!(choise < 10 && choise>0))
			continue;
		switch (choise) {
		case 1: {
			show_student(*list);
			system("pause");
			break;
		}
		case 2: {
			set_massage(*list);
			system("pause");
			break;
		}
		case 3: {
			find(*list);
			system("pause");
			break;
		}
		case 4: {
			delete_him(*list);
			system("pause");
			break;
		}
		case 5: {
			change(*list);
			system("pause");
			break;
		}
		case 6: {
			sum_student(*list);
			system("pause");
			break;
		}
		case 7: {
			sort(*list);
			system("pause");
			break;
		}
		case 8: {
			clear_all(*list);
			system("pause");
			break;
		}
		case 9: {
			return 0;
			break;
		}
		}
	}
	system("pause");
	return 0;
}
