#include <iostream>

using namespace std;
#define SIX 6

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int cnt = 0;

    for (int max = 2; max <= N; cnt++){
        max += cnt * SIX;
    }

    if(N == 1)
        cnt = 1;

    cout << cnt;
}