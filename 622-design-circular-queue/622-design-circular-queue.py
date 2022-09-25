class MyCircularQueue:
    def __init__(self, k: int):
      self.front = -1
      self.back = -1
      self.cap = k
      self.arr = [0]*self.cap
    def enQueue(self, value: int) -> bool:
      if(self.isFull()):
        return False;
      if(self.isEmpty()):
        self.front = 0
      self.back = (self.back+1)%self.cap
      self.arr[self.back] = value
      return True;
    def deQueue(self) -> bool:
      if(self.isEmpty()):
        return False;
      if(self.front == self.back):
        self.front = self.back = -1
        return True
      self.front = (self.front+1)%(self.cap)
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
      return self.front == self.back == -1
    def isFull(self) -> bool:
      return (self.back+1)%self.cap == self.front
