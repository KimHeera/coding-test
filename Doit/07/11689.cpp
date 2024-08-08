/*
BOJ 11689.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.08
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long n;
    cin >> n;

    long result = n;
    for (long i = 2; i <= sqrt(n); i++){
        if(n%i == 0){ //i가 소수인지 확인
            result = result - result / i; //결괏값 업데이트
            while(n%i == 0) //해당 소인수 지우기(2^7*11이라면 2^7을 없애고 11만 남김)
                n /= i;
        }
    }

    if(n>1) //아직 소인수 구성이 남아있는 경우
        result = result - result / n; //반복문에서 제곱근까지만 탐색했기 때문에 1개의 소인수가 누락되는 케이스

    cout << result << endl;
}