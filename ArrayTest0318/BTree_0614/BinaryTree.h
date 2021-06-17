#pragma once
//20303 �����
typedef int BTData; // ����� ���� int�� ����

typedef struct _bTreeNode {
	BTData data; // ����� ��
	struct _bTreeNode* left; // ���� �ڽ� ���
	struct _bTreeNode* right; // ������ �ڽ� ���
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