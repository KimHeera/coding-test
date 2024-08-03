/*
BOJ 1920.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.03
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;
int N;
void binarySearch(int input);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    A.resize(N, 0);

    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int M, input;
    cin >> M;
    for (int i = 0; i < M; i++){
        cin >> input;
        binarySearch(input);
    }
}

void binarySearch(int input){
    int start = 0;
    int end = N - 1;
    bool find = false;

    while(start <= end){
        int mid = (start + end) / 2;
        int midValue = A[mid];

        if(midValue > input)
            end = mid - 1;
        else if(midValue < input)
            start = mid + 1;
        else {
            find = true;
            break;
        }
    }

    if(find)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}