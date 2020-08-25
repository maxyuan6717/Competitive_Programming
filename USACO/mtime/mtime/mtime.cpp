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

struct job {
    int e,t;
};

int N;
vector<job> jobs;

bool compare(job a, job b) {
    return a.e < b.e;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        job j;
        cin >> j.t >> j.e;
        jobs.push_back(j);
    }
    sort(jobs.begin(),jobs.end(),compare);
    int ans = -1;
    for (int s = jobs.begin()->e-jobs.begin()->t; s >= 0; s--) {
        int last = s;
        bool possible = 1;
        for (int i = 0; i < N-1; i++) {
            last += jobs[i].t;
            if (last+jobs[i+1].t > jobs[i+1].e) {
                possible = 0;
                break;
            }
        }
        if (possible) {
            ans = s;
            break;
        }
    }
    cout << ans << endl;
    
    return 0;
}