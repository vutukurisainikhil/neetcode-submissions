class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> line;
        int length = 0, i = 0;

        while (i < words.size()) {
            if (length + words[i].size() + line.size() <= maxWidth) {
                line.push_back(words[i]);
                length += words[i].size();
                i++; // as it reaches end, exits while to handle last line.
            } else {
                // Line exceding the max width.
                int extra_space = maxWidth - length;
                // identifing space needed after each word.
                int space = extra_space / max(1, (int)(line.size() - 1));
                // after spliting equal space, left out ones are added from left.
                int remainder = extra_space % max(1, (int)(line.size() - 1));
                

                for (int j = 0; j < max(1, (int)line.size() - 1); j++) {
                    line[j] += string(space, ' ');
                    if (remainder > 0) {
                        line[j] += " ";
                        remainder--;
                    }
                }

                string justified_line = accumulate(line.begin(), line.end(), string());
                res.push_back(justified_line);
                line.clear();
                length = 0;
            }
        }

        // Handling last line, as no extra space needed.
        string last_line = accumulate(line.begin(), line.end(), string(),
                                      [](string a, string b) {
                                            return a.empty() ? b : a + " " + b;
                                        });
        int trail_space = maxWidth - last_line.size();
        last_line += string(trail_space, ' ');
        res.push_back(last_line);

        return res;
    }
};