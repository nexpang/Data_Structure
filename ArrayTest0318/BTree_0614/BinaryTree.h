#pragma once
//20303 김경혁
typedef int BTData; // 노드의 값을 int로 설정

typedef struct _bTreeNode {
	BTData data; // 노드의 값
	struct _bTreeNode* left; // 왼쪽 자식 노드
	struct _bTreeNode* right; // 오른쪽 자식 노드
	int level;
}BTreeNode;

BTreeNode* MakeBTreeNode(void);
void DeleteBTreeNode(BTreeNode* bt);

BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data, int level=-1);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

void PreorderTraverse(BTreeNode* bt);
void InorderTraverse(BTreeNode* bt);
void PostorderTraverse(BTreeNode* bt);