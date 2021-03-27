#pragma once
#include<stdio.h>
#include<malloc.h>
#include<iostream>
#define MaxSize 100

template<class ElemType>
class Stack
{
private:
	typedef struct
	{
		ElemType* data[MaxSize];
		int Top;//ջ��ָ��1
	}SqStack;
	SqStack* s;
public:
	Stack();
	~Stack();
	bool Push(ElemType* e);//��Ԫ��eѹ��ջ��
	bool Pop(ElemType* e);//��ջ��Ԫ�س�ջ��ֵ��e
	bool GetTop(ElemType* e);//��ջ��Ԫ�ظ�ֵ��e,�������г�ջ����
	bool StackEmpty();//�ж�ջ�Ƿ�Ϊ��
	int GetNum();//�õ�ջ��ָ��
	ElemType* GetElement(int suf);//�õ�ջ��ָ��Ϊsuf��Ԫ��

};

//���캯��
template<class ElemType>
Stack<ElemType>::Stack() {
	this->Top = -1;
	this->data = new ElemType[MaxSize];
}

//��������
template<class ElemType>
Stack<ElemType>::~Stack() {
	delete[]data;
}

//��Ԫ��ѹ��ջ��
template<class ElemType>
bool Stack<ElemType>::Push(ElemType* e) {
	if (this->Top == MaxSize - 1)
		cout << "ջ����" << endl;
	else {
		this->data[this->Top + 1] = e;
		this->Top++;
	}
	return 1;
}

//��ջ��Ԫ�س�ջ��ֵ��e
template <class ElemType>
bool Stack<ElemType>::Pop(ElemType* e) {
	if (this->GetTop == -1) {
		return 0;
	}
	else {
		*e = this->data[this->top];
		this->Top--;
	}
	return 1;

}

//��ջ��Ԫ�ظ�ֵ��e���������г�ջ����
template <class ElemType>
bool Stack<ElemType>::GetTop(ElemType* e) {
	*e = this->data[this->Top];
	return 1;
}

//�ж�ջ�Ƿ�Ϊ��
template <class ElemType>
bool Stack<ElemType>::StackEmpty() {
	if (this->Top == -1)
		return 0;//��
	else
		return 1;//�ǿ�
}

//�õ�ջ��ָ��
template<class ElemType>
int Stack<ElemType>::GetNum() {
	return this->Top;
}

//�õ�ջ��ָ��Ϊsuf��ָ��
template <class ElemType>
ElemType* Stack<ElemType>::GetElement(int suf) {
	for (int i = 0; i <Top; i++) {
		if (i == suf)
		{
			return ElemType * i;
		}
	}
}