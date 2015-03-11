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

vector<vector<char> > chld;
vector<bool> isWord;

struct hashp { // hash pair
    size_t operator()(const pair<int , char> & p )const{
        return p.first*256 + p.second ;
    }
};

unordered_map<pair<int , char>,int , hashp> trie ;


int addnode() {
    chld.push_back(vector<char>()); //ra7a nafsia
    isWord.push_back(0);
    return isWord.size() - 1;
}

void insert(const char * str) {
    int cur = 0;
    for (; *str; str++) {
        auto it = trie.find(make_pair(cur , *str));

        if(it == trie.end()){
            int tmp = addnode();
            chld[cur].push_back(*str);
            trie[make_pair(cur , *str)] = tmp;
        }
        cur = trie[make_pair(cur , *str)] ;
    }
    isWord[cur] = 1;
}

void init() {
    trie.clear();
    isWord.clear();
    addnode();
}


int memo[100015];
int memo2[100015];
bool win(int node){
    int& m = memo[node];
    if(m != -1) return m;
    repa(i,'a','z',1){
        if(trie.find(make_pair(node, char(i))) == trie.end()) continue;
        int nxt = trie[make_pair(node, char(i))];
        if(nxt == 0) continue;
        if(!win(nxt)) return m = 1;
    }
    return m = 0;
}
bool lose(int node){
    int& m = memo2[node];
    if(m != -1) return m;
    bool finish=1;
    repa(i,'a','z',1){
        if(trie.find(make_pair(node, char(i))) == trie.end()) continue;
        int nxt = trie[make_pair(node, char(i))];
        if(nxt == 0) continue;
        finish=0;
        if(lose(nxt)) return m = 0;
    }
    if(finish) return m=0;
    return m = 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int n,k;
    while(cin >> n >> k){
        init();
        mem(memo,-1);
        mem(memo2,-1);
        string str;
        rep(i,n) cin >> str, insert(str.c_str());
        if(win(0) == 1 && lose(0)==0){
            cout << "First\n";
        }
        else if(win(0) == 1 && (k&1)){
            cout << "First\n";
        }
        else cout << "Second\n";
    }




    return 0;
}

