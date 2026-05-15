class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        combinations(candidates, path, 0, target);
        return res;
    }
    
    void combinations(vector<int> candidates, vector<int> &path, int index, int target){
        if(target<0)
            return;
        
        if(target==0){
            res.push_back(path);
            return;
        }
        // Starting from index
        for(int i=index;i<candidates.size(); i++){
            path.push_back(candidates[i]);
            combinations(candidates, path, i+1, target - candidates[i]);
            path.pop_back();
            
            // To eliminates duplicates, as in candidates array has duplicates.
            while(i+1 < candidates.size() && candidates[i+1]==candidates[i]){
                i++;
            }
        }
    }
};