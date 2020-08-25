#include <iostream>
#include <algorithm>
#include <vector>

#define LARGE 999999999

using namespace std;

int N;
int used[100001];
int elsie[50001];
int bessie[50001];
int counter = 0;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> elsie[i];
        used[elsie[i]] = 1;
    }
    for (int i = 1; i <= 2*N; i++) {
        if (!used[i]) {
            bessie[counter] = i;
            counter++;
        }
    }
    sort(elsie,elsie+N/2);
    sort(elsie+N/2,elsie+N);
    int ans = 0;
    int cur = N/2;
    for (int i = 0; i < N/2; i++) {
        for (int j = cur; j < N; j++) {
            if (bessie[j] > elsie[i]){
                ans++;
                cur = j+1;
                break;
            }
        }
    }
    cur = 0;
    for (int i = N/2; i < N; i++) {
        for (int j = cur; j < N/2; j++) {
            if (bessie[j] < elsie[i]) {
                ans++;
                cur = j+1;
                break;
            }
        }
    }
    //for (int i = 0; i < N; i++) cout << bessie[i] << " ";
    //cout << endl;
    cout << ans << endl;
    
    return 0;
}