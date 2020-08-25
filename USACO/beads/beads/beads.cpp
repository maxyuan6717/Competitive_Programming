/*
 ID: yuanmax1
 PROG: beads
 LANG: C++
 */
#include <fstream>
#include <string>

using namespace std;

int L,lsum,rsum,sum,ans = 0;
string beads;

int calc(int s, int dir, char c, int lim) {
    for (sum = 0; sum < lim && (beads[s] == c || beads[s] == 'w'); sum++,s=(s+L+dir)%L);
    return sum;
}

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    fin >> L >> beads;
    for (int i = 0; i < L; i++) {
        int l = i, r = (i+1)%L;
        lsum = 0, rsum = 0;
        if (beads[l] == 'w') lsum = max(calc(l,-1,'r',L),calc(l,-1,'b',L));
        else lsum = calc(l,-1,beads[l],L);
        if (beads[r] == 'w') rsum = max(calc(r,1,'r',L-lsum),calc(r,1,'b',L-lsum));
        else rsum = calc(r,1,beads[r],L-lsum);
        ans = max(ans,lsum+rsum);
    }
    fout << ans << endl;
    return 0;
}