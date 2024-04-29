#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int findNumber;
    srand(time(NULL));
    findNumber = rand() % 100; // 0 ~ 99 사이의 값 무작위 선택

    for(int i = 0; i < 100; i++){
        if(i == findNumber){
            cout << i;
            break;
        }
    }
}

/*
코딩 테스트에서는 O(n) 표기법을 기준으로 수행 시간을 계산하는 것이 좋다. 
응시자가 작성한 프로그램으로 다양한 테스트 케이스를 수행해 모든 케이스를 통과해야만 합격하므로 최악의 시간 복잡도를 염두에 두어야 한다.
*/