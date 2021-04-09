/*
**  Author: Kartikey Tewari
**  Time: 10-04-2021  00:40:42
*/

#include <bits/stdc++.h>
using namespace std;

int main(int count, char* inp[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // moving_price_buffer decide how many past/present real_values determine the value of present moving_value
    // higher number means low risk and vice-versa
    int moving_price_buffer=stoi(inp[1]);

    // share_buffer determines what percentage of shares should be sold 
    // lower value means lower risk and vice-versa
    int share_buffer=stoi(inp[2]);

    // number of values
    int n;
    cin >> n;

    vector<int> real_price(n,0);
    for (int i=0;i<=n-1;i++)
    {
        cin >> real_price[i];
    }

    vector<int> moving_price(n,0);
    for (int i=0;i<=n-1;i++)
    {
        int local=0;
        int count_avg=0;
        for (int j=i;j>=max(i-moving_price_buffer,0);j--)
        {
            local+=real_price[j];
            count_avg++;
        }
        cout << "i= " << i << endl;
        moving_price[i]=local/count_avg;
    }

    for (int i=1;i<=n-1;i++)
    {
        if ((real_price[i]>moving_price[i])&&(moving_price[i]>moving_price[i-1]))
        {
            cout << "BUY" << endl;
        }
        else if ((real_price[i]<moving_price[i])&&(moving_price[i]<moving_price[i-1]))
        {
            cout << "SELL" << endl;
        }
    }

    return 0;
}