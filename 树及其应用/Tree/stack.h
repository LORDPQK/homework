#pragma once
#ifndef _STACK_H_
#define _STACK_H_

#define MaxSize 100

#include <iostream>
using namespace std;
template<class ElemType>
class Stack
{
private:
	typedef struct
	{
		ElemType*  data[MaxSize];  //ջ���ݱ�            
		int    top;  //ջ��ָ��
	} SqStack;
	SqStack* S;
	
public:

	Stack() {
			S = (SqStack*)malloc(sizeof(SqStack));
			S->top = -1;
	}

	bool Push( ElemType* e)
	{
		if (S->top == MaxSize - 1)  //ջ������ջ����
			return false;
		S->top++;            //ջ��ָ����1
		S->data[S->top] = e;  //Ԫ��e����ջ����
		return true;
	}

	bool Pop(ElemType*& e)
	{
		if (S->top == -1)    //ջΪ�գ���ջ�����
		return false;
		e = S->data[S->top];   //ȡջ��ָ��Ԫ��
		S->top--;		//ջ��ָ���1
		return true;
	}

	void Copy(Stack s) {
		Stack v;
		ElemType* p;
		while (!s.StackEmpty())
		{
			s.Pop(p);
			v.Push(p);
		}
		while (!v.StackEmpty())
		{
			v.Pop(p);
			Push(p);
		}
	}

	bool GetTop( ElemType* &e)
	{
		if (S->top == -1)  //ջΪ�գ���ջ����� 	   
			return false;
		e = S->data[S->top];   //ȡջ��Ԫ��
		return true;
	}

	bool StackEmpty()
	{
		if (S->top == -1)
			return true;
		else
		{
			return false;
		}
	}

	int GetNum() 
	{
		return S->top;
	}

	void DestroyStack()
	{
		free(S);
	}

	ElemType* GetElemType(int suf)//�õ�ջ��ָ��Ϊsuf��Ԫ��
	{
		return S->data[suf];
	}

};


#endif // !_STACK_H_
