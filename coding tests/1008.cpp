/*
첫째 줄에 A/B를 출력한다. 실제 정답과 출력값의 절대오차 또는 상대오차가 10-9 이하이면 정답이다.
*/
#include <iostream>

using namespace std;

int main()
{
    double num1, num2;
    cin >> num1 >> num2;

    printf("%.9lf", num1 / num2);
}