#ifndef TienNo_h
#define TienNo_h
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class TienNo
{
protected:
	double tienNoGoc;
	string ngayMuonNo;
public:
	TienNo();
	
	void ganTienNoGoc(double);
	void ganNgayMuonNo(string);

	double layTienNoGoc();
	string layNgayMuonNo();

	virtual void nhapLaiSuat() = 0;
	virtual void ganLaiSuat(vector<double>) = 0;
	virtual vector<double> layLaiSuat() = 0;

	virtual void nhapKhoanNo() = 0;

	virtual double layTienNoOThangThuX(int) = 0;
	virtual double tinhTongNoSauXThang(int) = 0;
	virtual double laiNoSauXThang(int) = 0;
	virtual void xuatThongTinNo() = 0;
	virtual string layNgayDaoHan() = 0;

	virtual void ghiFile(ostream&) = 0;
};
#endif // !TienNo_h



