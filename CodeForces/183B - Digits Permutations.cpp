#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
#define repi(it,stl) for(auto it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define myfind(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

int vis1[10],vis2[10],cnt[10];
string str,r1,r2,s1,s2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //      freopen("out.txt","wt",stdout);
#endif

    string str;
    cin >> str;
    rep(i,sz(str)) cnt[str[i]-'0']++;
    int mx=-1;
    repa(d,1,9,1){
        mem(vis1,0), mem(vis2,0);
        s1 = s2 = "";
        int c=0;
        if(vis1[d] < cnt[d] && vis2[10-d] < cnt[10-d]){
            c++;
            s1 += d+'0';
            s2 += 10-d+'0';
            vis1[d]++, vis2[10-d]++;

            rep(i,10){
                if(vis1[i] < cnt[i] && vis2[9-i] < cnt[9-i]){
                    int mn = min(cnt[i]-vis1[i], cnt[9-i]-vis2[9-i]);
                    vis1[i] += mn, vis2[9-i]+=mn, c += mn;
                    s1 += string(mn, i+'0');
                    s2 += string(mn, 9-i+'0');
                }
            }
        }
        if(vis1[0] < cnt[0] && vis2[0] < cnt[0]){
            int mn = min(cnt[0]-vis1[0], cnt[0]-vis2[0]);
            vis1[0] += mn, vis2[0]+=mn, c += mn;
            s1 = string(mn, '0') + s1;
            s2 = string(mn, '0') + s2;
        }
        rep(i,10){
            s1 += string(cnt[i]-vis1[i], i+'0');
            s2 += string(cnt[i]-vis2[i], i+'0');
        }
        if(c > mx)
            mx = c, r1 = s1, r2 = s2;

    }
    reverse(all(r1));
    reverse(all(r2));
    cout << r1 << "\n" << r2;
    return 0;
}
