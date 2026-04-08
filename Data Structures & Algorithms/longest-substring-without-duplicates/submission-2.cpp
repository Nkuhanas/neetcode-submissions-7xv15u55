#include <unordered_map>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, bool> existingChars;

        string longestSubstring;
        string currentSubstring;

        for (char c : s) {

            if (existingChars[c]) {

                if (currentSubstring.length() > longestSubstring.length()) {
                    longestSubstring = currentSubstring;
                }

                if (currentSubstring[0] == c) {

                    currentSubstring.erase(0, 1);

                } else {

                    currentSubstring = "";
                    existingChars.clear();

                }

            }

            currentSubstring += c;
            existingChars[c] = true;

        }

        if (currentSubstring.length() > longestSubstring.length()) {
            longestSubstring = currentSubstring;
        }

        return longestSubstring.length();

    }
};
