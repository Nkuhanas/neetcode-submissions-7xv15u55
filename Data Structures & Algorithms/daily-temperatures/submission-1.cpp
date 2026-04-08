#include <vector>
#include <stack>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        // it seems reverse iteration here would be better
        // obviously we want something with lookups, rather than iterating all future days for warmer temps
        // although it seems i cant really avoid iterations, so im not sure

        // alternatively, we start a value, then reverse iterate until we hit a next highest value
        // except its an issue to be 

        stack<pair<int, int>> tempStack;
        vector<int> daysUntilNextWarmest;

        for (int i = temperatures.size() - 1; i >= 0; --i) {

            int temp = temperatures[i];
            int distance = 0;
            
            while (!tempStack.empty()) {

                pair<int, int> nextDay = tempStack.top();

                if (nextDay.first > temp) {

                    distance = nextDay.second - i;
                    break;

                } else {

                    tempStack.pop();

                }

            }

            tempStack.push(std::pair(temp, i));
            daysUntilNextWarmest.push_back(distance);

        }

        std::reverse(daysUntilNextWarmest.begin(), daysUntilNextWarmest.end());

        return daysUntilNextWarmest;

    }
};
