//20303 �����
#include <iostream>

using namespace std;

#include "BinaryTree.h"

BTreeNode* MakeBTreeNode(void) { // ���� ����
	BTreeNode* nd = new BTreeNode;
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

void DeleteBTreeNode(BTreeNode* bt) { //��� ����
	delete bt;
}

BTData GetData(BTreeNode* bt) {
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data, int level) // ��� ������
{
	bt->data = data;
	if(level!=-1)
		bt->level = level;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt) {
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt) {
	return bt->left;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) { // ���� �ڽ� ���� ����
	if (main->left != NULL)
		delete main->left;
	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) { // ������ �ڽ� ���� ����
	if (main->right != NULL)
		delete main->right;
	main->right = sub;
}

void PreorderTraverse(BTreeNode* bt) {
	if (bt == NULL)
		return;

	cout << bt->data << " ";
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}
void InorderTraverse(BTreeNode* bt) {
	if (bt == NULL)
		return;

	InorderTraverse(bt->left);
	cout << bt->data << endl;
	InorderTraverse(bt->right);
}
void PostorderTraverse(BTreeNode* bt) {
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	cout << bt->data << endl;
}