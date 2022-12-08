﻿#include"Header.h"
#include<cstring>
#include<fstream>
using namespace std;

void khoiTao(Nodeptr& list)
{
	list = NULL; //khởi tạo một node có giá trị rỗng trong danh sách liên kết 
}
int isEmpty(Nodeptr list)
{
	return list == NULL ? 1 : 0;
}
void giaiPhong(Nodeptr& list)
{
	Nodeptr p = list;
	while (p != NULL)
	{
		list = list->link;
		delete p;
		p = list;
	}
}
Nodeptr taoNode(NhanVien nv)
{
	Nodeptr p;
	p = new Node;
	p->data = nv; //đưa dữ liệu của biến nhân viên nv vào data của node p
	p->link = NULL; //khởi tạo 1 node p nhưng chưa trỏ đến node nào hết 
	return p;
}
Nodeptr themDau(Nodeptr& list, NhanVien nv)
{
	Nodeptr p = taoNode(nv);
	p->link = list;
	list = p;
	return p;
}
Nodeptr themCuoi(Nodeptr& list, NhanVien nv)
{
	Nodeptr p;
	p = taoNode(nv);
	if (list == NULL)
		list = p;
	else {
		Nodeptr q = list;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
	return p;
}
void nhapDSNV(Nodeptr& list)
{
	NhanVien nv;
	khoiTao(list);
	do
	{
		cout << "\nNhap ma so nhan vien (NHAP 0 DE THOAT): ";
		cin.getline(nv.msnv, 10);
		cout << "\nMoi ban nhap lai ma so nhan vien: ";
		cin.getline(nv.msnv, 10);
		cout << "\nNhap ho cua nhan vien: ";
		cin.getline(nv.honv, 30);
		cout << "\nNhap ten cau nhan vien: ";
		cin.getline(nv.tennv, 30);
		cout << "Nhap vao luong cua nhan vien: ";
		cin >> nv.luong;
		cout << "\nNhap he so luong cua nhan vien: ";
		cin >> nv.heSoLuong;
		cout << "\nNhap vao tham nien cua nhan vien: ";
		cin >> nv.thamnien;
		cin.ignore();
		themCuoi(list, nv);
	} while (1);
}
void xuatDSNV(Nodeptr list)
{
	Nodeptr p = list;
	int w = 10;
	cout << "\n\t\tDANH SACH NHAN VIEN" << endl;
	cout << setw(w) << "MSNV" << setw(w) << "Ho NV" << setw(w) << "Ten NV" << setw(w) << "Luong" << setw(w) << "HeSoLuong" << setw(w) << "ThamNien" << setw(w) << "Thanhtien" << endl;
	while (p != NULL)
	{
		cout << setw(w) << p->data.msnv << setw(w) << p->data.honv << setw(w) << p->data.tennv << setw(w) << p->data.luong << setw(w) << p->data.heSoLuong << setw(w) << p->data.thamnien << setw(w) << p->data.heSoLuong * p->data.luong << endl;
		p = p->link;
	}
}