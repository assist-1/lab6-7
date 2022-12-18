#include <iostream>
#include <string>
using std::to_string;

int checkdata(int yearr, int monthh, int dayy) {
	if (yearr <= 0 || (to_string(yearr).size()) < 4) { return 0; }
	else {
		if (monthh < 0 || monthh > 12) { return 0; }
		else {
			if ((monthh == 1 || monthh == 3 || monthh == 5 || monthh == 7 || monthh == 8 || monthh == 10 || monthh == 12) && dayy > 0 && dayy <= 31) {
				return 1;
			}
			else if ((monthh == 4 || monthh == 6 || monthh == 9 || monthh == 11) && dayy > 0 && dayy <= 30) {
				return 1;
			}
			else if (monthh == 2 && dayy > 0 && dayy <= 29) {
				int a = yearr % 10;
				int b = (yearr / 10) % 10;
				if ((a == b) && (a == 0) && (yearr % 400 == 0) && (dayy <= 29)) {
					return 1;
				}
				else if ((a != b) && (yearr % 4 == 0) && (dayy <= 29)) {
					return 1;
				}
				else if ((((a != b) && (yearr % 4 != 0)) || ((a == b) && (a == 0) && (yearr % 400 != 0))) && (dayy <= 28)) {
					return 1;
				}
				else {
					return 0;
				}
			}
		}
	}
	return 0;
}
