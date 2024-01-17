// #include<stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int min_coin(vector<int> &coins, int target)
{
    // Table for store the minimum no. of coins for each every amount
    vector<int> N(target + 1, INT_MAX);
    // 0 coins is required when 0 amunt is needed
    N[0] = 0;
    // iterate each coin denomination
    for (int coin : coins)
    {
        //  here update the table for each possibled amount
        for (int i = coin; i <= target; ++i)
        {
            if (N[i - coin] != INT_MAX)
            {
                N[i] = min(N[i], N[i - coin] + 1);
            }
        }
    }

    // If N[target] is still INT_MAX, it means it is not possible to reach target
    return (N[target] == INT_MAX) ? -1 : N[target];
}
int main()
{
    // example
    vector<int> deno = {1, 5, 10};
    int target = 27;
    int result = min_coin(deno, target);
    if (result != -1)
    {
        cout << "Minimum no. of coins required to fulfill target (" << target << ") is " << result << endl;
    }
    else
    {
        cout << "Not possible";
    }

    return 0;
}