/*
ID: yuanmax1
PROG: ride
LANG: C++                
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet, group;
    fin >> comet >> group;
    int cometNum = 1, groupNum = 1;
    for (int i = 0; i < comet.length(); i++) {
    	cometNum *= comet[i] - 'A' + 1;
    }
    for (int i = 0; i < group.length(); i++) {
    	groupNum *= group[i] - 'A' + 1;
    }
    if ((cometNum % 47) == (groupNum % 47)) {
    	fout << "GO\n";
    }
    else {
    	fout << "STAY\n";
    }
    return 0;
}