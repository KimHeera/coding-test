#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int num;

    cin >> num;
    for (int row = 1; row <= num; row++)
    {

        // 공백은 num - row개 만큼 출력한다.
        for (int i = 0; i < num - row; i++)
        {
            cout << ' ';
        }

        // 별은 row개만큼 출력한다.
        for (int i = 0; i < row; i++)
        {
            cout << '*';
        }

        // 한 행의 출력이 끝나면 개행(줄바꿈)
        cout << '\n';
    }
}