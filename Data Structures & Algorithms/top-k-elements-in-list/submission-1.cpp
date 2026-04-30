class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        std::priority_queue<std::pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        
        for(auto [key,val]:m){
            heap.push({val, key});
            if(heap.size()>k){
                heap.pop();
            }
        }

        std::vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
