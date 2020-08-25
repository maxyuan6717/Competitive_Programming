/*
ID: yuanmax1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;



int main() {
    ofstream fout ("transform.out");
	ifstream fin ("transform.in");
	int N;
	fin >> N;
    char square[N][N];
    char square2[N][N];
    char test[N][N];
    char holder[N][N];
    int transformation;
    string input;
    for (int x = 0; x < N; x++) {
    	fin >> input;
    	for (int y = 0; y < N; y++) {
    		square[x][y] = input[y];
    		test[x][y] = input[y];
    	}
    }
    for (int x = 0; x < N; x++) {
    	fin >> input;
    	for (int y = 0; y < N; y++) {
    		square2[x][y] = input[y];
    	}
    }   
   
	/*
    for (int x = 0; x < N; x++) {
    	for (int y = 0; y < N; y++) {
    		cout << square[x][y];
    	}
    	cout << endl;
    }
    */
    //******************************************************//
    
    //   ROTATE  90  //
    for (int x = 0; x < N; x++) {
    	for (int y = x+1; y < N; y++) {
    		int temp = test[x][y];
    		test[x][y] = test[y][x];
    		test[y][x] = temp;
    	}
    }  
    for (int x = 0; x< N; x++) {
    	for (int y = 0; y < N/2; y++) {
    		int temp = test[x][y];
    		test[x][y] = test[x][N-1-y];
    		test[x][N-1-y] = temp;
    	}
    }
    int counter = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (test[x][y] == square2[x][y]) {
				counter++;
			}
		}
	}
	if (counter == (pow(N,2))) {
		fout << "1" << endl;
		return 0;
	}
	//******************************************************//
	
	//    ROTATE 180   //
	for (int x = 0; x < N; x++) {
    	for (int y = 0; y < N; y++) {
    		test[x][y] = square[x][y];
    	}
    }
	for (int i = 0; i < 2; i++) {
		for (int x = 0; x < N; x++) {
    		for (int y = x+1; y < N; y++) {
    			int temp = test[x][y];
    			test[x][y] = test[y][x];
    			test[y][x] = temp;
    		}
   		 }  
   	 	for (int x = 0; x< N; x++) {
    		for (int y = 0; y < N/2; y++) {
    			int temp = test[x][y];
    			test[x][y] = test[x][N-1-y];
    			test[x][N-1-y] = temp;
    		}
    	}
    	counter = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (test[x][y] == square2[x][y]) {
					counter++;
				}
			}
		}	
		if (counter == (pow(N,2))) {
			fout << "2" << endl;
			return 0;
		}
	}
	//******************************************************//

	//    ROTATE 270   //
	for (int x = 0; x < N; x++) {
    	for (int y = 0; y < N; y++) {
    		test[x][y] = square[x][y];
    	}
    }
	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < N; x++) {
    		for (int y = x+1; y < N; y++) {
    			int temp = test[x][y];
    			test[x][y] = test[y][x];
    			test[y][x] = temp;
    		}
   		 }  
   	 	for (int x = 0; x< N; x++) {
    		for (int y = 0; y < N/2; y++) {
    			int temp = test[x][y];
    			test[x][y] = test[x][N-1-y];
    			test[x][N-1-y] = temp;
    		}
    	}
    	counter = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (test[x][y] == square2[x][y]) {
					counter++;
				}
			}
		}	
		if (counter == (pow(N,2))) {
			fout << "3" << endl;
			return 0;
		}
	}

	//******************************************************//
	
	//    REFLECTION   //
	for (int x = 0; x < N; x++) {
    	for (int y = 0; y < N; y++) {
    		test[x][y] = square[x][y];
    	}
    }
	for (int x = 0; x < N; x++) {
    	for (int y = 0; y < ((N+1)/2); y++) {
    		swap(test[x][y],test[x][N-1-y]);
    	}
   	 }  
   	
   	counter = 0;		
   	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (test[x][y] == square2[x][y]) {
				counter++;
			}
		}
	}	
	if (counter == (pow(N,2))) {
		fout << "4" << endl;
		return 0;
	}
	else {
		
		for (int x = 0; x < N; x++) {
    		for (int y = 0; y < N; y++) {
    			holder[x][y] = test[x][y];
    		}
   	 	}
	}
	
	//******************************************************//
	
	 //   ROTATE  90  //
    
    for (int x = 0; x< N; x++) {
    	for (int y = 0; y < N/2; y++) {
    		int temp = test[x][y];
    		test[x][y] = test[x][N-1-y];
    		test[x][N-1-y] = temp;
    	}
    }
    counter = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (test[x][y] == square2[x][y]) {
				counter++;
			}
		}
	}
	if (counter == (pow(N,2))) {
		fout << "5" << endl;
		return 0;
	}
	//******************************************************//
	
	//    ROTATE 180   //
	for (int x = 0; x < N; x++) {
    	for (int y = 0; y < N; y++) {
    		test[x][y] = holder[x][y];
    	}
    }
	for (int i = 0; i < 2; i++) {
		for (int x = 0; x < N; x++) {
    		for (int y = x+1; y < N; y++) {
    			int temp = test[x][y];
    			test[x][y] = test[y][x];
    			test[y][x] = temp;
    		}
   		 }  
   	 	for (int x = 0; x< N; x++) {
    		for (int y = 0; y < N/2; y++) {
    			int temp = test[x][y];
    			test[x][y] = test[x][N-1-y];
    			test[x][N-1-y] = temp;
    		}
    	}
    	counter = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (test[x][y] == square2[x][y]) {
					counter++;
				}
			}
		}	
		if (counter == (pow(N,2))) {
			fout << "5" << endl;
			return 0;
		}
	}
	//******************************************************//

	//    ROTATE 270   //
	for (int x = 0; x < N; x++) {
    	for (int y = 0; y < N; y++) {
    		test[x][y] = holder[x][y];
    	}
    }
	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < N; x++) {
    		for (int y = x+1; y < N; y++) {
    			int temp = test[x][y];
    			test[x][y] = test[y][x];
    			test[y][x] = temp;
    		}
   		 }  
   	 	for (int x = 0; x< N; x++) {
    		for (int y = 0; y < N/2; y++) {
    			int temp = test[x][y];
    			test[x][y] = test[x][N-1-y];
    			test[x][N-1-y] = temp;
    		}
    	}
    	counter = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (test[x][y] == square2[x][y]) {
					counter++;
				}
			}
		}	
		if (counter == (pow(N,2))) {
			fout << "5" << endl;
			return 0;
		}
	}

	//******************************************************//
	
	counter = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (square[x][y] == square2[x][y]) {
					counter++;
				}
			}
		}
		if (counter == (pow(N,2))) {
			fout << "6" << endl;
			return 0;
		}
	
	
	fout << "7" << endl;
	
    
    
    
    return 0;
}