class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key = lambda x: -x[1])
        tot = 0
        box = 0
        for numOfBox, unit in boxTypes:
          print(numOfBox, unit)
          if box == truckSize:
            return tot
          if box+numOfBox <= truckSize:
            tot += unit*numOfBox
            box += numOfBox
          else:
            tot += (truckSize - box)*unit
            box += truckSize - box
        return tot
          
            
          
        