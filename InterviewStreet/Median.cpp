#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <climits>

#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define fnd(v,x) (find(all((v)),(x))!=(v).end())
#define itr(A,B) typeof(B) A = B
typedef long long ll;
using namespace std;

typedef int T;
#define OO 1e9
struct node {
    static node* empty;
    node* left, *right;
    int pri, size, freq;
    T val;
    bool bad;
    node() {
        memset(this,0,sizeof(this));
        left = right = this;
        pri = INT_MAX;
    }
    node(T v) {
        val = v;
        left = right = empty;
        bad = 0;
        pri = rand();
        size = freq = 1;
    }
    void update() {
        size = left->getSize() + right->getSize() + freq;
        bad = 0;
    }
    int getSize() {
        if (bad)    update();
        return size;
    }
    int lower_bound(T v) {
        if(this == empty) return OO;
        if (val == v)   return left->getSize();
        if (v < val)    return left->lower_bound(v);
        else            return left->getSize() + freq + right->lower_bound(v);
    }
    int upper_bound(T v) {
        if(this == empty) return OO;
        if (val == v)   return left->getSize() + freq;
        if (v < val)    return left->upper_bound(v);
        else            return left->getSize() + freq + right->upper_bound(v);
    }
    T getValue(int idx) {
        if (idx < left->getSize())
            return left->getValue(idx);
        if (idx >= left->getSize() + freq)
            return right->getValue(idx - left->getSize() - freq);
        return val;
    }
};
node* node::empty = new node;

node* find(node* root, T v){
    if(root == node::empty) return root;
    if (root->val == v)     return root;
    else if (v < root->val)
        return find(root->left, v);
    else
        return find(root->right, v);
}

node* rotateRight(node* root) {
    node* l = root->left;
    root->left = l->right;
    l->right = root;
    l->bad = root->bad = 1;
    return l;
}

node* rotateLeft(node* root) {
    node* r = root->right;
    root->right = r->left;
    r->left = root;
    r->bad = root->bad = 1;
    return r;
}
node* balance(node* root) {
    if (root->left->pri < root->pri)
        root = rotateRight(root);
    else if (root->right->pri < root->pri)
        root = rotateLeft(root);
    return root;
}
node* insert(node* root, T val) {
    if (root == node::empty)
        return root = new node(val);
    if (root->val == val) {
        ++root->freq, ++root->size;
        return root;
    }
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    root->bad=1;
    return balance(root);
}
node* remove(node* root, T val) {
    if (root == node::empty)
        return root;
    root->bad = 1;
    if (root->val == val) {
        if (root->freq > 1) {
            --root->freq;
            return root;
        }
        if (root->right == node::empty)
            return root->left;
        if (root->left == node::empty)
            return root->right;
        if (root->left->pri < root->right->pri)
            root = rotateRight(root);
        else
            root = rotateLeft(root);
        root = remove(root, val);
        return root;
    }
    if (val < root->val)
        root->left = remove(root->left, val);
    else
        root->right = remove(root->right, val);
    return root;
}
int main(){


    ios_base::sync_with_stdio(0);
    node* root = node::empty;
    int q;
    scanf("%d",&q);
    while(q--){
        char c;
        int n;
        scanf(" %c%d",&c,&n);
        if(c == 'r' && find(root,n) == node::empty){
            printf("Wrong!\n");
            continue;
        }
        if(c == 'r')
            root = remove(root,n);
        else
            root = insert(root,n);

        int siz = root->getSize();
        if(siz&1)
            printf("%d\n",root->getValue(siz/2));
        else{
            if(siz == 0){
                printf("Wrong!\n");
                continue;
            }
            ll a = root->getValue(siz/2-1);
            ll b = root->getValue(siz/2);
            if((a+b) & 1)
                printf("%.1lf\n",(a+b)/2.0);
            else
                printf("%lld\n",(a+b)/2);

        }
    }


    return 0;

}
