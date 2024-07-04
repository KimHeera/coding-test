/*
BOJ 1940.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.04
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> numbers(N, 0);

    for (int i = 0; i < N; i++){
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());

    int startIndex = 0, endIndex = N-1;
    int count = 0;

    while(startIndex < endIndex){
        if(numbers[startIndex] + numbers[endIndex] < M){
            startIndex++;
        }
        else if (numbers[startIndex] + numbers[endIndex] > M){
            endIndex--;
        }
        else if (numbers[startIndex] + numbers[endIndex] == M){
            startIndex++;
            endIndex--;
            count++;
        }
    }

    cout << count << endl;
}