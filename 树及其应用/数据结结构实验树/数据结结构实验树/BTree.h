#pragma once
#ifndef __BTREE_H__
#define __BTREE_H__

#include <stdio.h>
#include<malloc.h>
#include<iostream>
#include"Node.h"
#include"Stack.h"
#define MaxSize 100


using namespace std;

template <class ElemType>
class BTree
{
	//���Ľṹ�嶨��
	typedef struct node
	{
		ElemType data;//���ڵ�ֵ
		struct node* lchild;//���ڵ�����
		struct node* rchild;//���ڵ��Һ���
	}BTNode;
	BTNode* b;//���ڵ�

public:
	BTree(std::string str);//�������ű�ʾ����ʼ����
	~BTree();
	void PostOrder();
	void PostOrderRe(BTNode* b = b);//��������ǵݹ��㷨
	void PreOrderNotRe();//��������ǵݹ��㷨
	void FindAllAncestor(char object);//����ڵ�obiect�����г���
	void ShowAncestor(BTNode* ancestor);//���ancestor��ֵ����ͬ����ֵ
	                                    //�����ֵܱ�ʾ���������������ֵ�
	void DestroyBTree(BTNode* &b);//������

};

#endif __BTREE_H__

template<class ElemType>
BTree<class ElemType>::BTree(std::string str) {
	Node<ElemType>* node = NULL;//��ʱ�ڵ�ָ��
	int n = 1;//1.���� 2.�Һ���
	//����װÿ���������ڵ��ջ
	Stack<Node<ElemType>*> *stack = new Stack<Node<ElemType>*>();


	while (*p != '0') {
		switch (*p)
		{
		case'(':
			stack->Push(node);
			n = 1;
			break;
		case',':
			n = 2;
			break;
		case')':
			stack->Pop();
			break;
		default:
			node->generationLevel = 1;
			if (b == NULL) {

			}

		}
	}

}
