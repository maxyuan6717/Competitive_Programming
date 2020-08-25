#include <iostream>
#include <cmath>
using namespace std;
char getC(string s) { int sum = 0; for (int i = 6; i >= 3; i--) {if (s[8-i] == 'o') sum += pow(2,i);} for (int i = 2; i >= 0; i--) {if (s[9-i] == 'o') sum += pow(2,i);} return sum;}
int main() {
	string s;
	getline(cin,s);
	while (getline(cin,s)) {
		if (s == "___________") break;
		cout << getC(s);
	}
    return 0;
}
