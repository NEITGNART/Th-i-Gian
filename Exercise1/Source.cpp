#include "ThoiGian.h"

int main(void) {
	ThoiGian tg1; //00:00:00
	ThoiGian tg2(1212); //00:20:12
	ThoiGian tg3(125, 45); //02:05:45
	ThoiGian tg4(12, 239, -78); //16:00:18
	ThoiGian tg5 = tg2 + tg3; //02:25:57
	ThoiGian tg6 = 5000 + tg2; //01:43:32
	ThoiGian tg7 = tg4 - tg6; //14:16:46
	ThoiGian tg8 = 12300 - tg4; //00:00:00
	ThoiGian tg9, tg10;
	if (tg8 <= tg3)
	{
		tg9 = tg1 + tg2 + 36000; //10:20:12
	}
	if ( (12345 <= tg5)) // conditions fail cuz 12345 > tg5
	{
		tg10 = tg5 + 12345; //05:51:42
	}
	cout << tg1 << endl << tg2 << endl << tg3 << endl << tg4 << endl;
	cout << tg5 << endl << tg6 << endl << tg7 << endl << tg8 << endl;
	cout << tg9 << endl << tg10 << endl;
	return 0;
}