
#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        std::unordered_map<char, int> charMap;

        if (s.length() != t.length()) {
            return false;
        }

        for (char c : s) {

            charMap[c]++;

        }

        for (char c : t) {

            if (not charMap.contains(c)) {
                return false;
            }

            charMap[c]++;

        }

        for (const auto& [_, value] : charMap) {

            if (value % 2 == 1) {

                return false;

            }

        }

        return true;


    }
};
