class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        bool isWordEnd = false;
};

class WordDictionary {
    TrieNode* trie;
public:
    WordDictionary() {
        trie = new TrieNode;
    }
    
    void addWord(string word) {
        TrieNode* cur = trie;
        for(auto s: word){
            if(cur->children[s] == nullptr){
                cur->children[s] = new TrieNode;
            }
            cur = cur->children[s];
        }
        cur->isWordEnd = true;
    }
    bool search(string word){
        TrieNode* cur = trie;
        return search_helper(word, cur);
    }
    
    bool search_helper(string word, TrieNode* cur) {
        for(int i=0;i<word.size();i++){
            if(word[i] == '.'){
                for(char j='a';j<'z';j++){
                    if((cur->children[j] != NULL) && search_helper(word.substr(i+1), cur->children[j])){
                        return true;
                    }
                }
                return false; // if not found with regex return false
            }
            else if(cur->children[word[i]] == nullptr){
                return false;
            }
            else {
                cur = cur->children[word[i]];
            }
        }
        return cur->isWordEnd;
    }
};
