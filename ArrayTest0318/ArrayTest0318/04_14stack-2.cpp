// 20303 ����� 
// stack �ǽ�1-2
#include <iostream>
#include <stack>
#include <conio.h>

using namespace std;

int main() {
	stack<int> i_s;
	const int arrSize = 5;
	int c_arr[arrSize];
	char ch;
	cout << "2. ���� �Ųٷ� ����ϱ�\n5 �ڸ� ���ڸ� �Է��ϼ���.";
	for (int i = 0; i < arrSize; i++) {
		ch = _getch();
		if (ch - 48 < 0 || ch - 48 > 9) {
			cout << "\n0~9���ڸ� �Է��Ͻÿ�";
			return 0;
		}
		c_arr[i] = (int)ch - 48;
		cout << c_arr[i];
	}
	cout << endl;
	//cin.getline(c_arr,arrSize);
	for (int i = 0; i < arrSize; i++) {
		i_s.push(c_arr[i]);
	}
	for (int i = 0; i < arrSize; i++) {
		if (!i_s.empty()) {
			cout << i_s.top();
			i_s.pop();
		}
	}
	return 0;
}