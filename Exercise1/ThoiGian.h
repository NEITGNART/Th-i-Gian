#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;

class ThoiGian
{
private:
	int second, minute, hour;

public:
	ThoiGian();
	ThoiGian(int s);
	void setSMH(int s);
	ThoiGian(int m, int s);
	ThoiGian(int h, int m, int s);
	ThoiGian operator+(ThoiGian x);
	ThoiGian operator+(int);
	friend ThoiGian operator+(int s, ThoiGian x);
	ThoiGian operator-(ThoiGian x);
	friend ThoiGian operator-(int s, ThoiGian x);
	bool operator <=(ThoiGian);
	friend bool operator <=(int, ThoiGian);
	friend ostream& operator<<(ostream& os, ThoiGian);

};

