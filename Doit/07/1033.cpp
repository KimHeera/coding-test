/*
BOJ 1033.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.12
*/

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N;
vector<tuple<int, int, int>> P[10];
bool visited[10];
int D[10];

long gcd(int a, int b);
void dfs(int index);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int lcm = 1;

    for (int i = 0; i < N - 1; i++){
        int a, b, p, q;
        cin >> a >> b >> p >> q;

        P[a].push_back(make_tuple(b, p, q));
        P[b].push_back(make_tuple(a, p, q));
        lcm *= a * b / gcd(a, b);
    }

    D[0] = lcm;
    dfs(0);

    long mgcd = D[0];
    for (int i = 1; i < N; i++){
        mgcd = gcd(mgcd, D[i]);
    }

    for (int i = 0; i < N; i++){
        cout << D[i] << "\n";
    }
}

long gcd(int a, int b){
    if(b == 0)
        return a;
    
    else
        return gcd(b, a % b);
}

void dfs(int index){
    visited[index] = true;

    for (int i = 0; i < N; i++){
        int next = get<0>(P[index][i]);
        if(!visited[next]){
            D[next] = D[index] * get<2>(P[index][i]);
            dfs(next);
        }
    }
}