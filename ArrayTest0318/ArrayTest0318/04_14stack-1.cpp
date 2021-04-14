// 20303 ±Ë∞Ê«ı
#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<char> c_s;
	c_s.push('a');
	if (!c_s.empty()) {
		cout << c_s.top();
		c_s.pop();
	}
	return 0;
}