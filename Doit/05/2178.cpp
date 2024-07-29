/*
BOJ 2178.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.29
*/

#include <iostream>
#include <queue>
using namespace std;

void BFS(int i, int j);
static int dx[] = {1, 0, -1, 0};
static int dy[] = {0, -1, 0, 1};
int P[101][101];
bool visited[101][101] = {false};
int N, M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++){
        string s;
        cin >> s;

        for (int j = 0; j < M; j++){
            P[i][j] = s[j] - '0';
        }
    }

    BFS(0, 0);
    cout << P[N - 1][M - 1] << endl;
}

void BFS(int i, int j){
    queue<pair<int, int>> myQueue;
    myQueue.push(make_pair(i, j));

    while(!myQueue.empty()){
        int now[2];
        now[0] = myQueue.front().first;
        now[1] = myQueue.front().second;
        myQueue.pop();
        visited[i][j] = true;

        for (int k = 0; k < 4; k++){
            int x = now[0] + dx[k];
            int y = now[1] + dy[k];

            if(x >= 0 && y >= 0 && x < N && y < M){
                if(P[x][y] != 0 && !visited[x][y]){
                    visited[x][y] = true;
                    P[x][y] = P[now[0]][now[1]] + 1;
                    myQueue.push(make_pair(x, y));
                }
            }
        }
    }
}