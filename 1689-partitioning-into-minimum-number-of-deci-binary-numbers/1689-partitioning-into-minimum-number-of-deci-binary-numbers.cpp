class Solution {
public:
    int minPartitions(string n) {
      sort(begin(n), end(n));
      return n[n.length()-1]-'0';
    }
};