class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            // Get the middle index between left and right boundary indexes.
            // hourSpent stands for the total hour Koko spends.
            int middle = left + (right - left) / 2;
            int hourSpent = 0;
            // Iterate over the piles and calculate hourSpent.
            // We increase the hourSpent by ceil(pile / middle).
            for (int pile : piles) {
                hourSpent += pile / middle + ((pile % middle != 0) ? 1 : 0);
            }
            // Check if middle is a workable speed, and cut the search space by
            // half.
            if (hourSpent <= h) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        // Once the left and right boundaries coincide, we find the target
        // value, that is, the minimum workable eating speed.
        return right;
    }
};
