// 20303 ����� 
// stack �ǽ�1-3
#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> i_s;
	const int arrSize = 3;
	int c_arr[arrSize] = { 0, };
	cout << "3. �� ���� �Ųٷ� ����ϱ�\n���� 3���� �Է��ϼ���.\n";
	for (int i = 0; i < arrSize; i++) {
		cout << i+1 << "��° ������ �Է��Ͻÿ� : ";
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