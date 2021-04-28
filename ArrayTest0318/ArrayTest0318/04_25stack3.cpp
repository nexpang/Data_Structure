// 20303 김경혁
// stack 실습3-1
/*
#include <iostream>
#include <stack>

using namespace std;

bool isFull(stack<int>, int);

int main() {
	stack<int> c_s;
	int sSize = 1000;

	int input;
	cout << "데이터를 넣을 수를 입력하시오 : ";
	cin >> input;
	if (input <= 0) {
		cout << "데이터의 수가 0이하 입니다.";
		return 0;
	}

	for (int i = 0; i < input; i++) {
		if (!isFull(c_s, sSize)) {
			c_s.push(1 + i);
		}
		else {
			cout << "stack이 꽉찼습니다";
			return 0;
		}
	}

	while (!c_s.empty()) {
		cout << c_s.top() << " ";
		c_s.pop();
	}

	return 0;
}
bool isFull(stack<int> s, int i) {
	if (s.size() == i) {
		return true;
	}
	return false;
}*/
/*
// 20303 김경혁
// stack 실습3-2
#include <iostream>
#include <stack>
#include <Windows.h>
#include <conio.h>

using namespace std;

bool isFull(stack<int>, int);

int main() {
	stack<int> c_s;
	int sSize = 10;
	char ch = ' ';
	int state = 0; // 1 = 숫자 입력, 2 = 계산
	int oper = 4; // 0 == +	1 == -	2 == *	3 == /
	double num1 =0, num2 =0;
	bool isFirst = true;
	cout << "계산하는 수는 10000000000자리 까지 입력 가능하다.\n\t\t\t\t\tq : 종료" << endl;
	while (true) {
		if (state == 2) {
			num2 = 0;
			int r = c_s.size();
			for (int i = 0; i < r; i++) {
				if (!c_s.empty()) {
					int sqare=1;
					for (int j = 0; j < i; j++) {
						sqare *= 10;
					}
					num2 += c_s.top() * sqare;
					c_s.pop();
				}
				else {
					cout << "stack이 비어있습니다";
					return 0;
				}
			}
			if (isFirst) {
				num1 += num2;
				isFirst = false;
			}
			else {
				switch (oper)
				{
				case 0:
					num1 += num2;
					break;
				case 1:
					num1 -= num2;
					break;
				case 2:
					num1 *= num2;
					break;
				case 3:
					num1 /= num2;
					break;
				default:
					num1 += num2;
					break;
				}
			}
			if (num1 == 0)
				cout << '0';
			cout << ' ' << ch << ' ';
		}
		ch = _getch();
		state = 1;
		
		if (ch == 'q') {
			break;
		}
		else if (ch >= '0' && ch <= '9') {
			if (!isFull(c_s, sSize)) {
				c_s.push(ch - '0');
				cout << c_s.top();
			}
		}
		else if(ch == '+'|| ch== '-'||ch=='*'||ch=='/'){
			switch (ch)
			{
			case '+':
				oper = 0;
				break;
			case '-':
				oper = 1;
				break;
			case '*':
				oper = 2;
				break;
			case '/':
				oper = 3;
				break;
			default:
				break;
			}
			state = 2;
		}
		else if (ch == 13) {
			num2 = 0;
			int r = c_s.size();
			for (int i = 0; i < r; i++) {
				if (!c_s.empty()) {
					int sqare = 1;
					for (int j = 0; j < i; j++) {
						sqare *= 10;
					}
					num2 += c_s.top() * sqare;
					c_s.pop();
				}
				else {
					cout << "stack이 비어있습니다";
					return 0;
				}
			}
			switch (oper)
			{
			case 0:
				cout << " = " << num1 + num2 << endl;
				break;
			case 1:
				cout << " = " << num1 - num2 << endl;
				break;
			case 2:
				cout << " = " << num1 * num2 << endl;
				break;
			case 3:
				cout << " = " << num1 / num2 << endl;
				break;
			default:
				num1 += num2;
				break;
			}
			num1 = 0;
			state = 1;
			isFirst = true;
		}
		else {
			cout << " 잘못된 값이 입력되었습니다";
			return 0;
		}
	}
	cout << "종료됨";
	return 0;
}
bool isFull(stack<int> s, int i) {
	if (s.size() == i) {
		return true;
	}
	return false;
}*/

// 20303 김경혁
// stack 실습3-3
// stack 사용함
#include <iostream>
#include <stack>
#include <conio.h>

using namespace std;

bool isFull(stack<char>, int);

int main() {
	stack<char> c_s;
	const int sSize = 10000;

	int num = 0;
	int num1 = 0;
	int num2 = 0;
	string str = "";
	char ch;
	cout << "천단위를 구분할 수를 입력하시오 : ";
	while (true) {
		ch = _getch();
		if (ch >= '0' && ch <= '9') {
			if (!isFull(c_s, sSize)) {
				c_s.push(ch);
				cout << c_s.top();
			}
		}
		else {
			ch = ' ';
			break;
		}
	}
	cout << endl;
	int r = c_s.size();
	char arrC1[sSize] = { ' ', };
	char arrC2[sSize] = {' ',};
	for (int i = r-1; i >= 0; i--) {
		if (!c_s.empty()) {
			arrC1[i] = c_s.top();
			c_s.pop();
		}
		else {
			cout << "dd";
			break;
		}
	}
	if (r > 3) {
		num1 = r % 3;
	}
	for (int i=0; i < num1; i++) {
		str = str + arrC1[i];
	}
	if(num1>0)
		str = str + ',';
	for (int i = 0; i < r-num1; i++) {
		if ((i) % 3 == 0 && i != 0)
			str = str + ',';
		str = str + arrC1[i+num1];
	}
	cout << str;
}
bool isFull(stack<char> s, int i) {
	if (s.size() == i) {
		return true;
	}
	return false;
}