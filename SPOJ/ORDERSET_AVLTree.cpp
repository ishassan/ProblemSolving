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
#include <list>
#include <climits>
#include <assert.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define allarr(n) (n), (n)+( (sizeof (n)) / (sizeof (*n)) )
#define mp(a,b) make_pair((a),(b))
#define pnt(a,b) mp((a),(b))
#define pii pair<int,int>
#define pib pair<int,bool>,&n
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define sstr stringstream
typedef long long ll;
using namespace std;

typedef int T;
struct node {
	T val;
	int  size, hi;
	node* left, *right;
	bool bad;
	static node* empty;
	node() {
		mem(this,0);
		left = right = this;
	}
	node(T v) {
		val = v;
		size = 1;
		hi = 1;
		left = right = empty;
		bad = 0;
	}

	void update() {
		size = left->getSize() + right->getSize() + 1;
		hi = max(left->getHi(), right->getHi()) + 1;
		bad = 0;
	}

	int getSize() {
		if (bad)
			update();
		return size;
	}

	int getHi() {
		if (bad)
			update();
		return hi;
	}
};

node* node::empty = new node;
node* rotateRight(node* rt) {
	node* lft = rt->left;
	node* rlft = rt->left->right;

	lft->right = rt;
	rt->left = rlft;
	rt->bad=1;
	return rt = lft;
}

node* rotateLeft(node* rt) {
	node* rht = rt->right;
	node* lrht = rt->right->left;

	rht->left = rt;
	rt->right = lrht;
	rt->bad=1;
	return rt = rht;
}

node* insert(node* rt, T val) {
	if (rt == node::empty) {
		rt = new node(val);
		return rt;
	}

	if (rt->val == val)
		return rt;


	if (val < rt->val) {
		rt->left = insert(rt->left, val);
		if (abs(rt->left->getHi() - rt->right->getHi()) > 1)
			rt = rotateRight(rt);
	} else {
		rt->right = insert(rt->right, val);
		if (abs(rt->left->getHi() - rt->right->getHi()) > 1)
			rt = rotateLeft(rt);
	}
	rt->bad = 1;
	return rt;
}

int lower_bound(node* root, T val) {
	if(root == node::empty)
		return 0;
	if (root->val == val)
		return root->left->getSize();

	if (val < root->val)
		return lower_bound(root->left, val);

	else
		return lower_bound(root->right, val) + root->left->getSize()+1;
}

node* remove(node* rt, T val){
	if(rt == node::empty)
		return rt;

	rt->bad=1;
	if(rt->val == val){
		if(rt->right == node::empty){
			rt = rt->left;
			return rt;
		}
		else if(rt->left == node::empty){
			rt = rt->right;
			return rt;
		}

		if(rt->left->getHi() - rt->right->getHi() > 1)
			rt = rotateRight(rt);
		else
			rt = rotateLeft(rt);

		rt = remove(rt, val);
		return rt;
	}

	if(val < rt->val)
		rt->left = remove(rt->left, val);
	else
		rt->right = remove(rt->right, val);
	return rt;
}

T getValue(node* root, int idx){
	if(root == node::empty)
		return INT_MIN;
	if(root->left->getSize() == idx)
		return root->val;
	if(root->left->getSize() > idx)
		return getValue(root->left, idx);
	return getValue(root->right, idx-root->left->getSize()-1);
}
int main() {

	node* root = node::empty;
	srand(2);

	int tst, n;
	char c;
	scanf("%d", &tst);

	while (tst--) {
		scanf(" %c %d", &c, &n);
		if (c == 'I')
			root = insert(root, n);
		else if (c == 'D')
			root = remove(root, n);
		else if (c == 'K') {
			int res = getValue(root, n-1);
			if (res < -1e9)
				printf("invalid\n");
			else
				printf("%d\n", res);
		} else
			printf("%d\n", lower_bound(root, n));
	}

	return 0;
}

