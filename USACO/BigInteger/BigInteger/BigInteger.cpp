/*
 ID: yuanmax1
 PROG: BigInteger
 LANG: C++
 */
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <bitset>
#include <iomanip>
#include <climits>

#define LARGE INT_MAX
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

class BigInt {
    vector<int> digits;
public:
    BigInt() {};
    BigInt(int a);
    void print();
    BigInt add(BigInt b);
    BigInt subtract(BigInt b);
};

BigInt::BigInt(int a) {
    while (a) {
        digits.push_back(a%10);
        a/=10;
    }
    reverse(digits.begin(),digits.end());
}

void BigInt::print() {
    for (int i = 0; i < digits.size(); i++) cout << digits[i];
    cout << endl;
}

BigInt BigInt::add(BigInt x) {
    BigInt ret;
    vector<int> a = digits;
    vector<int> b = x.digits;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int carry = 0;
    int i;
    for (i = 0; i < min(a.size(),b.size()); i++) {
        ret.digits.push_back((carry + a[i] + b[i])%10);
        carry = (carry+a[i]+b[i])/10;
    }
    if (a.size() > b.size()) {
        for (;i < a.size(); i++) {
            ret.digits.push_back((carry + a[i])%10);
            carry = (carry + a[i])/10;
        }
    }
    else {
        for (;i < b.size(); i++) {
            ret.digits.push_back((carry + b[i])%10);
            carry = (carry + b[i])/10;
        }
    }
    reverse (ret.digits.begin(),ret.digits.end());
    return ret;
}

int main() {
    BigInt a(123456789);
    BigInt res = a.add(a);
    res.print();
    return 0;
}