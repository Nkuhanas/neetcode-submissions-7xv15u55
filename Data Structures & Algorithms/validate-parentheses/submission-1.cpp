#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        
        vector<char> closures;
        
        unordered_map<char, char> closuresMap = { 
            {'(', ')'}, 
            {'{', '}'}, 
            {'[', ']'}
        };

        for (char c : s) {

            char closure = closuresMap[c];

            if (!closures.empty() && !closure) {

                if (c != closures.back()) {

                    return false;

                }

                closures.pop_back();
                continue;

            }

            closures.push_back(closure);

        }

        return closures.size() <= 0;

    }
};
