#include "Date.h"

Date::Date() {
	this->ngay = 0;
	this->thang = 0;
	this->nam = 0;
}
Date::Date(unsigned int ngay, unsigned int thang, unsigned int nam) {
	this->ngay = ngay;
	this->thang = thang;
	this->nam = nam;
}

Date::~Date() {

}

//setter
void Date::ganNgay(unsigned int ngay) {
	this->ngay = ngay;
}

void Date::ganThang(unsigned int thang) {
	this->thang = thang;	
}

void Date::ganNam(unsigned int nam) {
	this->nam = nam;
}

//getter
unsigned int Date::layNgay() {
	return this->ngay;
}

unsigned int Date::layThang() {
	return this->thang;
}

unsigned int Date::layNam() {
	return this->nam;
}

Date& Date::tangThemThang(int n) {
	this->thang += n;
	if (this->thang > 12) {
		this->thang -= 12;
		++this->nam;
	}
	return *this;
}

void Date::operator=(Date& d) {
	this->ngay = d.ngay;
	this->thang = d.thang;
	this->nam = d.nam;
}
bool Date::operator==(Date& d) {
	return (this->ngay == d.ngay) && (this->thang == d.thang) && (this->nam == d.nam);
}

istream& operator >> (istream& in, Date& d) {
	cout << "Ngay: ";
	in >> d.ngay;
	cout << "Thang: ";
	in >> d.thang;
	cout << "Nam: ";
	in >> d.nam;
	return in;
 }

ostream& operator << (ostream& out, Date &d) {
	if (log10(d.ngay) < 1) {
		out << '0' << d.ngay << "/";
	}
	else {
		out << d.ngay << "/";
	}
	if (log10(d.thang) < 1) {
		out << '0' << d.thang << "/";
	}
	else {
		out <<d.thang << "/";
	}
	out << d.nam;
	return out;
}