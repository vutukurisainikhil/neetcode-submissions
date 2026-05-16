class Solution {
public:
    // Greedy BFS-by-levels: each "jump" expands to the farthest reachable index
    // among all positions in the current jump's range.
    // Time: O(n), Space: O(1).
    int jump(vector<int>& nums) {
        int jumps = 0;             // number of jumps taken so far
        int currentEnd = 0;        // farthest index reachable with `jumps` jumps
        int farthest = 0;          // farthest index reachable with `jumps + 1` jumps
        
        // Iterate up to n-2: we don't need to jump from the last index.
        for (int i = 0; i < nums.size() - 1; i++) {
            // Update the farthest we could reach by extending one more jump from i.
            farthest = max(farthest, i + nums[i]);
            
            // Exhausted current jump's range — must take another jump.
            // The next jump extends to `farthest`.
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};