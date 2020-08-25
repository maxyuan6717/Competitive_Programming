/*
 ID: yuanmax1
 PROG: gift1
 LANG: C++
 */
#include <fstream>
#include <map>

using namespace std;

int N,amt,M;
map<string,int> balance;
string name[10],u,v;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    fin >> N;
    for (int i = 0; i < N; i++) fin >> name[i];
    while (fin >> u >> amt >> M)
        for (int i = 0; i < M; i++) {
            fin >> v;
            balance[v] += amt/M;
            balance[u] -= amt/M;
        }
    for (int i = 0; i < N; i++) fout << name[i] << " " << balance[name[i]] << endl;
    return 0;
}