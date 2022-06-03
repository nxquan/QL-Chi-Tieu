#include "NoBaNam.h"

NoBaNam::NoBaNam()
{
	this->laiSuat = 0;
}

void NoBaNam::nhapLaiSuat()
{
	double lai;
	cout << "Nhap lai suat(%/nam): ";
	cin >> lai;
	this->laiSuat = lai / 100;
}
void NoBaNam::ganLaiSuat(vector<double> ls)
{
	return;
}
vector<double> NoBaNam::layLaiSuat() {
	return { this->laiSuat };
}
void NoBaNam::nhapKhoanNo()
{
	cout << "===========Nhap khoan no 3 nam===========" << endl;
	cin.ignore();
	cout << "Nhap thang muon: ";
	string thangMuon;
	getline(cin, thangMuon);
	if (thangMuon.length() < 2) {
		thangMuon = '0' + thangMuon;
	}
	cout << "Nhap nam muon: ";
	string namMuon;
	getline(cin, namMuon);
	while (namMuon.length() < 4) {
		cout << "Nam phai co dinh dang yyyy. Moi nhap lai: ";
		getline(cin, namMuon);
	}
	this->ngayMuonNo = this->ngayMuonNo + "01" + "/" + thangMuon + "/" + namMuon;
	cout << "Nhap so tien muon(Trieu VND): ";
	cin >> this->tienNoGoc;
	this->nhapLaiSuat();
}
void NoBaNam:: ghiFile(ostream& myfile)
{
	myfile << "TIEN NO 3 NAM\n";
	myfile << "Thang, Tien muon, Ngay muon, Ngay tra, Lai suat(%), Tien no trong thang, Tong lai sau x thang, Tong no sau x thang\n";
	myfile << "" << "," << this->layTienNoGoc() << "," << this->layNgayMuonNo() << "," << this->layNgayDaoHan() << "," << this->layLaiSuat().at(0)*100 << "," << "" << "," << "" << "," << "" << "\n";
	for (int i = 0; i < 36; i++)
	{
		myfile << i + 1 << "," << "" << "," << "" << "," << "" << "," << "" << "," << this->layTienNoOThangThuX(i + 1) << "," << this->laiNoSauXThang(i + 1) << "," << this->tinhTongNoSauXThang(i + 1) << "\n";
	}
}
double NoBaNam::layTienNoOThangThuX(int x)
{
	while (x <= 0 || x > 36) {
		cout << "Thang khong hop le, nhap lai: ";
		cin >> x;
	}
	return (this->tienNoGoc / 36)+(this->tienNoGoc / 36) * (this->laiSuat/12);
}

double NoBaNam::tinhTongNoSauXThang(int x)
{
	while (x < 0 || x > 36) {
		cout << "Thoi gian truyen vao khong hop le, nhap lai: ";
		cin >> x;
	}
	double laiSuatThang = this->laiSuat / 12;
	double tongNo = 0;
	for (int i = 0; i < x; i++) {
		tongNo += this->tienNoGoc * laiSuatThang;
	}
	tongNo += this->tienNoGoc;
	return tongNo;
}

double NoBaNam::laiNoSauXThang(int x)
{
	while (x < 0 || x>36) {
		cout << "Thoi gian truyen vao khong hop le, nhap lai: ";
		cin >> x;
	}
	return this->tinhTongNoSauXThang(x)-this->tienNoGoc;
}

void NoBaNam::xuatThongTinNo()
{
	cout << "Tien no goc: " << this->tienNoGoc << " trieu" << endl;
	cout << "Lai suat(%/nam): " << this->laiSuat * 100 << "%" << endl;
	cout << "Ngay muon: " << this->ngayMuonNo << endl;
	cout << "Tong no: " << this->tinhTongNoSauXThang(36) << " trieu vnd" << endl;
	cout << "Ngay dao han: " << this->layNgayDaoHan() << endl;
}

string NoBaNam::layNgayDaoHan()
{
	int thang = stoi(this->ngayMuonNo.substr(3, 2));
	int nam = stoi(this->ngayMuonNo.substr(6, 4));
	for (int i = 0; i < 35; i++) {
		thang += 1;
		if (thang > 12) {
			thang = 1;
			nam += 1;
		}
	}
	string ngayTra = to_string(30) + "/" + to_string(thang) + '/' + to_string(nam);
	if (ngayTra[5] != '/') {
		ngayTra.insert(3, "0");
	}
	return ngayTra;
}
