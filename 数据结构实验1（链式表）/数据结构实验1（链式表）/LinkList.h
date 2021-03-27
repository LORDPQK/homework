#pragma once
#include<iostream>
using namespace std;
#ifndef __LINK_LIST_H__
#endif
#define __LINK_LIST_H__
#include "Node.h"     // �����
// ��������
template <class ElemType>
class LinkList
{
protected:
	//  ����������ݳ�Ա
	Node<ElemType> *head;    // ͷ���ָ��
	int length;     // �������� 
public:
	// �޲����Ĺ��캯��
	LinkList() {
		this->head = new Node<ElemType>();
		this->length = 0;
	}
	// �в����Ĺ��캯��
	LinkList(ElemType v[], int n) {
		this->length = n;
		for (int i = 0; i < n; i++) {
			Node<ElemType> *a = new Node<ElemType>;
			a->data = v[i];
			a->next = this->head->next;
			this->head->next = a;
		}
	}
	// ��������
	virtual ~LinkList() {
	}
	// �������� 
	int GetLength() const {
		return this->length;
	}
	// �жϵ������Ƿ�Ϊ��
	bool IsEmpty() const {
		return this->length == 0;
	}
	// �����������
	void Clear() {
		Node<ElemType>*p = this->head;
		while (this->head->next != nullptr) {
			p = p->next;
			this->head->next = this->head->next->next;
			delete p;
		}
		if (this->head->next == nullptr)
			this->length = 0;
		else
			cout << "���ʧ�ܣ�*********" << endl;
	}
	// ����������
	void Traverse(void(*Visit)(const ElemType &)) const {
		Node<ElemType>*p = this->head->next;
		while (p != nullptr) {
			(*Visit)(p->data);
			p = p->next;
		}
	}// Ԫ�ض�λ 
	int LocateElem(const ElemType &e) const {
		int sign = 0;
		int areyou = 0;
		Node<ElemType> *p = this->head;
		for (int i = 0; i < this->length; i++) {
			sign++;
			if (p->next->data == e) {
				areyou = 1;
				return sign;
			}
		}
		if (areyou = 0)
			cout << "û���������" << endl;
		return 0;
	}
	// ��ָ��λ�õ�Ԫ��
	int  GetElem(int index, ElemType &e) const {
		if (index > this->length)
			cout << "�������ޣ�" << endl;
		else {
			Node<ElemType> *p = this->head;
			for (int i = 0; i < index; i++) {
				p = p->next;
			}
			e = p->data;
		}
		return 0;
	}
	// ����ָ��λ�õ�Ԫ��ֵ
	int SetElem(int index, const ElemType &e) {
		if (index > this->length)
			cout << "�������ޣ�" << endl;
		else {
			Node<ElemType> *p = this->head;
			for (int i = 0; i < index; i++) {
				p = p->next;
			}
			p->data = e;
		}
		return 0;
	}
	// ɾ��Ԫ��
	int DeleteElem(int index, ElemType &e) {
		if (index > this->length)
			cout << "�������ޣ�" << endl;
		else {
			Node<ElemType> *p = this->head;
			Node<ElemType> *m;
			for (int i = 1; i <= index - 1; i++) {
				p = p->next;
			}
			m = p->next;
			e = p->next->data;
			p->next = p->next->next;
			delete m;
			m = nullptr;
		}
		this->length--;
		return 0;
	}
	// ���ƶ�λ�ò���Ԫ��
	int InsertElem(int index, const ElemType &e) {
		Node<ElemType> *p = this->head;
		Node<ElemType> *q = new Node<ElemType>();
		q->data = e;
		if (index > this->length + 1) {
			cout << "�������ޣ�" << endl;
		}
		else {
			this->length++;
			for (int i = 1; i < index; i++) {
				p = p->next;
			}
			q->next = p->next;
			p->next = q;
		}
		return 0;
	}
	//������������Ԫ�ص�λ��
	void change_two(int a) {
		Node<ElemType> *m1 = this->head;
		for (int i = 0; i < a - 1; i++)
			m1 = m1->next;
		Node<ElemType> *m2 = m1->next;
		Node<ElemType> *m3 = m2->next;
		m1->next = m3;
		m2->next = m3->next;
		m3->next = m2;
	}
	// �ڱ�β����Ԫ��
	int InsertElem(const ElemType &e) {
		Node<ElemType> *p = this->head;
		Node<ElemType> *q = new Node<ElemType>();
		q->data = e;
		for (int i = 0; i < this->length; i++) {
			p = p->next;
		}
		p->next = q;
		this->length++;
		return 0;
	}
	// ���ƹ��캯��
	LinkList(const LinkList<ElemType> &la) {
		Node<ElemType>*p;
		Node<ElemType>*q;
		p = this->head;
		q = la.head;
		for (int i = 0; i < this->length; i++) {
			Node<ElemType>*a = new Node<ElemType>;
			a->data = p->data;
			p = p->next;
			a->next = q->next;
			q->next = a;
		}
	}
	// ���ظ�ֵ����
	LinkList<ElemType> &operator =(const LinkList<ElemType> &la) {
		LinkList(la);
		return *this;
	}
};