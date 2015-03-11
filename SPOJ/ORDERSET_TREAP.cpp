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
#include <map>

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
#define mit map<int,int>::iterator
typedef long long ll;
using namespace std;
using namespace __gnu_cxx;

typedef int T;

struct node {
	T val;
	int pri, size;
	node* left, *right;
	static node* empty;
	bool badsize;
	node() {
		mem(this,0);
		val = pri = INT_MAX;
		left = right = this;
	}

	node(T value) {
		val = value;
		size = 1;
		badsize = 0;
		pri = rand();
		left = right = node::empty;
	}

	void update() {
		badsize = 0;
		size = left->getSize() + right->getSize() + 1;
	}

	int getSize() {
		if (badsize)
			update();
		return size;
	}

};

node* node::empty = new node;
struct treap {

	node* root;
	treap() {
		root = node::empty;
	}

	node* rotateRight(node* rt) {
		node* lft = rt->left;
		node* rlft = lft->right;

		lft->right = rt;
		rt->left = rlft;

		rt->badsize = lft->badsize = 1;
		return lft;
	}

	node* rotateLeft(node* rt) {
		node* rht = rt->right;
		node* lrht = rht->left;

		rht->left = rt;
		rt->right = lrht;

		rt->badsize = rht->badsize = 1;
		return rht;
	}

	node* balance(node* rt) {
		if (rt->left->pri < rt->pri)
			return rotateRight(rt);
		if (rt->right->pri < rt->pri)
			return rotateLeft(rt);

		return rt;
	}

	node* insert(node* rt, T value) {
		if (rt == node::empty) {
			rt = new node(value);
			return rt;
		}
		if (value == rt->val)
			return rt;

		if (value < rt->val)
			rt->left = insert(rt->left, value), rt->left->badsize = 1;

		else
			rt->right = insert(rt->right, value), rt->right->badsize = 1;

		rt->badsize = 1;
		return balance(rt);
	}

	node* remove(node* rt, T value) {
		if (rt == node::empty)
			return rt;

		rt->badsize = 1;
		if (rt->val == value) {
			if (rt->right == node::empty)
				rt = rt->left;
			else if (rt->left == node::empty)
				rt = rt->right;

			else if (rt->left->pri < rt->right->pri)
				rt = rotateRight(rt);
			else
				rt = rotateLeft(rt);

			rt = remove(rt, value);
			return rt;
		}

		if (value < rt->val)
			rt->left = remove(rt->left, value);
		else
			rt->right = remove(rt->right, value);

		return rt;
	}

	T getValue(node* rt, int idx) {
		if (rt == node::empty)
			return INT_MAX;

		if (rt->left->getSize() == idx)
			return rt->val;

		if (rt->left->getSize() > idx)
			return getValue(rt->left, idx);
		else
			return getValue(rt->right, idx - rt->left->getSize() - 1);
	}

	int lower_bound(node* rt, T value) {
		if (rt == node::empty)
			return 0;

		if (value == rt->val)
			return rt->left->getSize();

		if (value < rt->val)
			return lower_bound(rt->left, value);
		else
			return lower_bound(rt->right, value) + rt->left->getSize() + 1;
	}

};

int main() {

	srand(2);
	treap tr;

	int tst, n;
	char c;
	scanf("%d", &tst);

	while (tst--) {
		scanf(" %c %d", &c, &n);
		if (c == 'I')
			tr.root = tr.insert(tr.root, n);
		else if (c == 'D')
			tr.root = tr.remove(tr.root, n);
		else if (c == 'K') {
			int res = tr.getValue(tr.root, n - 1);
			if (res == INT_MAX)
				printf("invalid\n");
			else
				printf("%d\n", res);
		} else
			printf("%d\n", tr.lower_bound(tr.root, n));
	}

	return 0;
}
