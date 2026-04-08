#include <vector>
#include <set>

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        // ok essentially we need to figure out how many steps ((target-position) / speed)
        // each car needs to reach the target
        // once each car is assigned a steps value, we figure out how many cars share a steps count
        // as they will be considered a fleet
        // then we return the amount of distinct fleets

        // ok so, cars are limited by the speed of the cars infront of them yikes
        // it looks like we'll need to reverse iterate and limit the speed of each car
        // by the next fastest car in front of them

        // i think continue with calculating the steps of each car
        // 

        set<double> stepsSet;
        vector<pair<int, int>> cars;

        for (int i = position.size() - 1; i >= 0; --i) {

            cars.push_back(pair(position[i], speed[i]));

        }

        std::sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });

        double steps = 0;

        for (int i = cars.size() - 1; i >= 0; --i) {

            pair<int, int> car = cars[i];

            steps = std::max(steps, static_cast<double>(target - car.first) / static_cast<double>(car.second));

            stepsSet.insert(steps);

        }

        return stepsSet.size();

    }
};
