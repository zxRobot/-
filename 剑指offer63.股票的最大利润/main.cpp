#include <vector>
using namespace std;
int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len<=1)
        {
            return 0;
        }
        int profit=0;
        int min=prices[0];
        for(int i=0;i<len;i++)
        {
            min=prices[i]<min?prices[i]:min;
            profit=profit>prices[i]-min?profit:prices[i]-min;
        }
        return profit;
    }