#include "TKTietKiem.h"

TKTietKiem::TKTietKiem()
{
	this->tienGui = 0;
	this->laiSuat = 0;
	this->kiHan = 0;
	this->soThangDaGui = 0;
	this->ngayGui = "chua biet";
	this->daTatToan = false;
}

TKTietKiem::TKTietKiem(int thoiHan, double laiSuat, double tienGui,int soThangDaGui,string ngayGui)
{
	this->kiHan = thoiHan;
	this->laiSuat = laiSuat;
	this->tienGui = tienGui;
	this->soThangDaGui = soThangDaGui;
	this->ngayGui = ngayGui;
	this->daTatToan = false;
	int ngay = stoi(this->ngayGui.substr(0, 2));
	int thang = stoi(this->ngayGui.substr(3, 2));
	int nam = stoi(this->ngayGui.substr(6, 4));
	for (int i = 0; i < this->kiHan; i++) {
		thang += 1;
		if (thang > 12) {
			thang = 1;
			nam += 1;
		}
	}
	this->ngayDaoHan = to_string(ngay) + "/" + to_string(thang) + '/' + to_string(nam);
	if (this->ngayDaoHan[2] != '/') {
		this->ngayDaoHan = '0' + this->ngayDaoHan;
	}
	if (this->ngayDaoHan[5] != '/') {
		this->ngayDaoHan.insert(3, "0");
	}
}

void TKTietKiem::ganTienGui(double tienGui)
{
	this->tienGui = tienGui;
}
void TKTietKiem::ganLaiSuat(double laiSuat)
{
	this->laiSuat = laiSuat;
}

void TKTietKiem::capNhatSoThangDaGui()
{
	if (this->daTatToan==false) {
		this->soThangDaGui += 1;
	}
}

void TKTietKiem::capNhatTinhTrang()
{
	this->daTatToan = true;
}

bool TKTietKiem::kiemTraTinhTrang()
{
	return this->daTatToan;
}

double TKTietKiem::layTienGui()
{
	return this->tienGui;
}
int TKTietKiem::layKiHan()
{
	return this->kiHan;
}

int TKTietKiem::laySoThangDaGui()
{
	return this->soThangDaGui;
}

string TKTietKiem::layNgayGui()
{
	return this->ngayGui;
}

void TKTietKiem::xuatThongTin()
{
	cout << "Tien gui: " << this->tienGui << " trieu vnd" << endl;
	cout << "Ki han: " << this->kiHan << endl;
	cout << "Ngay gui: " << this->ngayGui << endl;
	cout << "So thang da gui: " << this->laySoThangDaGui() << endl;
	cout << "Ngay dao han: " << this->ngayDaoHan << endl;
	cout << "Tong tien sau khi tat toan: " << this->tattoanTKTietKiem() << " trieu" << endl;
}

void TKTietKiem::ghiFile(ostream& os)
{
	double tien = 0;
	if (this->daTatToan = true) {
		tien = this->tattoanTKTietKiem();
	}
	else {
		tien = this->tienGui;
	}
	os << this->ngayGui << "," << this->ngayDaoHan << "," << this->tienGui << "," << this->laiSuat*100 << "," << this->kiHan << "," << this->soThangDaGui << "," << tien << endl;
}

double TKTietKiem::tattoanTKTietKiem()
{
	return this->tienGui * this->laiSuat + this->tienGui;
}


TKTietKiem::~TKTietKiem(){

}
