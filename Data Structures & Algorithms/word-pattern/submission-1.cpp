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
        // map<string, index>
        // Create a single map from characters to their first occurrence index.
        unordered_map<char, int> charToWord;
        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            const string& w = words[i];
            // For each character-word pair, if the character exists in the map, verify the stored
            // index points to the same word.
            if (charToWord.count(c)) {
                if (words[charToWord[c]] != w) {
                    return false;
                }
            } else {
                // If the character is new, iterate through all existing mappings to ensure no other
                // character maps to this word.
                for (const auto& [key, val] : charToWord) {
                    // If a conflict is found, return false. Otherwise, add the new mapping.
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