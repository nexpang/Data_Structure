#include<iostream>
using namespace std;

int Factorial(int num);
int Gauss(int num);
int main() {
	int a = 10;
	cout << "1. ���丮�� (����Լ�) :";
	cin >> a;
	cout << "1����" << a << "������ ���� " << Factorial(a) <<endl;

	cout << "\n2.���콺 : ";
	cin >> a;
	cout << "1����" << a << "������ ���� " << ((1+a)*a)/2 << endl;

	cout << "\n3.����Լ� ��� ���콺 : ";
	cin >> a;
	cout <<"1����"<<a<<"������ ���� "<<Gauss(a)<<endl;

	cout << "\n4. ���丮�� : ";
	cin >> a;
	for (int i = 2; i <= a; i++) {
		int total = 0;
		total *= i* (i - 1);
	}
	cout << "1����" << a << "������ ���� " << Factorial(a) << '\n' << endl;
	return 0;
}

int Factorial(int num) {
	if (num == 0)
		return 1;
	else
		return(num * Factorial(num - 1));
}
int Gauss(int num) {
	if (num == 0)
		return 0;
	else
		return num + (Gauss(num-1));
}