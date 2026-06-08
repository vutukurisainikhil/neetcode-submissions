class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        std::priority_queue<std::pair<int,int>> maxheap;
        
        for(auto [key,val]:m){
            maxheap.push({val, key});
        }

        std::vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return res;
    }
};
