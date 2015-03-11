#include <bits/stdc++.h>

using namespace std;

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
unordered_map<pair<int, char> , int , hashing> trie;
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

vector<int> D[128];
int mx;

void dfs(int id, int sc) { //dfs 3ala L tri we backtrack 3ala L chars
    if (nodes[id].mpind.size()) //id is id for every node
        mx = max(mx, sc);
    for (int i = 0; i < (int)nodes[id].children.size(); i++) {
        int c = nodes[id].children[i];
        if (D[c].empty())
            continue;
        int s = D[c].back();
        D[c].pop_back();
        dfs(trie[make_pair(id , c)] , sc + s);
        D[c].push_back(s);
    }
}

void init(){
    trie.clear();
    nodes.clear();
    nodes.push_back(node());
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif
    int n, q, m, sc;
    char c;
    while (cin >> n) {
        init();
        while (n--) {
            string s;
            cin >> s;
            insert(s.c_str(),n); //n is dummy
        }
        cin >> q;
        while (q--) {
            fill(D, D + 128, vector<int>());
            mx = 0;
            cin >> m;
            while (m--) {
                cin >> c >> sc;
                D[(int) c].push_back(sc);
                sort(D[(int) c].begin(), D[(int) c].end());
            }
            dfs(0, 0);
            cout << mx << endl;
        }
    }
}
