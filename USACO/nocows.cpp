/*
ID: fci_isl1
PROG: nocows
LANG: C++
*/
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <cstring>


using namespace std;
int calc(int n,int k);
int dp [209][109];
int dp2[209][109];
int calc2(int n,int d)
{
    if(n<0 || d<0)return 0;
    if(n==1&&d>0)return 1;
    if(dp2[n][d]!=-1)return dp2[n][d];
    int tot=0;
    for(int i=1;i<=d;i++)
     tot+=calc(n,i)%9901;
    return dp2[n][d]=tot%9901;
}


int calc(int n,int d)
{
    if(n<0 || d<0)return 0;
    if(n==1 && d==1) return 1;
    if(dp[n][d]!=-1)return dp[n][d];
    
    int tot=0;
    for(int i=1;i<n-1;i++)
    {
        tot+=((calc(i,d-1))*(calc(n-1-i,d-1)))%9901;
        tot+=((calc(i,d-1))*(calc2(n-i-1,d-2)))%9901;
        tot+=((calc2(i,d-2))*(calc(n-1-i,d-1)))%9901;       
    }
    return dp[n][d]=tot%9901;
}

int main()
{


    freopen("nocows.in","rt",stdin);
    freopen("nocows.out","wt",stdout);
    memset(dp ,-1,sizeof dp );
    memset(dp2,-1,sizeof dp2);
    
    int n,k;scanf("%d%d",&n,&k);
    if(n%2)cout<<calc(n,k)%9901<<endl;
    else cout<<0<<endl; 
    return 0;
}
