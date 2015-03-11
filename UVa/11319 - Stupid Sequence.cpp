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


const double eps = 1e-9;

typedef vector<vector<double> > matrix;
enum sol {
    NOSOL, UNIQUE, INF
};

inline int dcmp(const double &x, const double &y) {
    if (fabs(x - y) < eps)
        return 0;
    return (x < y) * -2 + 1;
}

inline bool isZero(const vector<double> &v) {
    for (int i = 0; i < (int) v.size() - 1; i++)
        if (dcmp(v[i], 0.0) != 0) // v[i] != 0 in parallel universe
            return 0;
    return 1;
}

inline void divideRow(vector<double>&v, const double d) {
    for (int i = 0; i < (int) v.size(); i++)
        v[i] /= d;
}

inline void makeZero(vector<double> &v, vector<double> &u, int idx) {
    double tmp = -v[idx];
    for (int i = 0; i < (int) v.size(); i++)
        v[i] += tmp * u[i];
}

inline int nextZero(matrix &mat, int idx) {
    for (int i = idx; i < (int) mat.size(); i++) {
        if (dcmp(mat[i][idx], 0.0) != 0)
            return i;
    }
    return -1;
}

sol gauss_jordan(matrix &mat) {
    sol ret = UNIQUE;
    for (int i = 0; i < (int) mat.size(); i++) {
        if (isZero(mat[i])) {
            if (dcmp(mat[i].back(), 0.0) != 0)
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

        for (int j = 0; j < (int) mat.size(); j++) {
            if (i == j || dcmp(mat[j][i], 0.0) == 0)
                continue;
            makeZero(mat[j], mat[i], i);
        }
    }
    if (mat.empty() || mat.size() < mat[0].size() - 1)
        ret = INF;
    return ret;
}

matrix mat;
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
        mat.clear();
        mat.resize(7, vector<double>(8));
        rep(i,1500){
            cin >> arr[i];
            if(i < 7){
                double x = i+1;
                double pw=1;
                rep(j,sz(mat[0])-1){
                    mat[i][j]=pw;
                    pw *= x;
                }
                mat[i].back() = arr[i];
            }
        }
        if(gauss_jordan(mat) != UNIQUE){
            goto bad;
        }
        ull res[7];
        rep(i,7){
            res[i] = round(mat[i].back());
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
