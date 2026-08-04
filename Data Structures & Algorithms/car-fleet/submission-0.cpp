class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
       
        vector<pair<int, double>> cars(n);

        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }

        
        sort(cars.begin(), cars.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.first > b.first;
        });

        int fleets = 0;
        double max_time = 0.0;

        for (const auto& car : cars) {
            double current_time = car.second;

            if (current_time > max_time) {
                fleets++;
                max_time = current_time;
            }
        }

        return fleets;
    }
};