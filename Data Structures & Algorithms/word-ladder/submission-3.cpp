class Solution {
public:
    // TimeComplexity: O(N*L^2)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            pair<string,int> curr = q.front();q.pop();
            int steps = curr.second;
            string word = curr.first;
            if(word==endWord) 
                return steps; // first early return would be shortest transformation seq.
            for(int i=0;i<word.length();i++){
                char org = word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(set.find(word)!=set.end()) {
                        q.push({word,steps+1});
                        set.erase(word);
                    }
                }
                word[i]=org; 
            }
        }
    return 0;
    }
};