//20303 �����
#pragma once

typedef int BTData; // ����� ���� int�� ����

typedef struct _bTreeNode {
	BTData data; // ����� ��
	struct _bTreeNode* left; // ���� �ڽ� ���
	struct _bTreeNode* right; // ������ �ڽ� ���
}BTreeNode;

BTreeNode* MakeBTreeNode(void);
void DeleteBTreeNode(BTreeNode* bt);

BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

void PreorderTraverse(BTreeNode* bt);
void InorderTraverse(BTreeNode* bt);
void PostorderTraverse(BTreeNode* bt);