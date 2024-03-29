#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;

    vector<vector<int> > matrix(N + 1, vector<int>(M + 1, 0));
    vector<vector<int> > dp(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++){
            cin >> matrix[i][j];
            dp[i][j] = matrix[i][j];
        }
    }

    for (int i = 1; i <=N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            dp[i][j] = matrix[i][j] + max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
        }
    }

    cout << dp[N][M];
}