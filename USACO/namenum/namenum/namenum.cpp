/*
 ID: yuanmax1
 PROG: namenum
 LANG: C++
 */
#include <fstream>
using namespace std;
string targ,cur;
char key[100];
int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream dict("dict.txt");
    fin >> targ;
    int curKey = '2',cnter = 0;
    for (char c = 'A'; c <= 'Y'; c++) {
        if (c == 'Q') continue;
        key[c] = (char) curKey;
        if (cnter++ == 2) { curKey++; cnter = 0; }
    }
    bool works = 0;
    while (dict >> cur) {
        string id = "";
        for (int i = 0; i < cur.size(); i++) id += key[cur[i]];
        if (id == targ) { fout << cur << endl;works=1; }
    }
    if (!works) fout << "NONE" << endl;
    return 0;
}