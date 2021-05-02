// 20303 김경혁
// stack 실습3-2
#include <iostream>
#include <stack> 

using namespace std;

bool isFull(stack<long>, int);

long oper(long, long, char);

int main() {
	stack<long> num_s;
	stack<long> i_s;
	stack<char> c_s;
	int sSize = 10;
	int cSize = 10;

	bool b = false;
	string s = "";
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(') {
			b = true;
			c_s.push(s[i]);
		}
		else if (s[i] == ')') {
			if (b) {
				while (c_s.top() != '(') {
					
				}
			}
			else {
				return 0;
			}
		}
		else if (s[i] >= '0' && s[i] <= '9') {
			if (i == (s.length()-1)) {
				i_s.push(s[i] - '0');
				int r = i_s.size();
				int num1 = 0;

				for (int j = 0; j < r; j++) {
					if (!i_s.empty()) {
						int sqare = 1;
						for (int k = 0; k < j; k++) {
							sqare *= 10;
						}
						num1 += i_s.top() * sqare;
						i_s.pop();
					}
					else {
						cout << "stack이 비어있습니다";
						return 0;
					}
				}
				num_s.push(num1);
			}
			if (!isFull(i_s, sSize)) {
				i_s.push(s[i] - '0');
			}
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			c_s.push(s[i]);

			int r = i_s.size();
			int num1 = 0;

			for (int j = 0; j < r; j++) {
				if (!i_s.empty()) {
					int sqare = 1;
					for (int k = 0; k < j; k++) {
						sqare *= 10;
					}
					num1 += i_s.top() * sqare;
					i_s.pop();
				}
				else {
					cout << "stack이 비어있습니다";
					return 0;
				}
			}
			num_s.push(num1);
		}
		else {
			cout << "알맞지 않은 값이 입력 되었습니다.";
			return 0;
		};
	}
	int size = num_s.size();
	for (int i = 0; i < size; i++)
	{
		if (!num_s.empty()) {
			cout << num_s.top()<<endl;
			num_s.pop();
		}
	}
	return 0;
}
bool isFull(stack<long> s, int i) {
	if (s.size() == i) {
		return true;
	}
	return false;
}

long oper(long num1, long num2, char oper) {
	if (oper == '*') {
		return num1* num2;
	}
	else if (oper == '/') {
		return num1 / num2;
	}
	else if (oper == '+') {
		return num1 + num2;
	}
	else if (oper == '-') {
		return num1 - num2;
	}
}