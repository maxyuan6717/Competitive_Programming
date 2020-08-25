/*
 ID: yuanmax1
 PROG: window
 LANG: C++
 */
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

struct window {
    char key;
    int t,b,l,r;
    int height,width;
    double area;
    window* next;
    window* prev;
};

window* top;
window* bot;
double exposed = 0;

int toint(string s) {
    int ret;
    istringstream convert(s);
    convert >> ret;
    return ret;
}

window* getnew() {
    window* w = new window();
    return w;
}

void create(string s) {
    total++;
    window* w = getnew();
    w->key = s[2];
    int index = 4;
    int len = 1;
    while (s[index+len] != ',') len++;
    w->l = toint(s.substr(index,len));
    index += len+1;
    len = 1;
    
    while (s[index+len] != ',') len++;
    w->b = toint(s.substr(index,len));
    index += len+1;
    len = 1;
    while (s[index+len] != ',') len++;
    w->r = toint(s.substr(index,len));
    if (w->r < w->l) {
        int temp = w->l;
        w->l = w->r;
        w->r = temp;
    }
    index += len+1;
    len = 1;
    while (s[index+len] != ')') len++;
    w->t = toint(s.substr(index,len));
    if (w->b < w->t) {
        int temp = w->b;
        w->b = w->t;
        w->t = temp;
    }
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
    w->height = w->b - w->t;
    w->width = w->r - w->l;
    w->area = w->width*w->height;
}

window* search(char c,window* w) {
    if (w->key != c) {
        return search(c,w->next);
    }
    else {
        return w;
    }
}

void puttop(window* w) {
    if (w == bot && w!= top) {
        w->prev->next = NULL;
        bot = w->prev;
        w->next = top;
        top->prev = w;
        w->prev = NULL;
        top = w;
    }
    else if (top != w) {
        if (w->prev != NULL) w->prev->next = w->next;
        if (w->next != NULL) w->next->prev = w->prev;
        w->next = top;
        top->prev = w;
        w->prev = NULL;
        top = w;
    }
}

void putbot(window* w) {
    if (w == top) {
        w->next->prev = NULL;
        top = w->next;
        w->prev = bot;
        w->next = NULL;
        bot->next = w;
        bot = w;
    }
    if (bot != w) {
        if (w->prev != NULL) w->prev->next = w->next;
        if (w->next != NULL) w->next->prev = w->prev;
        w->prev = bot;
        w->next = NULL;
        bot->next = w;
        bot = w;
    }
}

void del(window* w) {
    if (top == w && bot == w) {
        top = NULL;
        bot = NULL;
    }
    else if (top == w) {
        w->next->prev = NULL;
        top = w->next;
    }
    else if (bot == w) {
        w->prev->next = NULL;
        bot = w->prev;
    }
    else {
        w->prev->next = w->next;
        w->next->prev = w->prev;
    }
    total--;
}

window* overlapping(window* a, window* b) {
    //cout << a->l << " " << a->r << " " << a->t << " " << a->b << endl;
    //cout << b->l << " " << b->r << " " << b->t << " " << b->b << endl;

    if (a->r < b->l || a->l > b->r || a->t > b->b || a->b < b->t) return NULL;
    window* w = getnew();
    if (a->l < b->l) w->l = b->l;
    else w->l = a->l;
    if (a->r > b-> r) w->r = b->r;
    else w->r = a->r;
    if (a->t < b->t) w->t = b->t;
    else w->t = a->t;
    if (a->b > b->b) w->b = b->b;
    else w->b = a->b;
    w->width = w->r-w->l;
    w->height = w->b-w->t;
    w->area = w->width*w->height;
    return w;
}

void loop(window* cur, int lx, int rx, int ty, int by) {
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

double area(window* w) {
    exposed = 0.000;
    double ret = 0.0;
    if (w == top) return 100.000;
    loop(w->prev,w->l,w->r,w->t,w->b);
    ret = 100*exposed/w->area;
    return ret;
}

int main() {
    ofstream fout ("window.out");
    ifstream fin ("window.in");
    string s;
    while (fin >> s) {
        if (s[0] == 'w') {
            create(s);
        }
        else if (s[0] == 't') {
            puttop(search(s[2],top));
        }
        else if (s[0] == 'b') {
            putbot(search(s[2],top));
        }
        else if (s[0] == 'd') {
            del(search(s[2],top));
        }
        else if (s[0] == 's') {
            cout.precision(3);
            fout.precision(3);
            cout << fixed;
            fout << fixed;
            double ans = area(search(s[2],top));
            cout << ans << endl;
            fout << ans << endl;
        }
    }
    return 0;
}