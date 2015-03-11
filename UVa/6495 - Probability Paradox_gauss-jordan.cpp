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
        mat[var].back() = fraction(1,1);
        return;
    }
    if(m2 == n){
        mat[var].back() = fraction(0,1);
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



typedef vector<vector<fraction> > matrix;
enum sol {
    NOSOL, UNIQUE, INF
};

inline bool isZero(const vector<fraction> &v) {
    for (int i = 0; i < (int) v.size() - 1; i++)
        if (v[i].nom != 0) // v[i] != 0 in parallel universe
            return 0;
    return 1;
}

inline void divideRow(vector<fraction>&v, fraction d) {
    for (int i = 0; i < (int) v.size(); i++)
        v[i] /= d;
}

inline void makeZero(vector<fraction> &v, vector<fraction> &u, int idx) {
    fraction tmp = -v[idx];
    for (int i = 0; i < (int) v.size(); i++)
        v[i] += tmp * u[i];
}

inline int nextZero(matrix &mat, int idx) {
    for (int i = idx; i < (int) mat.size(); i++) {
        if (mat[i][idx].nom != 0)
            return i;
    }
    return -1;
}

int chk(matrix& mat){
    rep(i,sz(mat)){
        if(mat[i][21].nom) return i;
    }
   // assert(mat[0].back().nom==0);
    return -1;
}
sol gauss_jordan(matrix &mat) {
    sol ret = UNIQUE;
    for (int i = 0; i < (int) mat.size(); i++) {
        int c = chk(mat);
        if (isZero(mat[i])) {
            if (mat[i].back().nom != 0)
                return NOSOL;
            mat[i].swap(mat.back());
            mat.pop_back();
            i--;
            continue;
        }
        int p = nextZero(mat, i);
        if (p == -1) {
            ret = INF;
            continue;
        }

        if (p != i)
            mat[i].swap(mat[p]); // O(1)
        divideRow(mat[i], mat[i][i]);
        chk(mat);
        for (int j = 0; j < (int) mat.size(); j++) {
            if (i == j || mat[j][i].nom == 0)
                continue;
            makeZero(mat[j], mat[i], i);
   //         chk(mat);
        }
    }
    if (mat.empty() || mat.size() < mat[0].size() - 1)
        ret = INF;
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
        mat = vector<vector<fraction> >(dim, vector<fraction>(dim+1));
        rep(i,sz(mat)){
            mat[i][i] = fraction(1,1);
        }
        repa(i,0,n,1) repa(j,0,n,1){
            buildMat(i,j);
        }
        gauss_jordan(mat);
        mat[0].back().print();
        cout << "\n";
    }

    return 0;
}
