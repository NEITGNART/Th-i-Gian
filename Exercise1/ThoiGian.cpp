#include "ThoiGian.h"
//            ThoiGian::

void setSMH1(int s, int &_hour, int &_minute, int &_second) {
	_hour = (s / 3600) % 24 % 24;
	_minute = (s % 3600) / 60;
	_second = (s % 3600) % 60;
}

void ThoiGian::setSMH(int s) {
	hour = ((s/3600)%24)% 24;
	minute = (s % 3600) / 60;
	second = (s % 3600) % 60;
}
ThoiGian::ThoiGian() {
	second = 0; minute = 0; hour = 0;
}
ThoiGian::ThoiGian(int s) {
	setSMH(abs(s));
}
ThoiGian::ThoiGian(int h, int m, int s) {
	setSMH(abs(h * 3600) + abs(m * 60) + abs(s));
}
ostream& operator<<(ostream& os, ThoiGian x) {
	string strH, strM, strS;
	strH = to_string(x.hour); strM = to_string(x.minute); strS = to_string(x.second);
	if (x.hour < 10) strH = "0" + strH;
	if (x.minute < 10) strM = "0" + strM;
	if (x.second < 10) strS = "0" + strS;
	os << strH << ":" << strM << ":" << strS;

	return os;
}

ThoiGian ThoiGian::operator+(ThoiGian x) {
	ThoiGian z;
	int total = abs((hour + x.hour)) * 3600 + abs((minute + x.minute)) * 60 + abs(second + x.second);
	setSMH1(total, z.hour, z.minute, z.second);
	return z;
}

ThoiGian ThoiGian::operator+(int x) {
	ThoiGian z;
	setSMH1(x, z.hour, z.minute, z.second);
	z = *this + z;
	return z;
}

ThoiGian operator+(int s, ThoiGian x) {
	ThoiGian z;
	int total = s+ abs( + x.hour) * 3600 + abs( + x.minute) * 60 + abs(x.second);
	setSMH1(total, z.hour, z.minute, z.second);
	return z;
}

ThoiGian::ThoiGian(int m, int s) {
	setSMH(abs(m) * 60 + abs(s));
}

ThoiGian ThoiGian::operator-(ThoiGian x) {
	ThoiGian z;
	int total = ( hour*3600 + minute*60 + second ) - ( x.hour*3600 +  x.minute*60+ x.second);
	setSMH1(abs(total), z.hour, z.minute, z.second);
	return z;
}

ThoiGian operator-(int s, ThoiGian x) {
	ThoiGian z;
	int total =   s - (x.hour * 3600 + x.minute * 60 + x.second) ;
	if (total > 0) {
		setSMH1(total, z.hour, z.minute, z.second);
	}
	return z;
}

bool ThoiGian::operator <=(ThoiGian x) {
	if (hour > x.hour) return false;
	if (minute > x.minute) return false;
	if (second > x.second) return false;
	return true;
}
bool operator <=(int x, ThoiGian t) {
	ThoiGian z;
	setSMH1(x, z.hour, z.minute, z.second);
	return z <= t;
}

