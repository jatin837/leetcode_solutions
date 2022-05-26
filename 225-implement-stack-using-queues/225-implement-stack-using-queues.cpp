class MyStack {
public:
	queue<int> q1;
	queue<int> q2;
  int t=0;
	void push(int x) {
		q1.push(x);
    this->t = x; 
	}

	int pop() {
    while(q1.size()>1){
      q2.push(q1.front());
      this->t = q1.front();
      q1.pop();
    }
    int res = q1.front(); 
    q1.pop();
    queue<int> tmp = q2;
    q2 = q1;
    q1 = tmp;
    return res;
	}

	int top() {
		return this->t;
	}

	bool empty() {
		return q1.empty();
	}
};