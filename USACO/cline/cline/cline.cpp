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

int S;
vector<int> line;
int counter = 1;

int main() {
    cin >> S;
    for (int i = 0; i < S; i++) {
        char c,d;
        int n;
        cin >> c;
        if (c == 'A') {
            cin >> d;
            if (d == 'L') line.insert(line.begin(),counter);
            else line.push_back(counter);
            counter++;
        }
        else {
            cin >> d >> n;
            if (d == 'L') line.erase(line.begin(),line.begin()+n);
            else line.erase(line.end()-n,line.end());
        }
    }
    for (int i = 0; i < line.size(); i++) cout << line[i] << endl;
    
    return 0;
}