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
			chi += this->khoanDuTru[thangX - 2];
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

void QLChiTieu::moTKTietKiem() {
	if (this->tienGuiTietKiem[this->tienGuiTietKiem.size()-1] <= 0) {
		cout << "Thu chi am. Khong du tien gui tiet kiem!!!" << endl;
		return;
	}
	int choose = 0;
	cout << "=======CHON HINH THUC GUI TIET KIEM=======" << endl;
	cout << "*1. 6 thang- Lai suat 6%/tong tien gui   *" << endl;
	cout << "*2. 12 thang- Lai suat 6.5%/tong tien gui*" << endl;
	cout << "==========================================" << endl;
	cout << "Moi ban chon: ";
	cin >> choose;
	while (choose < 1 || choose>2) {
		cout << "Nhap lai lua chon: ";
		cin >> choose;
	}
	cin.ignore();
	cout << "Nhap ngay gui trong thang: ";
	string ngay;
	if (ngay.length() < 2) {
		ngay = "0" + ngay;
	}
	getline(cin, ngay);
	int thang = 0;
	int nam = 0;
	if (4 + this->khoanThuNhap.size() > 12) {
		if ((4 + this->khoanThuNhap.size()) % 12 == 0) {
			thang = 12;
		}
		else {
			thang = (4 + this->khoanThuNhap.size()) % 12;
		}
		nam = 2022 + ((4 + this->khoanThuNhap.size()) / 12);
	}
	else {
		thang = 4 + this->khoanThuNhap.size();
		nam = 2022;
	}
	string ngayGui = "";
	if (thang < 10) {
		ngayGui = ngayGui + ngay + "/" + "0" + to_string(thang) + "/" + to_string(nam);
	}
	else {
		ngayGui = ngayGui + ngay + "/" + to_string(thang) + "/" + to_string(nam);
	}
	if (choose == 1) {
		TKTietKiem tk(6, 0.06, this->tienGuiTietKiem[this->tienGuiTietKiem.size() - 1], 0,ngayGui);
		this->khoanTietKiem.push_back(tk);
	}
	else {
		TKTietKiem tk(12, 0.065, this->tienGuiTietKiem[this->tienGuiTietKiem.size() - 1], 0,ngayGui);
		this->khoanTietKiem.push_back(tk);
	}
	cout << "Da tao tai khoan tiet kiem thanh cong!!!" << endl;
}

void QLChiTieu::capNhatSoThangDaGuiCuaTKTietKiem() {
	for (int i = 0; i < this->khoanTietKiem.size(); i++) {
		this->khoanTietKiem[i].capNhatSoThangDaGui();
	}
}

void QLChiTieu::tatToanCacTKTietKiem()
{
	bool checkTKTietKiemToiHan = false;
	vector<int>index;
	for (int i = 0; i < this->khoanTietKiem.size(); i++) {
		if (this->khoanTietKiem[i].laySoThangDaGui() == this->khoanTietKiem[i].layKiHan()) {
			checkTKTietKiemToiHan = true;
			index.push_back(i);
		}
	}
	if (checkTKTietKiemToiHan) {
		system("cls");
		cout << "Co so tiet kiem toi han. Thuc hien tat toan so tiet kiem:" << endl;
		for (int i = 0; i < index.size(); i++) {
			cout << "Thong tin so tiet kiem:" << endl;
			this->khoanTietKiem[index[i]].xuatThongTin();
			cout << endl;
			cout << "Da tat toan, mo so tiet kiem moi voi so tien vua nhan duoc." << endl;
			this->tienGuiTietKiem.push_back(this->khoanTietKiem[index[i]].tattoanTKTietKiem());
			this->moTKTietKiem();
			cout << endl;
			this->tienGuiTietKiem[index[i]] = 0;
			this->khoanTietKiem[index[i]].ganTienGui(0);
			cout << "=============================" << endl;
		}
	}
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
		cout << "Tien du tru du: " << this->khoanDuTru[thangX - 1] << " trieu vnd" << endl;
		cout << "Tien gui tiet kiem: " << this->tienGuiTietKiem[thangX - 1] << " trieu vnd" << endl;
		return true;
	}
}


double QLChiTieu::tinhTongTienTKSauXThang(int thangX) {
	return 1;
}

double QLChiTieu::traNoNamRuoi(int thangX) {
	double tongTienTK = this->tinhTongTienTKSauXThang(18);
	double tongNo = this->khoanNo[0]->tinhTongNoSauXThang(18);
	return tongTienTK - tongNo;
}
double QLChiTieu::traNoBaNam(int thangX) {
	double tongTienTK = this->tinhTongTienTKSauXThang(36);
	double tongNo = this->khoanNo[1]->tinhTongNoSauXThang(36);
	return tongTienTK - tongNo;
}

void QLChiTieu::xuLyQLChiTieu() {
	cout << "*****CHUONG TRINH QUAN LY CHI TIEU*****" << endl;
	this->nhapKhoanNo();
	cout << endl;
	cout << "Nhan phim bat ky de tiep tuc." << endl;
	system("pause");
	system("cls");
	int choose = 0;
	int choose2 = 0;
	int count = 1;
	do {
		cout << "===============MENU===============" << endl;
		cout << "* 1. Nhap thu chi                *" << endl;
		cout << "* 2. Danh gia thu chi thang thu x*" << endl;
		cout << "* 3. Xem danh sach so tiet kiem  *" << endl;
		cout << "* 4. Xem thong tin cac khoan no  *" << endl;
		cout << "* 0. Thoat                       *" << endl;
		cout << "==================================" << endl;
		cout << "Moi ban chon: ";
		cin >> choose;
		while (choose < 0 || choose>4) {
			cout << "Nhap lai lua chon: ";
			cin >> choose;
		}
		system("cls");
		if (choose == 1) {
			do {
				cout << "Nhap thu chi thang thu " << count << ":" << endl;
				count += 1;
				this->nhapThuChi();
				this->tinhTienDuTruVaTienGuiHangThang(this->khoanThuNhap.size());
				this->capNhatSoThangDaGuiCuaTKTietKiem();
				this->moTKTietKiem();
				this->tatToanCacTKTietKiem();
				cout << endl;
				cout << "1.Nhap thu chi thang tiep theo" << endl;
				cout << "2. Quay lai menu chinh" << endl;
				cout << "Moi ban chon: ";
				cin >> choose2;
				while (choose2 < 1 || choose2>2) {
					cout << "Nhap lai lua chon: ";
					cin >> choose2;
				}
				system("cls");
			} while (choose2 != 2);
		}
		if (choose == 2) {
			int thangX;
			cout << "Nhap thang can xuat danh gia: ";
			cin >> thangX;
			while (thangX<1 || thangX>this->khoanThuNhap.size()) {
				cout << "Thang nhap khong hop le. Hien dang co thong tin cua " << this->khoanThuNhap.size() << " thang!" << endl;
				cout << "Nhap lai: ";
				cin >> thangX;
			}
			this->xuatvaDanhGiaThuChi(thangX);
			choose2 = 0;
		}
		if (choose == 3) {
			if (this->khoanTietKiem.size() > 0) {
				short count = 1;
				for (int i = 0; i < this->khoanTietKiem.size(); i++) {
					if (this->khoanTietKiem[i].layTienGui() != 0) {
						cout << "So thu " << count << ":" << endl;
						this->khoanTietKiem[i].xuatThongTin();
						cout << "=============================" << endl;
						count += 1;
					}
				}
				choose2 = 0;
			}
			else {
				cout << "Chua co tai khoan tiet kiem duoc mo!!!" << endl;
			}
		}
		if (choose == 4) {
			cout << "Khoan no 1.5 nam:" << endl;
			this->khoanNo[0]->xuatThongTinNo();
			cout << "================================" << endl;
			cout << "Khoan no 3 nam" << endl;
			this->khoanNo[1]->xuatThongTinNo();
			choose2 = 0;
		}
		if (choose != 0&&choose2!=2) {
			system("pause");
			system("cls");
		}
	} while (choose != 0);
}

