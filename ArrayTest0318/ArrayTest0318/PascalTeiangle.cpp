// 20303 �����
#include <iostream>

using namespace std;

int main() {
	int array[10][10] = { 0, };
	int i, j;
	for (i = 0; i < 10; i++) {
		array[i][0] = 1;
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (j > 0 && i > 0) {
				array[i][j] = array[i - 1][j] + array[i - 1][j - 1];
			}
			if (array[i][j] > 0) {
				cout << array[i][j] << " ";
			}
		}
		cout << endl;
	}

	cout << "-----------------------------------------------" << endl;

	char sArray[3][10] = { "", };
	for (i = 0; i < 3; i++) {
		cout << "*���� ���ڿ� �ִ� 9�ڸ��� �Է��Ͻÿ� : ";
		cin >> sArray[i];
	}
	cout << endl;
	for (i = 0; i < 3; i++) {
		cout << i + 1 << "��° ���ڿ� reverse : ";
		for (j = sizeof(sArray[i])-1 / sizeof(char); j >= 0; j--) {
			cout << sArray[i][j];
		}
		cout <<endl;
	}

	return 0;
}