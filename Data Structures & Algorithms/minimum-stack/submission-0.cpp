#include <stack>
#include <set>
#include <unordered_map>

class MinStack {
public:
    MinStack() = default;
    
    void push(int val) {
        
        valuesStack.push(val);
        valuesAvailable.insert(val);
        ++valuesMap[val];

    }
    
    void pop() {
        
        int value = valuesStack.top();
        --valuesMap[value];
        valuesStack.pop();

        if (valuesMap[value] <= 0) {

            valuesAvailable.erase(value);

        }

    }
    
    int top() {
        
        return valuesStack.top();

    }
    
    int getMin() {
        
        return *valuesAvailable.begin();

    }

private:
    stack<int> valuesStack;
    set<int> valuesAvailable;
    unordered_map<int, int> valuesMap;
};