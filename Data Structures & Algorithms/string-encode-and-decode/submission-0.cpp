class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;

        for (string &s : strs) {
            res += to_string(s.size()) + "#" + s;
        }

        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;

        while (i < s.size()) {

            // Find '#'
            int j = i;
            while (s[j] != '#')
                j++;

            // Length of current string
            int len = stoi(s.substr(i, j - i));

            // Move after '#'
            j++;

            // Extract the string
            res.push_back(s.substr(j, len));

            // Move to next encoded string
            i = j + len;
        }

        return res;
    }
};