#pragma once
#ifndef __SQ_LIST_H__
#endif
#define __SQ_LIST_H__
// ANSI C++��׼��ͷ�ļ�
#include <cstring>     // ��׼������
#include <iostream>     // ��׼������
using namespace std;
// �궨��
#define DEFAULT_SIZE 1000   // ȱʡԪ�ظ���
#define DEFAULT_INFINITY 1000000 // ȱʡ�����
// ˳���ģ��������� 
template <class ElemType>
class SqList
{
protected:
	// ˳�������ݳ�Ա
	int length;     // ˳���ĵ�ǰ���� 
	int maxLength;    // ˳�����������
	ElemType* data;   // Ԫ�ش洢�ռ���׵�ַ 
public:
	// ˳���ĺ�����Ա
	SqList(int size = DEFAULT_SIZE); // ����һ���ձ� 
	virtual ~SqList();   // ��������
	int GetLength() const;  // ȡ˳�����    
	int GetElem(int i, ElemType& e) const; // ȡ˳����е�i��Ԫ�ص�ֵ 
	int SetElem(int i, const ElemType& e); // �޸�˳����е�i��Ԫ�ص�ֵ
	int DeleteElem(int i, ElemType& e);      // ɾ��˳����е�i��Ԫ��  
	int InsertElem(const ElemType& e);        // ��˳����β����Ԫ��
};
// ����һ���ձ�
template<class ElemType>
SqList<ElemType>::SqList(int size) {
	this->length = 0;
	this->maxLength = size;
	data = new ElemType[DEFAULT_SIZE];
}
// ��������
template<class ElemType>
SqList<ElemType>::~SqList() {
}
// ȡ˳����� 
template<class ElemType>
int SqList<ElemType>::GetLength() const {
	return this->length;
}
// ȡ˳����е�i��Ԫ�ص�ֵ
template<class ElemType>
int SqList<ElemType>::GetElem(int i, ElemType& e) const {
	if ((i < this->length) && i >= 0)
		e = data[i];
	else
		cout << "û���ҵ�" << endl;
	return 0;
}
// �޸�˳����е�i��Ԫ�ص�ֵ
template<class ElemType>
int SqList<ElemType>::SetElem(int i, const ElemType& e) {
	if ((i < this->length) && i >= 0)
		this->data[i] = e;
	else
		cout << "û���ҵ�" << endl;
	return 0;
}
// ɾ��˳����е�i��Ԫ��  
template<class ElemType>
int SqList<ElemType>::DeleteElem(int i, ElemType& e) {
	e = this->data[i];
	if ((i < this->length) && i >= 0) {
		for (int j = i; j < this->length - 1; j++)
			this->data[j] = this->data[j + 1];
		this->length--;
	}
	else
		cout << "û���ҵ�" << endl;
	return 0;
}
// ��˳����β����Ԫ��
template<class ElemType>
int SqList<ElemType>::InsertElem(const ElemType& e) {
	this->data[this->length] = e;
	this->length++;
	return 0;
}
#pragma once
