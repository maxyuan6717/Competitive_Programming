/*
 ID: yuanmax1
 PROG: dualpal
 LANG: C++
 */
#include <fstream>
#include <algorithm>

using namespace std;

int N,S;

bool works(int B, int n) {
    string result = "",temp="";
    while (n) {
        int remainder = n%B;
        result += (char) (remainder+'0');
        n /= B;
    }
    string rev = result;
    reverse(result.begin(),result.end());
    return rev == result;
}

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    fin >> N >> S;
    for (int i = S + 1; N; i++) {
        int cnt = 0;
        for (int b = 2; b <= 10; b++) if (works(b,i)) cnt++;
        if (cnt >= 2) {
            fout << i << endl;
            N--;
        }
    }
    return 0;
}