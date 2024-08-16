/*
BOJ 2251.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.14
*/

#include <iostream>
#include <queue>
using namespace std;

void bfs();
int bottle[3];
bool result[201];
bool visited[201][201];
int sender[] = {0, 0, 1, 1, 2, 2};
int receiver[] = {1, 2, 0, 2, 0, 1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 3; i++){
        cin >> bottle[i];
    }

    bfs();

    for (int i = 0; i < 201; i++){
        if(result[i])
            cout << i << " ";
    }
}

void bfs(){
    queue<pair<int, int>> myQ;
    myQ.push(make_pair(0, 0));
    visited[0][0] = true;
    result[bottle[2]] = true;

    while(!myQ.empty()){
        pair<int, int> now = myQ.front();
        myQ.pop();

        int A = now.first;
        int B = now.second;
        int C = bottle[2] - A - B;

        for (int k = 0; k < 6; k++){
            int next[] = {A, B, C};

            next[receiver[k]] += next[sender[k]];
            next[sender[k]] = 0;

            if(next[receiver[k]] > bottle[receiver[k]]){
                next[sender[k]] = next[receiver[k]] - bottle[receiver[k]];
                next[receiver[k]] = bottle[receiver[k]];
            }

            if(!visited[next[0]][next[1]]){
                visited[next[0]][next[1]] = true;
                myQ.push(make_pair(next[0], next[1]));

                if(next[0] == 0)
                    result[next[2]] = true;
            }
        }
    }
}