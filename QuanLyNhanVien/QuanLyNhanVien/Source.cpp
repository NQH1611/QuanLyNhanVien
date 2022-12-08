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
	if(i==0){
		xoaNV(list, p->data);
	} else{
		break;
	}

}