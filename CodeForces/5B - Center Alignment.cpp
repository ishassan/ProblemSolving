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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//     freopen("out.txt", "wt", stdout);
#endif
    vs v;
    string str,b;
    int mx=0;
    while(getline(cin,str)){
        v.push_back(str);
        mx = max(mx, sz(str));
    }
    
    b.append(mx,'*');
    cout << "*" << b << "*\n";
    int left=0,l,r;
    rep(i,sz(v)){
        l=r=(mx-sz(v[i]))/2;
        if(mx%2 != sz(v[i])%2){
            if(left) ++l;
            else ++r;
            left ^=1;
        }
        string sl,sr;
        sl.append(l,' ');
        sr.append(r,' ');
        cout << "*" << sl << v[i] << sr << "*\n";
    }
    cout << "*" << b << "*\n";
    
    
    return 0;
}
