#include <vector>
#include <stack>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        // it seems reverse iteration here would be better
        // obviously we want something with lookups, rather than iterating all future days for warmer temps
        // although it seems i cant really avoid iterations, so im not sure

        // alternatively, we start a value, then reverse iterate until we hit a next highest value
        // except its an issue to be iterating through the stack again?
        // i have no idea what time complexity that is

        const int size = static_cast<int>(temperatures.size());

        vector<pair<int, int>> tempStack;
        vector<int> daysUntilNextWarmest(size, 0);

        for (int i = size - 1; i >= 0; --i) {

            int temp = temperatures[i];
            int distance = 0;
            
            while (!tempStack.empty()) {

                pair<int, int> nextDay = tempStack.back();

                if (nextDay.first > temp) {

                    distance = nextDay.second - i;
                    break;

                } else {

                    tempStack.pop_back();

                }

            }

            tempStack.push_back(pair(temp, i));
            daysUntilNextWarmest[i] = distance;

        }

        return daysUntilNextWarmest;

    }
};
