#include "NoNamRuoi.h"
#include<fstream>

NoNamRuoi::NoNamRuoi()
{
	this->laiSuat.resize(18);
	for (int i = 0; i < this->laiSuat.size(); i++) {
		this->laiSuat[i] = 0;
	}
}

void NoNamRuoi::nhapLaiSuat()
{
	for (int i = 0; i < this->laiSuat.size(); i++) {
		cout << "Nhap lai suat thang thu " << i + 1 << "(%): ";
		cin >> this->laiSuat[i];
		this->laiSuat[i] /= 100;
	}
}
void NoNamRuoi::ganLaiSuat(vector<double> ls)
{
	for (int i = 0; i < ls.size(); i++) {
		this->laiSuat[i] = ls[i];
	}
}
vector<double> NoNamRuoi::layLaiSuat() {
	return this->laiSuat;
}
void NoNamRuoi::nhapKhoanNo()
{
	cout << "===========Nhap khoan no 1.5 nam==========" << endl;
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

void NoNamRuoi::ghiFile(ostream& myfile) {
	myfile << "TIEN NO 1.5 NAM\n";
	myfile << "Thang, Tien muon, Ngay muon, Ngay tra, Lai xuat, Tien no trong thang, Tong lai no sau x thang, Tong no sau x thang\n";
	myfile << "" << "," << this->layTienNoGoc() << "," << this->layNgayMuonNo() << "," << this->layNgayDaoHan() << "," << "" << "," << "" << "," << "" << "," << "" << "\n";
	for (int i = 0; i < this->laiSuat.size(); i++)
	{
		myfile << i + 1 << "," << "" << "," << "" << "," << "" << "," << this->layLaiSuat().at(i) << "," << this->layTienNoOThangThuX(i+1) << "," << this->laiNoSauXThang(i+1) << "," << this->tinhTongNoSauXThang(i+1) << "\n";

	}
	myfile << endl;
}

double NoNamRuoi::layTienNoOThangThuX(int x)
{
	while (x <= 0 || x > 18) {
		cout << "Thang khong hop le, nhap lai: ";
		cin >> x;
	}
	return (this->tienNoGoc/18)+(this->tienNoGoc / 18) * this->laiSuat[x - 1];
}

double NoNamRuoi::tinhTongNoSauXThang(int x)
{
	while (x < 0 || x>18) {
		cout << "Thoi gian truyen vao khong hop le, nhap lai: ";
		cin >> x;
	}
	double tongNo = 0;
	for (int i = 0; i < x; i++) {
		tongNo += this->tienNoGoc * this->laiSuat[i];
	}
	tongNo += this->tienNoGoc;
	return tongNo;
}

double NoNamRuoi::laiNoSauXThang(int x)
{
	while (x < 0 || x>18) {
		cout << "Thoi gian truyen vao khong hop le, nhap lai: ";
		cin >> x;
	}
	return this->tinhTongNoSauXThang(x) - this->tienNoGoc;
}

void NoNamRuoi::xuatThongTinNo()
{
	cout << "Tien no goc: " << this->tienNoGoc << " trieu" << endl;
	cout << "Lai suat "<<this->laiSuat.size()<<" thang lan luot la : " << endl;
	for (int i = 0; i < this->laiSuat.size(); i++) {
		cout << "Thang " << i + 1 << ": " << this->laiSuat[i]*100 << "%" << endl;
	}
	cout << "Ngay muon: " << this->ngayMuonNo << endl;
	cout << "Tong no: " << this->tinhTongNoSauXThang(18) << " trieu vnd" << endl;
	cout << "Ngay dao han: " << this->layNgayDaoHan() << endl;
}

string NoNamRuoi::layNgayDaoHan()
{
	int thang = stoi(this->ngayMuonNo.substr(3, 2));
	int nam = stoi(this->ngayMuonNo.substr(6, 4));
	for (int i = 0; i < 17; i++) {
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
