//20303 ±Ë∞Ê«ı
#include <iostream>

using namespace std;

typedef struct
{
	char stackArr[10];
	int topIndex;
	char name;
}stack;

typedef stack* pstack;

void init(pstack ps, char c);

void init(pstack ps, char ch);

char pop(pstack ps);

int main() {
	stack s1;
	init(&s1, 'A');

	return 0;
}

void init(pstack ps, char c) 
{
	ps->topIndex = 0;
	ps->name = c;
	cout << "Constructing stack " << ps->name << '\n';
}

void push(pstack ps, char ch)
{
	if (ps->topIndex == 10)
	{
		cout << "Stack" << ps->name << "is full\n";
		return;
	}

	ps->stackArr[ps->topIndex] = ch;
	ps->topIndex++;
}

char pop(pstack ps)
{
	if(ps->topIndex == 0)
	{
		cout << "Stack " << ps->name << "is empty\n";
		return 0;
	}
	ps->topIndex--;

	return ps->stackArr[ps->topIndex];
}