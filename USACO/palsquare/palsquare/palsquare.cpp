/*
 ID: yuanmax1
 PROG: palsquare
 LANG: C++
 */
#include <fstream>
#include <algorithm>

using namespace std;

string baseConverter(int B, int N) {
    string result = "",temp="";
    while (N) {
        int remainder = N%B;
        if (remainder >= 10) result += (char) (remainder-10+'A');
        else result += (char) (remainder+'0');
        N /= B;
    }
    reverse(result.begin(),result.end());
    return result;
}

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int B;
    fin >> B;
    for (int N = 1; N <= 300; N++) {
        string newNum = baseConverter(B,N);
        string square = baseConverter(B,N*N);
        string squareRev = square;
        reverse(squareRev.begin(),squareRev.end());
        if (square == squareRev) fout << newNum << " " << square << endl;
    }
    return 0;
}