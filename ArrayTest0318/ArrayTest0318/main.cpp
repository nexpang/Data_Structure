#include <iostream>
using namespace std;

int main() {
	char identity[14];
	cout << "�ֹε�Ϲ�ȣ 13�ڸ��� �Է��Ͻÿ� : ";
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
		cout << "��ȿ�� Ȯ�� �Ϸ�\n----------------------\n";
	}
	else {
		cout << "��ȿ�� ����";
		return 0;
	}

	cout << "���� :\t\t";
	if (check[6] % 2 == 1 && check[6]< 5) {
		cout << "����"<<endl;
	}
	else {
		cout << "����" << endl;
	}

	cout << "���� : \t\t";
	int birth = 0;
	if (check[0] > 2) {
		birth = 1900 + (check[0]) * 10 + (check[1]);
	}
	else {
		birth = 2000 + (check [0]) * 10 + (check[1]);
	}
	cout << 2021 - birth + 1 << endl;
	
	cout << "��� ���� :\t" << birth << endl;

	cout << "��� ���� :\t";
	int local = (check[7] - 48) * 10 + (check[8]);
	if (local < 9)
		cout << "����\n";
	else if (local < 13)
		cout << "�λ�\n";
	else if (local < 16)
		cout << "��õ\n";
	else if (local < 19)
		cout << "��⵵ �ֿ� ����\n";
	else if (local < 26)
		cout << "�� ���� ��⵵\n";
	else if (local < 35)
		cout << "������\n";
	else if (local < 40)
		cout << "��û�ϵ�\n";
	else if (local < 48)
		cout << "��û����\n";
	else if (local < 55)
		cout << "����ϵ�\n";
	else if (local < 67)
		cout << "���󳲵�\n";
	else if (local < 90)
		cout << "���\n";

	return 0;
}