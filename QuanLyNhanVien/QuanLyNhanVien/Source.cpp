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
