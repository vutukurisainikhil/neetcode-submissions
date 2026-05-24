class Solution {
public:
   // O(N × K log K) 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       std::map<string,std::vector<string>> m;
       for(int i=0;i<strs.size();i++){
          std::string s = strs[i];
          sort(s.begin(),s.end());
          m[s].push_back(strs[i]);
       }

       std::vector<std::vector<std::string>> res;
       for(auto& [k,val]: m){
         res.push_back(val);
       }
       return res;
    }
};
