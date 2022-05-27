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
public:
	QLChiTieu();
	~QLChiTieu();

	//Nhập các khoản nợ
	void nhapKhoanNo();
	//Nhập thu chi từng tháng
	void nhapThuChi();

	//Kiểm tra tháng đó có thu chi âm không?
	vector<double> thuChiAm(int thangX);

	void tinhTienDuTruVaTienGuiHangThang(int thangX);

	void moTKTietKiem();
	//Cập nhật các STK bao gồm số tháng gửi, tất toán STK ...
	void capNhatSoThangDaGuiCuaTKTietKiem();
	void tatToanCacTKTietKiem();

	//Xuất đánh giá thu chi
	bool xuatvaDanhGiaThuChi(int thangX);
	
	double tinhTongTienTKSauXThang(int thangX);

	double traNoNamRuoi(int thangX);
	double traNoBaNam(int thangX);
	//Hàm tổng hợp các xử lý của QLChiTieu
	void xuLyQLChiTieu();
};

#endif // !QLChiTieu_h
