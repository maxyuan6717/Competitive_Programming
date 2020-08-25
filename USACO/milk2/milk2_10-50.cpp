/*
ID: yuanmax1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;




int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");       //CHANGE CHANGE
  //string input;
    int N;
    //cout << "Enter a number: ";
    //getline(cin, input);
    //N = stoi (input);
    fin >> N;
    cout << N << endl;
    int start[N];
    int end[N];
    for (int i = 0; i < N; i++) {
    	/*cout << "Enter a number";
    	getline(cin, input);
    	start[i] = stoi (input);
    	cout << "Enter another number";
    	getline(cin, input);
    	end[i] = stoi (input);*/
    	fin >> start[i];
    	fin >> end[i];
	}
	for (int x = 0;x < N; x++) {
		for (int y = 0; y < N-1; y++) {
			if (start[y]>start[y+1])
            {
                int z=start[y];
                int z2 = end[y];
                start[y]=start[y+1];
                end[y] = end[y+1];
                start[y+1]=z;
                end[y+1] = z2;
            }
			
		}
		
	}
	for (int i = 0; i < N; i++) {
		cout << start[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << end[i] << " ";
	}
	cout << endl;
    int idleT = 0;
    int maxT = 0;
    int counter1 = 0;
    int counter2 = 0;
    bool change1 = true;
    int counter3 = 0;
    int counter4 = 0;
    bool change2 = true;
    for (int i = 0; i < N; i++) {
    	if (i != N-1) {
    		if (start[i+1]<=end[i] || start[i+1]<=end[counter1]) {
    			if (change1 == true) {
    				change1 = false;
    				counter1 = i;
    				counter2 = i;
    			}
    			counter2++;
    		}
    		else {
    			if ((end[counter2]-start[counter1])>maxT) {
    				maxT = (end[counter2]-start[counter1]);
    			}
    			change1 = true;
			}
    		
    		
    	}
    	else if (i == (N-1)) {
    		if ((end[counter2]-start[counter1])>maxT) {
    			maxT = (end[counter2]-start[counter1]);
    		}
    		if ((end[counter1] - start[counter1]) > maxT) {
    			maxT = end[counter1] - start[counter1];
    		}
    	}
    	if ((end[i] - start[i]) > maxT) {
    		maxT = end[i] - start[i];
    	
    	}
    	
    }
    for (int i = 0; i < N; i++) {
    	
    	if (i != N-1) {
    		if (start[i+1] > end[i]) {
    			if (change2 == true) {
    				//change2 = false;
    				counter3 = i;
    				counter4 = i+1;
    			}
    			if ((start[counter4]-end[counter3])>idleT) {
    				idleT = (start[counter4]-end[counter3]);
    			}
    			
    		}
    		
    	}
    	if (end[0] > end[N-1]) {
    		idleT = 0;
    	}
    	/*else if (i == (N-1)) {
    		if ((start[i]-end[i-1])>idleT) {
    			idleT = (start[i]-end[i-1]);
    		}
    	}*/
    	/*else {
    		if ((start[counter4]-end[counter3])>idleT)  {
    			idleT = (start[counter4]-end[counter3]);
    		}
    		change2 = true;
    		
    	}*/
    	
    }
    string a;
    for (int i = 1; i < N; i++) {
    
    	if (start[i] < end[i-1]) {
    		a = "Yes";
    	}
    	else {
    		a = "No";
    	}
    	fout << start[i] << " " << end[i] << " " << end[i] - start[i] << " " << a << endl;
    }
    //fout << maxT << " " << idleT << endl;
    cout << maxT << " " << idleT << endl;
    
    return 0;
}