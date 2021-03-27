#pragma once
#ifndef _TREE_H_
#define _TREE_H_

#include<iostream>
#include"stack.h"

template<class ElemType>
class BTree
{
private:
	typedef struct node
	{
		ElemType data;
		struct node* lchild;
		struct node* rchild;
	} BTNode;

	BTNode* B;  //���ڵ�
	std::string aTree;
public:
	string getatree() {
		return aTree;
	}

	BTree(std::string str)
	{
		char ch;
		BTNode* p, *r;
		p = r = NULL;
		aTree = str;
		Stack<BTNode> stack;
		int  k, j = 0;                //k����˭�����Һ���

		while ((ch = str[j]) != '\0')
		{
			switch (ch)
			{
			case '(':
				stack.Push(r);          //���ڵ���ջ 
				r = p;
				k = 1;                    //1Ϊ���� 
				break;
			case ',':
				k = 2;					//2Ϊ�Һ��� 
				break;
			case ')':
				stack.Pop(r);                  //���ڵ��ջ 
				break;
			default:
				p = (BTNode*)malloc(sizeof(BTNode));
				p->data = ch;
				p->lchild = p->rchild = NULL;
				if (B == NULL)        //��Ϊ��ʱ 
				{
					B = p;
					r = B;
				}
				else                   //���ǿ�ʱ 
				{
					switch (k)
					{
					case 1:
						r->lchild = p;//���ڵ������ 
						break;
					case 2:
						r->rchild = p;//���ڵ���Һ��� 
						break;
					}
				}
			}
			j++;
		}
	}

	BTNode* GetBTNode() {
		return B;
	}

	void PreOrder(BTNode* B)//����ǵݹ�
	{
		if (B != NULL)
		{
			cout << B->data;    //���ʸ����
			PreOrder(B->lchild);
			PreOrder(B->rchild);
		}
	}

	void PreOrderNotRe()
	{
		BTNode* p;  Stack<BTNode> st;	//����һ��˳��ջ
		p = B;
		while (!st.StackEmpty() || p != NULL)
		{
			while (p != NULL)	 //���ʽ��p�����������½�㲢��ջ
			{
				cout << p->data;	//���ʽ��p
				st.Push(p);		//���p��ջ
				p = p->lchild;		//�ƶ�������
			}
			//���¿���ջ�����
			if (!st.StackEmpty())	 //��ջ����
			{
				st.Pop(p);	//��ջ���p
				p = p->rchild;	//ת������������
			}
		}
		cout << endl;
	}

	void InOrderNotRe()
	{
		BTNode* p;  Stack<BTNode> st;	//����һ��˳��ջ
		p = B;
		while (!st.StackEmpty() || p != NULL)
		{
			while (p != NULL)	//ɨ����p���������½�㲢��ջ
			{
				st.Push(p);		//���p��ջ
				p = p->lchild;	//�ƶ�������
			}
			//���¿���ջ�����
			if (!st.StackEmpty())	//��ջ����
			{
				st.Pop(p);		//��ջ���p�����ʽ��p
				cout << p->data;
				p = p->rchild;    //ת������������
			}
		}
		cout << endl;
	}

	void PostOrderNotRe(BTNode* b)	//����ǵݹ�����㷨
	{
		BTNode* p, *r;
		bool flag;
		Stack<BTNode> st;		//����һ��˳��ջ
		p = b;
		do
		{
			while (p != NULL)	//ɨ����p���������½�㲢��ջ
			{
				st.Push(p);		//���p��ջ
				p = p->lchild;	//�ƶ�������
			}
			r = NULL;		//rָ��ոշ��ʵĽ�㣬��ʼʱΪ��
			flag = true;
			while (!st.StackEmpty() && flag)
			{
				st.GetTop(p);	         //ȡ����ǰ��ջ�����p
				if (p->rchild == r)        //�����p���Һ���Ϊ�ջ���Ϊ�շ��ʽ��	
				{
					cout << p->data;    //���ʽ��p
					st.Pop(p);
					r = p;		 //rָ��շ��ʹ��Ľ��
				}
				else
				{
					p = p->rchild;	//ת������������
					flag = false;		//��ʾ��ǰ���Ǵ���ջ�����
				}
			}
		} while (!st.StackEmpty());	//ջ����ѭ��
		cout << endl;
	}

	void DestoryTree(BTNode*& b) {
		free(b);
	}

	template<int N>
	void ShowAncenstor(int row, BTNode* e[N][N], char object) //�����������ͬ���Լ�����ֵ
	{

		int  col = 0;
		if (row < 0)
		{
			cout << "û�иó�Ա";
			return;
		}
		cout << object << "�ĳ����У�";
		for (int i = 0; i < row; i++, col = 0)
			while (e[i][col] != NULL)
			{
				cout << e[i][col]->data;
				col++;
			}
		col = 0;
		cout << endl;
		cout << object << "��ͬ����:";
		while (e[row][col] != NULL)
		{
			cout << e[row][col]->data;
			col++;
		}
		col = 0;
		row++;
		cout << endl << object << "������:";
		while (e[row][col] != NULL) {
			while (e[row][col] != NULL)
			{
				cout << e[row][col]->data;
				col++;
			}
			col = 0;
			row++;
		}
		cout << endl;
	}


	/*****************************************************************************
	��һ��BTNode* e[i][j]��ά��������ʾ���֣�i��ʾ��ͬ���֣�j��ʾ��������е�������
	�������ӵ�e[0][0],��ʼ������i�е�����ֱ�������Ϊ�գ��ٿ�ʼ����i+1�е����ݡ�
	����ʱ��ÿ��Ԫ�����Һ���ʱֱ����ӵĵ�ǰ���ֵĺ�̣�������ֱ����ӵ���һ�еĺ�̡�
	ֱ��e[i][0]=NULLΪֹ��
	*********************************************************************************/
	template<int N>
	void ClsGenerations(BTNode* e[N][N])//�Բ�ͬ�ı��ֽ��з���
	{

		BTNode* p;
		p = B;
		//iΪ��ǰ��εĻ�û�ж�ȡ�ĸ�����nowΪ����εĸ�����nextΪ��һ����εĸ�����
		int deep = 0, i = 0, now = 0, next = 0;
		if (p == NULL)
			return;
		e[0][0] = p;
		now++;
		while (e[deep][i] != NULL)
		{
			while (e[deep][i] != NULL)//������ǰ��ȵ���������
			{
				if (e[deep][i]->rchild != NULL)//�Һ��ӱ�������ǰ��ȵĺ��
				{
					e[deep][now] = e[deep][i]->rchild;
					now++;
				}
				if (e[deep][i]->lchild != NULL)//���ӱ�������һ����ȵĺ�� 
				{
					e[deep + 1][next] = e[deep][i]->lchild;
					next++;
				}
				i++;
			}
			deep++;
			i = 0;
			now = next;
			next = 0;
		}
	}

	void intiarray(BTNode* e[100][100])
	{
		//��ʼ��
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				e[i][j] = NULL;

	}

	void  FindAllAncenstor(char object)//�ҵ�ͬ�����䳤��
	{
		BTNode* e[MaxSize][MaxSize];

		intiarray(e);

		ClsGenerations<MaxSize>(e);
		int row = -1;		//������¼Ԫ��������
		int col = 0;		//��¼��
		int flag = false;		//�ҵ�Ԫ�صı�־
		while (!flag)
		{
			row++;
			col = 0;
			while (e[row][col] != NULL)
			{
				if (e[row][col]->data == object)
				{
					flag = true;
				}
				col++;
			}

		}
		ShowAncenstor<MaxSize>(row, e, object);
	}


};



#endif // !tree
