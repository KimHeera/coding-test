/*
BOJ 21568.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.12
*/

#include <iostream>
#include <vector>
using namespace std;

long gcd(long a, long b);
vector<long> calculate(long a, long b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    long mgcd = gcd(a, b);
    int result = 1;

    if (c % mgcd != 0)
        cout << -1 << endl;
    else{
        int mok = (int)(c / mgcd);
        vector<long> ret = calculate(a, b);
        cout << ret[0] * mok << " " << ret[1] * mok;
    }
}

long gcd(long a, long b){
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

vector<long> calculate(long a, long b){
    vector<long> ret(2);

    if (b == 0){
        ret[0] = 1;
        ret[1] = 0;
        return ret;
    }

    long q = a / b; //현재 몫
    vector<long> v = calculate(b, a % b); //재귀 형태로 호제법 수행
    ret[0] = v[1]; //역으로 올라오면서 x, y값을 계산하는 로직
    ret[1] = v[0] - v[1] * q;
    return ret;
}