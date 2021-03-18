# Data_Structure

03_18 주민등록번호 판별 프로그램

+ 주민등록번호 자리를 받아 판별 시 성별, 나이, 출생 연도, 출생 지역을 출력

### 
```
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
  ```
