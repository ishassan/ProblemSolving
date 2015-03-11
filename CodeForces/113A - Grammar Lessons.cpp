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

bool male = 0, female = 0;
string m[] = {"lios", "etr", "initis"};
string f[] = {"liala", "etra", "inites"};
int cnt[3];
int main()
{

#ifndef ONLINE_JUDGE
    freopen("code.txt", "rt", stdin);
    //  freopen("out.txt", "wt", stdout);
#endif

    string str;

    getline(cin, str);
    stringstream ss(str);
    int cntword = 0, lst = 0;
    while(ss >> str) {
        ++cntword;
        bool found = 0;
        for(int i = 0; i < 3; i++) {
            int idx1 = str.rfind(m[i]);
            int idx2 = str.rfind(f[i]);
            if(idx1 == str.npos && idx2 == str.npos) continue;
            if(idx1 != sz(str) - sz(m[i]) && idx2 != sz(str) - sz(f[i])) continue;
            if(idx1 != str.npos && idx1 == sz(str) - sz(m[i]))
                male = 1;
            else
                female = 1;

            cnt[i]++;
            found = 1;
            if(i < lst || (male && female)) {
                printf("NO\n");
                return 0;
            }
            lst = i;
        }
        if(!found) {
            printf("NO\n");
            return 0;
        }
    }

    int sum = accumulate(cnt, cnt + 3, 0);
    if(cntword == 1 && sum == 0)
        printf("NO\n");
    else if(cntword == 1 && sum == 1)
        printf("YES\n");
    else if(cntword > 1 && cnt[1] != 1)
        printf("NO\n");
    else
        printf("YES\n");

    return 0;
}