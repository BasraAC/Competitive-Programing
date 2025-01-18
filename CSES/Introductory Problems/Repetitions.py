#https://cses.fi/problemset/task/1069


arr = list(str(input()))

lptr = 0
rptr = -1
maxi = 1
currChar = arr[0]
arr.append('#')

#sliding window algo 
for i in range(len(arr)):
    if arr[i] == currChar:
        rptr = i
    else:
        rptr = i
        maxi = max(maxi ,rptr - lptr)
        lptr = rptr
        currChar = arr[i]
        
print(maxi)
    
