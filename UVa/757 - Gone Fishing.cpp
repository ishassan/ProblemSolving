#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <numeric>
#include <algorithm>
using namespace std;

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,j,n) for(int i=j; i<n; i++)
#define mp(a,b) make_pair(a,b)

typedef vector<int> vi;

const int SZ = 27;
int n, h;
int fish[SZ], decrease[SZ], travel[SZ], RES[SZ];
int memo[27][206][206];

int DP(int i, int rep, int remt, int remf) {
    if (i == n || remt <= 0)
        return 0;

    int &m = memo[i][rep][remt];

    if (m != -1)
        return m;

    remf = (remf < 0) ? 0 : remf;
    int yes = DP(i, rep + 1, remt - 1, remf - decrease[i]) + remf;
    int no = DP(i + 1, 0, remt - travel[i], fish[i + 1]);
    return m = max(yes, no);
}

void build(int i, int rep, int remt, int remf) {
    if (i == n || remt < 0)
            return;

    if(remt==0){
    	RES[i]=rep*5;
    	return;
    }

    remf = (remf < 0) ? 0 : remf;
    int ans = DP(i,rep,remt,remf);
    int yes = DP(i, rep + 1, remt - 1, remf - decrease[i]) + remf;

    if(ans==yes)
        build(i,rep+1,remt-1, remf - decrease[i]);


    else{
    	RES[i] = rep*5;
        build(i+1,0,remt-travel[i],fish[i+1]);
    }

}
void clr() {
    for (int i = 0; i < SZ; i++)
        fish[i] = decrease[i] = travel[i]=RES[i] = 0;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int in;
    char* c = "";
    while (scanf("%d", &n) && n > 0) {
        scanf("%d", &h);
        clr();
        memset(memo, -1, sizeof memo);

        n++;

        foo(i,1,n) {
            scanf("%d", &in);
            fish[i] = in;
        }

        foo(i,1,n) {
            scanf("%d", &in);
            decrease[i] = in;
        }

        foo(i,1,n-1) {
            scanf("%d", &in);
            travel[i] = in;
        }

        printf("%s",c), c = "\n";
        int res = DP(1, 0, 12 * h, fish[1]);
        build(1,0,12*h,fish[1]);
        foo(i,1,n-1)
            printf("%d, ",RES[i]);
        printf("%d",RES[n-1]);
        printf("\nNumber of fish expected: %d\n", res);

    }

    return 0;
}
