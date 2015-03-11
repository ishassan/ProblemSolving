/*
ID: Manal Sadek
LANG: C++
TASK:
*/

#include <map>
#include <set>
#include <math.h>
#include <deque>
#include <stack>
#include <queue>
#include <vector>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,s,m) for(int i=s;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define PI = (2.0 * acos(0.0));
typedef stringstream ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
#define OO ((int)1e9)

int n = 100000;
bool prime[100002];
int cum[100002];

void seive()
{
     memset(prime , 1,sizeof(prime));
     memset(cum,0,sizeof(cum));
     prime[0] = prime[1] = 0;
     for(int i = 2 ; i*i <= n ; i++)
     {
        if(prime[i])
         for(int j = i*i ; j<= n ; j+=i)
           prime[j] = false;
     } 
     for(int i = 1 ; i <= n ; i++)
       cum[i] = cum[i-1]+prime[i];
}


int main()
{
    int a , b;
    seive();
	cin>>a>> b;
     
      if( a < 0 ) a = 0;
      if( b < 0 ) b = 0;
      cout<<cum[b]-cum[a]+prime[a]<<endl;
        return 0;
}
