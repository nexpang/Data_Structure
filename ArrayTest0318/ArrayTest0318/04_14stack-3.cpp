// 20303 김경혁 
// stack 실습1-3
#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> i_s;
	const int arrSize = 3;
	int c_arr[arrSize] = { 0, };
	cout << "3. 세 정수 거꾸로 출력하기\n정수 3개를 입력하세요.\n";
	for (int i = 0; i < arrSize; i++) {
		cout << i+1 << "번째 정수를 입력하시오 : ";
		cin >> c_arr[i];
	}
	cout << endl;
	//cin.getline(c_arr,arrSize);
	for (int i = 0; i < arrSize; i++) {
		i_s.push(c_arr[i]);
	}
	for (int i = 0; i < arrSize; i++) {
		if (!i_s.empty()) {
			cout << i+1 <<". "<<i_s.top()<<endl;
			i_s.pop();
		}
	}
	return 0;
}