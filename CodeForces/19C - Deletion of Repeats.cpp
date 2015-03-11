#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define myfind(v,x) (find(all((v)),(x))-(v).begin())
#define itr(A,B) typeof(B) A = B

typedef long long ll;
using namespace std;

#define LIM 100002
int arr[LIM],org[LIM];
map<int, int> mapid;
vector<int> inds[LIM];
int idx[LIM]; // idx[i] = index of arr[i] inside inds[i]
int len[LIM][12]; //len[i][j] = length of sequence from i to k, j is encryption for k to reduce memsize, j is the occurence nymber of arr[i]
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    rep(i, n) {
        scanf("%d", &arr[i]);
        org[i] = arr[i];
        int id = sz(mapid);
        if(mapid.count(arr[i]))
            id = mapid[arr[i]];
        else
            mapid[arr[i]]=id;
        arr[i] = id;
        idx[i] = sz(inds[id]);
        inds[id].push_back(i);
    }

    //1 2 2 3 1 2 2 4 1 2 2 4
    repd(i,n-2,0,1){ //max n
        repd(j,idx[i]-1,0,1){ // max 10
             int k = inds[arr[i]][j];
             if(arr[i+1] == arr[k+1])
                 len[k][idx[i]] = len[k+1][idx[i+1]]+1;
        }
        
    }
    /*
    rep(i,LIM){
        cout << i<<": ";
        rep(j,12){
            cout << len[i][j] << " ";
        }
        cout << endl;
    }
    /*/
    vector<pii> rem;
    rep(i,n){
        repa(j,idx[i]+1, sz(inds[arr[i]])-1,1){
            int k = inds[arr[i]][j];
            int dist = k-i-1;
            if(dist <= len[i][idx[k]]) 
                rem.push_back(mp(i,dist));
        }
    }
    sort(all(rem));
    int encut=-1;
    rep(i,sz(rem)){
        if(encut >= rem[i].first) continue;
        encut = rem[i].first+rem[i].second;
    }
    cout << n-encut-1 << endl;
    repa(i,encut+1,n-1,1) cout << org[i] << " ";
    //*/
    return 0;
}
