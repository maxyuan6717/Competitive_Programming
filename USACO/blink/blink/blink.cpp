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

struct bulb {
    int index;
    bool state;
    long long T = 0;
};

int N;
long long B;
queue<bulb> q;
bulb bulbs[16];
vector<int> arr;
int use[65537];
int in[65537];
int t = 0;
long long curt = 0;
int num = 0;
int ans1;
int ans2;

int allzero() {
    for (int i = 0; i < N; i++) {
        if (arr[i]) return 0;
    }
    return 1;
}

int todec(vector<int> v) {
    int ret = 0;
    for (int i = int(v.size()-1); i >= 0; i--) {
        if (v[i]) ret += pow(2,v.size()-1-i);
    }
    return ret;
}

vector<int> tobin(int n) {
    vector<int> ret;
    for (int i = 0; i < N; i++) {
        ret.push_back(n%2);
        n/=2;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}


void bfs() {
    t = 0;
    while (t < pow(2,N)) {
        if (curt != t) {
            for (int i = 0; i < N; i++) {
                if (arr[i]) {
                    bulb n;
                    n.index = i;
                    n.state = 1;
                    n.T = t;
                    q.push(n);
                }
            }
        }
        while (!q.empty()) {
            bulb v = q.front();
            q.pop();
            arr[(v.index+1)%N] = !arr[(v.index+1)%N];
        }
        t++;
        //for (int i = 0; i < N; i++) cout << arr[i] << " ";
        //cout << endl;
        int a = todec(arr);
        if (use[a] == -1) {
            use[a] = t;
            in[t] = a;
            
        }
        else {
            //cout << a << endl;
            ans1 = use[a] + ((B-use[a])%(t-use[a]));
            ans2 = in[ans1];
            break;
        }
    }
    
}

int main() {
    cin >> N >> B;
    for (int i = 0; i < pow(2,N); i++) {
        use[i] = -1;
    }
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
        bulb b;
        b.index = i;
        b.state = arr[i];
        b.T= 0;
        if (arr[i]) q.push(b);
    }
    use[todec(arr)] = 0;
    bfs();
    //ans1--;
    //cout << repeated << " " << num << " " << ans1 << " " << (B-ans1+1)%(num-ans1)<< endl;
    arr = tobin(ans2);
    for (int i = 0; i < arr.size(); i++) cout << arr[i] << endl;
    
    return 0;
}