#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <list>
#include <stack>

using namespace std;

int main() {
	
	priority_queue<int,vector<int>,greater<int> > minQ;
	minQ.push(10);
	minQ.push(5);
	minQ.push(82);
	minQ.push(27);
	minQ.push(2);
	while (!minQ.empty()) {
		int num = minQ.top();
		minQ.pop();
		cout << num << endl;
	}
	return 0;
}