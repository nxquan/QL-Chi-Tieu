#define ThuNhap_h
#include<iostream>
using namespace std;

class ThuNhap
{
private:
	double luong;
	double thuNhapKhac;
public:
	ThuNhap();
	void nhapLuong();
	void nhapThuNhapKhac();
	double layLuong();
	double layThuNhapKhac();
	~ThuNhap();
};
#endif // !ThuNhap_h
