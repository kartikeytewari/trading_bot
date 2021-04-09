/*
**  Author: Kartikey Tewari
**  Time: 10-04-2021  00:34:43
*/

#include <bits/stdc++.h>
using namespace std;

int rand (int a, int b)
{
    return (rand()%(b-a+1))+a;
}

// first argument: number of data values
// second argument: seed value
int main(int count, char* inp[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n=stoi(inp[1]);
    srand(stoi(inp[2]));

    cout << n << endl;
    for (int i=0;i<=n-1;i++)
    {
        cout << (rand()%2000)+1000 << " ";
    }
    cout << endl;

    return 0;
}