/* 메모리초과 코드
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAX 100

using namespace std;

int W, H;
char map[MAX][MAX];
int visited[MAX][MAX];
pair<int, int> Start, End;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int first, int second){
    queue<pair<pair<int, int>, pair<int, int> > > q;

    for (int i = 0; i < 4; i++){
        q.push(make_pair(make_pair(first, second), make_pair(i, 0)));
    }
    visited[first][second] = 0;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second.first;
        int cnt = q.front().second.second;

        q.pop();

        for (int i = 0; i < 4; i ++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ncnt = cnt;

            if(nx < 0 || ny < 0 || nx > H || ny > W) continue;
            if(map[nx][ny] == '*') continue;
            if(dir != i)
                ncnt++;
            if(visited[nx][ny] >= ncnt){
                visited[nx][ny] = ncnt;
                q.push(make_pair(make_pair(nx, ny), make_pair(i, ncnt)));
            }
        }
    }
    return visited[End.first][End.second];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> W >> H;

    bool flag = true;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++){
            cin >> map[i][j];
            if(map[i][j] == 'C'){
                if(flag){
                    Start.first = i;
                    Start.second = j;
                    flag = false;
                }
                else {
                    End.first = i;
                    End.second = j;
                }
            }
            visited[i][j] = 9876;
        }
    }

    int result = bfs(Start.first, Start.second);
    cout << result << endl; 
}
*/

/* 시간초과 코드
#include <queue>
#include <vector>
#include <iostream>

#define INF 1000000000

using namespace std;

int w, h;
char map[101][101];
int dp[101][101];
priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
pair<int, int> start;
pair<int, int> ended;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS()
{

    while (!pq.empty())
    {
        int cnt = -pq.top().first.first;
        int direct = pq.top().first.second;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();

        if (dp[i][j] < cnt)
            continue;
        dp[i][j] = cnt;

        for (int k = 0; k < 4; k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                continue;
            if (map[nx][ny] == '*')
                continue;

            int next_cnt = (direct == k) ? cnt : cnt + 1;
            if (dp[nx][ny] < next_cnt)
                continue;
            dp[nx][ny] = next_cnt;
            pq.push({{-next_cnt, k},
                     {nx, ny}});
        }
    }
    cout << dp[ended.first][ended.second];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> w >> h;
    string s;
    bool flag = false;
    for (int i = 0; i < h; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            map[i][j] = s[j];
            if (s[j] == 'C')
            {
                if (!flag)
                {
                    start = {i, j};
                    flag = true;
                }
                else
                {
                    ended = {i, j};
                }
            }
            dp[i][j] = INF;
        }
    }

    dp[start.first][start.second] = 0;
    for (int k = 0; k < 4; k++)
    {
        int nx = start.first + dx[k];
        int ny = start.second + dy[k];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w)
            continue;
        if (map[nx][ny] == '*')
            continue;
        dp[nx][ny] = 0;
        pq.push(make_pair(make_pair(0, k), make_pair(nx, ny)));
    }

    BFS();
}
*/

//정답 코드
#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char arr[100][100];
int cnt[100][100] = {
    0,
};
bool visit[100][100] = {
    0,
};
int W, H;

void bfs(int x, int y)
{
    queue<pair<int, int>> bfsQ;
    bfsQ.push(pair<int, int>(x, y));

    while (!bfsQ.empty())
    {
        pair<int, int> p = bfsQ.front();
        bfsQ.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            while (nx >= 0 && ny >= 0 && nx < H && ny < W && arr[nx][ny] != '*')
            {
                if (cnt[nx][ny] == 0)
                {
                    cnt[nx][ny] = cnt[p.first][p.second] + 1;
                    bfsQ.push(pair<int, int>(nx, ny));
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
}

int main()
{
    cin >> W >> H;
    int x, y;
    int endX, endY;
    bool chk = false;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'C' && !chk)
            {
                x = i;
                y = j;
                chk = true;
            }
            else if (arr[i][j] == 'C' && chk)
            {
                endX = i;
                endY = j;
            }
        }
    }

    bfs(x, y);

    cout << cnt[endX][endY] - 1 << endl;

    return 0;
}