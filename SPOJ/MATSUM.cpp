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

const int R = 1100, C = 1100;
int cpy[R][C];
struct BIT2D {
    int arr[R][C];
    void add(int i, int j, int num) {
        i++;
        j++;
        while(i <= R) {
            int jj = j;
            while(jj <= C) {
                arr[i - 1][jj - 1] += num;
                jj += (jj & -jj);
            }
            i += (i & -i);
        }
    }
    int get(int i, int j) {
        int num = 0;
        i++;
        j++;
        while(i) {
            int jj = j;
            while(jj) {
                num += arr[i - 1][jj - 1];
                jj -= (jj & -jj);
            }
            i -= (i & -i);
        }
        return num;
    }
    int get2D(int i1, int j1, int i2, int j2) {
        ll v = 0;
        v += get(i2, j2);
        v -= get(i2, j1 - 1);
        v -= get(i1 - 1, j2);
        v += get(i1 - 1, j1 - 1);
        return v;
    }
    void clear() {
        memset(arr, 0, sizeof arr);
    }
} bit;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif


    int tst;
    scanf("%d", &tst);
    char str[10] = {0};
    while(tst--) {
        int i1, j1, i2, j2, num;
        scanf("%d", &num);
        bit.clear();
        mem(cpy,0);
        while(scanf("%s", str) && strcmp(str, "END")) {
            if(!strcmp(str, "SET")) {
                scanf("%d%d%d", &i1, &j1, &num);
                int nval = num-cpy[i1][j1];
                bit.add(i1, j1, nval);
                cpy[i1][j1] = num;
            } else {
                scanf("%d%d%d%d", &i1, &j1, &i2, &j2);
                printf("%d\n", bit.get2D(i1, j1, i2, j2));
            }
        }
        printf("\n");
    }

    return 0;
}