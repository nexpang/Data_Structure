#include <iostream>

using namespace std;

int maxNum(int arr[], int l);
int arrSum(int num, int total);
void gugudan(int num1, int num2);

int main()
{
	cout << "1. 숫자 5개 입력받아 최대값 출력" << endl;
	int iarr[5] = { 0, };
	for (int i = 0; i < 5; i++) {
		cin >> iarr[i];
	}

	cout << maxNum(iarr, sizeof(iarr) / sizeof(int)) << endl;
	cout << "\n2. 4자리 이상의 수를 입력받아 각 자리수의 합 출력" << endl;
	int n = 0;
	cin >> n;
	cout << arrSum(n, 0) << endl;

	cout << "\n3. 구구단 출력" << endl;
	gugudan(0, 0);
}

int maxNum(int arr[], int l)
{
	if (l == 1)
		return arr[0];
	else
		if (arr[l - 1] > maxNum(arr, l - 1))
			return arr[l - 1];
		else
			return maxNum(arr, l - 1);

		return 0;
}
int arrSum(int num, int total) {
	if (num > 0) {
		total += num % 10;
		arrSum(num/10, total);
	}
	else
	{
		return total;
	}
}
void gugudan(int num1, int num2)
{
	if (num1 == 0 && num2 == 0) 
	{
		return gugudan(num1 + 1, num2 + 1);
	}
	else if (num1 == 9 && num2 == 9) 
	{
		return;
	}
	else 
	{
		if (num2 == 9)
		{
			cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
			cout << endl;
			return gugudan(num1 + 1, 1);
		}
		else {
			cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
			return gugudan(num1, num2 + 1);
		}
	}
}