class Node{
  public:
  int key;
  int val;
  Node* prev;
  Node* next;
  Node(int key, int val, Node* prev = nullptr, Node* next = nullptr){
    this->key = key;
    this->val = val;
    this->prev = prev;
    this->next = next;
  }
};
class LRUCache {
public:
  unordered_map<int, Node*>mp;
  int capacity;
  Node* LRU = nullptr;
  Node* MRU = nullptr;
  
  LRUCache(int capacity) {
    this->capacity = capacity;
    this->LRU = new Node(-1, -1);
    this->MRU = new Node(-1, -1);
    LRU->next = MRU;
    MRU->prev = LRU;
  }
  void print(){
    Node* ptr = LRU;
    while(ptr){
      cout<<"["<<ptr->key<<','<<ptr->val<<"] ";
      ptr = ptr->next;
    }
    cout<<'\n';
    return;
  }
  void insert(Node* pos, int key, int val){
    Node* newNode = new Node(key, val);
    pos->prev->next = newNode;
    newNode->next = pos;
    newNode->prev = pos->prev;
    pos->prev = newNode;
    mp[key] = newNode;
    return;
  }
  void remove(int key){
    Node* currNode = mp[key];
    currNode->next->prev = currNode->prev;
    currNode->prev->next = currNode->next;
    currNode->next = nullptr;
    currNode->prev = nullptr;
    mp.erase(key);
    return;
  }
  int get(int key) {
    if(mp.find(key)!=mp.end()){
      int val = mp[key]->val;
      remove(key);
      insert(MRU, key, val);
      return val;     
    }
    return -1;
  }
  void put(int key, int val) {
    if(mp[key]){
      remove(key);
      insert(MRU, key, val);
      return;
    }
    insert(MRU, key, val);
    if(mp.size() > capacity)
      remove(LRU->next->key);
    return;
  }
};