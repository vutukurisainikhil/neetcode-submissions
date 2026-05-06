class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);
        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size()) {
            return false;
        }

        unordered_map<char, int> charToWord;
        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            const string& w = words[i];

            if (charToWord.count(c)) {
                if (words[charToWord[c]] != w) {
                    return false;
                }
            } else {
                for (const auto& [key, val] : charToWord) {
                    if (words[val] == w) {
                        return false;
                    }
                }
                charToWord[c] = i;
            }
        }

        return true;
    }
};