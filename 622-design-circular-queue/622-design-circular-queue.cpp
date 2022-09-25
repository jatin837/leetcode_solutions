class MyCircularQueue {
public:
    int arr[1000] = {0};
    int k=0;
    int front = -1;
    int rear = -1;
    MyCircularQueue(int k) {
      this->k = k;
    }
    bool enQueue(int value) {
      if(this->isFull())
        return false;
      if(this->isEmpty())
        this->front = 0;
      this->rear = (this->rear+1)%k;
      this->arr[this->rear]=value;
      return true;
    }
    bool deQueue() {
      if(this->isEmpty())
        return false;
      if(this->front == this->rear){
        this->front = -1;
        this->rear = -1;
        return true;
      }
      this->front = (front+1)%this->k;
      return true;
    }
    int Front() {
      if(this->isEmpty())
        return -1;
      return this->arr[this->front];
    }
    int Rear() {
      if(this->isEmpty())
        return -1;
      return this->arr[this->rear];
    }
    bool isEmpty() {
      return this->front == -1 && this->rear == -1;
    }
    bool isFull() {
      return (this->rear+1)%this->k == this->front;
    }
};
