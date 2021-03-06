// 20303 김경혁
#include<iostream>
using namespace std;

int Factorial(int num);
int Gauss(int num);
int main() {
	int a = 10;
	cout << "1. 팩토리얼 (재귀함수) :";
	cin >> a;
	cout << "1부터" << a << "까지의 곱은 " << Factorial(a) <<endl;

	a = 10;
	cout << "\n2.가우스계산법 : ";
	cin >> a;
	cout << "1부터" << a << "까지의 합은 " << ((1+a)*a)/2 << endl;

	cout << "\n3.재귀함수 사용 가우스 1~100 : ";
	a = 100;
	cout <<"1부터"<<a<<"까지의 합은 "<<Gauss(a)<<endl;

	a = 10;
	cout << "\n4. 팩토리얼 : ";
	cin >> a;
	for (int i = 2; i <= a; i++) {
		int total = 0;
		total *= i* (i - 1);
	}
	cout << "1부터" << a << "까지의 곱은 " << Factorial(a) << '\n' << endl;
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