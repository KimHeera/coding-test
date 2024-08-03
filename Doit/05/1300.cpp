/*
BOJ 1300.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.03
*/

#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N, k;
    cin >> N >> k;
    long result;

    long start = 1, end = k;

    while(start <= end){
        long mid = (start + end) / 2;
        long cnt = 0;

        for (int i = 1; i <= N; i++){
            cnt += min(mid / i, N);
        }

        if(cnt < k)
            start = mid + 1;
        else{
            end = mid - 1;
            result = mid;
        }
    }

    cout << result << endl;
}