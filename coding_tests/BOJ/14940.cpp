/*
BOJ 14940.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.09.11
*/

#include <iostream>
#include <queue>
using namespace std;

int P[1001][1001];
int result[1001][1001];
void bfs(int a);
int n, m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int num;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            result[i][j] = 0;
            cin >> P[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        bfs(i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}

void bfs(int a){
    queue<int> myQ;
    myQ.push(a);

    while(!myQ.empty()){
        int now = myQ.front();
        myQ.pop();

        for (int i = 0; i < m; i++){
            if(P[now][i] != 2){
                myQ.push(P[now][i]);
                result[now][i]++;
            }

            if(P[now][i] == 0)
                result[now][i] = 0;
        }
    }
}