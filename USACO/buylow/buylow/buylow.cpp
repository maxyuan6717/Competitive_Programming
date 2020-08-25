/*
 ID: yuanmax1
 PROG: buylow
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <utility>
#define LARGE 9999999

using namespace std;

int N,dp[5000],arr[5000],ans = 0;
string ans2 = "";
string counter[5000];

string add(string s1, string s2) {
    int si1 = s1.size() - 1;
    int si2 = s2.size() - 1;
    string s3(max(si1+1,si2+1), '0');
    int si3 = s3.size() - 1;
    int carry = 0;
    int sum = 0;
    while (si1 >= 0 && si2 >= 0) {
        sum = carry+(s1[si1]-'0')+(s2[si2]-'0');
        s3[si3] = (sum%10)+'0';
        carry = sum/10;
        si1--;
        si2--;
        si3--;
    }
    while (si1 >= 0) {
        sum = carry + (s1[si1]-'0');
        s3[si3] = (sum%10)+'0';
        carry = sum/10;
        si1--;
        si3--;
    }
    while (si2 >= 0) {
        sum = carry + (s2[si2]-'0');
        s3[si3] = (sum%10)+'0';
        carry = sum/10;
        si2--;
        si3--;
    }
    if (carry) s3 = "1" + s3;
    
    return s3;
}

int main() {
    
    ofstream fout ("buylow.out");
    ifstream fin ("buylow.in");
    fin >> N;
    if (N == 1) {
        ans = 1;
        ans2 = "1";
        cout << ans << " " << ans2 << endl;
        fout << ans << " " << ans2 << endl;
    }
    else {
        for (int i = 0; i < N; i++) {
            fin >> arr[i];
        }
        for (int i = 0; i < N; i++) {
            dp[i] = 0;
            counter[i] = "1";
        }
        dp[0] = 1;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[i] && dp[j] >= dp[i]) {
                    dp[i] = dp[j];
                }
            }
            dp[i]++;
            if (dp[i] > ans) {
                ans = dp[i];
            }
        }
        
        for (int i = 1; i < N; i++) {
            if (dp[i] != 1) counter[i] = "0";
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[i] && dp[j] + 1 == dp[i]) {
                    counter[i] = add(counter[i],counter[j]);
                }
                if (arr[j] == arr[i] && dp[j] < dp[i]) counter[j] = "0";
                else if (arr[j] == arr[i] && dp[j] == dp[i]) counter[i] = "0";
            }
        }
        for (int i = 0; i < N; i++) {
            if (dp[i] == ans) {
                ans2 = add(ans2,counter[i]);
            }
        }
        cout << ans << " " << ans2 << endl;
        fout << ans << " " << ans2 << endl;
    }
    return 0;
}