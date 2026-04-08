#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {

        std::erase_if(s, [](unsigned char c) {
            return !std::isalnum(c);
        });

        int length = s.length();

        for (int i = 0; i < length/2; ++i) {

            if (std::tolower(s[i]) != std::tolower(s[length-i-1])) {
                return false;
            }

        }

        return true;
    }
};
