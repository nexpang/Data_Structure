// 20303 김경혁
// stack 실습2-보너스포함
// 이준협 - 미로 랜덤을 어떻게 할지 도움을 줌
#include <iostream>
#include <stack>
#include <Windows.h>
#include <time.h>

using namespace std;

#define MAX_RAND 3
#define MAZESIZE_X 12
#define MAZESIZE_Y 22
#define EXIT_X 11
#define EXIT_Y 16

typedef struct Position {
	int x;
	int y;
	int d;
}Position;

typedef struct Mtable {
	int x;
	int y;
}Mtable;

int Maze [MAX_RAND][MAZESIZE_X][MAZESIZE_Y] = {
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},  //1
		{1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1},  //2
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},  //3
		{1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},  //4
		{1,0,0,1,0,1,0,1,0,0,1,1,1,1,1,0,0,1,1,1,0,1},  //5
		{1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},  //7
		{1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1},  //8
		{1,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1},  //9
		{1,1,1,0,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1},  //10
		{1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},  //11
		{1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,0,1,0,1},  //12
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}   //13
	},
	{
		{1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,0,1},
		{1,1,0,1,1,1,1,1},
		{1,0,0,0,0,0,1,1},
		{1,1,0,1,1,0,0,1},
		{1,1,1,1,1,1,1,1}
	},
	{
		{1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,0,0,0,0,0,0,0,1},
		{1,1,0,0,0,1,0,0,1,1,1,1},
		{1,1,0,1,1,1,1,1,0,0,0,1},
		{1,0,0,0,0,0,1,1,0,1,0,1},
		{1,1,0,1,1,0,0,0,1,1,0,1},
		{1,0,0,1,0,0,1,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1}
	}
};
int MAP[MAX_RAND][2] = {
	{11,16},
	{5, 6},
	{4, 1}
};

Mtable Move[4] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};

int Mark [MAX_RAND][MAZESIZE_X][MAZESIZE_Y];
int top;
Position Trace[(MAZESIZE_X - 2) * (MAZESIZE_Y - 2)];
void ShowMaze(Position, int);
void Push(Position);
void Pop(Position* P);

stack<Position> p_s;
int main() {
	srand(time(NULL));
	//int randMap = rand() % MAX_RAND;
	int randMap = 2;
	int isFound = FALSE;
	int i, dir;

	Position Now = { 1,1,0 };
	Position Next;

	Push(Now);
	while (!isFound && top>0) {
		Pop(&Now);
		dir = Now.d;

		while (dir < 4) {
			Next.x = Now.x + Move[dir].x;
			Next.y = Now.y + Move[dir].y;
			if (Next.x == MAP[randMap][0] && Next.y == MAP[randMap][1]) {
				Next.d = dir;
				Push(Next);
				isFound = TRUE;
				break;
			}
			else if (Maze[randMap][Next.x][Next.y] == 0 && Mark[randMap][Next.x][Next.y] == 0) {
				Now.d = ++dir;
				Push(Now);
				Now.x = Next.x;
				Now.y = Next.y;
				dir = 0;
				Mark [randMap][Next.x][Next.y] = 1;
			}
			else
				dir++;
			ShowMaze(Now , randMap);
		}
	}
	if (isFound == TRUE) {
		for (int i = 0; i < top; i++)
		{
			ShowMaze(Trace[i], randMap);
		}
	}
	else
		cout << "Not Found!" << endl;
	system("pause");
	return 0;
}

void ShowMaze(Position p ,int m) {
	int i, j;
	Sleep(50);
	system("cls");
	cout << "출구는 (" <<MAP[m][0]<<", "<<MAP[m][1]<<")"<< endl;
	cout << "현재 좌표는 " << p.x << " " << p.y << " " << p.d << endl;
	for (int i = 0; i < MAZESIZE_X; i++)
	{
		for (int j = 0; j < MAZESIZE_Y; j++)
		{
			if (Maze [m][i][j] == 1)
				cout << "#";
			else if (p.x == i && p.y == j)
				cout << "&";
			else 
				cout << " ";
		}
		cout << endl;
	}
}

void Push(Position p) {
	Trace[top].x = p.x;
	Trace[top].y = p.y;
	Trace[top].d = p.d;
	top++;
}

void Pop(Position* p) {
	top--;
	p->x = Trace[top].x;
	p->y = Trace[top].y;
	p->d = Trace[top].d;
}