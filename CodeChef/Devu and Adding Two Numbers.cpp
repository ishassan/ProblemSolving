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

void div(int num, vi& v){
    while(num){
        v.push_back(num%10);
        num/=10;
    }
}

set<int> s={1,10,100,1000,10000,100000,1000000};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //    int tst;
    //    cin >> tst;
    //    while(tst--){
    //        int n;
    //        cin >> n;
    //        bool yes=0;
    //        repa(i,1,n-1,1){
    //            int j = n-i;
    //            if(i > j) break;
    //            if(j <= 0) continue;
    //            vi v1,v2;
    //            div(i,v1);
    //            div(j,v2);
    //            while(sz(v1) < sz(v2)){
    //                v1.push_back(0);
    //            }
    //            while(sz(v2) < sz(v1)){
    //                v2.push_back(0);
    //            }
    //            yes=1;
    //            rep(i,sz(v1)){
    //                if(v1[i] + v2[i] >= 10){
    //                    yes=0;
    //                    break;
    //                }
    //            }
    //            if(yes)
    //                break;
    //        }
    //        if(yes)cout << "YES\n";
    //        else cout << "NO\n";
    //    }

//    cout << "{";
//    string sp;
//    repa(n,1,100000,1){
//        bool yes=0;

//        repa(i,1,n-1,1){
//            int j = n-i;
//            if(i > j) break;
//            if(j <= 0) continue;
//            vi v1,v2;
//            div(i,v1);
//            div(j,v2);
//            while(sz(v1) < sz(v2)){
//                v1.push_back(0);
//            }
//            while(sz(v2) < sz(v1)){
//                v2.push_back(0);
//            }
//            yes=1;
//            rep(i,sz(v1)){
//                if(v1[i] + v2[i] >= 10){
//                    yes=0;
//                    break;
//                }
//            }
//            if(yes)
//                break;
//        }
//        if(!yes){
//        cout<<sp <<n;
//        sp=",";
//        }

//    }
//    cout << "};";


    int tst;
    cin >> tst;
    while(tst--){
        int n;
        cin >> n;
        if(s.count(n)) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}

