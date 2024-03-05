#include <iostream>

using namespace std;

#define MAX 1000001
bool d[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    cin >> M >> N;

    for (int i = 2; i <= N; i++)
        d[i] = true;

    d[1] = false;
    for (int i = 2; i <= N; i++)
    {
        if (!d[i])
            continue;

        for (int j = i + i; j <= N; j += i)
            d[j] = false;
    }

    for (int i = M; i <= N; i++)
    {
        if (d[i])
            cout << i << '\n';
    }
}