//20303 김경혁
typedef BTData int; // 노드의 값을 int로 설정

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
}

//DeleteBTreeNode(bt); 실행

void DeleteBTreeNode(BTreeNode* bt) { //노드 삭제
	delete bt;
}

//SetData(bt1, 1); 실행

void SetData(BTreeNode* bt, BTData data) // 노드 값설정
{
	bt->data = data;
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