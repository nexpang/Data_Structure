// 20303 김경혁
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
		cout << "queue가 비어있습니다" << endl;
	}

	return 0;
}
//*//*
// 20303 김경혁
//queue 1-2
#include <queue>
#include <iostream>

using namespace std;

bool isFull(int size, queue<int>);

int main() {
	queue<int> i_q;
	int q_size = 3;
	bool q_isfull = false;

	for (int i = 0; i < q_size + 1; i++)//크기보다 하나 크게 삽입하여 full확인
	{
		if (!isFull(q_size, i_q)) {
			i_q.push(1);
			cout << i_q.back() << "가 삽입되었습니다" << endl;
		}
		else {
			cout << "queue가 꽉차있습니다" << endl;
		}
	}
	for (int i = 0; i < q_size+1; i++)//크기보다 하나 크게 삭제하여 empty확인
	{
		if (!i_q.empty()) {
			cout << i_q.front()<<endl;
			i_q.pop();
		}
		else {
			cout << "queue가 비어있습니다" << endl;
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
// 20303 김경혁
//queue 1-3
#include <queue>
#include <iostream>

using namespace std;

bool isFull(int size, queue<int>);

int main() {
	queue<int> i_q;
	int q_size = 3;
	bool q_isfull = false;

	for (int i = 0; i < q_size + 1; i++)//크기보다 하나 크게 삽입하여 full확인
	{
		if (!isFull(q_size, i_q)) {
			i_q.push(1);
			cout << i_q.back() << "가 삽입되었습니다" << endl;
		}
		else {
			cout << "queue가 꽉차있습니다" << endl;
		}
	}
	for (int i = 0; i < q_size + 1; i++)//크기보다 하나 크게 삭제하여 empty확인
	{
		if (!i_q.empty()) {
			cout << i_q.front() << endl;
			i_q.pop();
		}
		else {
			cout << "queue가 비어있습니다" << endl;
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