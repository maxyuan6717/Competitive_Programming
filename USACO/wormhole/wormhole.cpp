/*
ID: yuanmax1
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

#define max 12  
  
int N;
int x[max+1];
int y[max+1];  
int pair1[max+1];  
int right1[max+1];  

bool loop(void)  {  

	for (int i=1; i<=N; i++) {  
 		int place = i;  
    	for (int j=0; j<N; j++) {
      		place = right1[pair1[place]];  
      		
    	}  
    	if (place != 0) {
    		return true;  
  		}
  	}  
  	return false;  
}  

int calc(void)   {  	
	int i;
	int total=0;  
	
  	for (i=1; i<=N; i++)  { 
    	if (pair1[i] == 0) {
    		break;  
    	}
  	}
	
  	if (i > N) { 
  	
    	if (loop()){
    		return 1;  
    	}
    	else {
    		return 0;  
    	}
  	}  
  	
  	for (int j=i+1; j<=N; j++)  { 
    	if (pair1[j] == 0) {  
      	pair1[i] = j;  
      	pair1[j] = i;  
      	total += calc();  
      	
      	pair1[i] = pair1[j] = 0;  
      	}
      	
    }  
  	return total; 
}  
    
int main(void)  {  
	
	ofstream fout("wormhole.out");  
  	ifstream fin("wormhole.in");  
  	fin >> N;  
  
  	for (int i=1; i<=N; i++) {
  		fin >> x[i] >> y[i];   
  	}	
  	
	for (int i = 0;i < N; i++) {
		for (int j = 0; j < N-1; j++) {
			if (x[j]>y[j+1])
            {
                int z=x[j];
                int z2 = y[j];
                x[j]=x[j+1];
                y[j] = y[j+1];
                x[j+1]=z;
                y[j+1] = z2;                
            }			
		}		
	} 
  	for (int i=1; i<=N; i++){
    	for (int j=1; j<=N; j++)  {
      		if (x[j] > x[i] && y[i] == y[j]) {
    			if (right1[i] == 0 || x[j]-x[i] < x[right1[i]]-x[i])  {
      				right1[i] = j;  
      			}
      		}		
  		}
	}
  	fout << calc() << endl;  
  	return 0;  
}  