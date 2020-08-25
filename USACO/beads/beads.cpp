/*
ID: yuanmax1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int lmax = 0;
    int rmax = 0;
    int max = 0;
    string input;
    int N;
    /*cout << "Enter a number: ";
    getline(cin, input);
    N = stoi (input);
    cout << "Enter some numbers: ";
    getline(cin, beads);*/
    fin >> N;
    string beads;
    fin >> beads;
    beads = beads + beads;
    int size = beads.length();
    char bead[size];
    for (int i = 0; i < size; i++) {
    	bead[i] = beads[i];    
    }
    for (int beadNum = 1; beadNum < size; beadNum++) {
    	int left = beadNum-1;
    	int right = beadNum;
    	char leftC = bead[left];
    	char rightC = bead[right];
    	int lmax = 0;
    	int rmax = 0;
    	int lmax1 = 0;
    	int lmax2 = 0;
    	int rmax1 = 0;
    	int rmax2 = 0;
    	if (leftC = 'w') {
    	    leftC = 'r';   
        	for (int x = left; x>=0; x--) {
        		
        		if (bead[x] == leftC || bead[x] == 'w') {
        			lmax1+=1;
        		}
        		else {
        			break;
        		}
    	    }
    	    leftC = 'b';
    	    for (int x = left; x>=0; x--) {
        		
        		if (bead[x] == leftC || bead[x] == 'w') {
        			lmax2+=1;
        		}
        		else {
        			break;
        		}
    	    }
    	    if (lmax1>lmax2) {
    	        lmax = lmax1;   
    	    }
    	    else {
    	        lmax = lmax2;   
    	    }
    	}
    	  	
    	else {
    	    for (int x = left; x>=0; x--) {
    		
    		    if (bead[x] == leftC || bead[x] == 'w') {
    			    lmax+=1;
    		    }
    		    else {
    		    	break;
    		    }
    	    }
    	}
    	if (rightC = 'w') {
    	    rightC = 'r';   
        	for (int x = right; x<size; x++) {
        		
        		if (bead[x] == rightC || bead[x] == 'w') {
        			rmax1+=1;
        		}
        		else {
        			break;
        		}
    	    }
    	    rightC = 'b';
    	    for (int x = right; x<size; x++) {
        		
        		if (bead[x] == rightC || bead[x] == 'w') {
        			rmax2+=1;
        		}
        		else {
        			break;
        		}
    	    }
    	    if (rmax1>rmax2) {
    	        rmax = rmax1;   
    	    }
    	    else {
    	        rmax = rmax2;   
    	    }
    	}
    	  	
    	else {
    	    for (int x = right; x<size;x++ ) {
    		
    		    if (bead[x] == rightC || bead[x] == 'w') {
    			    rmax+=1;
    		    }
    		    else {
    		    	break;
    		    }
    	    }
    	}
    	
    	if ((lmax + rmax) > max) {
    		max = lmax+rmax;
    	
    	}
    	if ((lmax + rmax) > N) {
    		max = N;
        }
    	
    
    }   
     
    
    fout << max << endl;
    
    
    return 0;
}