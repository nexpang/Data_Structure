// 20303 �����
//queue 1-1
/*
#include <queue>
#include <iostream>

using namespace std;

int main() {
	queue<int> i_q;

	i_q.push(1);
	if (!i_q.empty()) {
		cout << i_q.front();
		i_q.pop();
	}
	else {
		cout << "queue�� ����ֽ��ϴ�" << endl;
	}

	return 0;
}
//*//*
// 20303 �����
//queue 1-2
#include <queue>
#include <iostream>

using namespace std;

bool isFull(int size, queue<int>);

int main() {
	queue<int> i_q;
	int q_size = 3;
	bool q_isfull = false;

	for (int i = 0; i < q_size + 1; i++)//ũ�⺸�� �ϳ� ũ�� �����Ͽ� fullȮ��
	{
		if (!isFull(q_size, i_q)) {
			i_q.push(1);
			cout << i_q.back() << "�� ���ԵǾ����ϴ�" << endl;
		}
		else {
			cout << "queue�� �����ֽ��ϴ�" << endl;
		}
	}
	for (int i = 0; i < q_size+1; i++)//ũ�⺸�� �ϳ� ũ�� �����Ͽ� emptyȮ��
	{
		if (!i_q.empty()) {
			cout << i_q.front()<<endl;
			i_q.pop();
		}
		else {
			cout << "queue�� ����ֽ��ϴ�" << endl;
		}
	}

	return 0;
}
bool isFull(int size, queue<int> q_i) {
	if (q_i.size() == size) {
		return true;
	}
	else {
		return false;
	}
}
//*///*
// 20303 �����
//queue 1-3
#include <queue>
#include <iostream>

using namespace std;

bool isFull(int size, queue<int>);

int main() {
	queue<int> i_q;
	int q_size = 3;
	bool q_isfull = false;

	for (int i = 0; i < q_size + 1; i++)//ũ�⺸�� �ϳ� ũ�� �����Ͽ� fullȮ��
	{
		if (!isFull(q_size, i_q)) {
			i_q.push(1);
			cout << i_q.back() << "�� ���ԵǾ����ϴ�" << endl;
		}
		else {
			cout << "queue�� �����ֽ��ϴ�" << endl;
		}
	}
	for (int i = 0; i < q_size + 1; i++)//ũ�⺸�� �ϳ� ũ�� �����Ͽ� emptyȮ��
	{
		if (!i_q.empty()) {
			cout << i_q.front() << endl;
			i_q.pop();
		}
		else {
			cout << "queue�� ����ֽ��ϴ�" << endl;
		}
	}

	return 0;
}
bool isFull(int size, queue<int> q_i) {
	if (q_i.size() == size) {
		return true;
	}
	else {
		return false;
	}
}

//*/