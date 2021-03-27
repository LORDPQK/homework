#pragma once
#include"Node.h"
#include<iostream>
using namespace std;
template <class ElemType>
class SqStack {
protected:
	Node<ElemType>* top = new Node<ElemType>();
public:
	SqStack();    // ���캯��
	virtual ~SqStack();       // ��������
	int getLength() const;       // ��ջ�ĳ���  
	bool isEmpty() const;       // �ж�ջ�Ƿ�Ϊ��
	void clear();         // ��ջ���
	void traverse(void(*Visit)(const ElemType&)) const; // ����ջ
	int push(const ElemType e);        // ��ջ
	int getTop(ElemType& e) const;        // ȡ��Ԫ��
	int pop(ElemType& e);         // ��ջ
	SqStack(const SqStack<ElemType>& s);  // ���ƹ��캯��
	SqStack<ElemType>& operator =(const SqStack<ElemType>& s); // ��ֵ�������
};
// ���캯��
template <class ElemType>
SqStack<ElemType>::SqStack() {
	this->top->next = nullptr;
}
// ��������
template <class ElemType>
SqStack<ElemType>::~SqStack() {
}
// ��ջ�ĳ���    
template <class ElemType>
int SqStack<ElemType>::getLength() const {
	Node<ElemType>* a = this->top->next;
	int num = 0;
	while (a != nullptr) {
		num++;
		a = a->next;
	}
	return num;
}
// �ж�ջ�Ƿ�Ϊ��
template <class ElemType>
bool SqStack<ElemType>::isEmpty() const {
	return this->top->next == nullptr;
}
// ��ջ���
template <class ElemType>
void SqStack<ElemType>::clear() {
	while (this->top->next != nullptr) {
		Node<ElemType>* a = this->top->next;
		this->top->next = this->top->next->next;
		delete a;
	}
}
// ����ջ
template <class ElemType>
void SqStack<ElemType>::traverse(void(*Visit)(const ElemType&)) const {
	Node<ElemType>* a = this->top->next;
	while (a != nullptr) {
		(*Visit)(a->data);
		a = a->next;
	}
}
// ��ջ
template <class ElemType>
int SqStack<ElemType>::push(const ElemType e) {
	Node<ElemType>* a = new Node<ElemType>();
	a->data = e;
	a->next = this->top->next;
	this->top->next = a;
	return 0;
}
// ȡ��Ԫ��
template <class ElemType>
int SqStack<ElemType>::getTop(ElemType& e) const {
	if (this->top->next == nullptr) {
		cout << "ջ����" << endl;
	}
	else {
		e = this->top->next->data;
	}
	return 0;
}
// ��ջ
template <class ElemType>
int SqStack<ElemType>::pop(ElemType& e) {
	if (this->top->next == nullptr)
		cout << "ջ����" << endl;
	else {
		e = this->top->next->data;
		this->top->next = this->top->next->next;
	}
	return 0;
}
// ���ƹ��캯��
template <class ElemType>
SqStack<ElemType>::SqStack(const SqStack<ElemType>& s) {
	Node<ElemType>* a = s.top->next;
	Node<ElemType>* b = new Node<ElemType>();
	this->top->next = b;
	while (a != nullptr) {
		b->data = a->data;
		b = b->next;
		a = a->next;
		b = new Node<ElemType>();
	}
}
// ��ֵ�������
template <class ElemType>
SqStack<ElemType>& SqStack<ElemType>:: operator =(const SqStack<ElemType>& s) {
	SqStack(s);
}
