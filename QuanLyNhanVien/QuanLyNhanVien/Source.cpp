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
void nhapDSNV(Nodeptr& list)
{
	NhanVien nv;
	khoiTao(list);
	do
	{
		cout << "\nNhap ma so nhan vien (NHAP 0 DE THOAT): ";
		cin.getline(nv.msnv, 10);
		if (strcmp(nv.msnv, "0") == 0)
			break;
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
void xoaNV(Nodeptr& list,NhanVien nv)
{
	if (strcmp(list->data.msnv, nv.msnv) == 0)
	{
		Nodeptr p = list;
		p = p->link;
		delete p;
		p = NULL;
	}
	else {
		Nodeptr p, before;
		p = list;
		before = list;
		while (p != NULL && strcmp(p->data.msnv, nv.msnv) != 0)
		{
			before = p;
			p = p->link;
		}
		if (p != NULL)
		{
			before->link = p->link;
			delete p;
			p = NULL;
		}
	}
}
void xoa_NVVT(Nodeptr& list, int vt)
{
	int i;
	Nodeptr p = list;
	for (int i = 0; i < vt-1; i++) {
		p = p->link;
	}
	cout << "Ban thuc su muon xoa ? 0: Co | 1: Khong ?";
	cin >> i;
	if (i == 0) {
		xoaNV(list, p->data);
	}
	else {
		return;
	}
}
void xuatNV(Nodeptr list)
{
	int w = 10;
	cout << setw(w) << "MSNV" << setw(w) << "Ho NV" << setw(w) << "Ten NV" << setw(w) << "Luong" << setw(w) << "HeSoLuong" << setw(w) << "ThamNen" << endl;
	cout << setw(w) << list->data.msnv << setw(w) << list->data.honv << setw(w) << list->data.tennv << setw(w) << list->data.luong << setw(w) << list->data.heSoLuong << setw(w) << list->data.thamnien << endl;
}
void timMSNV(Nodeptr list, char* ma)
{
	for (Nodeptr p = list; p != NULL; p = p->link)
		if (strcmp(p->data.msnv, ma) == 0)
			xuatNV(p);
}
void timHoNV(Nodeptr list, char* ho)
{
	for (Nodeptr p = list; p != NULL; p = p->link)
		if (strcmp(p->data.honv, ho) == 0)
			xuatNV(p);
}
void timTenNV(Nodeptr list, char* ten)
{
	for (Nodeptr p = list; p != NULL; p = p->link)
		if (strcmp(p->data.tennv, ten) == 0)
			xuatNV(p);
}


void sapXepNV(Nodeptr& list, NhanVien& nv)
{
	for (Nodeptr temp = list; temp != NULL; temp = temp->link)
	{
		for (Nodeptr temp1 = temp->link; temp1 != NULL; temp1 = temp1->link)
			if (strcmp(temp1->data.msnv, temp->data.msnv) == -1)
			{
				nv = temp->data;
				temp->data = temp1->data;
				temp1->data = nv;

			}
	}
	cout << "Danh sach sau khi sap xep" << endl;
	xuatDSNV(list);
}
	
void Ghi_Thong_Tin_1_NhanVien(ostream& fileout, NhanVien nv)
{
	fileout << nv.msnv << ",";
	fileout << nv.honv << ",";
	fileout << nv.tennv << ",";
	fileout << nv.luong << ",";
	fileout << nv.thamnien;
}
void GHIFILE(Nodeptr list)
{
	ofstream fileout;
	fileout.open("DANHSACHNHANVIEN.txt", ios::out);
	for (Nodeptr p = list; p != NULL; p = p->link)
	{
		Ghi_Thong_Tin_1_NhanVien(fileout, p->data);
		fileout << endl;
	}
	fileout.close();
}
