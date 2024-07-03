#include <iostream>
#include <string.h>
using namespace std;

/**
BOJ 11660.
Author: Heera Kim
E-mail Address: heeee998@handong.ac.kr
C++ 
Last Changed: 2024.05.07
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int numbers[N+1][N+1];
    int D[N + 1][N + 1];
    memset(numbers, 0, sizeof(numbers));
    memset(D, 0, sizeof(D));
    int input;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++){
            cin >> input;
            numbers[i][j] = input;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            D[i][j] = D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1] + numbers[i][j];
        }
    }

    int x1, x2, y1, y2;
    for (int i = 0; i < M; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int result = D[x2][y2] - D[x1 - 1][y2] - D[x2][y1 - 1] + D[x1 - 1][y1 - 1];
        cout << result << "\n";
    }
}