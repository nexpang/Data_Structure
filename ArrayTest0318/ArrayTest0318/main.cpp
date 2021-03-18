#include <iostream>
using namespace std;

int main() {
	char identity[14];
	cout << "주민등록번호 13자리를 입력하시오 : ";
	cin >> identity;

	int check[13] = { 0, };
	int total = 0;

	for (int i = 0; i < 13; i++) {
		check[i] = (int)identity[i] - 48;
		if (i < 8) {
			total += (check[i] * (i + 2));
		}
		else if (i < 12) {
			total += (check[i] * (i - 6));
		}
	}
	if (check[12] == (11 - (total % 11) % 10)) {
		cout << "유효성 확인 완료\n----------------------\n";
	}
	else {
		cout << "유효성 에러";
		return 0;
	}

	cout << "성별 :\t\t";
	if (check[6] % 2 == 1 && check[6]< 5) {
		cout << "남자"<<endl;
	}
	else {
		cout << "여자" << endl;
	}

	cout << "나이 : \t\t";
	int birth = 0;
	if (check[0] > 2) {
		birth = 1900 + (check[0]) * 10 + (check[1]);
	}
	else {
		birth = 2000 + (check [0]) * 10 + (check[1]);
	}
	cout << 2021 - birth + 1 << endl;
	
	cout << "출생 연도 :\t" << birth << endl;

	cout << "출생 지역 :\t";
	int local = (check[7] - 48) * 10 + (check[8]);
	if (local < 9)
		cout << "서울\n";
	else if (local < 13)
		cout << "부산\n";
	else if (local < 16)
		cout << "인천\n";
	else if (local < 19)
		cout << "경기도 주요 도시\n";
	else if (local < 26)
		cout << "그 밖의 경기도\n";
	else if (local < 35)
		cout << "강원도\n";
	else if (local < 40)
		cout << "충청북도\n";
	else if (local < 48)
		cout << "충청남도\n";
	else if (local < 55)
		cout << "전라북도\n";
	else if (local < 67)
		cout << "전라남도\n";
	else if (local < 90)
		cout << "경상도\n";

	return 0;
}