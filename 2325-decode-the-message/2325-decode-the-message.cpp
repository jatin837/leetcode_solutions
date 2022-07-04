class Solution {
public:
  string decodeMessage(string key, string mess) {
    vector<char> m(128, 0);
    char cur = 'a';
    m[' '] = ' ';
    for (char k : key)
        m[k] = m[k] ?: cur++;
    transform(begin(mess), end(mess), begin(mess), 
              [&](char ch){ return m[ch];});
    return mess;
  }
};