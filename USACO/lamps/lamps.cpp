/*
ID: yuanmax1
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
int N, button;
int lampsi[101];
int lampsf[101];
int temp[101];
string ans[101];
string a[101];
int total = 0;
bool cmp(string a, string b) {
	return a < b;
}
void reset() {
	for (int i = 0; i < N; i++) {
		temp[i] = 1;
	}
}
int compare() {
	int stop = 1;
	for (int i = 0; i < N; i++) {
		if (lampsf[i] != 2) {
			if (temp[i] != lampsf[i]) {
				stop = 0;
			}
		}
	}
	if (stop == 1) {
		for (int i = 0; i < N; i++) {
			a[total] += (char)(temp[i] + '0');
			
		}
		//cout<< a[total] << endl;
		if (total == 0 ) {
			
			ans[total] = a[total];
			total++;
		}
		else {
			int x = total;
			int counter = 0;
			for (int i = 0; i < x; i++) {
			
			//cout << a[x] <<  "    " << ans[i] << "   " << total <<endl;
				if (a[x] != ans[i]) {
					counter++;	
				}
			}	
			if (counter == total) {
				ans[total] = a[x];
				total++;
			}	
			else {
				a[total] = "";
			}
						
		}
	}
	return stop;
}
void press(int x) {
	if (x == 1) {
		for (int i = 0; i < N; i++) {
			temp[i] = !temp[i];
		}
	}
	else if (x == 2) {
		for (int i = 0; i < N; i+=2) {
			temp[i] = !temp[i];
		}
	}
	else if (x == 3) {
		for (int i = 1; i < N; i+=2) {
			temp[i] = !temp[i];
		}
	}
	else if (x == 4) {
		for (int i = 0; i < N; i += 3) {
			temp[i] = !temp[i];
			
		}
	}
}
void func1() {
	for (int i = 1; i < 5; i++) {
	reset();
		press(i);
		compare();
		
	}
}
void func2() {
	for (int i = 1; i <= 3; i++) {
	reset();
		press(4);
		press(i);
		compare();
		
	}
}
void func3() {
	func2();
	for (int i = 1; i <= 3; i++) {
	reset();
		press(i);
		compare();
		
	}
}
int main() {
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");

    fin >> N >> button;
    
    for (int i = 0; i < N; i++) {
    	lampsi[i] = 1;
    	temp[i] = 1;
    	lampsf[i] = 2;
    }
    int num;
    for (int i = 0; i < N; i++) {
    	fin >> num;
    	if (num != 0-1) {
    		lampsf[num-1] = 1;
    	}
		else {
			break;
		}
    }
    for (int i = 0; i < N; i++) {
    	fin >> num;
    	if (num != 0-1) {
    		lampsf[num-1] = 0;
    	}
		else {
			break;
		}
    }
    /*for (int i = 0; i < N; i++) {
    	cout << lampsf[i];
    }
    cout << endl;*/
    compare();
    if (button == 1) {
    	func1();
    }
    else if (button == 2) {
    	func3();
    }
    else if (button > 2) {
    	func1();
    	func2();
    }
    //cout << total << endl;
   	if (total == 0) {
   		fout << "IMPOSSIBLE" << endl;
   	}
   	else {
   		sort(ans,ans+total,cmp);
   		for (int i = 0; i < total; i++) {	
   			fout << ans[i] << endl;
   		}
   	}
   
    return 0;
}