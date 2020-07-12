#include "Menu.h"

Matrix::Matrix()
{
	_m = 0;
	_n = 0;
	_matrix = new double* [1];
	_matrix[0] = new double[1];
	_matrix[0][0] = 0;
}

Matrix::Matrix(int m, int n, double** arr)
{
	_m = m;
	_n = n;
	_matrix = new double* [_m];

	for (int i = 0; i < _m; i++)
		_matrix[i] = new double[_n];

	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			_matrix[i][j] = arr[i][j];
}

Matrix::Matrix(int m, int n)
{
	if (m == 0 || n == 0)
	{
		if (m != 0) _m = m;
		else _m = 1;
		if (n != 0) _n = n;
		else _n = 1;
	}
	else
	{
		_m = m;
		_n = n;
	}
	_matrix = new double* [_m];
	for (int i = 0; i < _m; i++)
		_matrix[i] = new double[_n];

	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			_matrix[i][j] = 0;
}

Matrix::Matrix(const Matrix& other)
{
	_m = other._m;
	_n = other._n;
	_matrix = new double* [_m];

	for (int i = 0; i < _m; i++)
		_matrix[i] = new double[_n];

	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			_matrix[i][j] = other._matrix[i][j];
}

Matrix::~Matrix()
{
	for (int i = 0; i < _m; i++)
		delete[] _matrix[i];
	delete[] _matrix;
}

istream& operator>>(istream& in, Matrix& temp)
{
	if (temp._m == 0 && temp._n == 0)
	{
		for (int i = 0; i < temp._m; i++)
			delete[] temp._matrix[i];
		delete[] temp._matrix;
	minput:
		gotoxy(10, 6);
		cout << "Nhap vao so dong: ";
		in >> temp._m;
		if (temp._m > 0)
		{
		}
		else
		{
			gotoxy(10, 7);
			cout << "So dong phai > 0!\n";
			gotoxy(26, 6);
			for (int i = 0; i < 10; i++)
				cout << " ";
			goto minput;
		}
	ninput:
		gotoxy(10, 8);
		cout << "Nhap vao so cot: ";
		in >> temp._n;
		if (temp._n > 0)
		{
		}
		else
		{
			gotoxy(10, 9);
			cout << "So cot phai > 0!\n";
			gotoxy(25, 8);
			for (int i = 0; i < 5; i++)
				cout << " ";
			goto ninput;
		}
		temp._matrix = new double* [temp._m];
		for (int i = 0; i < temp._m; i++)
			temp._matrix[i] = new double[temp._n];
	}
	gotoxy(10, 10);
	cout << "Nhap cac phan tu: ";
	for (int i = 0; i < temp._m; i++)
	{
		for(int j = 0; j < temp._n; j++)
		{
			in >> temp._matrix[i][j];
			gotoxy(10 + 10 * j, 11 + 2 * i);
			cout << temp._matrix[i][j];
			gotoxy(28, 10);
			for (int i = 28; i < 100; i++)
			 cout << " ";
			gotoxy(28, 10);
		}
	}
	return in;
}

void Matrix::Out(int x, int y)
{
	for (int i = 0; i < _m; i++)
	{
		for (int j = 0; j < _n; j++)
		{
			gotoxy(x + 10 * j, y + 2 * i);
			cout.precision(5);
			cout << _matrix[i][j];
		}
	}
}

Matrix& Matrix::operator=(const	Matrix& other)
{
	if (_m != other._m || _n != other._n)
	{
		for (int i = 0; i < _m; i++)
			delete[] _matrix[i];
		delete[] _matrix;
		_m = other._m;
		_n = other._n;
		_matrix = new double* [_m];
		for (int i = 0; i < _m; i++)
			_matrix[i] = new double[_n];
	}
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			_matrix[i][j] = other._matrix[i][j];
	return *this;
}

Matrix& Matrix::operator*(const	Matrix& other)
{
	Matrix* tmp = new Matrix;
	if (_n == other._m)
	{
		Matrix* temp = new Matrix(_m, other._n);
		for (int k = 0; k < _n; k++)
		{
			for (int i = 0; i < _m; i++)
			{
				for (int j = 0; j < other._n; j++)
					temp->_matrix[i][j] += _matrix[i][k] * other._matrix[k][j];
			}
		}
		return *temp;
		delete temp;
	}
	else
	{
		cout << "Khong the nhan 2 ma tran, so cot cua ma tran thu 1 phai bang so dong cua ma tran thu 2\n";
		return *tmp;
	}
	delete tmp;
}

Matrix& Matrix::operator*(double k)
{
	Matrix* temp = new Matrix(*this);
	for (int i = 0; i < _m; i++)
		for (int j = 0; j < _n; j++)
			if (temp->_matrix[i][j] != 0) temp->_matrix[i][j] *= k;
	return *temp;
	delete temp;
}

bool Matrix::CheckSquare()
{
	if (_m == _n) return 1;
	return 0;
}

bool Matrix::CheckRow0(int i)
{
	for (int j = 0; j < _n; j++)
	{
		if(_matrix[i][j] != 0) return 0;
	}
	return 1;
}

bool Matrix::CheckCol0(int j)
{
	for (int i = 0; i < _m; i++)
		if(_matrix[i][j] != 0) return 0;
	return 1;
}

void Matrix::SetRow(int i, double k)
{
	//Nhan dong i voi gia tri k, _n la so cot
	for (int j = 0; j < _n; j++)
	{
		if (_matrix[i][j] == 0) j++;
		_matrix[i][j] *= k;
	}
}

void Matrix::SetCol(int j, double k)
{
	//Nhan cot j voi a, _m la so dong
	for (int i = 0; i < _m; i++)
	{
		if (_matrix[i][j] == 0) i++;
		_matrix[i][j] *= k;
	}
}

void Matrix::ChangeRow(int i, int k)
{
	//Doi dong i voi dong k, _n la so cot
	double temp;
	for (int j = 0; j < _n; j++)
	{
		temp = _matrix[i][j];
		_matrix[i][j] = _matrix[k][j];
		_matrix[k][j] = temp;
	}
}

void Matrix::ChangeCol(int j, int k)
{
	//Doi cot j voi cot k, _m la so dong
	double temp;
	for (int i = 0; i < _m; i++)
	{
		temp = _matrix[i][j];
		_matrix[i][j] = _matrix[i][k];
		_matrix[i][k] = temp;
	}
}

Matrix Matrix::CreateIdentity(int n)
{
	Matrix* temp = new Matrix(n, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j) temp->_matrix[i][j] = 1;
	return *temp;
}

double Matrix::Det()
{
	if (CheckSquare() == 1)
	{
		for (int i = 0; i < _n; i++)
			if (CheckRow0(i) == 1 || CheckCol0(i) == 1) return 0;
		//Kiem tra ma tran tam giac
		double S1 = 0, S2 = 0, det = 1;
		for (int i = 0; i < _n; i++)
		{
			for (int j = 0; j < _n; j++)
			{
				if (i > j) S1 += _matrix[i][j];
				if (i < j) S2 += _matrix[i][j];
				if (i == j) det *= _matrix[i][j];
			}
		}
		if (S1 == 0 || S2 == 0) return det;
		S1 = 0; S2 = 0; det = 0;

		//Kiem tra n <= 3
		if (_n <= 3)
		{
			switch (_n)
			{
			case 1: return _matrix[0][0];
			case 2: return _matrix[0][0] * _matrix[1][1] - _matrix[0][1] * _matrix[1][0];
			case 3:
			{
				S1 = _matrix[0][0] * _matrix[1][1] * _matrix[2][2] + _matrix[0][1] * _matrix[1][2] * _matrix[2][0] + _matrix[0][2] * _matrix[1][0] * _matrix[2][1];
				S2 = _matrix[0][2] * _matrix[1][1] * _matrix[2][0] + _matrix[0][0] * _matrix[1][2] * _matrix[2][1] + _matrix[0][1] * _matrix[1][0] * _matrix[2][2];
				return S1 - S2;
			}
			}
		}

		//Tinh dinh thuc bang thuat toan Bareiss

		//Copy ma tran vao ma tran tam thoi

		Matrix* a = new Matrix(*this);
		Matrix* b = new Matrix(*this);

		//Mang chua pivot
		double* p = new double[_n + 1];
		int count = 0;
		p[count] = 1;
		//
		while (count < _n - 1)
		{
			//Kiem tra co dong hoac cot nao bang 0 khong
			for (int i = 0; i < _n; i++)
				if (CheckRow0(i) == 1 || CheckCol0(i) == 1) return 0;

			//Kiem tra pivot != 0
			if (b->_matrix[count][count] == 0)
			{
				int tmp = count;
				while (b->_matrix[tmp][count] == 0 && tmp < _m - 1) tmp++;
				b->SetRow(count, -1);
				a->SetRow(count, -1);
				b->ChangeRow(count, tmp);
				a->ChangeRow(count, tmp);
			}
			else
			{
				p[count + 1] = b->_matrix[count][count];
				for (int i = 0; i < _n; i++)
				{
					for (int j = 0; j < _n; j++)
					{
						if (i != count) a->_matrix[i][j] = (b->_matrix[count][count] * b->_matrix[i][j] - b->_matrix[i][count] * b->_matrix[count][j]) / p[count];
					}
				}
				//copy lai vao b
				*b = *a;
				count++;
			}
		}
		det = p[_n];

		delete a;
		delete b;
		delete[] p;
		return det;
	}
	else
	{
		cout << "Ma tran khong vuong, khong the tinh dinh thuc";
		gotoxy(5, 6);
	}
}

Matrix& Matrix::Invert()
{
	Matrix* I = new Matrix;
	if (CheckSquare() == 0)
	{
		gotoxy(5, 6);
		cout << "Ma tran khong kha nghich, khong the tim ma tran nghich dao\n";
		return *I;
	}
	else
	{
		if (Det() != 0)
		{
			*I = CreateIdentity(_n);
			Matrix* temp = new Matrix(*I);
			//Copy ma tran vao ma tran tam thoi

			Matrix* a = new Matrix(*this);
			Matrix* b = new Matrix(*this);

			//Mang chua pivot
			double* p = new double[_n + 1];
			int count = 0;
			p[count] = 1;
			//
			while (count < _n)
			{
				//Kiem tra pivot != 0
				if (b->_matrix[count][count] == 0)
				{
					int tmp = count + 1;
					while (b->_matrix[tmp][count] == 0 && tmp < _m - 1) tmp++;
					b->ChangeRow(count, tmp);
					a->ChangeRow(count, tmp);
					temp->ChangeRow(count, tmp);
					I->ChangeRow(count, tmp);
				}
				else
				{
					p[count + 1] = b->_matrix[count][count];
					for (int i = 0; i < _n; i++)
					{
						for (int j = 0; j < _n; j++)
						{
							if (i != count)
							{
								a->_matrix[i][j] = (b->_matrix[count][count] * b->_matrix[i][j] - b->_matrix[i][count] * b->_matrix[count][j]) / p[count];
								temp->_matrix[i][j] = (b->_matrix[count][count] * I->_matrix[i][j] - b->_matrix[i][count] * I->_matrix[count][j]) / p[count];
							}
						}
					}
					//copy lai vao b va I
					*b = *a;
					*I = *temp;
					count++;
				}
			}
			delete a;
			delete b;
			delete temp;
			return *I * (1.0 / p[_n]);
			delete[] p;
		}
		else
		{
			gotoxy(5, 6);
			cout << "Ma tran khong kha nghich, khong the tim ma tran nghich dao\n";
			return *I;
		}
	}
	delete I;
}

int Matrix::Rank()//Tinh hang cua ma tran nhap vao
{
	//Vi tri phan tu pivot dau tien
	int col = 0, row = 0;
	//Mang chua cac gia tri pivot
	double* p;
	if (_m < _n) p = new double[_m + 1];
	else p = new double[_n + 1];
	p[row] = 1;
	//Lay gia tri cac phan tu cua ma tran nhap vao sang 1 ma tran moi
	//de khong phai thay doi gia tri cua ma tran ban dau sau khi bien doi de tinh hang
	Matrix* a = new Matrix(*this);
	Matrix* b = new Matrix(*this);
	//Chon cot chua phan tu lam pivot tiep theo
	//Kiem tra cot chua pivot phai co it nhat 1 phan tu khac 0
	//Su dung _m va _n vi so dong va cot cua ma tran b = voi ma tran dang xet
	while (b->CheckCol0(col) == 1) col++;
	while (col < _n - 1 && row < _m - 1)
	{
		if (b->_matrix[row][col] == 0)
		{
			int temp = row;
			while (b->_matrix[temp][col] == 0 && temp < _m - 1) temp++;
			b->ChangeRow(row, temp);
			a->ChangeRow(row, temp);
		}
		else
		{
			p[row + 1] = b->_matrix[row][col];

			for (int i = 0; i < _m; i++)
			{
				for (int j = 0; j < _n; j++)
				{
					if (i != row) a->_matrix[i][j] = (b->_matrix[row][col] * b->_matrix[i][j] - b->_matrix[i][col] * b->_matrix[row][j]) / p[row];
				}
			}

			//copy lai vao b
			*b = *a;
			row++;
			col++;
		}
	}

	for (int i = 0; i < _m; i++)
		if (a->CheckRow0(i) == 1) return i;
	return _m;

	delete a;
	delete b;
	delete[] p;
}

void Matrix::LinearSystem()
{
	Matrix* b = new Matrix(_m, 1);
	gotoxy(31, 5);
	cout << "GIAI HE PHUONG TRINH TUYEN TINH AX = B";
	gotoxy(5, 9);
	cout << "Nhap ma tran B (ma tran chi gom 1 cot chua ket qua cua he phuong trinh trong A)";
	cin >> *b;
	system("cls");
	Khung();
	gotoxy(31, 5);
	cout << "GIAI HE PHUONG TRINH TUYEN TINH AX = B";
	TextColor(rand() % 14 + 1);
	//Vi tri gia tri pivot dau tien
	int col = 0, row = 0;
	//Mang chua cac pivot
	double* p = new double[_m + 1];
	p[row] = 1;
	//Mang chua chu cai lam ten bien cua he phuong trinh
	char c[25];
	for (int i = 0; i < 25; i++)
		c[i] = i + 97;

	//Lay ma tran A
	Matrix* a = new Matrix(*this);
	//Ma tran ab = a|b
	Matrix* ab = new Matrix(a->_m, a->_n + 1);
	for (int i = 0; i < ab->_m; i++)
	{
		for (int j = 0; j < ab->_n - 1; j++)
		{
			ab->_matrix[i][j] = a->_matrix[i][j];
		}
		ab->_matrix[i][ab->_n - 1] = b->_matrix[i][0];
	}
	//ra la hang cua ma tran A, rab la hang cua ma tran A|B
	int ra = a->Rank(), rab = ab->Rank();

	if (ra < rab)//rank(a) < rank(a|b)
	{
		gotoxy(5, 9);
		cout << "He phuong trinh vo nghiem";
		return;
	}

	//Chon cot chua phan tu lam pivot tiep theo
	//Kiem tra cot chua pivot phai co it nhat 1 phan tu khac 0
	while (a->CheckCol0(col) == 1) col++;//Tra ve cot dau tien cua ma tran khac 0

	//Copy ma tran a va b vao 2 ma tran dem
	Matrix* tempa = new Matrix(*a);
	Matrix* tempb = new Matrix(*b);
	//Bien doi ma tran theo pivot va ma tran truoc do (thuat toan Bareiss, phuong phap montante)
	while (row < _m - 1 && col < _n - 1)
	{
		//Chon phan tu pivot khac 0
		int temp = row;
		if (tempa->_matrix[row][col] == 0)
		{
			//Neu phan tu pivot cua dong dang xet = 0 thi doi vi tri voi dong khac co phan tu tai vi tri tuong ung khac 0
			while (tempa->_matrix[temp][col] == 0 && temp < tempa->_m - 1) temp++;
			tempa->ChangeRow(row, temp);
			a->ChangeRow(row, temp);
			b->ChangeRow(row, temp);
			tempb->ChangeRow(row, temp);
		}
		else
		{
			//gan phan tu pivot moi
			p[row + 1] = a->_matrix[row][col];

			for (int i = 0; i < a->_m; i++)
			{
				if (i != row)//Neu dong dang xet khac voi dong chua phan tu pivot
				{
					//Bien doi theo thuat toan Bareiss
					for (int j = 0; j < _n; j++)
						//tempa[i][j] = (a[row][col] * a[i][j] - a[i][col] * a[row][j]) / pivot[row]
						tempa->_matrix[i][j] = (a->_matrix[row][col] * a->_matrix[i][j] - a->_matrix[i][col] * a->_matrix[row][j]) / p[row];
					//tempb[i][j] = (a[row][col] * b[i][0] - a[i][col] * b[row][0]) / pivot[row]
					tempb->_matrix[i][0] = (a->_matrix[row][col] * b->_matrix[i][0] - a->_matrix[i][col] * b->_matrix[row][0]) / p[row];
				}
			}

			//Thay doi lai gia tri phan tu cua ma tran a va b
			*a = *tempa;
			*b = *tempb;

			//Vi tri cua phan tu pivot tiep theo
			row++;
			col++;
		}
	}

	//Thay doi lai gia tri phan tu cua ma tran A|B sau khi da bien doi theo Bareiss
	for (int i = 0; i < ab->_m; i++)
	{
		for (int j = 0; j < ab->_n - 1; j++)
		{
			ab->_matrix[i][j] = a->_matrix[i][j];
		}
		ab->_matrix[i][ab->_n - 1] = b->_matrix[i][0];
	}

	//Xet truong hop

	if (ra == rab)//rank(a) = rank(a|b)
	{
		gotoxy(5, 9);
		if (ra == a->_n)//rank(a) = so luong bien cua he phuong trinh
		{
			cout << "He phuong trinh co nghiem duy nhat\n";
			for (int i = 0; i < ra; i++)
			{
				//Xuat nghiem
				gotoxy(5, 10 + i);
				cout << c[i] << " = " << ab->_matrix[i][ra - 1] / ab->_matrix[i][i] << endl;
			}
		}

		if (ra < a->_n)//rank(a) > so luong bien cua he phuong trinh
		{
			gotoxy(5, 9);
			cout << "He phuong trinh co vo so nghiem";
		}
	}

	ab->Out(5, 15);

	//Xoa bo nho da cap phat
	delete ab;
	delete a;
	delete b;
	delete[] p;
	delete tempa;
	delete tempb;
}