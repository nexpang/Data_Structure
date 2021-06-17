//20303 김경혁

#include<iostream>
#include<vector>

#include "BinaryTree.h"

using namespace std;

vector<BTreeNode*> bts;
int input = 0;
int num = 1;
int num1 = 1;
int num2 = 1;
int numCnt = 1;

int getNextLevel(int a)
{
	int cnt=0;
	do {
		a /= 2;
		cnt++;
	} 	while (a != 0);
	return cnt;
}

int main() {
	cout << "입력\n";
	cin >> input;
	for (int i = 0; i < input; i++)
	{
		num *= 2;
	}
	for (int i = 0; i < input-1; i++)
	{
		num1 *= 2;
	}
	for (int i = 0; i < input - 2; i++)
	{
		num2 *= 2;
	}
	bts.push_back(MakeBTreeNode());
	SetData(bts[0], 1,-1);

	for (int i = 1; i < num; i++) {
		bts.push_back(MakeBTreeNode());
		SetData(bts[i], 1, 0);
	}
	
	for (int i = 1; i < num1; i++)
	{
		int left = i * 2;
		int right = (i * 2) + 1;
		int rightData = 1;
		int nextLevel = getNextLevel(i);
		//cout << "다음레벨" << nextLevel<<endl;
		SetData(bts[left], bts[i]->data, nextLevel);
		//cout << "왼노드 " << left << " 값: " << bts[i]->data<<endl;
		for (int j = 0; j < nextLevel - 1; j++)
		{
			rightData *= 2;
		}
		SetData(bts[right], bts[i]->data+rightData, nextLevel);
		//cout << "오른노드 " << right << " 값: "<< bts[i]->data + rightData << endl;
		MakeLeftSubTree(bts[i], bts[left]);
		MakeRightSubTree(bts[i], bts[right]);
	}
	SetData(bts[1], num - numCnt);
	for (int i = 1; i < num2; i++)
	{
		numCnt++;
		SetData(bts[i]->left, num-numCnt);
		numCnt++;
		SetData(bts[i]->right, num - numCnt);
	}
	for (int i = 1; i < num; i++) {
		//cout << bts[i]->data;
		cout << " ";
	}
	cout << endl;
	PreorderTraverse(bts[1]);

	return 0;
}