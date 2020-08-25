/*
ID: yuanmax1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool ifLeapYear(int x) {
	return ((x%4==0 && x%400 == 0) || (x%4 == 0 && x%100 != 0));
}
int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int days13[7] = {0,0,0,0,0,0,0};

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int numYears;
    fin >> numYears;
    int day = 2;
    
    for (int year = 1900; year < 1900 + numYears; year++) {
    	for (int month = 0; month < 12; month++) {
    		int numDays = monthDays[month];
    		if (month == 1 && ifLeapYear(year) == true) {
    			numDays += 1;
    		}
    		for (int i = 1; i<=numDays; i++) {
    			if (i == 13) {
    				days13[day]++;
    			}
    			day = (day + 1) % 7;
    		}
    	}
    }
    
    for (int i = 0; i < 6; i++) {
    	fout << days13[i] << " ";
    }
    fout << days13[6] << endl;
    
    return 0;
}