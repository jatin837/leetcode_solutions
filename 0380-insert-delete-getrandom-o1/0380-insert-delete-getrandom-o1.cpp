class RandomizedSet {
public:
    vector<int>vals; unordered_map<int, int>index;
    bool insert(int val) {
        if(index.find(val) != index.end())
            return false;
        vals.push_back(val);
        index[val] = vals.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(index.find(val) == index.end())
            return false;
        
        int last = vals.back();
        index[last]=index[val];
        vals[index[val]] = vals.back();
        index[val] = vals.size()-1;
        vals.pop_back();
        index.erase(val);
        return true;
    }
    
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */