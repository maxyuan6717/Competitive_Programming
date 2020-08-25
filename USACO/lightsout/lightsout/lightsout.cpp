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

#define LARGE 999999999

using namespace std;

struct corner {
    long x,y;
};

int N;
vector<corner> barn;
int dist[201];
int clwise[201];
int cowise[201];
bool angle[201];
map<vector<int>,int> m;

int finddist(corner a, corner b) {
    return (abs(a.x-b.x)+abs(a.y-b.y));
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        corner c;
        cin >> c.x >> c.y;
        barn.push_back(c);
        dist[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        dist[i] = finddist(barn[i],barn[(i+1)%N]);
        //cout << dist[i] << " ";
    }
    //cout << endl;
    clwise[N-1] = dist[N-1];
    cowise[1] = dist[0];
    for (int i = N-2; i> 0; i--) {
        clwise[i] = clwise[i+1] + dist[i];
        //cout << clwise[i+1] << endl;
    }
    for (int i = 2; i < N; i++) {
        cowise[i] = cowise[i-1] + dist[i-1];
    }
    /*for (int i = 0; i < N; i++) cout << clwise[i] << " ";
    cout << endl;
    for (int i = 0; i < N; i++) cout << cowise[i] << " ";
    cout << endl;*/
    for (int i = 0; i < N; i++) {
        int j = (i+1)%N;
        int h = (i-1+N)%N;
        //cout << v1x << " " << v1y << " "<< v2x << " " << v2y << endl;
        angle[i] = (((barn[i].x-barn[h].x)*(barn[i].y-barn[j].y))-((barn[i].x-barn[j].x)*(barn[i].y-barn[h].y))) > 0;
        //cout << angle[i] << endl;
    }
    int ans = 0;
    for (int i = 1; i < N; i++) {
        if (clwise[i] <= cowise[i]) break;
        for (int j = 1; j < N; j++) {
            if (i!=j) {
                int total = 0;
                int tempi = i;
                int tempj = j;
                while (tempi < N && tempj < N) {
                    if (angle[tempi] != angle[tempj]) break;
                    total += dist[tempi];
                    //cout << dist[tempi] << " " << dist[tempj] << endl;
                    if (dist[tempi] != dist[tempj]) {
                        tempi++;
                        tempj++;
                        break;
                    }
                    tempi++;
                    tempj++;
                }
                //cout << total << " ";
                total += min(clwise[tempi%N],cowise[tempi%N]);
                //cout << total << " " << clwise[i] << endl;
                //cout << i << " " << total << " " << clwise[i] << endl;
                //cout << total << endl;
                ans = max(ans,total-min(clwise[i],cowise[i]));
            }
        }
    }
    
    
    cout << ans << endl;
    return 0;
}