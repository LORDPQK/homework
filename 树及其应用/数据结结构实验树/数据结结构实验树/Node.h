#pragma once
template<class ElemType>
class Node
{
public:
	Node<ElemType> *leftchild;//����
	Node<ElemType> *reftchild;//�Һ���
	ElemType data;//�ڵ��ֵ
	int generationLevel;//�ýڵ����ڵı���
	

	Node();
	Node(ElemType data);
	~Node();
};

template<class ElemType>
Node<class ElemType>::Node() {

}

template<class ElemType>
Node<class ElemType>::Node(ElemType data) {
	this->data = data;

}

template<class ElemType>
Node<class ElemType>::~Node() {

}




