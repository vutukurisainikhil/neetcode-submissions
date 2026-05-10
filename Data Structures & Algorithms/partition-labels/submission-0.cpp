class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        vector<int> last_occurance(26, 0);
        for(int i=0;i<s.size();i++){
            last_occurance[s[i]-'a'] = i;
        }

        int start_index = 0,  lastOccuranceExists = 0;
        for(int i=0; i<s.size();i++){
            // Logic which checks for complete chars last occurance.
            lastOccuranceExists = max(lastOccuranceExists, last_occurance[s[i]-'a']);
            // if found, then push as result.
            if(i == lastOccuranceExists){
                res.push_back( i - start_index + 1);
                start_index = i+1;
            }
        }
        return res;
    }
};