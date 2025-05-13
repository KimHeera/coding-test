/*
BOJ 1854.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2025.05.13
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> edge;
int arr[1001][1001];
priority_queue<int> distanceQ[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m ; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        arr[a][b] = c;
    }

    priority_queue<edge, vector<edge>, greater<edge> > pq;

    pq.push(make_pair(0, 1));
    distanceQ[1].push(0);

    while (!pq.empty())
    {
        edge nowNode = pq.top();
        int now = nowNode.second;
        pq.pop();

        for (int i = 1; i <= n; i++){
            if(arr[now][i] != 0){
                if(distanceQ[i].size() < k){
                    distanceQ[i].push(nowNode.first + arr[now][i]);
                    pq.push(make_pair(nowNode.first + arr[now][i], i));
                }
                else if(distanceQ[i].top() > nowNode.first + arr[now][i]){
                    distanceQ[i].pop();
                    distanceQ[i].push(nowNode.first + arr[now][i]);
                    pq.push(make_pair(nowNode.first + arr[now][i], i));
                }
            }
        }
    }

    for (int i = 1; i <= n; i++){
        if(distanceQ[i].size() == k)
            cout << distanceQ[i].top() << "\n";
        else
            cout << -1 << "\n";
    }
}