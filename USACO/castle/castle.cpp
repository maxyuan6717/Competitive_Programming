/*
ID: yuanmax1
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int M, N;
int temps[51][51];
int rooms[51][51];
int nums[51][51];
int temps2[51][51];
int counter = 1;
int startn = 1;
int startm = 1;
int size = 0;
int sum = 0;
int sum2 = 0;
int roomNum;
int roomBig;
int maxR;
int maxN;
int maxM;
char maxL;
string moves = "";
void reset() {
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			rooms[n][m] = temps[n][m];			
		}
	}	
	int counter = 1;
	int startn = 1;
	int startm = 1;
	int size = 0;
	
	string moves = "";
}
void reset2() {
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			nums[n][m] = 0;		
		}
	}
}
void find() {
	
	//		wall not on right
	if ((rooms[startn][startm] == 0 || rooms[startn][startm] == 1 || rooms[startn][startm] == 2 || rooms[startn][startm] == 8 || rooms[startn][startm] == 3 || rooms[startn][startm] == 9 || rooms[startn][startm] == 10 ||rooms[startn][startm] == 11) && nums[startn][startm+1] == 0) {
		startm += 1;
		if (nums[startn][startm] == 0) {
			nums[startn][startm] = counter;
			moves += "r";
			find();
		}
		/*else if (nums[startn][startm] == 1) {
			startm -=1;
		}*/
		
 	}
 	
 	//		wall not on bottom
 	if ((rooms[startn][startm] == 0 || rooms[startn][startm] == 1 || rooms[startn][startm] == 2 || rooms[startn][startm] == 4 || rooms[startn][startm] == 3 || rooms[startn][startm] == 5 || rooms[startn][startm] == 6 ||rooms[startn][startm] == 7) && nums[startn+1][startm] == 0) {
 		//cout << "hi" << endl;
		startn += 1;
		if (nums[startn][startm] == 0) {
			nums[startn][startm] = counter;
			moves += "b";
			find();
		}
		/*else if (nums[startn][startm] == 1) {
			startn -=1;
		}*/
		
 	}
 
 	//		wall not on top
	if ((rooms[startn][startm] == 0 || rooms[startn][startm] == 1 || rooms[startn][startm] == 4 || rooms[startn][startm] == 8 || rooms[startn][startm] == 5 || rooms[startn][startm] == 9 || rooms[startn][startm] == 12 ||rooms[startn][startm] == 13) && nums[startn-1][startm] == 0) {
		startn -= 1;
		if (nums[startn][startm] == 0) {
			nums[startn][startm] = counter;
			moves += "t";
			find();
		}
		/*else if (nums[startn][startm] == 1) {
			startn +=1;
		}*/
		
		
	}	
 	
 	//		wall not on left
 	if ((rooms[startn][startm]%2 == 0) && nums[startn][startm-1] == 0) {
		startm -= 1;
		if (nums[startn][startm] == 0) {
			nums[startn][startm] = counter;
			moves += "l";
			find();
		}	
		
 	}
 	size = moves.size() - 1;
 	if (moves.size() != 0) {
 	 	if (moves[size] == 'r') {
 	 		//moves.pop_back();
 	 		moves.erase(size);
 			startm -=1;
 			find();
 			}
 		else if (moves[size] == 'l') {
 			//moves.pop_back();
 			moves.erase(size);
 			startm +=1;
 			find();
 		}
 		else if (moves[size] == 't') {
 			//moves.pop_back();
 			moves.erase(size);
 			startn +=1;
 			find();
 		}
 		else if (moves[size] == 'b') {
 			//moves.pop_back();
 			moves.erase(size);
 			startn -=1;
 			find();
 		}
 	}
 	
  	
}
int biggest() {
	roomBig = 0;
	int temp = 0;
	for (int i = 1 ; i <= roomNum; i++) {
		for (int n = 1; n <= N; n++) {
			for (int m = 1; m <= M; m++) {
				if (nums[n][m] == i) {
					temp++;
				}
			}
		}	
		if (temp > roomBig) {
			roomBig = temp;
		}
		temp = 0;
	}
	return roomBig;
}
void remove() {
	reset();
	reset2();
	int x;
	for (int m = 1; m <= M; m++) {
    	for (int n = N; n >0; n--) {
    		//cout << n << " " << m << " " << endl;
    		//cout << roomNum << endl;
    		if (roomNum == M*N) {
    			//cout << "HI" << endl;
    			if (N == 1) {
    				maxR = 2;
    				maxN = N;
    				maxM = 1;
    				maxL = 'E';
    			}
    			else {
    				maxR = 2;
    				maxN = N;
    				maxM = 1;
    				maxL = 'N';
    			}
    			break;
    		}
    		else if (n == 1 && m != M) {
    			// East
    			if ((rooms[n][m] == 4 || rooms[n][m] == 5 || rooms[n][m] == 6 || rooms[n][m] == 12 || rooms[n][m] == 7 || rooms[n][m] == 13 || rooms[n][m] == 14 || rooms[n][m] == 15) && (temps2[n][m+1] != temps2[n][m])) {
    				/*rooms[n][m] -= 4;
    				rooms[n][m+1] -= 1;
    				for (int n2 = 1; n2 <= N; n2++) {
    					for (int m2 = 1; m2 <= M; m2++) {
    						if (nums[n2][m2] == 0) {
    							startn = n2;
    							startm = m2;
    							nums[startn][startm] = counter;
    							find();
    							counter++;
								//reset();
    							//cout << counter << endl;
    						}
    					}		
    				}	
    				roomNum = counter-1;
    				x = biggest();
    				if (x > maxR) {
    					maxR = x;
    					maxN = n;
    					maxM = m;
    					maxL = 'E';
    				}
    				x = 0;
    				reset();
    				reset2();
    				roomNum = 0;*/
    				for (int n2 = 1; n2 <= N; n2++) {
    					for (int m2 = 1; m2 <= M; m2++) {
    						if (temps2[n2][m2] == temps2[n][m] || temps2[n2][m2] == temps2[n][m+1]) {
    							sum2++;
    						}
    					}
    				}
    				if (sum2 > maxR) {
    					maxR = sum2;
    					maxN = n;
    					maxM = m;
    					maxL = 'E';
    				}
    				sum2 = 0;
    				reset();
    				reset2();
    			}
    			
    		}
    		else if (m == M && n != 1) {
    			// North
    			if ((rooms[n][m] == 2 || rooms[n][m] == 3 || rooms[n][m] == 6 || rooms[n][m] == 10 || rooms[n][m] == 7 || rooms[n][m] == 11 || rooms[n][m] == 14 || rooms[n][m] == 15) && (temps2[n-1][m] != temps2[n][m])) {
    				/*rooms[n][m] -= 2;
    				rooms[n-1][m] -=8;
    				for (int n2 = 1; n2 <= N; n2++) {
    					for (int m2 = 1; m2 <= M; m2++) {
    						if (nums[n2][m2] == 0) {
    							startn = n2;
    							startm = m2;
    							nums[startn][startm] = counter;
    							find();
    							counter++;
								//reset();
    							//cout << counter << endl;
    						}
    					}		
    				}	
    				roomNum = counter-1;
    				x = biggest();
    				if (x > maxR) {
    					maxR = x;
    					maxN = n;
    					maxM = m;
    					maxL = 'N';
    				}
    				x = 0;
    				reset();
    				reset2();
    				roomNum = 0;*/
    				for (int n2 = 1; n2 <= N; n2++) {
    					for (int m2 = 1; m2 <= M; m2++) {
    						if (temps2[n2][m2] == temps2[n][m] || temps2[n2][m2] == temps2[n-1][m]) {
    							sum2++;
    						}
    					}
    				}
    				if (sum2 > maxR) {
    					maxR = sum2;
    					maxN = n;
    					maxM = m;
    					maxL = 'N';
    				}
    				sum2 = 0;
    				reset();
    				reset2();
    			}
    		}
    		else if (n == 1 && m == M) {
    			int nothing = 0;
    		}
    		
    		else {
    			// North
    			if ((rooms[n][m] == 2 || rooms[n][m] == 3 || rooms[n][m] == 6 || rooms[n][m] == 10 || rooms[n][m] == 7 || rooms[n][m] == 11 || rooms[n][m] == 14 || rooms[n][m] == 15) && (temps2[n-1][m] != temps2[n][m])) {
    				/*rooms[n][m] -= 2;
    				rooms[n-1][m] -=8;
    				for (int n2 = 1; n2 <= N; n2++) {
    					for (int m2 = 1; m2 <= M; m2++) {
    						if (nums[n2][m2] == 0) {
    							startn = n2;
    							startm = m2;
    							nums[startn][startm] = counter;
    							find();
    							counter++;
								//reset();
    							//cout << counter << endl;
    						}
    					}		
    				}	
    				roomNum = counter-1;
    				x = biggest();
    				if (x > maxR) {
    					
    					cout << x << endl;
    					maxR = x;
    					maxN = n;
    					maxM = m;
    					maxL = 'N';
    					//cout << maxN << " " << maxM << endl;
    					
    				}
    				x = 0;
    				reset();
    				reset2();
    				roomNum = 0;*/
    				for (int n2 = 1; n2 <= N; n2++) {
    					for (int m2 = 1; m2 <= M; m2++) {
    						if (temps2[n2][m2] == temps2[n][m] || temps2[n2][m2] == temps2[n-1][m]) {
    							sum2++;
    						}
    					}
    				}
    				if (sum2 > maxR) {
    					maxR = sum2;
    					maxN = n;
    					maxM = m;
    					maxL = 'N';
    				}
    				sum2 = 0;
    				reset();
    				reset2();
    			}
    			// East
    			if ((rooms[n][m] == 4 || rooms[n][m] == 5 || rooms[n][m] == 6 || rooms[n][m] == 12 || rooms[n][m] == 7 || rooms[n][m] == 13 || rooms[n][m] == 14 || rooms[n][m] == 15) && (temps2[n][m+1] != temps2[n][m])) {
    				//cout << temps2[n][m] << endl;
    				//cout << temps2[n][m+1] << endl;
    				/*rooms[n][m] -= 4;
    				rooms[n][m+1] -= 1;
    				for (int n2 = 1; n2 <= N; n2++) {
    					for (int m2 = 1; m2 <= M; m2++) {
    						if (nums[n2][m2] == 0) {
    							startn = n2;
    							startm = m2;
    							nums[startn][startm] = counter;
    							find();
    							counter++;
								//reset();
    							//cout << counter << endl;
    						}
    					}		
    				}	
    				
    				roomNum = counter-1;
    				x = biggest();
    				//cout << x << " " << n << " " << m << " " << endl;
    				if (x > maxR) {
    					
    					//cout << x << endl;
    					maxR = x;
    					maxN = n;
    					maxM = m;
    					maxL = 'E';
    					//cout << maxN << " " << maxM << endl;
    				}
    				x = 0;
    				reset();
    				reset2();
    				roomNum = 0;*/
    				for (int n2 = 1; n2 <= N; n2++) {
    					for (int m2 = 1; m2 <= M; m2++) {
    						if ((temps2[n2][m2] == temps2[n][m]) || (temps2[n2][m2] == temps2[n][m+1])) {
    							
    							sum2++;
    							//cout << sum2 << endl;
    						}
    					}
    				}
    				if (sum2 > maxR) {
    					maxR = sum2;
    					maxN = n;
    					maxM = m;
    					maxL = 'E';
    				}
    				sum2 = 0;
    				reset();
    				reset2();
    			}
    			
    		}
    	}
    }
}
int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");   
    fin >> M >> N;   
    for (int n = 1; n <= N; n++) {
    	for (int m = 1; m <= M; m++) {
    		fin >> rooms[n][m];
    		temps[n][m] = rooms[n][m];
    		nums[n][m] = 0;
    	}
    }
    for (int n = 1; n <= N; n++) {
    	for (int m = 1; m <= M; m++) {
    		if (nums[n][m] == 0) {
    			startn = n;
    			startm = m;
    			nums[startn][startm] = counter;
    			find();
    			counter++;
				//reset();
    			//cout << counter << endl;
    		}
    	}
    }	
    for (int n = 1; n <= N; n++) {
    	for (int m = 1; m <= M; m++) {
    		temps2[n][m] = nums[n][m];
    		//cout << temps2[n][m] << " ";
    	}
    	//cout << endl;
    }
    roomNum = counter-1;
    fout << roomNum << endl;
    fout << biggest() << endl;
    remove();
    fout << maxR << endl;
    fout << maxN << " " << maxM << " " << maxL << endl;
    /*for (int n = 1; n <= N; n++) {
    	for (int m = 1; m <= M; m++) {
    		cout << nums[n][m] << " ";
    	}
    	cout << endl;
    }*/
    
    return 0;
} 