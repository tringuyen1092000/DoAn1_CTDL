#include "Menu.h"

Vector& Vector::operator+(const Vector& other)
{
	Vector* s = new Vector(1);
	if (_n == other._n)
	{
		delete[] s->_vt;
		s->_n = _n;
		s->_vt = new double[_n];
		for (int i = 0; i < _n; i++)
			s->_vt[i] = _vt[i] + other._vt[i];
	}
	else cout << "Khong the cong 2 vecto vi so luong thanh phan khong bang nhau";
	return *s;
	delete s;
}

Vector& Vector::operator*(double a)
{
	Vector *p = new Vector(*this);
	for (int i = 0; i < p->_n; i++)
		p->_vt[i] *= a;
	return *p;
	delete p;
}

Vector::Vector ()
{
	_n = 3;
	_vt = new double[_n];
	_vt[0] = 0;
	_vt[1] = 0;
	_vt[2] = 0;
}

Vector::Vector (int n)
{
	_n = n;
	_vt = new double[_n];
	for(int i = 0; i < _n; i++)
		_vt[i] = 0;
}

Vector::Vector (const Vector& other)
{
	_n = other._n;
	_vt = new double[_n];
	for (int i = 0; i < _n; i++)
		_vt[i] = other._vt[i];
}

Vector::Vector(double x, double y, double z)
{
	_n = 3;
	_vt = new double[_n];
	_vt[0] = x;
	_vt[1] = y;
	_vt[2] = z;
}

istream& operator>>(istream& in, Vector& a)
{
	if (a._n == 0) delete[] a._vt;
_ninput:
	gotoxy(10, 6);
	cout << "Nhap so luong thanh phan cua vecto: ";
	in >> a._n;
	if (a._n > 0){}
	else
	{
		gotoxy(10, 7);
		cout << "So luong thanh phan phai > 0!";
		gotoxy(36, 6);
		for (int i = 0; i < 10; i++)
			cout << " ";
		goto _ninput;
	}
	gotoxy(10, 8);
	cout << "Nhap cac thanh phan: ";
	gotoxy(9, 9);
	cout << "(";
	gotoxy(31, 8);
	for (int i = 0; i < a._n - 1; i++)
	{
			in >> a._vt[i];
			gotoxy(10 + 5 * i, 9);
			cout << a._vt[i] << ", ";
			gotoxy(31, 8);
			for (int i = 31; i < 100; i++)
				cout << " ";
			gotoxy(31, 8);
	}
	in >> a._vt[a._n - 1];
	gotoxy(10 + 5 * (a._n - 1), 9);
	cout << a._vt[a._n - 1] << ")";
	return in;
}

ostream& operator<<(ostream& out, Vector& a)
{
	out << "(";
	for (int i = 0; i < a._n - 1; i++)
		out << a._vt[i] << ", ";
	out << a._vt[a._n - 1] << ")";
	return out;
}

Vector& Vector::operator=(const	Vector& other)
{
	if (_n != other._n)
	{
		delete[] _vt;
		_n = other._n;
		_vt = new double[_n];
	}
	for (int i = 0; i < _n; i++)
		_vt[i] = other._vt[i];
	return *this;
}

void Vector::Out(int x, int y)
{
	gotoxy(x - 1, y);
	if (_n > 0)
	{
		cout << "(";
		for (int i = 0; i < _n - 1; i++)
		{
			cout.precision(5);
			gotoxy(x + 5 * i, y);
			cout << _vt[i] << ", ";
		}
		gotoxy(x + 5 * (_n - 1), y);
		cout << _vt[_n - 1] << ")";
	}
}