#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

#include <string>
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

class Boole
{
public:
	int data;//data=0 or 1
	int exist = 0;
	int BU = 0;
	string type;
	void giao(Boole a) { data = a.data*data; };
	void hop(Boole a){ data = a.data + data - a.data*data; }
	void bu(){ data = 1 - data; }
	Boole();
};

struct HJHJ
{
	int *A;//4 
	string oxuathien;//1,2,,4,8
	int flag = 1;
};

