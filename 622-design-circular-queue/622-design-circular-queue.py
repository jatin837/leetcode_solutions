class MyCircularQueue:

    def __init__(self, k: int):
      self.front = -1
      self.back = -1
      self.size = 0
      self.cap = k
      self.arr = [0]*self.cap

    def enQueue(self, value: int) -> bool:
      if(self.isFull()):
        return False;
      if(self.front == -1):
        self.front = 0
      self.back = (self.back+1)%self.cap
      self.arr[self.back] = value
      self.size += 1
      return True;

    def deQueue(self) -> bool:
      if(self.isEmpty()):
        return False;
      self.front = (self.front+1)%(self.cap)
      self.size -= 1
      return True;
        
    def Front(self) -> int:
      if(self.isEmpty()):
        return -1
      return self.arr[self.front]
        
    def Rear(self) -> int:
      if(self.isEmpty()):
        return -1
      return self.arr[self.back]
        
    def isEmpty(self) -> bool:
      return self.size == 0
        
    def isFull(self) -> bool:
      return self.size == self.cap
        


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()