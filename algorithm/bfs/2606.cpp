#include <iostream>
#include <queue>

using namespace std;

#define MAXNUM 101

int network[MAXNUM][MAXNUM];
int computerNum;
int cnt = 0;
bool visited[MAXNUM] = {
    0,
};
queue<int> que;

void bfs(int node)
{
    que.push(node);
    visited[node] = true;

    while(!que.empty()){
        node = que.front();
        que.pop();

        for (int i = 1; i <= computerNum; i++)
        {
            if (network[node][i] && !visited[i] == 0)
            {
                que.push(i);
                visited[i] = true;
                cnt++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int connnectNum;

    cin >> computerNum;
    cin >> connnectNum;

    int node1, node2;

    for (int i = 0; i < connnectNum; i++)
    {
        cin >> node1 >> node2;

        network[node1][node2] = network[node2][node1] = 1;
    }

    bfs(1);

    cout << cnt;
    return 0;
}