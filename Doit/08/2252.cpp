/*
BOJ 2252.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.25
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> P;
vector<int> student;

int main(){
    int N, M;
    cin >> N >> M;

    P.resize(N + 1);
    student.resize(N + 1, 0);

    for (int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        P[A].push_back(B);
        student[B]++;
    }

    queue<int> result;

    for (int i = 1; i <= N; i++){
        if (student[i] == 0)
        {
            result.push(i);
        }
    }   

    while(!result.empty()){
        int now = result.front();
        result.pop();
        cout << now << " ";

        for (int i = 0; i < P[now].size(); i++){
            student[P[now][i]]--;

            if (student[P[now][i]] == 0)
                result.push(P[now][i]);
        }
    }
}