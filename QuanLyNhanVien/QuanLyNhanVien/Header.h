#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include"string.h"
using namespace std;
struct NhanVien
{
	char msnv[10];
	char honv[30];
	char tennv[30];
	int luong;
	int heSoLuong;
	int thamnien;
};

typedef struct Node* Nodeptr;
struct Node
{
	NhanVien data;
	Nodeptr link;
};

void khoiTao(Nodeptr& list);
int isEmpty(Nodeptr list);
void giaiPhong(Nodeptr& list);
Nodeptr taoNode(NhanVien nv);
Nodeptr themDau(Nodeptr& list, NhanVien nv);
Nodeptr themCuoi(Nodeptr& list, NhanVien nv);
void nhapDSNV(Nodeptr& list);
Nodeptr NhapNV(Nodeptr& list);
void xuatDSNV(Nodeptr list);
void Them_NV(Nodeptr list);
void xoaNV(Nodeptr& list, NhanVien nv);
void xoa_NVVT(Nodeptr& list, int vt);
void timMSNV(Nodeptr list, char* ma);
void xuatNV(Nodeptr list);
void timHoNV(Nodeptr list, char* ho);
void suaNV(Nodeptr& list);
void timTenNV(Nodeptr list, char* ten);
void sapXepNV(Nodeptr& list, NhanVien& nv);
void Ghi_Thong_Tin_1_NhanVien(ostream& fileout, NhanVien nv);
void GHIFILE(Nodeptr list);
