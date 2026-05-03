class Solution {
public:
    string minWindow(string str, string pat) {
        int len1 = str.length();
        int len2 = pat.length(); 
        
        if (len1 < len2) return ""; 

        int hash_pat[256] = {0}, hash_str[256] = {0}; 
        
        for (char c: pat) 
            hash_pat[c]++; 

        int start = 0, start_index = -1, min_len = INT_MAX, count = 0;
        
        for (int j = 0; j < len1 ; j++) 
        {
            hash_str[str[j]]++; 
            // finding all chars in pat string with respect to str
            if (hash_pat[str[j]] != 0 && 
                hash_str[str[j]] <= hash_pat[str[j]] ) 
                count++; 
            // if all chars in ptr is found in str string, first sliding windows is found.
            if (count == len2) 
            { 
                // removing duplicate elements in hash_str by iterating to s[i] & incrementing start (removed chars are not needed)
                // similarly moving forward to fins minimum window substring
                while ( hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0) {
                    //cout<<" h_str:"<<hash_str[str[start]]<<" s:"<<str[start] <<" h_pat:"<< hash_pat[str[start]]<<endl;
                    if (hash_str[str[start]] > hash_pat[str[start]]) 
                        hash_str[str[start]]--; 
                    start++; 
                } 

                int len_window = j - start + 1; 
                if (min_len > len_window) { 
                    min_len = len_window; 
                    start_index = start; 
                } 
            }
        } 

        return start_index == -1 ? "" : str.substr(start_index, min_len); 
    }
};
