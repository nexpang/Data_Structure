//20303 김경혁
#include <iostream>

using namespace std;

typedef int BTData; // 노드의 값을 int로 설정

struct BTreeNode {
	BTData data; // 노드의 값
	struct BTreeNode* left; // 왼쪽 자식 노드
	struct BTreeNode* right; // 오른쪽 자식 노드
};

//BTreeNode* bt1 = MakeBTreeNode(); 실행

BTreeNode* MakeBTreeNode(void) { // 빈노드 생성
	BTreeNode* nd = new BTreeNode;
	nd->left = NULL;
	nd->right = NULL;
	return nd;

}

//DeleteBTreeNode(bt); 실행

void DeleteBTreeNode(BTreeNode* bt) { //노드 삭제
	delete bt;
}

BTData GetData(BTreeNode* bt) {
	return bt->data;
}

//SetData(bt1, 1); 실행

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

//MakeLeftSubTree(bt1, bt2) 실행

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) { // 왼쪽 자식 노드로 연결
	if (main->left != NULL)
		delete main->left;
	main->left = sub;
}

//MakeRightSubTree(bt1, bt2) 실행

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) { // 오른쪽 자식 노드로 연결
	if (main->right != NULL)
		delete main->right;
	main->right = sub;
}

int main() {
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	cout << GetData(GetLeftSubTree(bt1)) << endl;
	cout << GetData(GetLeftSubTree(GetLeftSubTree(bt1))) << endl;

	DeleteBTreeNode(bt1);
	DeleteBTreeNode(bt2);
	DeleteBTreeNode(bt3);
	DeleteBTreeNode(bt4);
}