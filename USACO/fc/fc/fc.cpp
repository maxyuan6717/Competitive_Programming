
/*
 ID: yuanmax1
 PROG: fc
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
#define PI 3.14159265

using namespace std;

struct point {
    double x,y,angle;
};

int N;
int l = 0;
vector<point> points;
vector<point> hull;

bool compare(point i, point j) {
    return i.angle < j.angle;
}

int check(point p, point q, point r) {
    double ang = (q.y-p.y)*(r.x-q.x) - (q.x-p.x) * (r.y-q.y);
    if (ang == 0) return 0;
    if (ang > 0) return 1;
    else return 2;
}

int main() {
    ofstream fout ("fc.out");
    ifstream fin ("fc.in");
    fin >> N;
    for (int i = 0; i < N; i++) {
        points.push_back(point());
        double x,y;
        fin >> x >> y;
        points[i].x = x;
        points[i].y = y;
        if (x < points[l].x) l = i;
        else if (x == points[l].x && y < points[l].y) l = i;
    }
    //cout << l << endl;
    int p = l,q = (p+1)%N;
    do {
        //cout << points[p].x << " " << points[p].y << endl;
        hull.push_back(points[p]);
        for (int i = 0; i < N; i++) {
            if (check(points[p],points[i],points[q]) == 2) q = i;
        }
        p = q;
        q = (p+1)%N;
    } while (p!=l);
    int s = int(hull.size());
    //for (int i = 0; i < s; i++) cout << hull[i].x << " " << hull[i].y << endl;
    double ans = 0;
    for (int i = 0; i < s; i++) {
        int j = (i+1)%s;
        double dist = sqrt(pow((hull[i].x-hull[j].x),2) + pow((hull[i].y-hull[j].y),2));
        ans += dist;
    }
    cout.precision(2);
    fout.precision(2);
    cout << fixed;
    fout << fixed;
    cout << ans << endl;
    fout << ans << endl;
    return 0;
}