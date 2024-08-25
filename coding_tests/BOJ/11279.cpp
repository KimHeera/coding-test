/*
BOJ 11279.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.25
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, less<int>> maxHeap;

    int N;
    cin >> N;

    int x;
    while (N--){
        cin >> x;

        if(x == 0){
            if(!maxHeap.empty()){
                cout << maxHeap.top() << "\n";
                maxHeap.pop();
            }
            else
                cout << 0 << "\n";
        }
        else{
            maxHeap.push(x);
        }
    }
}