/*
BOJ 1389.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2025.06.25
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<int> > edges;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    edges.resize(N + 1);

    for (int i = 1; i <= N; i++){
        edges[i].resize(N + 1, 1000001);
        edges[i][i] = 0;
    }

    int A, B;
    for (int i = 0; i < M; i++){
        cin >> A >> B;

        edges[A][B] = 1;
        edges[B][A] = 1;
    }
    
    for (int i = 1; i <= N; i++){
        for (int s = 1; s <= N; s++){
            for (int e = 1; e <= N; e++){
                if (edges[s][e] > edges[s][i] + edges[i][e])
                    edges[s][e] = min(edges[s][e], edges[s][i] + edges[i][e]);
            }
        }
    }

    int arr[N + 1];
    for (int i = 1; i <= N; i++){
        arr[i] = 0;
        for (int j = 1; j <= N; j++){
            arr[i] += edges[i][j];
        }
    }

    int result = 1;
    for (int i = 2; i <= N; i++){
        if(arr[result] > arr[i])
            result = i;
    }


    cout << result;
}