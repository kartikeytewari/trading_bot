/*
**  Author: Kartikey Tewari
**  Time: 10-04-2021  00:40:42
*/

#include <bits/stdc++.h>
using namespace std;

// share buy logic
pair<int,int> share_buy(pair<int,int> initial_asset, int price, int buffer)
{
    pair<int,int> local=initial_asset;
    int max_share_buy=min(local.first/price, buffer);
    local.first-=max_share_buy*price;
    local.second+=max_share_buy;

    return local;
}

// share sell logic
pair<int,int> share_sell (pair<int,int> initial_asset, int price, int buffer)
{
    pair<int,int> local=initial_asset;
    int max_share_sell=min(local.second, buffer);
    local.first+=max_share_sell*price;
    local.second-=max_share_sell;

    return local;
}

void print_asset(pair<int,int> asset)
{
    cerr << "Money with the bot = " << asset.first << endl;
    //cerr << "Share with the bot = " << asset.second << endl;
}

int main(int count, char* inp[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // money with bot: asset.first
    // share with bot: asset.second
    pair<int,int> asset;
    asset.first=stoi(inp[1]);
    asset.second=0;

    // moving_price_buffer decide how many past/present real_values determine the value of present moving_value
    // higher number means low risk and vice-versa
    int moving_price_buffer=stoi(inp[2]);

    // share_buffer determines what number of shares should be sold 
    // lower value means lower risk and vice-versa
    int share_buffer=stoi(inp[3]);

    // number of values
    int n;
    cin >> n;

    print_asset(asset);

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
        moving_price[i]=local/count_avg;
    }

    for (int i=1;i<=n-1;i++)
    {
        if ((real_price[i]>moving_price[i])&&(moving_price[i]>moving_price[i-1]))
        {
            asset=share_sell(asset,real_price[i],share_buffer);
            cout << "BUY" << endl;
        }
        else if ((real_price[i]<moving_price[i])&&(moving_price[i]<moving_price[i-1]))
        {
            asset=share_buy(asset,real_price[i],share_buffer);
            cout << "SELL" << endl;
        }
    }

    asset=share_sell(asset,real_price[n-1],asset.second);
    print_asset(asset);

    return 0;
}