struct trie_node{
    trie_node* data[26];
    bool end;
    trie_node(){
        for(int i=0;i<26;i++){
            data[i]=NULL;
        }
        end = false;
    }
};
/* we can use unordered_map in place to trie struct for faster runtime*/
class WordDictionary {
    trie_node* root;
public:
    WordDictionary() {
        root = new trie_node;
    }
    
    /*Generic way to add word to trie*/
    void addWord(string word) {
        trie_node* temp = this->root;
        for(int i=0;i<word.size();i++){
            if(temp->data[word[i]-'a']==NULL){
                temp->data[word[i]-'a'] = new trie_node();
            }
            temp = temp->data[word[i]-'a'];
        }
        temp->end = true;
    }
    
    /* When '.' occurs in word, we need check whether regex word is found or not. */
    
    bool search_help(string word, trie_node* temp){
        for(int i=0;i<word.size();i++){
            if(word[i]=='.'){
                for(int j=0;j<26;j++){
                    if(temp->data[j]!=NULL && search_help(word.substr(i+1),temp->data[j])){ 
     // this '&& search_help' is need to check whether it is valid or not.
                        return true;
                    }
                }
                return false;
            }
            else if(temp->data[word[i]-'a']==NULL){
                return false;
            }
            else{
                temp = temp->data[word[i]-'a'];
            }
        }
        return temp->end;
    }
   
    bool search(string word) {
        trie_node* temp = this->root;
        return search_help(word, temp);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */