//20303 �����
typedef BTData int; // ����� ���� int�� ����

struct BTreeNode {
	BTData data; // ����� ��
	struct BTreeNode* left; // ���� �ڽ� ���
	struct BTreeNode* right; // ������ �ڽ� ���
};

//BTreeNode* bt1 = MakeBTreeNode(); ����

BTreeNode* MakeBTreeNode(void) { // ���� ����
	BTreeNode* nd = new BTreeNode;
	nd->left = NULL;
	nd->right = NULL;
}

//DeleteBTreeNode(bt); ����

void DeleteBTreeNode(BTreeNode* bt) { //��� ����
	delete bt;
}

//SetData(bt1, 1); ����

void SetData(BTreeNode* bt, BTData data) // ��� ������
{
	bt->data = data;
}

//MakeLeftSubTree(bt1, bt2) ����

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) { // ���� �ڽ� ���� ����
	if (main->left != NULL)
		delete main->left;
	main->left = sub;
}

//MakeRightSubTree(bt1, bt2) ����

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) { // ������ �ڽ� ���� ����
	if (main->right != NULL)
		delete main->right;
	main->right = sub;
}