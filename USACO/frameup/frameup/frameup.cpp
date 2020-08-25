/*
 ID: yuanmax1
 PROG: frameup
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

int H,W;
int fsize;
char arr[30][30];
int dag[26][26];
int visited[26];
int indeg[26];
vector<char> result;
vector<string> ans;
vector<char> framekeys;

struct frame {
    pair<int,int> tl,bl,tr,br;
    int t,b,l,r;
    int exists = 0;
} frames[26];

void init(int i, int j) {
    int index = arr[i][j]-65;
    frames[index].exists = 1;
    framekeys.push_back(arr[i][j]);
    frames[index].t = i;
    frames[index].b = i;
    frames[index].r = j;
    frames[index].l = j;
}

void update(int i, int j) {
    int index = arr[i][j] - 65;
    frames[index].t = min(frames[index].t,i);
    frames[index].b = max(frames[index].b,i);
    frames[index].l = min(frames[index].l,j);
    frames[index].r = max(frames[index].r,j);
    frames[index].tl = make_pair(frames[index].t,frames[index].l);
    frames[index].bl = make_pair(frames[index].b,frames[index].l);
    frames[index].tr = make_pair(frames[index].t,frames[index].r);
    frames[index].br = make_pair(frames[index].b,frames[index].r);
}

int infront(int i, int j) {
    char c1 = framekeys[i];
    char c2 = framekeys[j];
    int i1 = c1-65;
    int i2 = c2-65;
    if (frames[i1].t > frames[i2].b || frames[i1].b < frames[i2].t || frames[i1].l > frames[i2].r || frames[i1].r < frames[i2].l) return 2;
    for (int a = frames[i2].l; a <= frames[i2].r; a++) {
        if (arr[frames[i2].t][a] == c1) return 1;
        if (arr[frames[i2].b][a] == c1) return 1;
    }
    for (int a = frames[i2].t; a <= frames[i2].b; a++) {
        if (arr[a][frames[i2].l] == c1) return 1;
        if (arr[a][frames[i2].r] == c1) return 1;
    }
    
    return 0;
}

void topsort() {
    int done = 0;
    for (int i = 0; i < fsize; i++) {
        int index = framekeys[i]-65;
        if (indeg[index] == 0 && !visited[index]) {
            //cout << framekeys[i] << endl;
            for (int j = 0; j < 26; j++) {
                if (dag[index][j]) indeg[j]--;
            }
            result.push_back(framekeys[i]);
            visited[index] = 1;
            topsort();
            visited[index] = 0;
            result.erase(result.end()-1);
            for (int j = 0; j < 26; j++) {
                if (dag[index][j]) indeg[j]++;
            }
            done = 1;
        }
    }
    if (!done) {
        string str;
        for (int i = 0; i < result.size(); i++) str += result[i];
        ans.push_back(str);
    }
}

int main() {
    ofstream fout ("frameup.out");
    ifstream fin ("frameup.in");
    fin >> H >> W;
    string s;
    for (int i = 0; i < 26; i++) {
        visited[i] = 0;
        indeg[i] = 0;
        for (int j = 0; j < 26; j++) {
            dag[i][j] = 0;
        }
    }
    for (int i = 0; i < H; i++) {
        fin >> s;
        for (int j = 0; j < W; j++) {
            arr[i][j] = s[j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (arr[i][j] != '.' && frames[arr[i][j]-65].exists == 0) {
                init(i,j);
            }
            else if (arr[i][j] != '.' && frames[arr[i][j]-65].exists) {
                update(i,j);
            }
        }
    }
    fsize = int(framekeys.size());
    for (int i = 0; i < fsize; i++) cout << framekeys[i] << " ";
    cout << endl;
    for (int i = 0; i < fsize; i++) {
        for (int j = 0; j < fsize; j++) {
            if (i == j) continue;
            int i1 = framekeys[i]-65;
            int i2 = framekeys[j]-65;
            int num = infront(i,j);
            if (num == 1) {
                dag[i2][i1] = 1;
                indeg[i1]++;
            }
        }
    }
    topsort();
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i] << endl;
        //cout << ans[i] << endl;
    }
    
    
    
    return 0;
}