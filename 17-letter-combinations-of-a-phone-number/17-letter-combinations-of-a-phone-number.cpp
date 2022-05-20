class Solution {
public:
   vector<vector<char>> mapping = {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'},
        };
    
   vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        
        if(digits.length() == 0) return ans;
        
        string tmp = "";
        letterCom(digits, 0, tmp, ans);
        return ans;
    }
    
    void letterCom(string digits, int idx, string tmp, vector<string> &ans) {
        if(idx == digits.length()) {
            ans.push_back(tmp);
            return;
        }
		 // since digits starts from 2, so to make it 0 index we subtract 2
        vector<char> charSet = mapping[digits[idx] - '2'];
        
        for(int i = 0; i < charSet.size(); i++) {
            tmp += charSet[i];
            letterCom(digits, idx + 1, tmp, ans);
            tmp.pop_back();
        }
    }
};