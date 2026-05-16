class Solution {
public:
    // Time Complexity = O(NlogN + N)

    // A fleet of size > 1 is formed if a car is slower than the car behind it
    // and there is enough time for the car behind to catch the car in front
    // before reaching the target destination
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int /*position*/, int /*speed*/>> cars;

        for (int i = 0; i < n; i++) {
            cars.push_back(make_pair(position[i], speed[i]));
        }
        stack<float> st;
        sort(cars.begin(), cars.end()); // sorting cars(postion, speed).
        for (int i = 0; i < n; i++) {
            float time = (float)(target - cars[i].first /*position*/) /
                         (float)cars[i].second /*speed*/;
            // if top <= time, means they can become fleet at some point of time.
            while (!st.empty() && st.top() <= time) {
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};