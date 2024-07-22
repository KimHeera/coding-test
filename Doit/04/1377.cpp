/*
BOJ 1377.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.22
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> array(N);

    for (int i = 0; i < N; i++){
        cin >> array[i].first;
        array[i].second = i;
    }

    sort(array.begin(), array.end());

    int max = 0;
    for (int i = 0; i < N; i++){
        if(max < array[i].second - i){
            max = array[i].second - i;
        }
    }

    cout << max + 1 << endl;
}