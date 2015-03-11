#include <iostream>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)

struct line {
	int x1, y1, x2, y2;
};

const int MAX = 15;
bool adjMat[MAX][MAX];
line lns[MAX];

void floydWarshal(bool adjMax[MAX][MAX], int n) { // O(n^3)
	for (int k = 1; k < n; ++k) {
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < n; ++j) {
				if (adjMax[i][k] && adjMax[k][j])
					adjMax[i][j] = 1, adjMax[j][i] = 1;
			}
		}
	}
}


struct point
{
	int x, y;
	point(){							}

	point(int xx, int yy)
	{	x = xx, y = yy;					}

	point operator - (const point &b) const
	{	return point(x-b.x, y-b.y);		}
};

int norm(point v)
{
	return v.x * v.x + v.y * v.y;
}

int ccw( point p0, point p1, point p2 ) /* ccw test : counterclockwise */
{	/* Dirction value(-1,0,1) from p0->p1->p2. counterclockwise = 1 */
	point v1(p1-p0), v2(p2-p0);	/* vectors p0p1, p0p2 */

	/* cp = d1-d2  dp = d3+d4 */
	int d1 = v1.x*v2.y;
	int d2 = v1.y*v2.x;
	int d3 = v1.x*v2.x;
	int d4 = v1.y*v2.y;

	if (d1 > d2)				return +1; /* p2 to right of segment p0p1 */
	if (d1 < d2)				return -1; /* p2 to left  of segment p0p1 */
			/* Co-linear three cases */
	if (d3 < 0 || d4 < 0)		return -1; /* p2 to left  of segment p0p1 */
	if ( norm(v1) < norm(v2) )	return +1; /* p2 to right of segment p0p1 */
								return  0; /* p2 Colinear on segment p0p1 */
}

bool intersect(point p1, point p2, point p3, point p4)
{	/* Does segments p1p2 & p3p4 intersect */
	return ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0  &&
		   ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}

bool intersection_lines(line ln1, line ln2) {

	point a(ln1.x1, ln1.y1);
	point b(ln1.x2, ln1.y2);

	point c(ln2.x1, ln2.y1);
	point d(ln2.x2, ln2.y2);

	return intersect(a, b, c, d);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("c.in", "r", stdin);

#endif

	int tst, n, x, y;
	cin >> tst;
	bool start = 0;
	while (tst--) {
		if (start)
			cout << endl;
		start = 1;

		memset(adjMat, 0, sizeof adjMat);
		cin >> n;
		n++;
		foo(i,1,n) {
			cin >> lns[i].x1;
			cin >> lns[i].y1;
			cin >> lns[i].x2;
			cin >> lns[i].y2;
		}

		foo(i,1,n)
			adjMat[i][i] = 1;

		foo(i,1,n)
			foo(j,i+1,n) {
				if (intersection_lines(lns[i], lns[j]))
					adjMat[i][j] = 1, adjMat[j][i] = 1;
			}

		floydWarshal(adjMat, n);

		while (cin >> x >> y) {
			if (x == 0 && y == 0)
				break;

			(adjMat[x][y]) ? cout << "CONNECTED\n" : cout << "NOT CONNECTED\n";

		}
	}

	return 0;
}
