#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int numbers[N+1]; //배열 크기를 N으로 했을 때 outOfBounds가 뜸. N+1로 바꾸니 잘 작동됨
    for (int i = 1; i <= N; i++){
        int input;
        cin >> input;

        numbers[i] = numbers[i - 1] + input;
    }

    int i, j;
    for (int k = 0; k < M; k++){
        cin >> i >> j;
        cout << numbers[j] - numbers[i - 1] << "\n";
    }
}