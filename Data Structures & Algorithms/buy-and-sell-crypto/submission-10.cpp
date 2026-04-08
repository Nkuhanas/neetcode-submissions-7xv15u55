#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // okay what if i just start from the middle instead and go from there

        int profit = 0;

        int left = 0;
        int right = 1;

        int lowestBuying = prices[left];

        while (right < prices.size()) {

            lowestBuying = std::min(lowestBuying, prices[left]);
            profit = std::max(profit, prices[right] - lowestBuying);

            if (prices[right] <= lowestBuying) {
                
                left = right;

            }

            ++right;

        }


        return profit;

    }
};
