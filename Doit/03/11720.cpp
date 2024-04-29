#include <iostream>
using namespace std;

int main(){
    int N;
    string numbers;
    int sum = 0;

    cin >> N >> numbers;

    for (char num : numbers){
        sum += num - '0';
    }
    cout << sum;
}