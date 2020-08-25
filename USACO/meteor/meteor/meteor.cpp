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

short int arr[302][302];
bool visited[302][302];
vector< int > possible;
int M;
int T = 0;

int bfs() {
    for (int i = 0; i < possible.size(); i++) {
        if (arr[possible[i]/302][possible[i]%302] == -1) {
            return T;
        }
    }
    T++;
    int s = int(possible.size());
    //cout << s << endl;
    for (int i = 0; i < s; i++) {
        int x = possible[i]%302;
        int y = possible[i]/302;
        if (y-1>=0 && (arr[y-1][x] > T || arr[y-1][x] == -1) && !visited[y-1][x]) {
            possible.push_back(302*(y-1)+x);
            visited[y-1][x] = 1;
        }
        if ((arr[y+1][x] > T || arr[y+1][x] == -1) && !visited[y+1][x]) {
            possible.push_back(302*(y+1)+x);
            visited[y+1][x] = 1;
        }
        if (x-1>=0 && (arr[y][x-1] > T || arr[y][x-1] == -1) && !visited[y][x-1]) {
            possible.push_back(302*y+x-1);
            visited[y][x-1] = 1;
        }
        if ((arr[y][x+1] > T || arr[y][x+1] == -1) && !visited[y][x+1]) {
            possible.push_back(302*y+x+1);
            visited[y][x+1] = 1;
        }
        
    }
    possible.erase(possible.begin(),possible.begin()+s);
    if (possible.empty()) return -1;
    return bfs();
}

int main() {
    cin >> M;
    for (int i = 0; i <= 301; i++) {
        for (int j = 0; j <= 301; j++) {
            arr[i][j] = -1;
            visited[i][j] = 0;
        }
    }
    int x,y,t;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> t;
        if (arr[y][x] == -1 || t < arr[y][x]) arr[y][x]=t;
        if (y-1>=0 && (arr[y-1][x] == -1 || t < arr[y-1][x])) arr[y-1][x] = t;
        if ((arr[y+1][x] == -1 || t < arr[y+1][x])) arr[y+1][x] = t;
        if (x-1>=0 && (arr[y][x-1] == -1 || t < arr[y][x-1])) arr[y][x-1] = t;
        if ((arr[y][x+1] == -1 || t < arr[y][x+1])) arr[y][x+1] = t;
        //cout << i << " " << x << " " << y << " " << arr[y][x] << endl;
    }
    possible.push_back(0);
    cout << bfs() << endl;
    
    return 0;
}