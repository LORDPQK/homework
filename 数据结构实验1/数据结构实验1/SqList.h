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


template <class ElemType>
class SqList
{
protected:
	// ˳�������ݳ�Ա
	int length;     // ˳���ĵ�ǰ���� 
	int maxLength;    // ˳�����������
	ElemType* data;   // Ԫ�ش洢�ռ���׵�ַ 
public:
	// ˳���ĺ����� ����һ���ձ� 
	SqList(int size = DEFAULT_SIZE) {
		this->length = 0;
		this->maxLength = size;
		data = new ElemType[DEFAULT_SIZE];
	}
	// ��������v�����ݹ���˳��� 
	template <class ElemType>
	SqList(ElemType v[], int n, int size = DEFAULT_SIZE) {
		this->data = new ElemType(DEFAULT_SIZE);
		this->length = n;
		this->maxLength = size;
		for (int i = 0; i < n; i++) {
			ElemType* p = new ElemType;
			*p = v[i];
			data[i] = *p;
		}
	}
	// ��������
	virtual ~SqList() {
	}
	// ȡ˳����� 
	int GetLength() const {
		return this->length;
	}
	// �ж�˳����Ƿ�Ϊ��
	bool IsEmpty() const {
		return this->length == 0;
	}
	// ��˳������
	void Clear() {
		delete[] data;
		//this->length = 0;
	}
	// ����˳���
	template <class ElemType>
	void Traverse(void(*Visit)(const ElemType&)) const {
		for (int i = 0; i < this->length; i++) {
			(*Visit)(data[i]);
		}
		if (this->length == 0)
			cout << "û�г�Ա" << endl;
	}
	// Ԫ�ض�λ����ָ��Ԫ����˳����е�λ��
	template <class ElemType>
	int LocateElem(const ElemType& e) {
		int sign = 0;
		for (int i = 0; i < this->length; i++) {
			if (this->data[i] == e) {
				sign = 1;
				return i + 1;
			}
		}
		if (sign == 0)
			cout << "û���ҵ�" << endl;
		return -1;
	}
	// ȡ˳����е�i��Ԫ�ص�ֵ
	template <class ElemType>
	int GetElem(int i, ElemType& e) const {

		if ((i - 1 <= this->length - 1) && i >= 0)
			e = data[i - 1];
		else
			cout << "û���ҵ�" << endl;
		return 0;
	}
	// �޸�˳����е�i��Ԫ�ص�ֵ
	template <class ElemType>
	int SetElem(int i, const ElemType& e) {
		if ((i <= this->length) && i >= 0)
			this->data[i - 1] = e;
		else
			cout << "û���ҵ�" << endl;
		return 0;
	}
	// ɾ��˳����е�i��Ԫ��  
	template <class ElemType>
	int DeleteElem(int i, ElemType& e) {
		e = this->data[i - 1];
		if ((i <= this->length) && i >= 0) {
			for (int j = i - 1; j < this->length - 1; j++)
				this->data[j] = this->data[j + 1];
			this->length--;
		}
		else
			cout << "û���ҵ�" << endl;
		return 0;
	}
	// ��˳����i��λ�ò���Ԫ��
	template <class ElemType>
	int InsertElem(int i, const ElemType& e) {
		if (((i - 1 <= this->length) && i > 0)) {
			for (int j = this->length; j > i - 1; j--) {
				this->data[j] = this->data[j - 1];
			}
			this->data[i - 1] = e;
		}
		else
			cout << "û���ҵ�" << endl;
		this->length++;
		return 0;
	}
	void change_two(int m) {
		ElemType a;
		a = this->data[m - 1];
		this->data[m - 1] = this->data[m + 1 - 1];
		this->data[m + 1 - 1] = a;
	}
	// ��˳����β����Ԫ��
	template <class ElemType>
	int InsertElem(const ElemType& e) {
		this->data[this->length] = e;
		this->length++;
		return 0;
	}
	// ���ƹ��캯��
	template <class ElemType>
	SqList(const SqList<ElemType>& sa) {
		for (int i = 0; i < sa.GetLength(); i++) {
			this->data[i] = sa.data[i];
		}
		this->length = sa.GetLength();
	}
	// ��ֵ�������
	template <class ElemType>
	SqList<ElemType>& operator =(const SqList<ElemType>& sa) {
		SqList(sa);
		return *this;
	}
};