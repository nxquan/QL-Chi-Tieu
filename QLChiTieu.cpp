#include "QLChiTieu.h"

QLChiTieu::QLChiTieu() {
	this->khoanDuTru.resize(0);
}
QLChiTieu::~QLChiTieu() {

}

void QLChiTieu::nhapKhoanNo() {
	//Tạo nợ 1.5 năm
	TienNo* n1 = new NoNamRuoi;
	n1->nhapKhoanNo();
	this->khoanNo.push_back(n1);

	system("cls");
	//Tạo nợ 3 năm
	TienNo* n2 = new NoBaNam;
	n2->nhapKhoanNo();
	this->khoanNo.push_back(n2);
}

void QLChiTieu::nhapThuChi() {
	ThuNhap tn;
	//Nhập thu nhập
	cout << "===NHAP THU NHAP===" << endl;
	tn.nhapLuong();
	tn.nhapThuNhapKhac();
	this->khoanThuNhap.push_back(tn);

	cout << "\n";
	//Nhập chi tiêu
	ChiTieu ct;
	cout << "===NHAP CHI TIEU===" << endl;
	ct.nhapChiTieu();

	this->khoanChiTieu.push_back(ct);
}

vector<double> QLChiTieu::thuChiAm(int thangX) {
	double chi = this->khoanThuNhap[thangX - 1].layLuong() 
		+ this->khoanThuNhap[thangX - 1].layThuNhapKhac();
	if (thangX > 1) {
		chi += this->khoanDuTru[thangX - 2]; // (x - 1) - 1
	}
	//thu nhap khac + tien du tru neu co
	double tienDu = chi - this->khoanChiTieu[thangX - 1].tinhTongChiTieu();
	vector<double>check;
	check.resize(2, 0); //0: âm hay dương: > 0 => 0 dương 1
	//check[1] => tiền dư
	if (tienDu >= 0) {
		check[0] = 0; //Chi tiêu không âm
	}
	else {
		check[0] = 1; //Chi tiêu âm
	}
	check[1] = tienDu; //Xuất ra số tiền âm để show ra màn hình
	return check;
}

void QLChiTieu::tinhTienDuTruVaTienGuiHangThang(int thangX) {
	if (this->thuChiAm(thangX)[0] == 0) {
		//lưu tiền chi = thu nhập khác + tiền dự trù
		double chi = khoanThuNhap[thangX - 1].layThuNhapKhac();	
		if (thangX >= 2) {
			chi += this->khoanDuTru[thangX - 1];
		}

		//Tính tiền dự trù và tiền gửi tiết kiệm của tháng đang xét
		if (chi >= khoanChiTieu[thangX - 1].tinhTongChiTieu()) {
			this->khoanDuTru.push_back(chi - khoanChiTieu[thangX - 1].tinhTongChiTieu());
			this->tienGuiTietKiem.push_back(khoanThuNhap[thangX - 1].layLuong());
		}
		else {
			this->khoanDuTru.push_back(0);
			this->tienGuiTietKiem.push_back(khoanThuNhap[thangX - 1].layLuong()
				+ chi - khoanChiTieu[thangX - 1].tinhTongChiTieu());
		}
	}
}

void QLChiTieu::moTKTietKiem(int thangX) {
	TKTietKiem tk1;
}

void QLChiTieu::capNhatCacTKTietKiem() {

}


bool QLChiTieu::xuatvaDanhGiaThuChi(int thangX) {
	cout << "\t=========== DANH GIA CHI TIEU THANG " << thangX << " ===========" << endl;

	this->khoanThuNhap[thangX - 1].xuatThuNhap();
	this->khoanChiTieu[thangX - 1].xuatChiTieu();
	vector <double> check = thuChiAm(thangX);

	if (check[0] == 1) {
		cout << "Chi tieu khong hop ly, am "<<check[1] << "trieu vnd, => VO NO" << endl;
		return false;
	}
	else {
		cout << "Chi tieu hop ly" << endl;
		cout << "Tien du tru du: " << this->khoanDuTru[thangX - 1] << endl;
		cout << "Tien gui tiet kiem: " << this->tienGuiTietKiem[thangX - 1] << endl;
		return true;
	}
}


double QLChiTieu::tinhTongTienTKSauXThang(int thangX) {
	return 1;
}

void QLChiTieu::traNoNamRuoi(int thangX) {

}
void QLChiTieu::traNoBaNam(int thangX) {

}

void QLChiTieu::xuLyQLChiTieu() {
	int soThangCanQL;
	int i = 1;
	int check = true;
	this->nhapKhoanNo(); //B1
	cout << "Nhap so thang can QL Chi Tieu: ";
	cin >> soThangCanQL;

	while (i <= soThangCanQL && check) {
		system("cls");
		cout << "\t=========== NHAP THU - CHI THANG " << i << " ===========" << endl;
		this->nhapThuChi();
		this->tinhTienDuTruVaTienGuiHangThang(i);

		//Có thể tạo menu tại đây
		while (true) {
			system("cls");
			cout << "===MENU===" << endl;
			cout << "1. Danh gia thu - chi thang vua nhap" << endl;
			cout << "2. Danh gia thu - chi thang x" << endl;

			cout << "0. Nhap thu - chi thang tiep theo" << endl;
			int select;
			cout << "Nhap lua chon: ";
			cin >> select;

			system("cls");
			if (select == 0) {
				break;
			}
			else if (select == 1) {
				check = this->xuatvaDanhGiaThuChi(i);
			}
			else if (select == 2) {
				int thangX;
				cout << "Nhap thang can xuat danh gia: ";
				cin >> thangX;
				this->xuatvaDanhGiaThuChi(thangX);
			}

			system("pause");
		}

		i++;
	}
}

