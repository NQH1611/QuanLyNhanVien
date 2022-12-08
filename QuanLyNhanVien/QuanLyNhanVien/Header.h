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
