#include <iostream>
//#include <string>
//#include <algorithm>
//#include <cmath>
//#include <queue>
//#include <vector>

using namespace std;

// 문제 규칙에 맞도록 pre-order순서로 출력
void pre(int level, int cur, int n)
{
	if (level == 1) {
		printf("%d ", cur);
		return;
	}
	int start = (1 << n) - (1 << (n - level + 1));//처음:2
	int lmax = (1 << (n - level));//처음:0
	// root
	printf("%d ", lmax - cur + 1 + start);
	// left
	pre(level - 1, cur, n);
	// right
	pre(level - 1, cur + (1 << (n - level)), n);
}

int main()
{
	int n;
	scanf_s("%d", &n);
	pre(n, 1, n);
}