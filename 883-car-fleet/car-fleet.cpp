class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,double>> cars;

        for(int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort from closest to target
        sort(cars.begin(), cars.end(), greater<pair<int,double>>());

        stack<double> fleets;

        for(auto &car : cars) {

            double time = car.second;

            // If it cannot catch the fleet ahead
            if(fleets.empty() || time > fleets.top()) {
                fleets.push(time);
            }
        }

        return fleets.size();
    }
};