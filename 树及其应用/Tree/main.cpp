#include<iostream>
#include<string>
#include"stack.h"
#include"Tree.h"
using namespace std;

int main() {
	BTree<char> tree = BTree<char>("A(B(E(G(N,H),F(I,J)),C(K,D(L,M))),)");
	cout << "�������ű�ʾ����" << tree.getatree() << "\n���������";
	tree.InOrderNotRe();
	cout << "ǰ�����:";
	tree.PreOrderNotRe();
	cout << "���������";
	tree.PostOrderNotRe(tree.GetBTNode());
	tree.FindAllAncenstor('G');
	return 0;
}