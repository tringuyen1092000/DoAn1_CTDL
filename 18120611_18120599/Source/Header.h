#pragma once
#include <iostream>

using namespace std;

class Vector
{
private:
	int _n;//So luong thanh phan cua vector
	double* _vt;//Mang chua gia tri cac thanh phan
public:
	void SetN(int Value) { _n = Value; }//Thay doi so luong thanh phan vector
	int GetN() { return _n; }//Xuat ra so luong thanh phan vector
	double GetVi(int i) { return _vt[i]; }//Lay gia tri thanh phan thu i cua vector
	void SetVi(int i, double Value) { _vt[i] = Value; }//Thay doi gia tri thanh phan thu i cua vector
public:
	Vector& operator+(const	Vector& other);//Cong vector voi 1 vector khac
	Vector& operator*(double a);//Nhan vecto voi mot so alpha
	Vector& operator=(const	Vector& other); //Gan ma tran bang 1 ma tran khac
	friend istream& operator>>(istream& in, Vector& a);//Nhap ma tran
	friend ostream& operator<<(ostream& out, Vector& a);//Xuat ma tran bat dau tu 0, 0
	void Out(int x, int y);//Xuat vector tai vi tri x, y
public:
	Vector();
	Vector(int);
	Vector(double, double, double);
	Vector(const Vector&);
	~Vector() {}
};

class Matrix
{
private:
	int _m, _n;
	double** _matrix;
public:
	const int M() { return _m; }
	const int N() { return _n; }
	const double GetAij(int i, int j) { return _matrix[i][j]; }
	void SetM(int m) { if (m > 0)_m = m; }
	void SetN(int n) { if (n > 0) _n = n; }
	void SetAij(int i, int j, double Value) { _matrix[i][j] = Value; }//
public:
	bool CheckSquare();//Kiem tra ma tran vuong
	bool CheckRow0(int);//Kiem tra tat ca phan tu cua dong i co bang 0 hay khong
	bool CheckCol0(int);//Kiem tra tat ca phan tu cua cot j co bang 0 hay khong
	void ChangeRow(int, int);//Doi vi tri 2 dong
	void ChangeCol(int, int);//Doi vi tri 2 cot
	void SetRow(int, double);//Nhan dong i voi gia tri k
	void SetCol(int, double);//Nhan cot j voi gia tri k
public:
	Matrix CreateIdentity(int);//Tao ma tran don vi bac n
	double Det();//Tinh dinh thuc
	Matrix& Invert();//Tra ve ma tran nghich dao (neu co)
	int Rank();//Tinh hang cua ma tran
	void LinearSystem();//Giai he phuong trinh tuyen tinh
public:
	Matrix();
	Matrix(int m, int n, double** arr);
	Matrix(int m, int n);
	Matrix(const Matrix&);
	~Matrix();
public:
	friend istream& operator>>(istream& in, Matrix& a);//Nhap gia tri vao ma tran
	void Out(int x, int y);//Xuat ma tran tai vi tri x, y
	Matrix& operator=(const	Matrix& other);//Gan ma tran bang 1 ma tran khac
	Matrix& operator*(const	Matrix& other);//Nhan ma tran voi 1 ma tran khac
	Matrix& operator*(const	double k);//Nhan ma tran voi 1 so k
};