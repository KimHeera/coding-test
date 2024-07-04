/**
BOJ 2018.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.04
*/

#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int startIndex = 1, endIndex = 1;
    int count = 1, sum = 1;

    cin >> N;

    while(endIndex != N){
        if(sum == N) {
            count++;
            endIndex++;
            sum += endIndex;
        }
        else if(sum > N){
            sum -= startIndex;
            startIndex++;
        }
        else if(sum < N){
            endIndex++;
            sum += endIndex;
        }
    }

    cout << count << endl;
}