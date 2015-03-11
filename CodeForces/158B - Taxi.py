n = int(raw_input())
arr = map(int, raw_input().split())
cnt = map(arr.count, range(0,5))
cnt[1] -= cnt[3]
if cnt[2]&1:
    cnt[4] +=1
    cnt[1] -= 2
print cnt[4] + cnt[3] + cnt[2]/2 + (max(cnt[1],0)+3)/4