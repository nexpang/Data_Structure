#include <iostream>

using namespace std;

int Fibo(int n);
void Hanoi(int num, int from, char by, char to);
int Gauss(int num);
void reverse(int num);

int main()
{
	cout << "1.\n";
	for (int i = 1; i <= 15; i++)
		cout << Fibo(i) << endl;
	cout << endl;
	cout << "2.\n";
	Hanoi(3, 'A', 'B', 'C');
	cout << endl;
	cout << "3.\n";
	int a = 1234;
	cin >> a;
	cout << Gauss(a) << endl;

	cout << endl;
	cout << "4.\n";
	cin >> a;
	reverse(a);
	return 0;
}

int Fibo(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}
void Hanoi(int num, int from, char by, char to) {
	if (num == 1)
		cout << "원반 1을" << from << "에서" << to << "로 이동" << endl;
	else 
	{
		Hanoi(num - 1, from, to, by);

		cout << "원반 "<<num<<"을(를)" << from << "에서" << to << "로 이동" << endl;

		Hanoi(num - 1, by, from, to);
	}
}
int Gauss(int num) 
{
	if (num == 0)
		return 0;
	else
		return num + (Gauss(num - 1));
}
void reverse(int num) {
	if (num > 0) {
		cout << num % 10;
		reverse(num / 10);
	}
}
