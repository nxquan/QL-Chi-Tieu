#ifndef QLChiTieu_h
#define QLChiTieu_h
#include "ThuNhap.h"
#include "ChiTieu.h"
#include "TKTietKiem.h"
#include "TienNo.h"
#include "NoNamRuoi.h"
#include "NoBaNam.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class QLChiTieu
{
private:
	vector <ThuNhap> khoanThuNhap;
	vector <ChiTieu> khoanChiTieu;
	vector <double> khoanDuTru;
	vector <double> tienGuiTietKiem;
	vector <TKTietKiem> khoanTietKiem;
	vector <TienNo*> khoanNo;
	double soTKGD[2];
public:
	QLChiTieu();
	QLChiTieu(vector<ThuNhap>, vector<ChiTieu>, vector<double>, vector<double>, vector<TKTietKiem>, vector<TienNo*>);
	~QLChiTieu();

	//Nhập các khoản nợ
	void nhapKhoanNo();
	//Nhập thu chi từng tháng
	void nhapThuChi();

	//Kiểm tra tháng đó có thu chi âm không?
	vector<double> thuChiAm(int thangX);
	double tinhTienDu(int thangX);
	void tinhTienDuTruVaTienGuiHangThang(int thangX);

	void moTKTietKiem();
	//Cập nhật các STK bao gồm số tháng gửi, tất toán STK ...
	void capNhatSoThangDaGuiCuaTKTietKiem();
	void tatToanCacTKTietKiem();

	//Xuất đánh giá thu chi
	bool xuatvaDanhGiaThuChi(int thangX);
	bool xuatvaDanhGiaThuChi_LaiNo(int thangX);

	vector<double> traNoNamRuoi(int thangX);
	vector<double> traNoBaNam(int thangX);
	bool tinhTrangTraNo(int);

	void duDoanTraNo();
	//Hàm tổng hợp các xử lý của QLChiTieu

	bool ghiFileThuChi();
	bool ghiFileTKTK();
	bool ghiFileNo();
	bool ghiFile();

	void xuLyQLChiTieu();

};

#endif // !QLChiTieu_h
