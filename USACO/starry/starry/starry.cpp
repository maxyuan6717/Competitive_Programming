/*
 ID: yuanmax1
 PROG: starry
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

struct cluster {
    int tlcornery, tlcornerx;
    int t,b,l,r;
    int width,height;
    char key;
    int index;
};

int H,W;
int arr[100][100];
int temp[8][100][100];
char ans[100][100];
int ans2[100][100];
char current = 'a';
vector<cluster> clusters[100][100];
vector<cluster> c;
int counter = 0;

void init(int j) {
    c[counter].b = c[counter].t;
    c[counter].l = j;
    c[counter].r = c[counter].l;
    c[counter].key = ' ';
}

void flood(int i, int j) {
    if (i > c[counter].b) c[counter].b = i;
    if (j < c[counter].l) {
        c[counter].l = j;
        c[counter].tlcornerx = j;
    }
    if (j > c[counter].r) c[counter].r = j;
    ans2[i][j] = counter;
    if (i-1 >= 0 && arr[i-1][j] && ans2[i-1][j] != counter) flood(i-1,j);
    if (i-1 >= 0 && j-1 >= 0 && arr[i-1][j-1] && ans2[i-1][j-1] != counter) flood(i-1,j-1);
    if (i-1 >= 0 && j+1 < W && arr[i-1][j+1] && ans[i-1][j+1] != counter) flood(i-1,j+1);
    if (j-1 >= 0 && arr[i][j-1] && ans2[i][j-1] != counter) flood(i,j-1);
    if (j+1 < W && arr[i][j+1] && ans2[i][j+1] != counter) flood(i,j+1);
    if (i+1 < H && arr[i+1][j] && ans2[i+1][j] != counter) flood(i+1,j);
    if (i+1 < H && j-1 >= 0 && arr[i+1][j-1] && ans2[i+1][j-1] != counter) flood(i+1,j-1);
    if (i+1 < H && j+1 < W && arr[i+1][j+1] && ans2[i+1][j+1] != counter) flood(i+1,j+1);
}

int comp(int a,int k) {
    
    int w = c[a].width;
    int h = c[a].height;
    int x = c[a].tlcornerx;
    int y = c[a].tlcornery;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (temp[k][i][j] != arr[i+y][j+x] && (ans2[i+y][j+x] == c[a].index || ans2[i+y][j+x] == -1)) {
                return 0;
            }
        }
    }
    c[counter].key = c[a].key;
    return 1;
}

int unique() {
    if (clusters[c[counter].height][c[counter].width].empty() && clusters[c[counter].width][c[counter].height].empty()) return 1;
    int x = c[counter].tlcornerx;
    int y = c[counter].tlcornery;
    int w = c[counter].width;
    int h = c[counter].height;
    for (int k = 0; k < 8; k++) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                temp[k][i][j] = 0;
                temp[k][j][i] = 0;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (ans2[y+i][x+j] == counter) temp[0][i][j] = arr[y+i][x+j];
            if (ans2[y+(h-i-1)][x+j] == counter) temp[1][i][j] = arr[y+(h-i-1)][x+j];
            if (ans2[y+i][x+(w-j-1)] == counter) temp[2][i][j] = arr[y+i][x+(w-j-1)];
            if (ans2[y+(h-i-1)][x+(w-j-1)] == counter) temp[3][i][j] = arr[y+(h-i-1)][x+(w-j-1)];
            temp[4][j][i] = temp[0][i][j];
            temp[5][j][i] = temp[1][i][j];
            temp[6][j][i] = temp[2][i][j];
            temp[7][j][i] = temp[3][i][j];
        }
    }
    for (int i = 0; i < clusters[c[counter].height][c[counter].width].size(); i++) {
        int a = clusters[c[counter].height][c[counter].width][i].index;
        for (int j = 0; j < 4; j++) {
            if (comp(a,j)) return 0;
        }
    }
    for (int i = 0; i < clusters[c[counter].width][c[counter].height].size(); i++) {
        int a = clusters[c[counter].width][c[counter].height][i].index;
        for (int j = 4; j < 8; j++) {
            if (comp(a,j)) return 0;
        }
    }
    return 1;
}

void paint() {
    int w = c[counter].width;
    int h = c[counter].height;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (arr[i+c[counter].tlcornery][j+c[counter].tlcornerx] && ans2[i+c[counter].tlcornery][j+c[counter].tlcornerx] == counter) ans[i+c[counter].tlcornery][j+c[counter].tlcornerx] = c[counter].key;
        }
    }
}

int main() {
    ofstream fout ("starry.out");
    ifstream fin ("starry.in");
    fin >> W >> H;
    for (int i = 0; i < H; i++) {
        string s;
        fin >> s;
        for (int j = 0; j < W; j++) {
            arr[i][j] = s[j]-48;
            ans[i][j] = '0';
            ans2[i][j] = -1;
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (arr[i][j] && ans2[i][j] == -1) {
                c.push_back(cluster());
                c[counter].index = counter;
                c[counter].tlcornery = i;
                c[counter].tlcornerx = j;
                c[counter].t = i;
                init(j);
                flood(i,j);
                c[counter].width = c[counter].r-c[counter].l+1;
                c[counter].height = c[counter].b-c[counter].t+1;
                counter++;
                
            }
        }
    }
    int t = counter;
    for (counter = 0; counter < t; counter++) {
        int u = unique();
        if (u) {
            c[counter].key = current;
            current++;
            clusters[c[counter].height][c[counter].width].push_back(c[counter]);
        }
        paint();
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            //cout << ans[i][j];
            fout << ans[i][j];
        }
        //cout << endl;
        fout << endl;
    }
    
    
    return 0;
}