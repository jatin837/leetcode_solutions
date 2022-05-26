class MyStack {
public:
	queue<int> que;
	void push(int x) {
		que.push(x);
		for(int i=0;i<que.size()-1;++i){
			que.push(que.front());
			que.pop();
		}
	}

	int pop() {
    int res = this->top();
		que.pop();
    return res;
	}

	int top() {
		return que.front();
	}

	bool empty() {
		return que.empty();
	}
};