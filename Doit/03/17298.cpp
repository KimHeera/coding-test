/*
BOJ 17298.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.16
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; //수열 A의 크기
    cin >> N;

    vector<int> A(N, 0);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    
    vector<int> result(N, -1);
    stack<int> mystack;

    for (int i = 0; i < N; i++)
    {
        while (!mystack.empty() && A[mystack.top()] < A[i])
        {
            result[mystack.top()] = A[i];
            mystack.pop();
        }
        mystack.push(i);
    }

    
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
}