#include <unordered_map>
#include <vector>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> frequencies;
        vector<pair<int, int>> numPairs;
        vector<int> topFrequent;

        for (int i : nums) {

            frequencies[i] += 1;

        }

        for (auto const& pair : frequencies) {

            numPairs.push_back(pair);

        }

        std::sort(numPairs.begin(), numPairs.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        for (int i=0; i < k; ++i) {

            topFrequent.push_back(numPairs[i].first);

        }

        return topFrequent;

    }
};
