#include "QLChiTieu.h"

QLChiTieu::QLChiTieu() {
	this->khoanDuTru.resize(0);
	this->soTKGD[0] = 0;
	this->soTKGD[1] = 0;
}
QLChiTieu::QLChiTieu(vector<ThuNhap> thuNhap, vector<ChiTieu> chiTieu
	, vector<double> duTru, vector<double> tienTK
	, vector<TKTietKiem> soTK, vector<TienNo*> no) {
	this->khoanDuTru.resize(0);
	for (int i = 0; i < thuNhap.size(); i++) {
		this->khoanThuNhap.push_back(thuNhap[i]);
		this->khoanChiTieu.push_back(chiTieu[i]);
		this->khoanDuTru.push_back(duTru[i]);
	}
	for (int i = 0; i < tienTK.size(); i++) {
		this->tienGuiTietKiem.push_back(tienTK[i]);
	}
	for (int i = 0; i < soTK.size(); i++) {
		this->khoanTietKiem.push_back(soTK[i]);
	}
	TienNo* temp1 = new NoNamRuoi;
	temp1->ganTienNoGoc(no[0]->layTienNoGoc());
	temp1->ganNgayMuonNo(no[0]->layNgayMuonNo());
	temp1->ganLaiSuat(no[0]->layLaiSuat());

	this->khoanNo.push_back(temp1);

	TienNo* temp2 = new NoBaNam;
	temp2->ganTienNoGoc(no[1]->layTienNoGoc());
	temp2->ganNgayMuonNo(no[1]->layNgayMuonNo());
	temp2->ganLaiSuat(no[1]->layLaiSuat());
	this->khoanNo.push_back(temp2);
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
	tn.nhapThuNhap();
	this->khoanThuNhap.push_back(tn);
	cout << "\n";

	//Nhập chi tiêu
	ChiTieu ct;
	cout << "===NHAP CHI TIEU===" << endl;
	ct.nhapChiTieu();
	this->khoanChiTieu.push_back(ct);
}

vector<double> QLChiTieu::thuChiAm(int thangX) {
	double thu = this->khoanThuNhap[thangX - 1].tongLuongVoChong()+this->khoanThuNhap[thangX - 1].layThuNhapKhac();
	if (thangX > 1 && thangX != 19) {
		thu += this->khoanDuTru[thangX - 2];
	}
	double tienDu = thu - this->khoanChiTieu[thangX - 1].tinhTongChiTieu();
	vector<double>check;
	check.resize(2, 0);
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

double QLChiTieu::tinhTienDu(int thangX) {
	double tienDu = this->khoanThuNhap[thangX - 1].layThuNhapKhac()
		- this->khoanChiTieu[thangX - 1].tinhTongChiTieu();
	if (thangX > 1 && thangX != 19) {
		tienDu += this->khoanDuTru[thangX - 2];
	}
	return tienDu;
}

void QLChiTieu::tinhTienDuTruVaTienGuiHangThang(int thangX) {
	vector <double> check = this->thuChiAm(thangX);
	if (check[0] == 0) {
		double duTru = tinhTienDu(thangX);
		double tienGuiTK = khoanThuNhap[thangX - 1].tongLuongVoChong();
		if (duTru >= 0) {
			this->khoanDuTru.push_back(duTru);
			this->tienGuiTietKiem.push_back(tienGuiTK);
		}else {
			tienGuiTK +=  duTru;
			this->khoanDuTru.push_back(0);
			this->tienGuiTietKiem.push_back(tienGuiTK);
		}
	}
	else if (check[0] == 0 && check[1] == 0) {
		this->khoanDuTru.push_back(0);
		this->tienGuiTietKiem.push_back(0);
	}
}

void QLChiTieu::moTKTietKiem() {
	if (this->tienGuiTietKiem[this->tienGuiTietKiem.size()-1] <= 0) {
		cout << "Thu chi am. Khong du tien gui tiet kiem!!!" << endl;
		return;
	}
	int choose = 0;
	cout <<"\n==>> So tien gui trong thang: "<<this->tienGuiTietKiem[this->tienGuiTietKiem.size() - 1]<<" trieu" <<"\n\n";
	cout << "=======CHON HINH THUC GUI TIET KIEM=======" << endl;
	cout << "*1. 6 thang- Lai suat 6%/tong tien gui   *" << endl;
	cout << "*2. 12 thang- Lai suat 6.5%/tong tien gui*" << endl;
	cout << "*3. Khong gui tiet kiem                  *" << endl;
	cout << "==========================================" << endl;
	cout << "Moi ban chon: ";
	cin >> choose;
	while (choose < 1 || choose>3) {
		cout << "Nhap lai lua chon: ";
		cin >> choose;
	}
	cin.ignore();
	if (choose != 3) {
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
			TKTietKiem tk(6, 0.06, this->tienGuiTietKiem[this->tienGuiTietKiem.size() - 1], 0, ngayGui);
			this->khoanTietKiem.push_back(tk);
		}
		else {
			TKTietKiem tk(12, 0.065, this->tienGuiTietKiem[this->tienGuiTietKiem.size() - 1], 0, ngayGui);
			this->khoanTietKiem.push_back(tk);
		}
		cout << "Da tao tai khoan tiet kiem thanh cong!!!" << endl;
	}
	else {
		cout << "Ban da chon khong gui tien vao tai khoan tiet kiem!" << endl;
		if (this->khoanThuNhap.size() <= 18) {
			this->soTKGD[0] += this->tienGuiTietKiem[this->tienGuiTietKiem.size() - 1];
		}
		else {
			this->soTKGD[1] += this->tienGuiTietKiem[this->tienGuiTietKiem.size() - 1];
		}
	}
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
		if (this->khoanTietKiem[i].laySoThangDaGui() == this->khoanTietKiem[i].layKiHan() && this->khoanTietKiem[i].kiemTraTinhTrang()==false) {
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
			this->tienGuiTietKiem.pop_back();
			cout << endl;
			this->khoanTietKiem[index[i]].capNhatTinhTrang();
			system("cls");
		}
	}
}

bool QLChiTieu::xuatvaDanhGiaThuChi(int thangX) {
	cout << "\t=========== DANH GIA CHI TIEU THANG " << thangX << " ===========" << endl;

	this->khoanThuNhap[thangX - 1].xuatThuNhap();
	this->khoanChiTieu[thangX - 1].xuatChiTieu();
	if (thangX <= 18) {
		cout << "+ So tien trong so TKGD: " << this->soTKGD[0] <<" trieu" << endl;
	}
	else {
		cout << "+ So tien trong so TKGD: " << this->soTKGD[1] <<" trieu"<< "\n\n";
	}

	vector <double> check = thuChiAm(thangX);
	if (check[0] == 1) {
		cout << "Chi tieu khong hop ly, am "<<check[1] << "trieu, => VO NO" << endl;
		return false;
	}
	else {
		double tienDu = tinhTienDu(thangX);
		if (tienDu < 0) {
			cout << "==>> Chi tieu khong vo no nhung chua hop ly, am "<<-tienDu<<" trieu" << endl;
		}
		else {
			cout << "==>>Chi tieu hop ly" << endl;
		}
		cout << "+ Tien du tru du: " << this->khoanDuTru[thangX - 1] << " trieu" << endl;
		cout << "+ Tien gui tiet kiem: " << this->tienGuiTietKiem[thangX - 1] << " trieu" << endl;
		return true;
	}
}

bool QLChiTieu::xuatvaDanhGiaThuChi_LaiNo(int thangX) {
	double check = this->tienGuiTietKiem[thangX - 1] - this->khoanNo[0]->layTienNoOThangThuX(thangX)
		- this->khoanNo[1]->layTienNoOThangThuX(thangX);
	if (check >= 0) {
		cout << "==>> Thu-chi can doi, tong tien gui tiet kiem - tong tien no trong thang =  " << check << " trieu" << endl;
		return true;
	}
	else {
		cout << "==>> Thu-chi chua can doi, am tien = " << -check << " trieu" << endl;
		return false;
	}
}

vector<double> QLChiTieu::traNoNamRuoi(int thangX) {
	double tongTienTK = 0;
	for (int i = 0; i < this->khoanTietKiem.size(); i++) {
		if (this->khoanTietKiem[i].kiemTraTinhTrang() == false) {
			tongTienTK += this->khoanTietKiem[i].layTienGui();
			this->khoanTietKiem[i].capNhatTinhTrang();
		}
	}
	double tongNo = this->khoanNo[0]->tinhTongNoSauXThang(thangX);
	double tienDu = tongTienTK + this->khoanDuTru[thangX - 2] + this->soTKGD[0] - tongNo;
	double checkTraNo=0;
	if (tienDu >= 0) {
		checkTraNo = 1;
	}
	else {
		checkTraNo = 0;
	}
	return {checkTraNo,tienDu};
}
vector<double> QLChiTieu::traNoBaNam(int thangX) {
	double tongTienTK = 0;
	for (int i = 0; i < this->khoanTietKiem.size(); i++) {
		if (this->khoanTietKiem[i].kiemTraTinhTrang() == false) {
			tongTienTK += this->khoanTietKiem[i].layTienGui();
			this->khoanTietKiem[i].capNhatTinhTrang();
		}
	}
	double tongNo = this->khoanNo[1]->tinhTongNoSauXThang(thangX);
	double tienDu = tongTienTK + this->khoanDuTru[thangX - 2] + this->soTKGD[1] - tongNo;
	double checkTraNo = 0;
	if (tienDu >= 0) {
		checkTraNo = 1;
	}
	else {
		checkTraNo = 0;
	}
	return { checkTraNo,tienDu };
}

bool QLChiTieu::tinhTrangTraNo(int soThang)
{
	vector<double> traNo;
	traNo.resize(2);
	bool check = true;
	if (soThang == 18) {
		traNo = this->traNoNamRuoi(soThang);
	}
	if (soThang == 36) {
		traNo = this->traNoBaNam(soThang);
	}
	if (traNo[0] == 0) {
		cout << "Khong the tra duoc no. VO NO!!!" << endl;
		cout << "Khoang tien bi am la: " << traNo[1] << " trieu" << endl;
		check = false;
	}
	else {
		if (soThang == 18) {
			cout << "TRA kKHOAN NO MOT NAM RUOI THANH CONG!!!" << endl;
		}
		if (soThang == 36) {
			cout << "TRA kKHOAN NO BA NAM THANH CONG!!!" << endl;
		}
		cout << "Khoang tien du la: " << traNo[1] << " trieu" << endl;
		check = true;
		return check;
	}
}

void QLChiTieu::duDoanTraNo() {
	QLChiTieu QL(this->khoanThuNhap, this->khoanChiTieu,
		this->khoanDuTru, this->tienGuiTietKiem,
		this->khoanTietKiem, this->khoanNo);

	int thangX = QL.khoanThuNhap.size();
	if (thangX >= 1) {
		ThuNhap thuNhapX(QL.khoanThuNhap[thangX - 1]);
		ChiTieu chiTieuX(QL.khoanChiTieu[thangX - 1]);

		for (int i = thangX; i < 36; i++) {
			QL.khoanThuNhap.push_back(thuNhapX);
			QL.khoanChiTieu.push_back(chiTieuX);

			//Tính toán dựa trên số tháng hiện tại
			QL.tinhTienDuTruVaTienGuiHangThang(QL.khoanThuNhap.size());
			QL.capNhatSoThangDaGuiCuaTKTietKiem();

			//Tính ngày gửi và mở sổ tiết kiệm
			int nam = 0;
			int thang = 0;
			int soThang = QL.khoanThuNhap.size();
			if (4 + soThang > 12) {
				if ((4 + soThang) % 12 == 0) {
					thang = 12;
				}
				else {
					thang = (4 + soThang) % 12;
				}
				nam = 2022 + ((4 + soThang) / 12);
			}
			else {
				thang = 4 + soThang;
				nam = 2022;
			}
			string ngayGui = "";
			if (thang < 10) {
				ngayGui = ngayGui + "28" + "/" + "0" + to_string(thang) + "/" + to_string(nam);
			}
			else {
				ngayGui = ngayGui + "28" + "/" + to_string(thang) + "/" + to_string(nam);
			}
			TKTietKiem tk(6, 0.06, QL.tienGuiTietKiem[QL.tienGuiTietKiem.size() - 1], 0, ngayGui);
			QL.khoanTietKiem.push_back(tk);

			//Cập nhật các tài khoản tiết kiệm
			bool checkTKTietKiemToiHan = false;
			vector<int>index;
			for (int i = 0; i < QL.khoanTietKiem.size(); i++) {
				if (QL.khoanTietKiem[i].laySoThangDaGui() == QL.khoanTietKiem[i].layKiHan() && QL.khoanTietKiem[i].kiemTraTinhTrang() == false) {
					checkTKTietKiemToiHan = true;
					index.push_back(i);
				}
			}
			if (checkTKTietKiemToiHan) {
				for (int i = 0; i < index.size(); i++) {
					QL.tienGuiTietKiem.push_back(QL.khoanTietKiem[index[i]].tattoanTKTietKiem());
					TKTietKiem tk(6, 0.06, QL.tienGuiTietKiem[QL.tienGuiTietKiem.size() - 1], 0, ngayGui);

					QL.khoanTietKiem.push_back(tk);
					QL.tienGuiTietKiem.pop_back();
					QL.khoanTietKiem[index[i]].capNhatTinhTrang();
				}
			}

			if (soThang == 18) {
				vector<double> traNo = QL.traNoNamRuoi(soThang);
				if (traNo[1] > 0) {
					cout << "CHUC MUNG BAN DA TRA DUOC NO 1.5 NAM" << endl;
					QL.tienGuiTietKiem.push_back(traNo[1]);
					cout << "Chon hinh thuc gui tiet kiem cho tien du" << endl;
					QL.moTKTietKiem();
					QL.tienGuiTietKiem.pop_back();
				}
				else {
					cout << "<<\\Neu cu tiep tuc chi-tieu nhu thang hien tai thi khong the tra no 1.5nam>>" << endl;
					return;
				}
			}
			else if (soThang == 36) {
				vector<double> traNo = QL.traNoBaNam(soThang);
				if (traNo[1] > 0) {
					cout << "CHUC MUNG BAN DA TRA DUOC NO 3 NAM" << endl;
					cout << "So tien du: " << traNo[1] << " trieu" << endl;
				}
				else {
					cout << "<<\\Neu cu tiep tuc chi-tieu nhu thang hien tai thi khong the tra no 3 nam>>" << endl;
					return;
				}
			}
		}
	}
	else {
		cout << "Chua co du lieu thang gan nhat" << endl;
	}
	

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
		cout << "=========================MENU==========================" << endl;
		cout << "* 1. Nhap thu chi                                     *" << endl;
		cout << "* 2. Danh gia thu chi thang thu x                     *" << endl;
		cout << "* 3. Danh gia thu chi thang thu x voi tong no thang do*" << endl;
		cout << "* 4. Xem danh sach so tiet kiem                       *" << endl;
		cout << "* 5. Xem thong tin cac khoan no                       *" << endl;
		cout << "* 6. Du doan tra no dua tren chi-tieu thang moi nhat  *" << endl;
		cout << "* 7. Ghi du lieu vao file .csv			               *" << endl;
		cout << "* 0. Thoat                                            *" << endl;
		cout << "=======================================================" << endl;
		cout << "Moi ban chon: ";
		cin >> choose;
		while (choose < 0 || choose>7) {
			cout << "Nhap lai lua chon: ";
			cin >> choose;
		}
		system("cls");
		if (choose == 1) {
			do {
				cout << "Nhap thu chi thang thu " << count << ":" << endl;
				count += 1;
				this->nhapThuChi();
				vector<double>check = this->thuChiAm(this->khoanThuNhap.size());
				if (check[0] == 1) {
					cout << endl;
					cout << "QUA TRINH THU CHI THANG NAY BI AM TIEN!!!" << endl;
					cout << "SO TIEN AM LA: " << -check[1] << " trieu" << endl;
					cout << "KHONG THE TRA DUOC NO. VO NO!!! (Bam phim bat ky de thoat chuong trinh)" << endl;
					choose = 0;
					system("pause");
					break;
				}
				this->tinhTienDuTruVaTienGuiHangThang(this->khoanThuNhap.size());
				this->capNhatSoThangDaGuiCuaTKTietKiem();
				this->moTKTietKiem();
				this->tatToanCacTKTietKiem();
				cout << endl;
				if (this->khoanThuNhap.size() == 18 || this->khoanThuNhap.size() == 36) {
					system("cls");
					cout << "Da toi han tra no " << this->khoanThuNhap.size() << " thang:" << endl;
					this->tinhTrangTraNo(this->khoanThuNhap.size());
					if (this->khoanThuNhap.size() == 18) {
						if (this->traNoNamRuoi(this->khoanThuNhap.size())[1] > 0) {
							cout << "Ban co muon gui tai khoan tiet kiem so tien du?" << endl;
							this->tienGuiTietKiem.push_back(this->traNoNamRuoi(this->khoanThuNhap.size())[1]);
							this->moTKTietKiem();
							this->tienGuiTietKiem.pop_back();
						}
					}
				}
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
			if (this->khoanThuNhap.size() >= 1) {
				int thangX;
				cout << "Nhap thang can xuat danh gia: ";
				cin >> thangX;
				while (thangX<1 || thangX>this->khoanThuNhap.size()) {
					cout << "Thang nhap khong hop le. Hien dang co thong tin cua " << this->khoanThuNhap.size() << " thang!" << endl;
					cout << "Nhap lai: ";
					cin >> thangX;
				}
				xuatvaDanhGiaThuChi(thangX);
				choose2 = 0;
			}
			else {
				cout << "Chua co du lieu thu-chi thang nao" << endl;
			}
		}
		if (choose == 3) {
			if (this->khoanThuNhap.size() >= 1) {
				int thangX;
				cout << "Nhap thang can xuat danh gia: ";
				cin >> thangX;
				while (thangX<1 || thangX>this->khoanThuNhap.size()) {
					cout << "Thang nhap khong hop le. Hien dang co thong tin cua " << this->khoanThuNhap.size() << " thang!" << endl;
					cout << "Nhap lai: ";
					cin >> thangX;
				}
				this->xuatvaDanhGiaThuChi_LaiNo(thangX);
				choose2 = 0;
			}
			else {
				cout << "Chua co du lieu thu-chi thang nao" << endl;
			}
		}
		if (choose == 4) {
			if (this->khoanTietKiem.size() > 0) {
				short count = 1;
				for (int i = 0; i < this->khoanTietKiem.size(); i++) {
					if (this->khoanTietKiem[i].laySoThangDaGui() != this->khoanTietKiem[i].layKiHan()) {
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
		if (choose == 5) {
			cout << "Khoan no 1.5 nam:" << endl;
			this->khoanNo[0]->xuatThongTinNo();
			cout << "================================" << endl;
			cout << "Khoan no 3 nam" << endl;
			this->khoanNo[1]->xuatThongTinNo();
			choose2 = 0;
		}
		else if (choose == 6) {
			this->duDoanTraNo();
			choose2 = 0;
		}
		else if (choose == 7) {
			char opt;
			bool check;
			if (count <= 36) {
				cout << "Du lieu chua du 36 thang, ban muon tiep thu ghi khong?" << endl;
				cout << "Chon Y(yes)/N(No) de chon: ";
				cin >> opt;
				if (opt == 'Y' || opt == 'y') {
					check = this->ghiFile();
					if (check) {
						cout << "Ghi thanh cong!" << endl;

					}
					else {
						cout << "Ghi that bai!" << endl;
					}
				}
			}
			else {
				check = this->ghiFile();
				if (check) {
					cout << "Ghi thanh cong!" << endl;
				}
				else {
					cout << "Ghi that bai!" << endl;
				}
			}
			choose2 = 0;
		}
		if (choose != 0 && choose2!=2) {
			system("pause");
			system("cls");
		}
	} while (choose != 0);
	system("cls");
	cout << "Cam on ban da su dung. Hen gap lai!!!" << endl;
}

bool QLChiTieu::ghiFileThuChi() {
	fstream fout("./resultFiles/ThuChi.csv", ios::out);
	if (fout.is_open() == false) {
		return false;
	}
	string heading = "THANG, ,THU NHAP, , ,CHI TIEU, , , ,DANH GIA, , , ";
	string subHeading = " ,Luong chong,Luong vo,TN khac,An uong,Dien nuoc, Chi tieu khac, ,Thu-Chi,Tong tien gui-Tong no trong thang, Tien du tru,Tien gui TK";

	fout << heading << endl;
	fout << subHeading << endl;
	int n = this->khoanThuNhap.size();
	for (int i = 0; i < n; i++) {
		int nam = 0;
		int thang = 0;
		int soThang = i + 1;
		string value = "";
		if (4 + soThang > 12) {
			if ((4 + soThang) % 12 == 0) {
				thang = 12;
			}
			else {
				thang = (4 + soThang) % 12;
			}
			nam = 2022 + ((4 + soThang) / 12);
		}
		else {
			thang = 4 + soThang;
			nam = 2022;
		}
		string ngayGui = "";
		if (thang < 10) {
			ngayGui += "0" + to_string(thang) + "/" + to_string(nam);
		}
		else {
			ngayGui += to_string(thang) + "/" + to_string(nam);
		}
		//--Thang/Luong Chong/Luong Vo/TN Khac/Dien,Nuoc/An, Uong/Chi tieu khac/ /Thu - Chi/Thu, Chi - Lai no/Du tru/ Tien gui TK
		double lChong = this->khoanThuNhap[i].layLuongChong();
		double lVo = this->khoanThuNhap[i].layLuongVo();
		double TNK = this->khoanThuNhap[i].layThuNhapKhac();

		double anUong = this->khoanChiTieu[i].layTienAnUong();
		double dienNuoc = this->khoanChiTieu[i].layTienDienNuoc();
		double chiTieuKhac = this->khoanChiTieu[i].layChiTieuKhac();

		double tienDu = this->tinhTienDu(i + 1);
		double tienDuLaiNo = this->tienGuiTietKiem[soThang - 1] - this->khoanNo[0]->layTienNoOThangThuX(soThang)
			- this->khoanNo[1]->layTienNoOThangThuX(soThang);

		value += ngayGui + "," + to_string(lChong) + "," + to_string(lVo) + "," + to_string(TNK)
			+ "," + to_string(anUong) + "," + to_string(dienNuoc) + "," + to_string(chiTieuKhac) + ", ,"
			+ (tienDu > 0 ? "Hop ly" : "Chua hop ly_am: " + to_string(tienDu)) + ","
			+ (tienDuLaiNo > 0 ? "Hop ly" : "Chua hop ly_am: " + to_string(tienDuLaiNo)) + ","
			+ to_string(this->khoanDuTru[soThang - 1]) + "," + to_string(this->tienGuiTietKiem[soThang - 1]);
		fout << value << endl;
	}
	fout.close();
	return true;
}
bool QLChiTieu::ghiFileTKTK()
{
	ofstream fout("./resultFiles/SoTietKiem.csv", ios::out);
	if (fout.is_open() == false) {
		return false;
	}
	fout << "TONG TIEN TIET KIEM GIA DINH NHAN DUOC:" << endl;
	fout << "Trong 18 thang dau: " << "," << this->soTKGD[0] << endl;
	fout << "Trong 18 thang sau: " << ", " << this->soTKGD[1] << endl;
	fout << endl;
	fout << "CAC KHOAN TIET KIEM:" << endl;
	fout << "," << "Ngay gui" << "," << "Ngay dao han" << "," << "So tien gui" << "," << "Lai suat(%/ki han)" << "," << "Ki han" << "," << "So thang da gui" << "," << "Tinh trang tat toan" << "," << "Tong tien nhan duoc" << endl;
	for (int i = 0; i < this->khoanTietKiem.size(); i++) {
		fout << "SO THU " << i + 1 << ": "<<",";
		this->khoanTietKiem[i].ghiFile(fout);
	}
	fout.close();
	return true;
}
bool QLChiTieu::ghiFileNo()
{
	ofstream fout("./resultFiles/TienNo.csv", ios::out);
	if (fout.is_open() == false) {
		return false;
	}
	this->khoanNo[0]->ghiFile(fout);
	this->khoanNo[1]->ghiFile(fout);
	fout.close();
	return true;
}

bool QLChiTieu::ghiFile()
{
	if (this->ghiFileThuChi() && this->ghiFileTKTK() && this->ghiFileNo()) {
		return true;
	}
	else {
		return false;
	}

}
