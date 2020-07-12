#pragma once
#include"Boole.h"
#include"tutoitiu.h"

int** CreateKar();
// tao ra mang Karnaugh

string recal2(tutoitiu Ec);// Ec la tu toi tieu duoc truyen vao
// chuyen tu toi tieu -> string

string intToString(int a);
// chuyen tu so int -> chuoi

void setHJHJ(HJHJ &ec);

int checkdif1(int *A, int *B);
// ktra khac nhau giua 2 mang 4

int* fixtungcai(int *A, int *B);
// sua 2 mang 4 sau khi ktra

int checkXuatHien(HJHJ A, HJHJ*B, int n);
// ktra xuat hien sau khi chay lan 1

int checkXuatHien2(HJHJ A, HJHJ*B, int n, int a);// n la so phan tu, a la vi tri cua A trong mang B
// ktra xuat hien khi clean2

HJHJ* FirstFix(HJHJ* KEC, int &n);// co trong luu do thuat toan
// core

tutoitiu* Add(int** Kar, int &n);// Karnaugh -> tutoitieu
// them vao mang tu toi tieu tu mang karnaugh

int* AddTTTtoString(tutoitiu B);
//TTT -> int

int cal(tutoitiu ec, int i1, int i2, int i3, int i4);
// tinh toan khi them tu toi tieu -> kar

int** doc(string a);
// doc string nhap vao

void printarr(int *A);
// in ra mang

void printHJHJ(HJHJ *k, int n);
// in struct hjhj
int check(int *A, int *B);
// kiem tra 2 mang giong nhau hay khong
HJHJ* clean(HJHJ* test, int &n);
// clean ket qua lan 1 
void delete1(HJHJ* test, int &n, int i);
// xoa phan tu thu i cua struct HJHJ co n phan tu
void clean2(HJHJ* test, int &n);
// clean ket qua lan 2
void config(HJHJ* test, tutoitiu* result, int i, int j);
// chuyen tu stuct HJHJ -> tu toi tieu
tutoitiu* Addfrom01(HJHJ *test, int n);
// chuyen tu stuct HJHJ -> tu toi tieu
void boolsolver();
// ham cuoi cung de giai toan
void gotoxy(int x, int y);
// chuyen con tro toi vi tri x y
void TextColor(int x);
// doi mau chu
void Nocursortype();
//Xoa con tro console