///20303 �����
#include <iostream>

using namespace std;

void reverse(int n);
void print1(int n, int n2);
void print2(int n, int n2);

int main() {
	int n = 0;
	cout << "1. n�� �Է¹޾� n ~ 1 ���� ���� ���\n";
	cin >> n;
	if (n == 0) {
		cout << 0;
	}
	else {

		reverse(n);
	}
	cout << "\n2. ���� 2���� �Է¹޾� �� �� ������ Ȧ�� ����ϱ�\n";
	int n1=0, n2=0;
	cin >> n1 >> n2;
	if (n1 > n2) {
		n1--;
	}
	else {
		n2--;
	}
	print1(n1, n2);
	cout << "\n3. ���� 2���� �Է¹޾� �� �� ������ ¦�� ����ϱ�\n";
	cin >> n1 >> n2;
	if (n1 > n2) {
		n1--;
	}
	else {
		n2--;
	}
	print2(n1, n2);

	return 0;
}

void reverse(int n) {
	if (n > 0) {
		cout << n << " ";
		return reverse(n-1);
	}
	else {
		cout << endl;
	}
}
void print1(int n, int n2) {
	if (n > n2) {
		if (n > n2 && n%2 ==1) {
			cout << n << " ";
			return print1(n - 1, n2);
		}
		else {
			return print1(n - 1, n2);
		}
	}
	else if(n2 > n){
		if (n2 > n && n2 % 2 == 1) {
			cout << n2 << " ";
			return print1(n,n2 - 1);
		}
		else {
			return print1(n, n2 - 1);
		}
	} else {
		cout << endl;
	}
}

void print2(int n, int n2) {
	if (n > n2) {
		if (n > n2 && n % 2 == 0) {
			cout << n << " ";
			return print2(n - 1, n2);
		}
		else {

			return print2(n - 1, n2);
		}
	}
	else if (n2 > n) {
		if (n2 > n && n2 % 2 == 0) {
			cout << n2 << " ";
			return print2(n,n2 - 1);
		}
		else {

			return print2(n, n2 - 1);
		}
	}
	else {
		cout << endl;
	}
}
