#include"Header.h"

int main() {
	Nodeptr dsnv;
	//NhanVien nv;
	//int n;
	int chon;
	nhapDSNV(dsnv);
	xuatDSNV(dsnv);
	do
	{
		cout << "\n\t\t------------------------MENU---------------------";
		cout << "\n\t\tQuan ly nhan vien";
		cout << "\n\t1.Them vao 1 nhan vien.";
		cout << "\n\t2.Tim nhan vien theo tieu chi.";
		cout << "\n\t3.Xoa 1 nhan vien.";
		cout << "\n\t4.Sua thong tin nhan vien theo tieu chi.";
		cout << "\n\t5.Luu file.";

		cout << "\n\t0.Thoat.";
		cout << "\n\t *************************************************";
		cout << "\n\tChon 1 trong chuc nang tren: ";
		cin >> chon;
		cin.ignore();

		switch (chon)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			Them_NV(dsnv);
			xuatDSNV(dsnv);
			break;
		}
		case 2:
		{
			int chonsua;
			cout << "\n\t\tBan mua tim kiem nhan vien theo thieu chi nao?";
			cout << "\n\t\t2.1.MA SO NHAN VIEN.";
			cout << "\n\t\t2.2.Ho nhan vien.";
			cout << "\n\t\t2.3.Ten nhan vien.";
			cout << "\n\t\tTieu chi ban chon: ";
			cin >> chonsua;
			cin.ignore();
			switch (chonsua)
			{
			case 1:
			{
				char ma[10];
				cout << "\nNhap ma so nhan vien can tim: ";
				cin.getline(ma, 10);
				timMSNV(dsnv, ma);
				break;
			}
			case 2:
			{
				char ho[30];
				cout << "\nNhap ho cua nhan vien can tim: ";
				cin.getline(ho, 30);
				timHoNV(dsnv, ho);
				break;
			}
			case 3:
			{
				char ten[30];
				cout << "\nNhap ten cua nhan vien can tim: ";
				cin.getline(ten, 30);
				timTenNV(dsnv, ten);
				break;
			}
			default:
				cout << "\nKhong co tieu chi ban muon chon!";
				break;
			}
			break;

		}
		case 3:
		{
			int vt;
			cout << "\n\tBan vi tri xoa nhan vien: ";
			cin >> vt;
			xoa_NVVT(dsnv, vt);
			xuatDSNV(dsnv);
			break;
		}
		case 4:
		{
			suaNV(dsnv);
			xuatDSNV(dsnv);
			break;
		}
		case 5:
		{
			GHIFILE(dsnv);
			break;
		}
		case 6:
		{
		}
		default:
		{
			cout << "\nkhong co chuc nang nay, moi ban chon lai!";
		}
		break;
		}
	} while (chon != 0);
	giaiPhong(dsnv);
	system("pause");
	return 0;
}