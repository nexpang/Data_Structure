// 20303 김경혁 
// stack 실습1-2
#include <iostream>
#include <stack>
#include <conio.h>

using namespace std;

int main() {
	stack<int> i_s;
	const int arrSize = 5;
	int c_arr[arrSize];
	char ch;
	cout << "2. 숫자 거꾸로 출력하기\n5 자리 숫자를 입력하세요.";
	for (int i = 0; i < arrSize; i++) {
		ch = _getch();
		if (ch - 48 < 0 || ch - 48 > 9) {
			cout << "\n0~9숫자만 입력하시오";
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