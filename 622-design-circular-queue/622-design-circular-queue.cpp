class MyCircularQueue {
public:
    int arr[1000] = {0};
    int k=0;
    int front = -1;
    int rear = -1;
    int size = 0;
    MyCircularQueue(int k) {
      this->k = k;
    }
    
    bool enQueue(int value) {
      if(this->size == this->k)
        return false;
      if(this->front == -1)
        this->front = 0;
      this->rear = (this->rear+1)%k;
      this->size++;
      this->arr[this->rear]=value;
      return true;
    }
    
    bool deQueue() {
      if(this->size == 0)
        return false;
      this->front = (front+1)%this->k;
      this->size--;
      return true;
    }
    
    int Front() {
      if(this->size == 0)
        return -1;
      return this->arr[this->front];
    }
    
    int Rear() {
      if(this->size == 0)
        return -1;
      return this->arr[this->rear];
    }
    
    bool isEmpty() {
      return this->size == 0;
    }
    
    bool isFull() {
      return this->size == this->k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */