/*
 ID: yuanmax1
 PROG: fence6
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


using namespace std;

int N,numpoints = 0,arr[200][200],touching[101][101],len[101],n1[101],n2[101],paths[101][2],s,num,counter = 1,up = 0,done = 0,curr;
int an1[101][101];
int an2[101][101];
int LARGE = 99999999;

int minDist(int dist[],int visited[]) {
    int min = LARGE;
    int minV = 0;
    for (int i = 1; i < counter; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            minV = i;
        }
    }
    
    return minV;
}

int dijkstra(int src, int end) {
    int dist[counter];
    int visited[counter];
    for (int i = 1; i < counter; i++) {
        dist[i] = LARGE;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int i = 0; i < counter-1; i++) {
        int u = minDist(dist,visited);
        visited[u] = 1;
        for (int j = 1; j < counter; j++) {
            //cout << src << " " << u << " " << j << " " << visited[j] << " " << arr[u][j] << " " << dist[j] << endl;
            if (!visited[j] && arr[u][j] && dist[u] != LARGE && dist[u] + arr[u][j] < dist[j]) {
                dist[j] = dist[u] + arr[u][j];
                //cout << src << " " << u << " " << j << " " << dist[u] << " " << arr[u][j] << " " << dist[j] << endl;
            }
        }
    }
    /*cout << src << " ";
    for (int i = 0; i < 2*N; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;*/
    return dist[end];
}

int main() {
    ofstream fout ("fence6.out");
    ifstream fin ("fence6.in");
    int ans = LARGE;
    fin >> N;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            touching[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        fin >> s;
        fin >> len[s] >> n1[s] >> n2[s];
        up = 0;
        done = 0;
        for (int j = 0; j < n1[s]; j++) {
            fin >> an1[s][j];
        }
        for (int j = 0; j < n1[s]; j++) {
            //fin >> num;
            num = an1[s][j];
            if (!touching[s][num] && !done) {
                up = 1;
                touching[s][num] = counter;
                touching[num][s] = counter;
                for (int k = 0; k < n1[s]; k++) {
                    if (num!=k) touching[num][an1[s][k]] = counter;
                }
            }
            else if (touching[s][num]){
                up = 0;
                done = 1;
                paths[s][0] = touching[s][num];
            }
        }
        if (up && !done) {
            paths[s][0] = counter;
            counter++;
            //cout << s << " " << 1 << endl;
        }
        up = 0;
        done = 0;
        for (int j = 0; j < n2[s]; j++) {
            fin >> an2[s][j];
        }
        for (int j = 0; j < n2[s]; j++) {
            //fin >> num;
            num = an2[s][j];
            if (!touching[s][num]&&!done) {
                up = 1;
                touching[s][num] = counter;
                touching[num][s] = counter;
                for (int k = 0; k < n2[s]; k++) {
                    if (num!=k) touching[num][an2[s][k]] = counter;
                }
            }
            else if (touching[s][num]){
                up = 0;
                done = 1;
                if (touching[s][num] != 0) paths[s][1] = touching[s][num];
            }
        }
        if (up && !done) {
            paths[s][1] = counter;
            counter++;
            //cout << s << " " << 2 << endl;
        }
        arr[paths[s][0]][paths[s][1]] = len[s];
        arr[paths[s][1]][paths[s][0]] = len[s];
    }
    for (int i = 1; i < counter; i++) {
        for (int j = i+1; j < counter; j++) {
            if (arr[i][j]) {
                int temp = arr[i][j];
                arr[i][j] = 0;
                num = dijkstra(i,j)+temp;
                if (num < ans) ans = num;
                arr[i][j] = temp;
            }
        }
    }

    fout << ans << endl;
    
}
