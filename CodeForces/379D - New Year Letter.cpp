#include <bits/stdc++.h>

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

const int SIZE = 55;
struct state {
    ll n1, n2, n11, n12, n21, n22, st, en; //st == 1 if starts with s1, 2 if s2, 0 if neither
};
state arr[SIZE];
char ch[3] = {'A', 'C', 'X'};

bool isval(int n, int m, int nac1, char st1, char en1, int nac2, char st2, char en2)
{
    if(n==1) return 1;
    ll cnt1 = nac1 * 2LL, cnt2 = nac2 * 2LL;
    cnt1 += (st1 != 'A'), cnt1 += (en1 != 'C');
    cnt2 += (st2 != 'A'), cnt2 += (en2 != 'C');
    return (cnt1 <= n && cnt2 <= m);
}
ll calc(int n, int m, int nac1, char st1, char en1, int nac2, char st2, char en2, int k)
{ 
    ll res = 1LL * nac1 * arr[k].n1 + nac2 * arr[k].n2;
    if(en1 == 'A') {
        if(st1 == 'C') res += arr[k].n11;
        if(st2 == 'C') res += arr[k].n12;
    }
    if(en2 == 'A') {
        if(st1 == 'C') res += arr[k].n21;
        if(st2 == 'C') res += arr[k].n22;
    }
    return res;
}

string build(int n, int ac, char st, char en)
{
    string str(n, ' ');
    int idx = 0;
    str[idx++] = st;
    str[--n] = en;
    if(ac && st == 'A') str[idx++] = 'C', ac--;
    if(ac && en == 'C') str[--n] = 'A', ac--;
    while(ac--) str[idx++] = 'A', str[idx++] = 'C';
    while(idx < n) str[idx++] = 'X';
    return str;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    arr[1] = {1, 0, 0, 0, 0, 0, 1, 0};
    arr[2] = {0, 1, 0, 0, 0, 0, 0, 1};
    arr[3] = {1, 1, 0, 1, 0, 0, 1, 2};
    arr[4] = {1, 2, 0, 1, 1, 0, 2, 2};
    int k, x, n, m;
    scanf("%d%d%d%d", &k, &x, &n, &m);
    ll tot = x;
    repa(i, 5, k, 1) {
        arr[i].n1 = arr[i - 2].n1 + arr[i - 1].n1;
        arr[i].n2 = arr[i - 2].n2 + arr[i - 1].n2;
        arr[i].n11 = arr[i - 2].n11 + arr[i - 1].n11 + (arr[i - 2].en == 1 && arr[i - 1].st == 1);
        arr[i].n12 = arr[i - 2].n12 + arr[i - 1].n12 + (arr[i - 2].en == 1 && arr[i - 1].st == 2);
        arr[i].n21 = arr[i - 2].n21 + arr[i - 1].n21 + (arr[i - 2].en == 2 && arr[i - 1].st == 1);
        arr[i].n22 = arr[i - 2].n22 + arr[i - 1].n22 + (arr[i - 2].en == 2 && arr[i - 1].st == 2);
        arr[i].st = arr[i - 2].st;
        arr[i].en = arr[i - 1].en;
    }
    int cap1 = n / 2, cap2 = m / 2;
    repa(i, 0, cap1, 1)
    repa(j, 0, cap2, 1)
    rep(c1, 3)
    rep(c2, 3)
    rep(c3, 3)
    rep(c4, 3) {
        char st1 = ch[c1], en1 = ch[c2];
        char st2 = ch[c3], en2 = ch[c4];
        if(n == 1) en1 = st1;
        if(m == 1) en2 = st2;
        if(n == 2 && i == 0 && st1 == 'A' && en1 == 'C') continue;
        if(m == 2 && j == 0 && st2 == 'A' && en2 == 'C') continue;
        
        if(!isval(n, m, i, st1, en1, j, st2, en2)) continue;
        if(calc(n, m, i, st1, en1, j, st2, en2, k) == tot) {
            calc(n, m, i, st1, en1, j, st2, en2, k);
            cout << build(n, i, st1, en1) << endl << build(m, j, st2, en2);
            return 0;
        }
    }
    cout << "Happy new year!";
    return 0;
}