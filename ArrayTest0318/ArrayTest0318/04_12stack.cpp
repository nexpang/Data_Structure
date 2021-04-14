//20303 �����
// ���ýǽ� 1-1
#include <iostream>

using namespace std;

#define SIZE 10

typedef struct
{
	char stackArr[SIZE];
	int topIndex;
	//char name;
}stack;

typedef stack* pstack;

void init(pstack ps, char c);

void push(pstack ps, char ch);

char pop(pstack ps);

int main() {
	stack s1;
	init(&s1, 'A');
	cout << endl;
	push(&s1, 'd');
	return 0;
}

void init(pstack ps, char c) 
{
	ps->topIndex = 0;
	//ps->name = c;
	//cout << "Constructing stack " << ps->name << '\n';
}

void push(pstack ps, char ch)
{
	if (ps->topIndex == SIZE)
	{
		//cout << "Stack" << ps->name << "is full\n";
		cout << "Stack�� �� ���ֽ��ϴ�.";
		return;
	}

	ps->stackArr[ps->topIndex] = ch;
	ps->topIndex++;
}

char pop(pstack ps)
{
	if(ps->topIndex == 0)
	{
		//cout << "Stack " << ps->name << "is empty\n";
		cout << "Stack�� ����ֽ��ϴ�.";
		return 0;
	}
	ps->topIndex--;

	return ps->stackArr[ps->topIndex];
}