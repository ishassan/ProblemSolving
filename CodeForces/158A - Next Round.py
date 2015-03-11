geti=lambda:map(int,raw_input().split())
n,k=geti()
arr=geti()
res=0
for i in xrange(n):
    if(arr[i]>=arr[k-1] and arr[i]):res+=1
    
print res