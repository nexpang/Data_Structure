//20303 김경혁
#include <iostream>

using namespace std;

#include "BinaryTree.h"

BTreeNode* MakeBTreeNode(void) { // 빈노드 생성
	BTreeNode* nd = new BTreeNode;
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

void DeleteBTreeNode(BTreeNode* bt) { //노드 삭제
	delete bt;
}

BTData GetData(BTreeNode* bt) {
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data) // 노드 값설정
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt) {
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt) {
	return bt->left;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) { // 왼쪽 자식 노드로 연결
	if (main->left != NULL)
		delete main->left;
	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) { // 오른쪽 자식 노드로 연결
	if (main->right != NULL)
		delete main->right;
	main->right = sub;
}

void PreorderTraverse(BTreeNode* bt) {
	if (bt == NULL)
		return;

	cout << bt->data << endl;
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