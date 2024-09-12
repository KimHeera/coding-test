/*
BOJ 1516.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.09.12
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> P;
    vector<int> W(N + 1, 0);
    vector<int> count(N + 1, 0);
    vector<int> result(N + 1, 0);

    P.resize(N + 1);

    int input;
    for (int i = 1; i < N + 1; i++){
        cin >> input;
        W[i] = input;

        while(true){
            cin >> input;

            if(input == -1)
                break;
            P[input].push_back(i);
            count[i]++;
        }
    }

    queue<int> myQ;
    for (int i = 1; i < N + 1; i++){
        if(count[i] == 0)
            myQ.push(i);
    }

    while(!myQ.empty()){
        int now = myQ.front();
        myQ.pop();

        for (int i = 0; i < P[now].size(); i++){
            count[P[now][i]]--;
            result[P[now][i]] = max(result[P[now][i]], result[now] + W[now]);

            if (count[P[now][i]] == 0)
                myQ.push(P[now][i]);
        }
    }

    for (int i = 1; i < N + 1; i++){
        cout << result[i] + W[i] << "\n";
    }
}