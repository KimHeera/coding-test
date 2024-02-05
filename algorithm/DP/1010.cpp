#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > bridge(30, vector<int>(30, 0));

int comb(int M, int N){
    if(bridge[M][N] != 0)
        return bridge[M][N];

    if(N == 0 || M == N){
        bridge[M][N] = 1;
        return bridge[M][N];
    }else{
        bridge[M][N] = comb(M - 1, N - 1) + comb(M - 1, N);
        return bridge[M][N];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int testcase;
    cin >> testcase;

    int N, M;
    for (int i = 0; i < testcase; i++)
    {
        cin >> N >> M;
        cout << comb(M, N) << "\n";
    }
}

// #include <iostream>

// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int testcase;
//     cin >> testcase;

//     int N, M, tmp;
//     while (testcase--)
//     {
//         long long result = 1;
//         cin >> N >> M;
//         tmp = M;
//         M = N;
//         N = tmp;

//         if(M > N-M)
//             M = N - M;

//         for (int i = N; i > N - M; i--)
//             result *= i;

//         for (int i = M; i >= 1; i--)
//             result /= i;

//         cout << result << "\n";
//     }
// }