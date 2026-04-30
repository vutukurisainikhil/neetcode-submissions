class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<int,int> m;
        if(s.length()!=t.length()){
            return false;
        }
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            if(m[t[i]]==0){
                return false;
            }
            m[t[i]]--;
            if(m[t[i]]==0){
                m.erase(t[i]);
            }
        }
        return true;
    }
};
