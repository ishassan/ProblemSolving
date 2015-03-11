#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,m,n) for(int i=(m);i<(n);++i)

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;
typedef stringstream sstr;

int main(){

	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);

	int tst,g,in;
	scanf("%d",&tst);
	fo(t,tst){
		printf("Case #%d: ",t+1);
		scanf("%d",&g);
		map<int,int> m;
		int arr[1001];
		fo(i,g){
			scanf("%d",&in);
			m[in]++;
			arr[i] =in;
		}
		fo(i,g){
			if(m[arr[i]] == 1){
				printf("%d\n",arr[i]);
				break;
			}
		}

	}
	return 0;
}
