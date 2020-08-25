#include <iostream>
#include <fstream>
#include <sstream>
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

int total = 0;

struct farm {
    int key;
    long long t,b,l,r;
    long long height,width;
    long long area;
    farm* next;
    farm* prev;
};

farm* top;
farm* bot;
long long exposed = 0;

farm* getnew() {
    farm* w = new farm();
    return w;
}

void create(int x1, int y1, int x2, int y2, int k) {
    total++;
    farm* w = getnew();
    w->key = k;
    w->l = x1;
    w->r = x2;
    w->t = y2;
    w->b = y1;
    //cout << w->l << " " << w->r << " " << w->t << " " << w->b << endl;
    if (total == 1) {
        w->prev = NULL;
        w->next = NULL;
        top = w;
        bot = w;
    }
    else {
        w->next = top;
        top->prev = w;
        w->prev = NULL;
        top = w;
    }
    w->height = abs(w->b - w->t);
    w->width = abs(w->r - w->l);
    w->area = w->width*w->height;
}

farm* search(int c,farm* w) {
    if (w->key != c) {
        return search(c,w->next);
    }
    else {
        return w;
    }
}

void putbot(farm* w) {
    if (w == top) {
        w->next->prev = NULL;
        top = w->next;
        w->prev = bot;
        w->next = NULL;
        bot->next = w;
        bot = w;
    }
}

void loop(farm* cur, long long lx, long long rx,long long ty, long long by) {
    if (cur == NULL) {
        exposed += (rx-lx)*(by-ty);
        return;
    }
    if (cur->l >= rx || cur->r <= lx || cur->t >= by || cur->b <= ty) {
        loop(cur->prev,lx,rx,ty,by);
        return;
    }
    if (cur->l > lx) {
        loop(cur->prev,lx,cur->l,ty,by);
        lx = cur->l;
    }
    if (cur->t > ty) {
        loop(cur->prev,lx,rx,ty,cur->t);
        ty = cur->t;
    }
    if (cur->r < rx) {
        loop(cur->prev,cur->r,rx,ty,by);
        rx = cur->r;
    }
    if (cur->b < by) {
        loop(cur->prev,lx,rx,cur->b,by);
        by = cur->b;
    }
}

long long area(farm* w) {
    exposed = 0;
    //double ret = 0.0;
    //if (w == top) return 100.000;
    loop(w->prev,w->l,w->r,w->t,w->b);
    //ret = 100*exposed/w->area;
    return w->area-exposed;
}

int N;

int main() {
    ifstream fin("test.in");
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        create(x1,y1,x2,y2,i);
    }
    create(-1000000001,1000000001,1000000001,-1000000001,N);
    putbot(search(N,top));
    cout << area(search(N,top)) << endl;
    return 0;
}