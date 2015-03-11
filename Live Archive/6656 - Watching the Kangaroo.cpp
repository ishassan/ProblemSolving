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
#define indexof(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

struct event{
    ll x;
    bool outEvent; //out: 0 for in event, 1 for out event
    int kangidx;
    int camidx;

};
bool cmp1(const event& e1,const event& e2){
    if(e1.x == e2.x) return e1.outEvent < e2.outEvent;
    return e1.x < e2.x;
}
bool cmp2(const event& e1,const event& e2){
    if(e1.x == e2.x) return e1.outEvent < e2.outEvent; //note: the same condition for both cmp1,cmp2
    return e1.x > e2.x;
}

vector<event> ev1,ev2; //ev2 do line sweep in the inverse direction
ll bst[100003];
pair<ll,ll> cam[100003];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int tst;
    cin >> tst;
    repa(cs,1,tst,1){
        ev1.clear(); ev2.clear();
        mem(bst,0);
        int n,k;
        cin >> n >> k;
        rep(i,n){
            ll l,r;
            cin >> l >> r;
            ll mid = (l+r)/2;
            ev1.push_back({l,0,-1,i});
            ev1.push_back({l+(r-l)/2,1,-1,i});

            ev2.push_back({r,0,-1,i});
            ev2.push_back({r-(r-l)/2,1,-1,i});
            cam[i] = mp(l,r);
        }
        rep(i,k){
            ll x; cin >> x;
            ev1.push_back({x,0,i,-1});
            ev2.push_back({x,0,i,-1});
        }
        sort(all(ev1),cmp1);
        sort(all(ev2),cmp2);
        multiset<ll> inEvents;
        rep(i,sz(ev1)){
            if(ev1[i].kangidx > -1){
                ll camleft = inEvents.empty()?ev1[i].x:*inEvents.begin();
                bst[ ev1[i].kangidx ] = max( bst[ ev1[i].kangidx ], ev1[i].x - camleft);
            }
            else if(ev1[i].outEvent){
                ll camleft = cam[ev1[i].camidx].first;
                inEvents.erase(inEvents.find(camleft));
            }
            else inEvents.insert(ev1[i].x);
        }
        rep(i,sz(ev2)){
            if(ev2[i].kangidx > -1){
                ll camrht = inEvents.empty()?ev2[i].x:*inEvents.rbegin();
                bst[ ev2[i].kangidx ] = max( bst[ ev2[i].kangidx ], camrht - ev2[i].x );
            }
            else if(ev2[i].outEvent){
                ll camrht = cam[ev2[i].camidx].second;
                inEvents.erase(inEvents.find(camrht));
            }
            else inEvents.insert(ev2[i].x);
        }
        cout <<"Case " << cs << ":\n";
        rep(i,k) cout << bst[i]<<"\n";
    }

    return 0;
}

