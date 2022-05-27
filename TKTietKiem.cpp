#include "TKTietKiem.h"

TKTietKiem::TKTietKiem()
{
	this->tienGui = 0;
	this->laiSuat = 0;
	this->kiHan = 0;
	this->soThangDaGui = 0;
	this->ngayGui = "chua biet";
}

TKTietKiem::TKTietKiem(int thoiHan, double laiSuat, double tienGui,int soThangDaGui,string ngayGui)
{
	this->kiHan = thoiHan;
	this->laiSuat = laiSuat;
	this->tienGui = tienGui;
	this->soThangDaGui = soThangDaGui;
	this->ngayGui = ngayGui;
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
	this->soThangDaGui += 1;
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

void TKTietKiem::xuatThongTin()
{
	cout << "Tien gui: " << this->tienGui << " trieu vnd" << endl;
	cout << "Ki han: " << this->kiHan << endl;
	cout << "Ngay gui: " << this->ngayGui << endl;
	cout << "So thang da gui: " << this->laySoThangDaGui() << endl;
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
	string ngayTra = to_string(ngay) + "/" + to_string(thang) + '/' + to_string(nam);
	if (ngayTra[2] != '/') {
		ngayTra = '0' + ngayTra;
	}
	if (ngayTra[5] != '/') {
		ngayTra.insert(3, "0");
	}
	cout << "Ngay dao han: " << ngayTra << endl;
	cout << "Tong tien sau khi tat toan: " << this->tattoanTKTietKiem() << " trieu vnd" << endl;
}

double TKTietKiem::tattoanTKTietKiem()
{
	return this->tienGui * this->laiSuat + this->tienGui;
}


TKTietKiem::~TKTietKiem(){

}
