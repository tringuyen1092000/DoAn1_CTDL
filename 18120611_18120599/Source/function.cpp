#pragma once
#include"Menu.h"

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

Boole::Boole()
{
	this->data = 1;
	type = "";
}
tutoitiu::tutoitiu()
{
	A[0].exist = 0;
	A[1].exist = 0;
	A[2].exist = 0;
	A[3].exist = 0;
	A[0].type = "";
	A[1].type = "";
	A[2].type = "";
	A[3].type = "";
}
int** CreateKar()
{
	int **Kar = new int*[4];
	for (int i = 0; i < 4; i++)
	{
		Kar[i] = new int[4];
		for (int j = 0; j < 4; j++)
		{
			Kar[i][j] = 0;
		}
	}
	return Kar;

}

string recal2(tutoitiu Ec)
{
	string result = "";
	if (Ec.A[0].exist == 1)
	{
		if (Ec.A[0].BU == 1) result += "X";
		else result += "x";
	}
	if (Ec.A[1].exist == 1)
	{
		if (Ec.A[1].BU == 1) result += "Y";
		else result += "y";
	}
	if (Ec.A[2].exist == 1)
	{
		if (Ec.A[2].BU == 1) result += "Z";
		else result += "z";
	}
	if (Ec.A[3].exist == 1)
	{
		if (Ec.A[3].BU == 1) result += "T";
		else result += "t";
	}
	return result;
}
// dung


string intToString(int a)
{
	char intStr[10000];
	itoa(a, intStr, 10);
	string str = string(intStr);
	return str;
}
void setHJHJ(HJHJ &ec)
{
	ec.A = new int[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> ec.A[i];
	}
}

int checkdif1(int *A, int *B)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if ((A[i] != B[i])) count++;
	}
	if (count == 1) return 1;
	if (count>1) return 0;

}
int* fixtungcai(int *A, int *B)
{
	int *result = new int[4];

	for (int i = 0; i < 4; i++)
	{
		if (A[i] != B[i]) result[i] = 2;
		else
			result[i] = A[i];
	}
	return result;

}
int checkXuatHien(HJHJ A, HJHJ*B, int n)//n la so phan tu cua B
{
	int check;
	for (int i = 0; i < A.oxuathien.length(); i++)
	{
		check = 0;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < B[j].oxuathien.length(); k++)
			{
				if (A.oxuathien[i] == B[j].oxuathien[k]) check = 1; // co
			}
		}
		if (check == 0)return 0;// 0 xuat hien trong day B
	}
	return 1;
}
int checkXuatHien2(HJHJ A, HJHJ*B, int n, int a)//n la so phan tu cua B
{
	int check;
	for (int i = 0; i < A.oxuathien.length(); i++)
	{
		check = 0;
		for (int j = 0; j < n; j++)
		{
			if (j == a)
			{

			}
			else
			for (int k = 0; k < B[j].oxuathien.length(); k++)
			{
				if (A.oxuathien[i] == B[j].oxuathien[k]) check = 1; // co
			}
		}
		if (check == 0)return 0;// 0 xuat hien trong day B
	}
	return 1;
}
HJHJ* FirstFix(HJHJ* KEC, int &n)// n la so ptu
{
	HJHJ* newKEC = new HJHJ[1000];
	int count = 0;
	bool check = false;
	bool done = false;
	// ktra tung cap
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (checkdif1(KEC[i].A, KEC[j].A) == 1)
			{
				newKEC[count].A = fixtungcai(KEC[i].A, KEC[j].A);
				newKEC[count].oxuathien = KEC[i].oxuathien + KEC[j].oxuathien;
				count++;
				check = true;
			}
		}
		if (check == false)
		{
			KEC[i].flag = 0;// ko xuat hien thi them flag de xuong duoi ktra lai
		}
		check = false;
	}
	// check xuat hien from line 69
	for (int i = 0; i < n; i++)// check ko co ->add
	{
		if (KEC[i].flag == 0)
		{
			if (checkXuatHien(KEC[i], newKEC, count) == 0)
			{
				newKEC[count] = KEC[i];
				count++;
			}
		}
	}
	n = count;
	return newKEC;
}
tutoitiu* Add(int** Kar, int &n)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	{
		if (Kar[i][j] == 1) count++;
	}
	tutoitiu* result = new tutoitiu[count];
	count = 0;
	int B[4][2] = { { 0, 1 }, { 0, 0 }, { 1, 0 }, { 1, 1 } };
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	{
		if (Kar[i][j] == 1)
		{
			result[count].A[0].exist = 1;
			result[count].A[0].BU = B[j][0];

			result[count].A[1].exist = 1;
			result[count].A[1].BU = B[j][1];

			result[count].A[2].exist = 1;
			result[count].A[2].BU = B[i][0];
			result[count].A[3].exist = 1;
			result[count].A[3].BU = B[i][1];
			count++;
		}
	}
	n = count;
	return result;
}
tutoitiu* Add2(int** Kar, int &n)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	{
		if (Kar[i][j] == 1) count++;
	}
	tutoitiu* result = new tutoitiu[count];
	count = 0;
	int B[4][2] = { { 0, 1 }, { 0, 0 }, { 1, 0 }, { 1, 1 } };
	for (int i = 3; i>=0; i--)
	for (int j = 3; j >=0 ; j--)
	{
		if (Kar[i][j] == 1)
		{
			result[count].A[0].exist = 1;
			result[count].A[0].BU = B[j][0];

			result[count].A[1].exist = 1;
			result[count].A[1].BU = B[j][1];

			result[count].A[2].exist = 1;
			result[count].A[2].BU = B[i][0];
			result[count].A[3].exist = 1;
			result[count].A[3].BU = B[i][1];
			count++;
		}
	}
	n = count;
	return result;
}
int* AddTTTtoString(tutoitiu B)// add tung tu toi tieu -> mang 4
{
	int* result = new int[4];
	for (int i = 0; i < 4; i++)
	{
		result[i] = abs(B.A[i].BU - 1);
	}
	return result;
}

// tinh toan khi dua string -> kar


int cal(tutoitiu ec, int i1, int i2, int i3, int i4)
{
	Boole K;
	if (ec.A[0].exist == 1)
	{
		ec.A[0].data = i1;
		if (ec.A[0].BU == 1)
		{
			ec.A[0].bu();
			K.giao(ec.A[0]);
		}
		else
			K.giao(ec.A[0]);
	}
	if (ec.A[1].exist == 1)
	{
		ec.A[1].data = i2;
		if (ec.A[1].BU == 1)
		{
			ec.A[1].bu();
			K.giao(ec.A[1]);
		}
		else
			K.giao(ec.A[1]);
	}
	if (ec.A[2].exist == 1)
	{
		ec.A[2].data = i3;
		if (ec.A[2].BU == 1)
		{
			ec.A[2].bu();
			K.giao(ec.A[2]);
		}
		else
			K.giao(ec.A[2]);
	}
	if (ec.A[3].exist == 1)
	{
		ec.A[3].data = i4;
		if (ec.A[3].BU == 1)
		{
			ec.A[3].bu();
			K.giao(ec.A[3]);
		}
		else
			K.giao(ec.A[3]);
	}
	return K.data;
}
int** doc(string a)
{
	int sotu = 1;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == 'v') sotu++;
	}
	int **Kar = CreateKar();
	tutoitiu* ec = new tutoitiu[sotu];
	int j = 0;
	int added = 0;
	while (j < a.length())
	{
		if (a[j] == 'v') added++;
		else
		if (a[j] == 'X')
		{
			ec[added].A[0].exist = 1;
			ec[added].A[0].BU = 1;
		}
		else
		if (a[j] == 'Y')
		{
			ec[added].A[1].exist = 1;
			ec[added].A[1].BU = 1;
		}
		else
		if (a[j] == 'Z')
		{
			ec[added].A[2].exist = 1;
			ec[added].A[2].BU = 1;
		}
		else
		if (a[j] == 'T')
		{
			ec[added].A[3].exist = 1;
			ec[added].A[3].BU = 1;
		}
		if (a[j] == 'x')
		{
			ec[added].A[0].exist = 1;
		}
		else
		if (a[j] == 'y')
		{
			ec[added].A[1].exist = 1;
		}
		else
		if (a[j] == 'z')
		{
			ec[added].A[2].exist = 1;
		}
		else
		if (a[j] == 't')
		{
			ec[added].A[3].exist = 1;
		}
		j++;
	}
	int var;
	Boole K;
	int i1, i2, i3, i4;
	for (int p = 0; p < sotu; p++)
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	{
		if (i < 2)
		{
			i1 = 1;
			i2 = i;
		}
		else
		{
			i1 = 0;
			i2 = 1 - i % 2;
		}
		if (j < 2) {
			i3 = 1;
			i4 = j;
		}
		else
		{
			i3 = 0;
			i4 = 1 - j % 2;
		}
		if (Kar[i][j] == 0) Kar[i][j] = cal(ec[p], i3, i4, i1, i2);
	}
	return Kar;
}

void printarr(int *A)
{
	for (int i = 0; i < 4; i++)
	{
		cout << " " << A[i];
	}
}
void printHJHJ(HJHJ *k, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		printarr(k[i].A);
		cout << " " << k[i].oxuathien;
	}
}
int check(int *A, int *B)
{
	for (int i = 0; i < 4; i++)
	{
		if (A[i] != B[i]) return 0;
	}
	return 1;
}
HJHJ* clean(HJHJ* test, int &n)
{
	int count = 0;
	int flag;
	HJHJ* result = new HJHJ[1000];
	result[0] = test[0];
	for (int i = 0; i < n; i++)
	{
		flag = 0;
		for (int j = 0; j <= count; j++)
		if (check(test[i].A, result[j].A) == 1)
		{
			flag = 1;
		}
		if (flag == 0)
		{
			count++;
			result[count] = test[i];
		}
	}
	HJHJ* finalresult = new HJHJ[count + 1];
	for (int i = 0; i <= count; i++)
	{
		finalresult[i] = result[i];
	}
	n = count + 1;
	return finalresult;

}
void delete1(HJHJ* test, int &n, int i) // xoa tai vi tri i
{
	n--;
	for (int k = i; k < n; k++)
	{
		test[k] = test[k + 1];
	}
}
void clean2(HJHJ* test, int &n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (checkXuatHien2(test[i], test, n, i) == 1)
		{
			delete1(test, n, i);
			i++;
		}
	}
}


void config(HJHJ* test, tutoitiu* result, int i, int j)
{
	if (test[i].A[j] == 2) result[i].A[j].exist = 0;
	if (test[i].A[j] == 1)
	{
		result[i].A[j].exist = 1;
		result[i].A[j].BU = 0;
	}
	if (test[i].A[j] == 0)
	{
		result[i].A[j].exist = 1;
		result[i].A[j].BU = 1;
	}
}
tutoitiu* Addfrom01(HJHJ *test, int n)
{
	tutoitiu* result = new tutoitiu[n];
	for (int i = 0; i < n; i++)
	{
		config(test, result, i, 0);
		config(test, result, i, 1);
		config(test, result, i, 2);
		config(test, result, i, 3);
	}
	return result;
}
void boolsolver()
{
	int n = 0;// n la so ptu
	int m = 0;
	string A = "";//YztvYZTvyZTvxyztvXzT
	Khung();
	TextColor(rand() % 15);
	gotoxy(5, 5);
	cout << "NHAP VAO HAM BOOL" ;
	gotoxy(5, 6);
	cout << "cac bien x,y,z,t :";
	gotoxy(5, 7);
	cout << "hop: 'v'";
	gotoxy(5, 8);
	cout << "phu dinh: viet hoa ky tu";
	gotoxy(5, 10);
	getline(cin, A);
	int** Karnaugh = doc(A);
	tutoitiu* HJ = Add(Karnaugh, n);
	HJHJ* test = new HJHJ[n];	
	for (int i = 0; i < n; i++)
	{
		test[i].A = AddTTTtoString(HJ[i]);
		test[i].oxuathien = intToString(i);
	}
	tutoitiu* HJ2 = Add2(Karnaugh, m);
	HJHJ* test2 = new HJHJ[m];
	for (int i = 0; i < m; i++)
	{
		test2[i].A = AddTTTtoString(HJ2[i]);
		test2[i].oxuathien = intToString(i);
	}
	test = FirstFix(test, n);
	test = FirstFix(test, n);
	test = FirstFix(test, n);
	test = FirstFix(test, n);
	test = clean(test, n);
	clean2(test, n);


	test2 = FirstFix(test2, m);
	test2 = FirstFix(test2, m);
	test2 = FirstFix(test2, m);
	test2 = FirstFix(test2, m);
	test2 = clean(test2, m);
	clean2(test2, m);

	if (n > m)
	{
		test = test2;
		n = m;
	}
	// fix -> chạy ngược -> compare
	string B;
	tutoitiu* result = Addfrom01(test, n);
	B = recal2(result[0]);
	for (int i = 1; i < n; i++)
	{
		B = B + " v " + recal2(result[i]);
	}
	gotoxy(5, 15);
	
	cout <<"ket qua : "<< B<<"  ";
	getch();
}



/*int main()
{
string A = "X";
int** Karnaugh = doc(A);
for (int i = 0; i < 4; i++)
{

for (int j = 0; j < 4; j++)
{
cout <<" "<< Karnaugh[i][j];
}
cout<<endl;
}
int n = 0;
tutoitiu* HJ= Add(Karnaugh,n);
for (int i = 0; i < n; i++)
{

string B = recal2(HJ[i]);
cout <<" " <<B;
}
system("pause");
}*/


// MENU
