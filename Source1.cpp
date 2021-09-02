#define _CRT_SECURE_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
void gotoxy(int, int);
void draw_ship(int,int);
void erase_ship(int, int);
int main() {
	char ch = ' ';
	int x = 38, y = 20;
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a'&&x>0) {
				erase_ship(x, y);
				draw_ship(--x, y);
			}
			if (ch == 'd'&&x<75)
			{
				erase_ship(x, y);
				draw_ship(++x, y); 
			}
			if (ch == 'w') {
				erase_ship(x, y );
				draw_ship(x, --y);
			}
			if (ch == 's') {
				erase_ship(x, y);
				draw_ship(x, ++y);
			}
			fflush(stdin);
		}
		Sleep(100);
	} while (ch != 'x');

	return 0;
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x,int y)
{
	gotoxy(x, y);
	printf("<-0->");
}
void erase_ship(int x, int y) {
	gotoxy(x, y);
	printf("     ");
}
