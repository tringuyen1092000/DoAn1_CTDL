#include "Menu.h"
#include <ctime>
#include <stdio.h>

int matran()
{
	srand(time(0));
	Khung();
	gotoxy(10, 10);
	TextColor(11);
	cout << "CAC LUA CHON:";
	gotoxy(15, 12);
	TextColor(14);
	cout << "1. TIM DINH THUC CUA MA TRAN";
	gotoxy(15, 14);
	cout << "2. NGHICH DAO MA TRAN";
	gotoxy(15, 16);
	cout << "3. TICH 2 MA TRAN";
	gotoxy(15, 18);
	cout << "4. TIM HANG CUA MA TRAN";
	gotoxy(15, 20);
	cout << "5. HE PHUONG TRINH TUYEN TINH";

	int x = 12;
	int y = 12;
	gotoxy(x, y);
	TextColor(13);
	cout << "->";
	char c = 32;
	bool check = 1;
	while (1)
	{
		c = getch();

		if (c == 'b' || c == 'B' || c == 27) return 0;

		if (c == 72)
		{// len
			if ( y > 12)
			{
				gotoxy(x, y);
				cout << "  ";
				y -= 2;
				gotoxy(x, y);
				cout << "->";
			}
		}

		if (c == 80)
		{// xuong
			if (y < 20)
			{
				gotoxy(x, y);
				cout << "  ";
				y += 2;
				gotoxy(x, y);
				cout << "->";
			}
		}

		//enter
		if (c == 13) break;
	}

	system("cls");
	Khung();
	TextColor(rand() % 14 + 1);
	Matrix a;
	gotoxy(5, 5);
	TextColor(rand() % 14 + 1);
	cout << "Nhap ma tran A";
	cin >> a;
	getch();
	system("cls");
	Khung();
	TextColor(rand() % 14 + 1);

	if (y == 12)
	{
		gotoxy(5, 5);
		cout << "Det(A) = " << a.Det() << endl;

	}

	if (y == 14)
	{	
		gotoxy(5, 5);
		cout << "Ma tran nghich dao cua A:";
		a.Invert().Out(5, 7);
	}

	if (y == 16)
	{
		Matrix b;
		gotoxy(5, 5);
		cout << "Nhap ma tran B";
		cin >> b;
		system("cls");
		Khung();
		TextColor(rand() % 14 + 1);
		gotoxy(5, 5);
		cout << "Ma tran A * B: ";
		Matrix c = a * b;
		c.Out(5, 7);
	}

	if (y == 18)
	{
		gotoxy(5, 5);
		cout << "Rank(A) = " << a.Rank() << endl;
	}

	if (y == 20)
	{
		a.LinearSystem();
	}
	getch();
	return 0;
}

int vector()
{
	Khung();
	gotoxy(10, 10);
	TextColor(11);
	cout << "CAC LUA CHON:";
	gotoxy(15, 12);
	TextColor(13);
	cout << "1. PHEP TOAN CONG HAI VECTOR";
	gotoxy(15, 14);
	cout << "2. PHEP TOAN NHAN VECTOR VOI 1 SO ALPHA";
	int x = 12, y = 12;
	gotoxy(x, y);
	TextColor(11);
	cout << "->";
	char c = 32;
	bool check = 1;
	while (1)
	{
		c = getch();

		if (c == 'b' || c == 'B' || c == 27) return 0;

		if (c == 72)
		{// len
			if (y > 12)
			{
				gotoxy(x, y);
				cout << "  ";
				y -= 2;
				gotoxy(x, y);
				cout << "->";
			}
		}

		if (c == 80)
		{// xuong
			if (y < 14)
			{
				gotoxy(x, y);
				cout << "  ";
				y += 2;
				gotoxy(x, y);
				cout << "->";
			}
		}

		//enter
		if (c == 13) break;
	}
	system("cls");
	Khung();
	TextColor(rand() % 14 + 1);
	Vector a;
	gotoxy(5, 5);
	TextColor(rand() % 14 + 1);
	cout << "Nhap vector A";
	cin >> a;
	getch();
	system("cls");
	Khung();
	TextColor(rand() % 14 + 1);

	if (y == 12)
	{
		Vector b;
		gotoxy(5, 5);
		cout << "Nhap vector B";
		cin >> b;
		system("cls");
		Khung();
		TextColor(rand() % 14 + 1);
		gotoxy(5, 5);
		cout << "Vecto A + B: ";
		Vector c = a + b;
		c.Out(5, 7);
	}

	if (y == 14)
	{
		double alpha;
		gotoxy(5, 5);
		cout << "Nhap he so alpha: ";
		cin >> alpha;
		system("cls");
		Khung();
		TextColor(rand() % 14 + 1);
		gotoxy(5, 5);
		cout << "Vecto A moi: ";
		a = a*alpha;
		a.Out(5, 6);
	}

	getch();
	return 0;
}