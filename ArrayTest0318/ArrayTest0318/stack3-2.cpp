// 20303 김경혁
// stack 실습3-2
// 참고 : https://penglog.tistory.com/99
// 문제에 맞게 변환함
#include <iostream>
#include <stack>

using namespace std;

struct oper {
	int p;
	char o;
};

bool numFirst = false;
stack<long> i_sNum;
stack<int> i_stack;
stack<oper> o_stack;

void calc() {
	int num1, num2, r;
	num2 = i_sNum.top();
	i_sNum.pop();
	num1 = i_sNum.top();
	i_sNum.pop();
	char oper = o_stack.top().o;
	o_stack.pop();

	switch (oper)
	{
	case '*':
		r = num1 * num2;
		break;
	case '/':
		r = num1 / num2;
		break;
	case '+':
		r = num1 + num2;
		break;
	case '-':
		r = num1 - num2;
		break;
	default:
		r = 0;
		break;
	}
	i_sNum.push(r);
	cout << "operate : " << r << endl;
}

int main() {

	string s = "1+(123/123-1+1+2)/2-1"; // 빈칸이 없는 수식
	cout << "Calculation : " << s << endl;
	cout << endl;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(') {
			o_stack.push({ 0, s[i] });
		}
		else if (s[i] == ')') {
			while (o_stack.top().o != '(')
				calc();
			o_stack.pop();
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			//if (!numFirst) i_sNum.push(0);
			int p;
			switch (s[i])
			{
			case '*':
				p = 2;
				break;
			case '/':
				p = 2;
				break;
			case '+':
				p = 1;
				break;
			case '-':
				p = 1;
				break;
			}

			while (!o_stack.empty() && p <= o_stack.top().p)
				calc();

			o_stack.push({ p, s[i] });
		}
		else if (s[i] >= '0' && s[i] <= '9') {
			//if (!numFirst) numFirst = true;

			i_stack.push(s[i] - '0');
			if (i != s.length()-1) {
				if (s[i + 1] == '+' || s[i + 1] == '-' || s[i + 1] == '*' || s[i + 1] == '/' || s[i + 1] == ')') {
					int loop = i_stack.size();
					int num = 0;
					for (int i = 0; i < loop; i++) {
						int zegop = 1;
						for (int j = 0; j < i; j++)
						{
							zegop *= 10;
						}
						num += (i_stack.top() * zegop);
						if (!i_stack.empty())
							i_stack.pop();
					}
					i_sNum.push(num);
				}
			}
			else {
				int loop = i_stack.size();
				int num = 0;
				for (int i = 0; i < loop; i++) {
					int zegop = 1;
					for (int j = 0; j < i; j++)
					{
						zegop *= 10;
					}
					num += (i_stack.top() * zegop);
					if (!i_stack.empty())
						i_stack.pop();
				}
				i_sNum.push(num);
			}
		}
		else {
			cout << "잘못된 값이 입력되었습니다."; // 숫자가 아닐 때 에러 처리
			return 0;
		}
	}
	while (!o_stack.empty())
		calc();

	cout << "\nresult : " <<i_sNum.top();

	return 0;
}