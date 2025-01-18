
'''
problem: https://dmoj.ca/problem/2spooky4me
solution: https://dmoj.ca/submission/6382495
'''

values = list(map(int, input("").split()))

NumberOfDecorations = values[0]
NumberOfHouses = values[1]
MaxSpook = values [2]
TooSpooky = False
houses = []

Sness = 0
No_candies = 0

for num in range(NumberOfDecorations):
  Decos = list(map(int, input("").split()))
  houses.append((Decos[0],Decos[2]))
  houses.append((Decos[1] + 1,(Decos[2]*-1)))



Sorted_Houses = sorted(houses)

for keys in Sorted_Houses:
  Sness += keys[1]
  
  if Sness >= MaxSpook and not TooSpooky:
    TooSpooky = True
    
    LastNotSpook = keys[0]
    
   
  if TooSpooky and Sness < MaxSpook:
    TooSpooky = False  
    No_candies += keys[0] - LastNotSpook

if TooSpooky and Sness >= MaxSpook:
  No_candies += NumberOfHouses


print(NumberOfHouses - No_candies)