#include "Menu.h"

void Khung()// khung 100 28
{
	TextColor(10);

	gotoxy(0, 0);
	for (int i = 0; i < 28; i++)
	{
		cout << (char)219;

		for (int j = 0; j < 100; j++)
		{
			if (i == 0 || i == 27)
			cout << (char)219;
			else cout << " ";
		}

		cout << (char)219;
		cout << endl;
	}

}

void Menu()
{
	system("cls");
	Khung();
	gotoxy(39, 5);
	cout << "CHUONG TRINH GIAI TOAN";
	TextColor(11);
	gotoxy(10, 10);
	cout << "CAC LUA CHON:";
	TextColor(12);
	gotoxy(15, 12);
	cout << "1. TIM DA THUC TOI TIEU CUA HAM BOOL";
	gotoxy(15, 14);
	cout << "2. PHEP TOAN TREN VECTOR";
	gotoxy(15, 16);
	cout << "3. PHEP TOAN TREN MA TRAN";
	gotoxy(10, 20);
	cout << "Nhan Enter de chon";
	gotoxy(10, 21);
	cout << "Nhan 'B' de thoat hoac quay lai";
	int x = 12;
	int y = 12;
	while (1)
	{
		TextColor(14);
		string op = "->";
		gotoxy(x, y);
		cout << op;
		char c = getch();
		if (c == 72)
		{	// len
			gotoxy(x, y);
			cout << "  ";
			if (y > 12) 
			{
				y -= 2;
				gotoxy(x, y);
			}
		}

		if (c == 80)
		{	// xuong
			gotoxy(x, y);
			cout << "  ";
			if (y < 16)
			{
				y += 2;
				gotoxy(x, y);
			}
		}
		if (c == 13) break;
		if (c == 'b' || c == 'B' || c == 27) return;// ket thuc
	}

	if (y == 12)
	{
		system("cls");
		boolsolver();
		Menu();
	}

	if (y == 14)
	{
		system("cls");
		vector();
		Menu();
	}

	if (y == 16)
	{
		system("cls");
		matran();
		Menu();
	}
}