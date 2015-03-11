#include <bits/stdc++.h>
#include <ext/numeric>

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

typedef unsigned long long ull;
using namespace std;
using namespace __gnu_cxx;


typedef vector<vector<double> > matrix;
const double eps = 1e-9;
enum sol{
    NOSOL, UNIQUE, INF
};
sol GaussianElimination(vector<vector<double> > &lhsMat, vector<double> &rhs){
    // the final answer will be in the rhs
    int eqnCnt = (int)lhsMat.size(), varCnt = (int)lhsMat[0].size();
    sol ret = UNIQUE;
    if(varCnt > eqnCnt) ret = INF;
    vector<bool> taken(eqnCnt,false);
    for(int i = 0; i < min(eqnCnt,varCnt); i++){
        for(int j = 0; j < eqnCnt; j++){ // get a row where mat[i][i] is not zero
            if(taken[j])continue;
            if(fabs(lhsMat[j][i]) > eps){
                swap(lhsMat[i],lhsMat[j]); // swapping vectors O(1)
                swap(rhs[i],rhs[j]);
                break;
            }
        }
        if(fabs(lhsMat[i][i]) < eps){
            continue;
        }

        // this eqns has been taken
        taken[i] = true;
        for(int j = i+1; j < eqnCnt; j++){
            if(fabs(lhsMat[j][i]) < eps) continue;
            double mulByThis = -lhsMat[j][i]/lhsMat[i][i];
            for(int k = i; k < varCnt; k++){
                lhsMat[j][k] += mulByThis*lhsMat[i][k];
            }
            rhs[j] += mulByThis*rhs[i];
        }
    }

    // check that all the extra eqns are 0 = 0
    for(int i = varCnt; i < eqnCnt; i++){
        if(fabs(rhs[i]) > eps)
            return NOSOL;
    }
    // go from bottom to top and get the answers
    for(int i = min(varCnt,eqnCnt)-1; i >= 0; --i){
        for(int j = i+1; j < varCnt; j++){
            rhs[i]-=lhsMat[i][j]*rhs[j];
        }
        if(fabs(lhsMat[i][i]) < eps){
            if(fabs(rhs[i]) > eps) return NOSOL;

            ret = INF;
            continue;
        }
        rhs[i]/=lhsMat[i][i];
    }
    return ret;
}
matrix mat;
vector<double> ans;
ull arr[1500];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int tst;
    cin >> tst;
    while(tst--){
        mat.clear(); ans.clear();
        mat.resize(7, vector<double>(7));
        ans.resize(7);
        rep(i,1500){
            cin >> arr[i];
            if(i < 7){
                double x = i+1;
                double pw=1;
                rep(j,sz(mat[0])){
                    mat[i][j]=pw;
                    pw *= x;
                }
                ans[i] = arr[i];
            }
        }
        if(GaussianElimination(mat, ans) != UNIQUE){
            goto bad;
        }
        ull res[7];
        rep(i,7){
            res[i] = round(ans[i]);
            if(res[i] < 0 || res[i] >= 1001)
                goto bad;
        }

        rep(i,1500){
            ull sum=0;
            rep(j,7){
                ull x = power(i+1ULL,(ull)j);
                ull a = res[j];
                if(a > ULLONG_MAX / x)
                    goto bad;
                x*=a;
                if(sum > ULLONG_MAX - x) goto bad;
                sum += x;
            }
            if(sum != arr[i])
                goto bad;
        }
        rep(i,7) cout <<res[i]<<" \n"[i==6];
        continue;
bad:;
        cout << "This is a smart sequence!\n";

    }

    return 0;
}
