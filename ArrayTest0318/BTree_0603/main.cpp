//20303 김경혁
#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
#include "BinaryTree.h"

using namespace std;

vector<BTreeNode*> bts;
int input = 0;
string stringInput;
vector<int> nums1;//전위순회결과
vector<int> nums2;//후위순회결과

void SetBTree2(int i = 0);

int main() {

	cout << "입력\n";
	cin >> input;
	for (int i = 0; i < input; i++)
	{
		bts.push_back(MakeBTreeNode());
	}

	cin.ignore();
	getline(cin, stringInput);
	string saveInt = "";
	for (int i = 0; i < stringInput.length(); i++)
	{
		if (stringInput[i] == ' ')
		{
			nums1.push_back(atoi(saveInt.c_str()));
			saveInt = "";
		}
		else {
			saveInt += stringInput[i];
		}
	}
	nums1.push_back(atoi(saveInt.c_str()));
	if (input != nums1.size()) {
		cout << "\n에러: 전위순회의 크기가 트리의 크기와 다릅니다.";
		exit(0);
	}

	cin.ignore();
	getline(cin, stringInput);
	for (int i = 0; i < stringInput.length(); i++)
	{
		if (stringInput[i] == ' ')
		{
			nums2.push_back(atoi(saveInt.c_str()));
			saveInt = "";
		}
		else {
			saveInt += stringInput[i];
		}
	}
	nums2.push_back(atoi(saveInt.c_str()));
	if (input != nums2.size()) {
		cout << "\n에러: 후휘순회의 크기가 트리의 크기와 다릅니다.";
		exit(0);
	}

	for (int i = 0; i < input; i++)
	{
		SetData(bts[i], nums1[i]);
	}

	for (int i = 0; i < input; i++)
	{
		if (bts[i]->left != NULL)
			cout << bts[i]->left->data;
		if (bts[i]->right != NULL)
			cout << bts[i]->right->data;
	}
	cout << "\n출력" << endl;
	SetBTree2();
	//cout << "전위순위" << endl;
	//PreorderTraverse(bts[0]);
	//cout << "\n 중위순위" << endl;
	InorderTraverse(bts[0]);
	//cout << "\n 후위순위" << endl;
	//PostorderTraverse(bts[0]);
	return 0;
}

void SetBTree2(int i) {
	int idx1 = 0, idx2 = 0, idx3 = 0;
	bool ihaveLParent = false, ihaveRParent = false;
	if (i >= input) {
		return;
	}
	//cout <<"\ni: "<< i <<endl;
	for (int j = 0; j < input; j++)
	{
		if (i + 1 >= input) {
			break;
		}
		if (bts[i + 1]->data == nums2[j]) {
			idx1 = j;
			break;
		}
	}
	for (int j = 0; j < input; j++)
	{
		if (i + 1 >= input) {
			break;
		}
		if (bts[j]->left != NULL) {
			if (bts[j]->left->data == bts[i + 1]->data) {
				//cout << "일 왼쪽의 부모";
				ihaveLParent = true;
				break;
			}
		}
		if (bts[j]->right != NULL) {
			if (bts[j]->right->data == bts[i + 1]->data) {
				//cout << "일 오른쪽의 부모";
				ihaveLParent = true;
				break;
			}

		}
	}
	if (!ihaveLParent) {
		if (i + 1 < input){
			MakeLeftSubTree(bts[i], bts[i + 1]);
			//cout << "왼쪽" << endl;
		}
	}
	for (int j = 0; j < input; j++)
	{
		if (bts[i]->data == nums2[j]) {
			idx2 = j;
			break;
		}
	}
	for (int j = 0; j < input; j++)
	{
		if (idx2 > 0) {
			if (bts[j]->data == nums2[idx2 - 1]) {
				idx3 = j;
				break;
			}
		}
	}
	for (int j = 0; j < input; j++)
	{
		if (idx2 <= 0)
			break;
		if (bts[j]->left != NULL) {
			if (bts[j]->left->data == bts[idx3]->data) {
				//cout << "이 왼쪽의 부모";
				ihaveRParent = true;
				break;
			}
		}
		if (bts[j]->right != NULL) {
			if (bts[j]->right->data == bts[idx3]->data) {
				//cout << "이 오른쪽의 부모";
				ihaveRParent = true;
				break;
			}
		}
	}
	if (!ihaveRParent) {
		if (idx2 > 0) {
			MakeRightSubTree(bts[i], bts[idx3]);
			//cout << "오른쪽"<< bts[i]->data<< bts[idx3]->data << endl;
		}
	}
	for (int j = 0; j <= input; j++)
	{
		if (bts[i]->left != NULL) {
			if (nums1[j] == bts[i]->left->data) {
				//cout << "ㅇ" << j << bts[i]->data;
				//cout << bts[i]->left->data;
				//cout << "왼트리";
				SetBTree2(j);
				break;
			}
		}
	}
	for (int j = 0; j <= input; j++)
	{
		if (bts[i]->right != NULL) {
			if (nums1[j] == bts[i]->right->data) {
				//cout << "ㅇ" << j << bts[i]->data;
				//cout << bts[i]->right->data;
				//cout << "오른트리";
				SetBTree2(j+1);
				break;
			}
		}
	}
}