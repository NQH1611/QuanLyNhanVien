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
Nodeptr NhapNV(Nodeptr& list)
{
	NhanVien nv;
	khoiTao(list);
	cout << "\nNhap ma so nhan vien: ";
	cin.getline(nv.msnv, 10);
	cout << "\nNhap ho nhan vien: ";
	cin.getline(nv.honv, 30);
	cout << "\nNhap ten nhan vien: ";
	cin.getline(nv.tennv, 30);
	cout << "\nnhap luong cua nhan vien: ";
	cin >> nv.luong;
	while (nv.luong <= 0)
	{
		cout << "\nluong cua nhan vien khong the nho hon hoac bang 0, moi nhap lai!";
		cin >> nv.luong;
	}
	cout << "\nNhap he so luong cua nhan vien: ";
	cin >> nv.heSoLuong;
	cout << "\nNhap tham nien cua nhan vien: ";
	cin >> nv.thamnien;
	cin.ignore();
	themCuoi(list, nv);
	return list;
}


void Them_NV(Nodeptr list)
{
	Nodeptr p = list;
	Nodeptr q = list;
	Nodeptr beforeq = list;
	Nodeptr temp;

	NhapNV(temp);
	int pos;
	int demds = 0;
	int dem = 0;
	while (p != NULL)
	{
		demds++;
		p = p->link;
	}
	cout << "Hien tai danh sach co " << demds << " vi tri." << "Chen sau vi tri: ";
	cin >> pos;
	while (pos < 0 || pos > demds)
	{
		cout << "(" << demds << ") " << "Vi tri nhan vien khong hop le! Vui long nhap lai: ";
		cin >> pos;
	}
	while (q != NULL)
	{
		dem++;
		if (dem == pos)
		{
			temp->link = q->link;
			q->link = temp;
		}
		q = q->link;
	}
	cout << endl;

}
