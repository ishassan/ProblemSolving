#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <sstream>
using namespace std;

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,j,n) for(int i=j; i<n; i++)

int val(char c)
{
    if(isdigit(c))
        return c-'0';
    return c-'A'+10;
}
char toChar(int i)
{
    if(i<10)
        return i+'0';
    return i-10+'A';
}
string convert(int num,int fromBase,int toBase)
{
    int temp = num;
    if(temp==0)
        return "0";
    string res="";
    while(temp>0)
    {
        res+=toChar(temp%toBase);
        temp/=toBase;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int T, n, k;
	scanf("%d", &T);

	foo(t,1,T+1) {
		printf("Case #%d: ", t);
		scanf("%d%d", &n, &k);

		string res = convert(k,10,2);
		int c=0;
		bool b=0;
		int i;
		for(i=res.size()-1; i>-1 && c<n; i--, c++){
			if(res[i]=='0'){
				printf("OFF\n");
				b=1;
				break;
			}

		}
		if(b)
			continue;
		if(i==-1 && c<n)
			printf("OFF\n");

		else
		printf("ON\n");

	}
	return 0;
}
