#include "md5.h"
#include <stdio.h>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
char res32[32];
char s_in[100], s_out[100];

int main() {
	setlocale(LC_ALL, "Russian");
	char retry = 'y';
	while (retry == 'y') {
		printf("Vivedite nazvanie fayla, ot kotoroqo xotite poluchit xesh: ");
		cin >> s_in;
		FILE * in = fopen(s_in, "rb");
		printf("Vivedite nazvanie fayla, kuda vi xotite napisat xesh summu: ");
		cin >> s_out;
		FILE * out = fopen(s_out, "w");
		string s = "";
		char c;
		while (fscanf(in, "%c", &c) != -1) {
			s += c;
		}
		md5hash(s.c_str(), s.length(), res32);
		fprintf(out, "%s", res32);
		cout << "xesh summa: " << res32 << ", Xotite prodoljit (Najmite y)?";
		cin >> retry;
	}
}