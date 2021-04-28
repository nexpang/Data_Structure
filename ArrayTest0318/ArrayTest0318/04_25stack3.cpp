// 20303 �����
// stack �ǽ�3-1
/*
#include <iostream>
#include <stack>

using namespace std;

bool isFull(stack<int>, int);

int main() {
	stack<int> c_s;
	int sSize = 1000;

	int input;
	cout << "�����͸� ���� ���� �Է��Ͻÿ� : ";
	cin >> input;
	if (input <= 0) {
		cout << "�������� ���� 0���� �Դϴ�.";
		return 0;
	}

	for (int i = 0; i < input; i++) {
		if (!isFull(c_s, sSize)) {
			c_s.push(1 + i);
		}
		else {
			cout << "stack�� ��á���ϴ�";
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
// 20303 �����
// stack �ǽ�3-2
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
	int state = 0; // 1 = ���� �Է�, 2 = ���
	int oper = 4; // 0 == +	1 == -	2 == *	3 == /
	double num1 =0, num2 =0;
	bool isFirst = true;
	cout << "����ϴ� ���� 10000000000�ڸ� ���� �Է� �����ϴ�.\n\t\t\t\t\tq : ����" << endl;
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
					cout << "stack�� ����ֽ��ϴ�";
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
					cout << "stack�� ����ֽ��ϴ�";
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
			cout << " �߸��� ���� �ԷµǾ����ϴ�";
			return 0;
		}
	}
	cout << "�����";
	return 0;
}
bool isFull(stack<int> s, int i) {
	if (s.size() == i) {
		return true;
	}
	return false;
}*/

// 20303 �����
// stack �ǽ�3-3
// stack �����
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
	cout << "õ������ ������ ���� �Է��Ͻÿ� : ";
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