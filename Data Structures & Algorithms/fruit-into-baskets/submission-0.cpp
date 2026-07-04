class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int l = 0;

        for (int r = 0; r < fruits.size(); r++) {
            count[fruits[r]]++;

            if (count.size() > 2) {
                count[fruits[l]]--;
                if (count[fruits[l]] == 0) {
                    count.erase(fruits[l]);
                }
                l++;
            }
        }

        return fruits.size() - l;
    }
};