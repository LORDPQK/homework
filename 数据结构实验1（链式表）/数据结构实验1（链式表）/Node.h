#ifndef __NODE_H__
#endif
#define __NODE_H__
// �����
template <class ElemType>
struct Node
{
	// ���ݳ�Ա:
	ElemType data;    // ������
	Node<ElemType> *next;  // ָ����
   // ���캯��:
   // �޲����Ĺ��캯��
	Node() {
		this->next = nullptr;
	}
	// ��֪������Ԫ��ֵ��ָ�뽨���ṹ
	template <class ElemType>
	Node(ElemType e, Node<ElemType> *link) {
		this->data = e;
		link = this;
		this->next = nullptr;
	}
};