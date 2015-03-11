#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;

int arr[2003];
int main(){
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
    freopen("out","wt",stdout);
#endif

    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    for (int i = 0; i < n; ++i) {
        scanf("%d",arr+i);

    }

    sort(arr,arr+n);
    --b;
    if(arr[b] == arr[b+1])
        printf("0\n");
    else
        printf("%d\n",arr[b+1]-arr[b]);
    return 0;
}
