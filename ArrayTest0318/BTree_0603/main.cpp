//20303 �����
#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
#include "BinaryTree.h"

using namespace std;

vector<BTreeNode*> bts;
int input = 0;
string stringInput;
vector<int> nums1;//������ȸ���
vector<int> nums2;//������ȸ���

void SetBTree2(int i = 0);

int main() {

	cout << "�Է�\n";
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
		cout << "\n����: ������ȸ�� ũ�Ⱑ Ʈ���� ũ��� �ٸ��ϴ�.";
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
		cout << "\n����: ���ּ�ȸ�� ũ�Ⱑ Ʈ���� ũ��� �ٸ��ϴ�.";
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
	cout << "\n���" << endl;
	SetBTree2();
	//cout << "��������" << endl;
	//PreorderTraverse(bts[0]);
	//cout << "\n ��������" << endl;
	InorderTraverse(bts[0]);
	//cout << "\n ��������" << endl;
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
				//cout << "�� ������ �θ�";
				ihaveLParent = true;
				break;
			}
		}
		if (bts[j]->right != NULL) {
			if (bts[j]->right->data == bts[i + 1]->data) {
				//cout << "�� �������� �θ�";
				ihaveLParent = true;
				break;
			}

		}
	}
	if (!ihaveLParent) {
		if (i + 1 < input){
			MakeLeftSubTree(bts[i], bts[i + 1]);
			//cout << "����" << endl;
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
				//cout << "�� ������ �θ�";
				ihaveRParent = true;
				break;
			}
		}
		if (bts[j]->right != NULL) {
			if (bts[j]->right->data == bts[idx3]->data) {
				//cout << "�� �������� �θ�";
				ihaveRParent = true;
				break;
			}
		}
	}
	if (!ihaveRParent) {
		if (idx2 > 0) {
			MakeRightSubTree(bts[i], bts[idx3]);
			//cout << "������"<< bts[i]->data<< bts[idx3]->data << endl;
		}
	}
	for (int j = 0; j <= input; j++)
	{
		if (bts[i]->left != NULL) {
			if (nums1[j] == bts[i]->left->data) {
				//cout << "��" << j << bts[i]->data;
				//cout << bts[i]->left->data;
				//cout << "��Ʈ��";
				SetBTree2(j);
				break;
			}
		}
	}
	for (int j = 0; j <= input; j++)
	{
		if (bts[i]->right != NULL) {
			if (nums1[j] == bts[i]->right->data) {
				//cout << "��" << j << bts[i]->data;
				//cout << bts[i]->right->data;
				//cout << "����Ʈ��";
				SetBTree2(j+1);
				break;
			}
		}
	}
}