class Solution {
public:
    
    int majorityElement(vector<int>& nums) {
        //Logic: As we know there will be only one element of majority, use ans,count to find it.
        int ans = 0, count = 0;
        for(auto& num : nums){
            if(count == 0){
                ans = num; 
                count = 1;
            }else{
                count += (ans == num) ? 1 : -1;
            }
        }
        return ans;
        // map<int,int> m;
        // int count =0,val;
        // for(int i=0;i<v.size();i++){
        //     m[v[i]]++;
        //     if(m[v[i]]>count){
        //         count = m[v[i]];
        //         val = v[i];
        //     }
        // }
        // return val;
        
    }
};