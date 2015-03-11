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

struct fraction{
    ll nom, denom;
    fraction(ll n, ll d):nom(n),denom(d){fix();}
    fraction(ll n):nom(n),denom(1){}
    fraction():nom(0),denom(1){}
    void div(int val){
        denom*=val;
        //fix();
    }
    fraction fix(){
        ll g = __gcd(nom, denom);
        nom/=g,denom/=g;
        if(denom<0) denom*=-1, nom*=-1;
        return *this;
    }
    inline fraction operator-(){
        fraction ret =  fraction(-nom,denom);
        //ret.fix();
        return ret;
    }
    inline fraction operator+(const fraction &f){
        fraction ret = fraction(nom*f.denom+f.nom*denom,denom*f.denom);
        ret.fix();
        return ret;
    }
    inline fraction operator+=(const fraction&f){
        (*this) = (*this) + f;
        return *this;
    }
    inline fraction operator-(const fraction &f){
        fraction ret = fraction(nom*f.denom-f.nom*denom , denom*f.denom);
        ret.fix();
        return ret;
    }
    inline fraction operator-=(const fraction&f){
        (*this) = (*this) - f;
        return *this;
    }
    inline fraction operator*(const fraction &f){
        fraction ret = fraction(nom*f.nom,denom*f.denom);
        ret.fix();
        return ret;
    }
    inline fraction operator*=(const fraction&f){
        (*this) = (*this) * f;
        return *this;
    }
    inline fraction operator/(const fraction &f){
        fraction ret = fraction(nom*f.denom,denom*f.nom);
        ret.fix();
        return ret;
    }
    inline fraction operator/=(const fraction&f){
        (*this) = (*this) / f;
        return *this;
        // fix();
    }
    inline bool operator==(const fraction&f){
        return nom == f.nom && denom == f.denom;
    }
    inline bool operator!=(const fraction&f){
        return !( (*this) == f );
    }
    void print(){
        cout << nom<<'/'<<denom;
    }
};
//=====================================

string s1,s2;
int n;
vector<vector<fraction> > mat;
vector<fraction> rhs,ans;

int maxMatch(string& s, int m, char cur){
    int mx = m;
    for(mx=m; mx; mx--){
        string sub1 = s.substr(m-(mx-1),mx-1)+string(1,cur);
        string sub2 = s.substr(0,mx);
        if(sub1==sub2) return mx;
    }
    return mx;
}
void buildMat(int m1, int m2){
    int var = m1*10+m2;
    mat[var][var] = 1;
    if(m1 == n){
        rhs[var] = fraction(1,1);
        return;
    }
    if(m2 == n){
        rhs[var] = fraction(0,1);
        return;
    }
    string tri="HT";
    rep(t,2){
        if(s1[m1] == tri[t]){
            if(s2[m2] == tri[t]){
                int nxtm1 = m1+1, nxtm2 = m2+1;
                int nxtvar = nxtm1*10+nxtm2;
                mat[var][nxtvar] += -fraction(1,2);
            }
            else{
                int nxtm1 = m1+1;
                int nxtm2 = maxMatch(s2,m2,tri[t]);
                int nxtvar = nxtm1*10+nxtm2;
                mat[var][nxtvar] += -fraction(1,2);
            }
        }
        else{
            if(s2[m2] == tri[t]){
                int nxtm1 = maxMatch(s1,m1,tri[t]);
                int nxtm2 = m2+1;
                int nxtvar = nxtm1*10+nxtm2;
                mat[var][nxtvar] += -fraction(1,2);
            }
            else{
                int nxtm1 = maxMatch(s1,m1,tri[t]);
                int nxtm2 = maxMatch(s2,m2,tri[t]);
                int nxtvar = nxtm1*10+nxtm2;
                mat[var][nxtvar] += -fraction(1,2);
            }
        }
    }

}
//============================================================


enum sol {
    NOSOL, UNIQUE, INF
};
sol GaussianElimination(vector<vector<fraction> >& lhsMat, vector<fraction>& rhs,
                        vector<fraction>&ans) {
    // the final answer will be in the rhs
    int eqnCnt = (int) lhsMat.size(), varCnt = (int) lhsMat[0].size();
    sol ret = UNIQUE;
    for (int curCol = 0, curRow = 0; curCol < min(eqnCnt, varCnt); curCol++,curRow++) {
        for (int j = curRow; j < eqnCnt; j++) { // get a row where mat[i][i] is not zero
            if (lhsMat[j][curCol].nom != 0) {
                swap(lhsMat[curRow], lhsMat[j]); // swapping vectors O(1)
                swap(rhs[curRow], rhs[j]);
                break;
            }
        }
        if (lhsMat[curRow][curCol].nom == 0) {
            curRow--;
            continue;
        }

        for (int j = curRow + 1; j < eqnCnt; j++) {
            if (lhsMat[j][curCol].nom == 0)
                continue;
            fraction mulByThis = -lhsMat[j][curCol] / lhsMat[curRow][curCol];
            for (int k = curCol; k < varCnt; k++) {
                lhsMat[j][k] += mulByThis * lhsMat[curRow][k];
            }
            rhs[j] += mulByThis * rhs[curRow];
        }
    }
    vector<bool> taken(varCnt, false);
    ans = vector<fraction>(varCnt, fraction(0,1));
    // go from bottom to top and get the answers
    for (int i = eqnCnt - 1; i >= 0; --i) {
        int k = 0;
        for (k = 0; k < varCnt; k++) {
            if (lhsMat[i][k].nom != 0) {
                break;
            }
        }
        if (k == varCnt) {
            if (rhs[i].nom != 0)
                return NOSOL;
            continue;
        }
        fraction val = rhs[i];
        for (int j = k + 1; j < varCnt; j++) {
            val -= ans[j] * lhsMat[i][j];
        }
        val /= lhsMat[i][k];
        if (taken[k] && ans[k] != val)
            return NOSOL;
        ans[k] = val;
        taken[k] = true;
    }
    if(find(taken.begin(), taken.end(),false) != taken.end()) ret = INF;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    while(cin >> s1, s1 != "$"){
        cin >> s2;
        n = sz(s1);
        int dim = n*10 + n+1;
        mat = vector<vector<fraction> >(dim, vector<fraction>(dim));
        rhs = vector<fraction>(dim);
        ans = vector<fraction>(dim);
        repa(i,0,n,1) repa(j,0,n,1){
            buildMat(i,j);
        }
        GaussianElimination(mat,rhs,ans);
        ans[0].print();
        cout << "\n";
    }

    return 0;
}
