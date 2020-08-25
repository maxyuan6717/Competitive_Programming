/*
 ID: yuanmax1
 PROG: lgame
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

string s;
vector<string> dictionary;
vector<string> allowed;
vector<string> answers;
int numans = 0;
int ans = 0;
int used[26];
int score[26] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
unsigned long int dsize;
unsigned long int allowedNum;
void reset() {
    for (int i = 0; i < 25; i++) {
        used[i] = 0;
    }
    for (int i = 0; i < s.size(); i++) {
        used[s[i]-97]++;
    }
}

int val(char c) {
    return score[c-97];
}

int calc(string str) {
    int sum = 0;
    reset();
    for (int i = 0; i < str.size(); i++) {
        if (used[str[i]-97]) {
            sum += val(str[i]);
            used[str[i]-97]--;
        }
        else {
            return 0;
        }
    }
    return sum;
}

int main() {
    ofstream fout ("lgame.out");
    ifstream fin ("lgame.in");
    ifstream din ("lgame.dict");
    fin >> s;
    int done = 0;
    while (!done) {
        string input;
        din >> input;
        if (input != ".") dictionary.push_back(input);
        else done = 1;
    }
    dsize = dictionary.size();
    if (dsize == 1) {
        int num = calc(dictionary[0]);
        cout << num << endl;
        if (num == 0) return 0;
        else {
            cout << dictionary[0] << endl;\
            return 0;
        }
    }
    for (int i = 0; i < dsize; i++) {
        int num = calc(dictionary[i]);
        if (num != 0) {
            allowed.push_back(dictionary[i]);
        }
        if (num > ans) {
            ans = num;
            answers.clear();
            numans = 0;
            answers.push_back(dictionary[i]);
            numans++;
        }
        else if (num == ans)  {
            answers.push_back(dictionary[i]);
            numans++;
        }
    }
    allowedNum = allowed.size();
    for (int i = 0; i < allowedNum-1; i++) {
        for (int j = i+1; j < allowedNum; j++) {
            string temp = allowed[i] + allowed[j];
            int num = calc(temp);
            if (num != 0 && num > ans) {
                ans = num;
                answers.clear();
                numans = 0;
                answers.push_back(allowed[i] + " " + allowed[j]);
                numans++;
            }
            else if (num != 0 && num == ans) {
                answers.push_back(allowed[i] + " " + allowed[j]);
                numans++;
            }
        }
    }
    sort(answers.begin(),answers.end());
    //cout << ans << endl;
    fout << ans << endl;
    for (int i = 0; i < numans; i++) {
        //cout << answers[i] << endl;
        fout << answers[i] << endl;
    }
    return 0;
}