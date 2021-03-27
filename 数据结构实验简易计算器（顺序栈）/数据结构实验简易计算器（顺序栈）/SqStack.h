#ifndef __SQ_STACK_HPP__
#endif
#define __SQ_STACK_HPP__
// ANSI C++��׼��ͷ�ļ�
#include <cstring>     // ��׼������
#include <iostream>     // ��׼������
using namespace std;
#define DEFAULT_SIZE 100
template<class ElemType>
class SqStack
{
protected:
	// ˳��ջ�����ݳ�Ա:
	int top;          // ջ��ָ�� 
	int maxSize;         // ջ��������� 
	ElemType* data;        // Ԫ�ش洢�ռ�
public:
	//  ˳��ջ�ķ������������ر���ϵͳĬ�Ϸ�������:
	SqStack(int size = DEFAULT_SIZE);    // ���캯��
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
template<class ElemType>
SqStack<ElemType>::SqStack(int size) {
	this->top = -1;
	this->maxSize = size;
	this->data = new ElemType[size];
}
// ��������
template<class ElemType>
SqStack<ElemType>::~SqStack() {
	delete[] data;
}
// ��ջ�ĳ���
template<class ElemType>
int SqStack<ElemType>::getLength() const {
	return this->top + 1;
}
// �ж�ջ�Ƿ�Ϊ��
template<class ElemType>
bool SqStack<ElemType>::isEmpty() const {
	return this->top == -1;
}
// ��ջ���
template<class ElemType>
void SqStack<ElemType>::clear() {
	this->top = -1;
}
// ����ջ
template<class ElemType>
void SqStack<ElemType>::traverse(void(*Visit)(const ElemType&)) const {
	for (int i = 0; i <= this->top; i++) {
		(*Visit)(data[i]);
	}
}
// ��ջ
template<class ElemType>
int SqStack<ElemType>::push(const ElemType e) {
	if (this->top == DEFAULT_SIZE - 1)
		cout << "ջ����" << endl;
	else {
		this->data[this->top + 1] = e;
		this->top++;
	}
	return 0;
}
// ȡ��Ԫ��
template<class ElemType>
int SqStack<ElemType>::getTop(ElemType& e) const {
	if (this->top == -1)
		cout << "ջ����" << endl;
	else
		e = this->data[this->top];
	return 0;
}
// ��ջ
template<class ElemType>
int SqStack<ElemType>::pop(ElemType& e) {
	if (this->top == -1)
		cout << "ջ����" << endl;
	else {
		e = this->data[this->top];
		this->top--;
	}
	return 0;
}
// ���ƹ��캯��
template<class ElemType>
SqStack<ElemType>::SqStack(const SqStack<ElemType>& s) {
	this->top = s.top;
	for (int i = 0; i < s.top; i++) {
		this->data[i] = s.data[i];
	}
}
// ��ֵ�������
template<class ElemType>
SqStack<ElemType>& SqStack<ElemType>::operator =(const SqStack<ElemType>& s) {
	this->top = s.top;
	for (int i = 0; i < s.top; i++) {
		this->data[i] = s.data[i];
	}
}
