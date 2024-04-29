#include <iostream>

using namespace std;

int main(){
    int N;

    cin >> N;

    int scores[N];

    for (int i = 0; i < N; i++){
        cin >> scores[i];
    }

    long maxScore = 0;
    long sum = 0;

    for (int i = 0; i < N; i++){
        sum += scores[i];
        if(scores[i] > maxScore)
            maxScore = scores[i];
    }

    double avg = sum * 100.0 / N / maxScore;
    cout << avg;
}