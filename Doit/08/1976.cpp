/*
BOJ 1976.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.16
*/

#include <iostream>
#include <vector>
using namespace std;

void unionFunc(int a, int b);
int find(int a);
vector<int> P;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    P.resize(N + 1);
    for (int i = 1; i <= N; i++)
        P[i] = i;

    int dosi[201][201];
    int path[1001];

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> dosi[i][j];
        }
    }

    for (int i = 1; i <= M; i++){
        cin >> path[i];
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if(dosi[i][j] == 1)
                unionFunc(i, j);
        }
    }

    int index = find(path[1]);
    bool connect = true;
    for (int i = 2; i <= M; i++){
        if(index != find(path[i])){
            connect = false;
            cout << "NO" << endl;
            break;
        }
    }

    if(connect)
        cout << "YES" << endl;
}

void unionFunc(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b)
        P[b] = a;
}

int find(int a){
    if(a == P[a])
        return a;
    else
        return P[a] = find(P[a]);
}