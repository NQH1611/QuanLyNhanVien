#include"Header.h"
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
void suaNV(Nodeptr& list)
{
	NhanVien x;
	Nodeptr q = list;
	Nodeptr p = list;
	int tongNV = 0;
	int pos;
	int timvt = 0;
	while (q != NULL)
	{
		tongNV++;
		q = q->link;
	}
	cout << "\nHien tai trong danh sach co " << tongNV << " nhan vien";
	cout << "\nBan muon sua nhan vien tai vi tri nao?";
	cout << "\nNhap vi tri muon sua: ";
	cin >> pos;
	while (pos<0 || pos>tongNV)
	{
		cout << "\nVi tri ban chon khong hop le, moi ban chon lai :";
		cin >> pos;
	}
	while (p != NULL)
	{
		timvt++;
		if (timvt == pos)
		{
			int suatt;
			cout << "\n\tBan muon sua thong tin: ";
			cout << "\n\t4.1.Ho NV.";
			cout << "\n\t4.2.Ten NV.";
			cout << "\n\t4.3.Luong NV.";
			cout << "\n\t4.4.Tham Nien NV.";
			cout << "\n\t0.Thoat";
			cout << "\n\tBan muon sua thong tin nao: ";
			cin >> suatt;
			cin.ignore();
			switch (suatt)
			{
			case 1:
			{
				cout << "\nNhap Ho NV muon doi: ";
				cin.getline(x.honv, 30);
				strcpy(p->data.honv, x.honv);
				break;
			}
			case 2:
			{
				cout << "\nNhap Ten NV muon doi: ";
				cin.getline(x.tennv, 30);
				strcpy(p->data.tennv, x.tennv);
				break;
			}
			case 3:
			{
				cout << "\nNhap Luong NV muon doi: ";
				cin >> x.luong;
				p->data.luong = x.luong;
				break;
			}
			case 4:
			{
				cout << "\nNhap Tham Nien muon doi: ";
				cin >> x.thamnien;
				p->data.thamnien = x.thamnien;
				break;
			}
			default:
				cout << "\nKhong co thong tin ban muon sua!";
				break;
			}
			break;
		}
		p = p->link;
	}

}
