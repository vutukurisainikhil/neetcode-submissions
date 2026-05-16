class TrieNode {
   public:
    unordered_map<char, TrieNode*> children;
    bool isEndWord = false;
};
/* we can use unordered_map in place to trie struct for faster runtime*/
class WordDictionary {
    TrieNode* root;

   public:
    WordDictionary() { root = new TrieNode; }

    /*Generic way to add word to trie*/
    void addWord(string word) {
        TrieNode* temp = this->root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->children[word[i]] == NULL) {
                temp->children[word[i]] = new TrieNode();
            }
            temp = temp->children[word[i]];
        }
        temp->isEndWord = true;
    }

    /* When '.' occurs in word, we need check whether regex word is found or
     * not. */
    bool search_help(string word, TrieNode* temp) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                for (char j = 'a'; j <= 'z'; j++) {
                    if (temp->children[j] != NULL &&
                        search_help(word.substr(i + 1), temp->children[j])) {
                        // this '&& search_help' is need to check whether it is
                        // valid or not.
                        return true;
                    }
                }
                // if '.' doesnt return true, then its false as we dont see any
                // search combination.
                return false;
            } else if (temp->children[word[i]] == NULL) {
                return false;
            } else {
                temp = temp->children[word[i]];
            }
        }
        return temp->isEndWord;
    }

    bool search(string word) {
        TrieNode* temp = this->root;
        return search_help(word, temp);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */