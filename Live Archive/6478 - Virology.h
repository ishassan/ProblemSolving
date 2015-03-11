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

int arr[15],freq[15]={0};

bool vul(int tri, int pr, int str, int step){
    if(pr == 2) return 0;
    if(tri + str == 4 && pr == 1) return 1;
    if(step==0){
        repa(i,1,9,1){
            if(freq[i] == 3){
                freq[i] -= 3;
                if(vul(tri+1,pr,str, 0)) return 1;
                freq[i] += 3;
            }
        }
        if(vul(tri,pr,str,step+1)) return 1;
    }
    else if(step <= 1 && pr == 0){
        repa(i,1,9,1){
            if(freq[i] >= 2){
                freq[i] -= 2;
                if(vul(tri,pr+1,str, 1)) return 1;
                freq[i] += 2;
            }
        }
        return 0;
    }

    else if(step >= 1){
        repa(i,1,7,1){
            if(freq[i] && freq[i+1] && freq[i+2]){
                --freq[i], --freq[i+1], --freq[i+2];
                if(vul(tri,pr,str+1, 2)) return 1;
                ++freq[i], ++freq[i+1], ++freq[i+2];
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
      freopen("out.txt","wt",stdout);
#endif


    int tst;
    cin >> tst;
    while(tst--){
        mem(freq,0);
        rep(i,14) {
            cin >> arr[i];
            freq[arr[i]]++;
        }

        if(vul(0,0,0,0)) cout << "Vulnerable\n";
        else cout << "Immune\n";


    }
    return 0;
}

