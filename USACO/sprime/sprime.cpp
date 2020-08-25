/*
ID: yuanmax1
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
int N;
int ans[50];
int digits[4] = {2,3,5,7};
int digits2[4] = {1,3,7,9};
int counter = 0;
int prime(int num) {
	int root = sqrt(num);
	if (num == 1) {
		return 0;
	}
	for (int i = 2; i <= int(root); i++) {
		if (num % i == 0) {
			return 0;
		}
		
	}
	return 1;
}
int check (int num) {
	for (int x = 0; x < N; x++) {
		if (prime(int(num/(pow(10,x)))) != 1) {
			return 0;
		}	
	}
	return 1;
}
void one() {
	ans[0] = digits[0];
	ans[1] = digits[1];
	ans[2] = digits[2];
	ans[3] = digits[3];
}
void two() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num = 10*digits[i] + digits2[j];
			if (check(num)) {
				ans[counter] = num;
				counter++;
			}
		}
	}
}
void three() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				int num = 100 * digits[i] + 10*digits2[j] + digits2[k];
				if (check(num)) {
					ans[counter] = num;
					counter++;
				}
			}
		}
	}
}

void four() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					int num = 1000*digits[i] + 100 * digits2[j] + 10*digits2[k] + digits2[l];
					if (check(num)) {
						ans[counter] = num;
						counter++;
					}
				}
			}
		}
	}
}
void five() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					for (int m = 0; m < 4; m++) {
						int num = 10000*digits[i] +1000*digits2[j] + 100 * digits2[k] + 10*digits2[l] + digits2[m];
						if (check(num)) {
							ans[counter] = num;
							counter++;
						}
					}
				}
			}
		}
	}
}
void six() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					for (int m = 0; m < 4; m++) {
						for (int n = 0; n < 4; n++) {
							int num = 100000*digits[i] + 10000*digits2[j] +1000*digits2[k] + 100 * digits2[l] + 10*digits2[m] + digits2[n];
							if (check(num)) {
								ans[counter] = num;
								counter++;
							}	
						}
					}
				}
			}
		}
	}
}
void seven() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					for (int m = 0; m < 4; m++) {
						for (int n = 0; n < 4; n++) {
							for (int o = 0; o < 4; o++) {
								int num = 1000000*digits[i] + 100000*digits2[j] + 10000*digits2[k] +1000*digits2[l] + 100 * digits2[m] + 10*digits2[n] + digits2[o];
								if (check(num)) {
									ans[counter] = num;
									counter++;
								}
							}	
						}
					}
				}
			}
		}
	}
}
void eight() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					for (int m = 0; m < 4; m++) {
						for (int n = 0; n < 4; n++) {
							for (int o = 0; o < 4; o++) {
								for (int p = 0; p < 4; p++) {
									int num = 10000000*digits[i]+1000000*digits2[j] + 100000*digits2[k] + 10000*digits2[l] +1000*digits2[m] + 100 * digits2[n] + 10*digits2[o] + digits2[p];
									if (check(num)) {
										ans[counter] = num;
										counter++;
									}
								}
							}	
						}
					}
				}
			}
		}
	}
}

int main() {
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in"); 
    fin >> N;
	if (N == 1) one();
	else if (N == 2) two();
	else if (N == 3) three();
	else if (N == 4) four();
	else if (N == 5) five();
	else if (N == 6) six();
	else if (N == 7) seven();
	else if (N == 8) eight();
	
	for (int i = 0; i < 50; i++) {
		if (ans[i] != 0) {
			fout << ans[i] << endl;
		}
	}
	
    return 0;
}