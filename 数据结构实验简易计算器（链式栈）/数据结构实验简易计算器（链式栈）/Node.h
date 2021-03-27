#ifndef __NODE_HPP__
#endif
#define __NODE_HPP__
// �����
template <class ElemType>
struct Node
{
	// ���ݳ�Ա:
	ElemType data;   // ������
	Node<ElemType>* next;  // ָ����
   // ���캯��: 
	Node();      // �޲����Ĺ��캯��
	Node(ElemType item, Node<ElemType>* link = NULL); // ��֪������Ԫ��ֵ��ָ
};
template <class ElemType>
Node<ElemType>::Node() {
	this->data = -1;
	this->next = nullptr;
}
template <class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType>* link) {
	this->data = item;
	link = this;
	this->next = nullptr;
}
