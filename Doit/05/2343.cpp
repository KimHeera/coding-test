/*
BOJ 2343.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.03
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> A(N, 0);
    int start = 0, end = 0;
    for (int i = 0; i < N; i++){
        cin >> A[i];

        if(start < A[i])
            start = A[i];

        end += A[i];
    }

    while(start <= end){
        int mid = (start + end) / 2;
        int sum = 0, count = 0;

        for (int i = 0; i < N; i++){
            if(sum + A[i] > mid){
                count++;
                sum = 0;
            }

            sum += A[i];
        }

        if(sum != 0)
            count++;
        
        if(count > M)
            start = mid + 1;
        else
            end = mid - 1;
    }

    cout << start << endl;
}