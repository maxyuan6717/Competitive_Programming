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

struct group {
    set<int> s;
};

int N,G;
bool invited[1000001];
vector<group> groups;
//vector<int> ingroup[1000001];
map<int,vector<int> > m;
int total = 1;
vector<int> invite;
int curindex = 0;

int main() {
    ifstream fin ("invite.in");
    ofstream fout ("invite.out");
    fin >> N >> G;
    for (int i = 1; i <= N; i++) invited[i] = 0;
    for (int i = 0; i < G; i++) {
        int num;
        fin >> num;
        group g;
        for (int j = 0; j < num; j++) {
            int cow;
            fin >> cow;
            g.s.insert(cow);
            //ingroup[cow].push_back(i);
            m[cow].push_back(i);
        }
        groups.push_back(g);
    }
    invite.push_back(1);
    invited[1] = 1;
    while (curindex != invite.size()) {
        int curcow = invite[curindex];
        //cout << curcow << ":";
        curindex++;
        for (int i = 0; i < m[curcow].size(); i++) {
            //cout << " " << ingroup[curcow][i];
            groups[m[curcow][i]].s.erase(curcow);
            if (groups[m[curcow][i]].s.size() == 1) {
                int cow2 = *groups[m[curcow][i]].s.begin();
                if (!invited[cow2]) {
                    //cout << " " << cow2;
                    invited[cow2] = 1;
                    invite.push_back(cow2);
                }
            }
        }
     //  cout << endl;
    }
    fout << invite.size() << endl;

    return 0;
}