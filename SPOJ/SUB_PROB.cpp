#include <bits/stdc++.h>
#include <hash_map>
using namespace std;
using namespace __gnu_cxx;

const char alphaSt = 'A', alphaEn='z';
struct hashing {
    int operator ()(const pair<int, char> &p) const {
        return p.first * 257 + p.second;
    }
};
struct node {
    vector<char> children;
    int fail;
    vector<int> mpind; // Matched patterns index
};
hash_map<pair<int, char> , int , hashing> trie;
vector<node> nodes;

void insert(const char * str, int Str_id) {
    int cur = 0;

    for (; *str; str++) {
        __typeof (trie.begin()) itr = trie.find(make_pair(cur, *str));

        int nwidx;
        if (itr == trie.end()) {
            nwidx = nodes.size();
            nodes[cur].children.push_back(*str);
            nodes.push_back(node());
            trie[make_pair(cur, *str)] = nwidx;
        } else
            nwidx = itr->second;

        cur = nwidx;
    }

    nodes[cur].mpind.push_back(Str_id);
}

//int dp2 [100001][128];
int getnode(int node, char c) {
//    int &x = dp2[node][(int)c] ;

//    if (x != -1)
//        return x ;

    while (trie.find(make_pair(node, c)) == trie.end())
        node = nodes[node].fail;

    return /*x =*/ trie[make_pair(node, c)];
}
void build_failure() {
    queue<int> Q;

    // loop over the alphabet
    for (char c = alphaSt; c <= alphaEn; ++c) {
        __typeof (trie.begin()) itr = trie.find(make_pair(0, c));

        if (itr == trie.end())
            trie[make_pair(0, c)] = 0;
        else {
            Q.push(itr->second);
            nodes[itr->second].fail = 0;
        }
    }

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        node &n = nodes[cur];

        for (int i = 0; i < (int) n.children.size(); ++i) {
            char ch = n.children[i];
            __typeof (trie.begin()) itr = trie.find(make_pair(cur, ch));

            int nxt = itr->second;
            nodes[nxt].fail = getnode(nodes[cur].fail, ch);
            node &nn = nodes[nodes[nxt].fail];
            nodes[nxt].mpind.insert(nodes[nxt].mpind.end(), nn.mpind.begin(),
                    nn.mpind.end());
            Q.push(nxt);
        }
    }
}

void init(){
    trie.clear();
    nodes.clear();
    nodes.push_back(node());
}
void match(vector<vector<int> > &pos, vector<string> &pats, const string &T) {
    init();
    pos.clear();
    pos.resize((int) pats.size());
//    memset(dp2,-1,sizeof(dp2));
    for (int i = 0; i < (int)pats.size(); i++)
        insert(pats[i].c_str(), i);
    build_failure();
    int cur = 0;
    for (int i = 0; i < (int) T.size(); i++) {
        char c = T[i];
        while (trie[make_pair(cur,c)] == -1)
            cur = nodes[cur].fail;
        cur = trie[make_pair(cur,c)];
        for (int j = 0; j < (int) nodes[cur].mpind.size(); j++) {
            int k = nodes[cur].mpind[j];
            pos[k].push_back(i - pats[k].size() + 1); // a match found...
        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("main.txt", "rt", stdin);
#endif
    string text;
    int n;
    vector<vector<int> > pos;
    cin >> text;
    cin >> n;
    vector<string> pats(n);
    for(int i = 0; i < n; i++){
        cin >> pats[i];
    }
    match(pos, pats, text);
    for(int i = 0; i < n; i++){
        cout << (pos[i].empty()?"N":"Y") << endl;
    }
}


