#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;

string str;
string Right,Left;

int memo[1002][1002];
int DP(int s, int e) {
    if (s > e)
        return 0;

    int& m = memo[s][e];
    if (m != -1)
        return m;

    int mini = 1 << 27;
    if (str[s] == str[e])
        mini = min(mini, DP(s + 1, e - 1));


    mini = min(mini, DP(s + 1, e) + 1);
    mini = min(mini, DP(s, e - 1) + 1);

    return m = mini;
}


void build(int s, int e) {
   if(s>e)
	   return;

   if(s==e){
	   Left += str[s];
	   return;
   }

   int ans = memo[s][e];

   if(ans==memo[s+1][e]+1){
	   Left+= str[s];
	   Right = str[s] + Right;
	   build(s+1,e);
   }

   else if(ans==memo[s][e-1]+1){
	   Left+= str[e];
	   Right = str[e] + Right;
	   build(s,e-1);
   }

   else{
	   Left+= str[s];
	   Right = str[e] + Right;
	   build(s+1,e-1);
   }

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

    while (cin >> str) {
        memset(memo, -1, sizeof memo);
        Right=Left="";

        int n = str.size() - 1;
        cout << DP(0, n) << " ";
        build(0,n);
        cout<<Left+Right<<endl;

    }

    return 0;
}
