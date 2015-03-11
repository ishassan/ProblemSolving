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
#define repi(it,stl) for(auto it = (stl).begin(); (it)!=stl.end(); ++(it))
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

typedef long long ll;
using namespace std;

bool cmp(pii a, pii b){
    if(abs(a.first) == abs(b.first))
        return abs(a.second) < abs(b.second);
    return abs(a.first) < abs(b.first);
}
pii arr[100002];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    int sum=0;
    rep(i,n){
        cin >> arr[i].first >> arr[i].second;
        sum += arr[i].first && arr[i].second?6:4;
    }
    sort(arr,arr+n,cmp);
    printf("%d\n",sum);
    rep(i,n){
        if(arr[i].first) printf("1 %d %c\n", abs(arr[i].first), arr[i].first<0?'L':'R');
        if(arr[i].second) printf("1 %d %c\n", abs(arr[i].second), arr[i].second<0?'D':'U');
        printf("2\n");
        if(arr[i].first) printf("1 %d %c\n", abs(arr[i].first), arr[i].first<0?'R':'L');
        if(arr[i].second) printf("1 %d %c\n", abs(arr[i].second), arr[i].second<0?'U':'D');
        printf("3\n");
    }
    return 0;
}
