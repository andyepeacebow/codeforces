#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define mset(a, val) memset(a, val, sizeof(a))
#define up(i, s, t) for (int i = (s); i < (t); i += 1)
#define down(i, s, t) for (int i = (s); i > (t); i -= 1)
#define rd1(a) scanf("%d", &a)
#define rd2(a, b) scanf("%d %d", &a, &b)
#define rd3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define rd4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define pii pair<int, int>

typedef long long ll;
using namespace std;
const int MAXINT = 1 << 31 - 1;
const ll MAXLONG = (ll) 1 << 63 - 1;
const int MAXN = 1e6 + 5;

int p, x;
int ar1[MAXN], ar2[MAXN];

bool check(int a) {
	ar1[p] = a;
	int ca = 0;
	down(i, p, 0) {
		ar2[i] = (ca * 10 + ar1[i]) / x;
		ca = ca * 10 + ar1[i] - ar2[i] * x;
		ar1[i - 1] = ar2[i];
	}
	if (ca == 0 && ar2[1] == a) {
		return true;
	} else {
		return false;
	}
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

	while (rd2(p, x) != -1) {
		bool ok = false;
		up(i, x, 10) { // top digit
			bool once = check(i);
			if (once) {
				// cout << i << endl;
				ok = true;
				break;
			}
		}
		if (ok) {
			down(i, p, 0) {
				printf("%d", ar2[i]);
			}
			cout << endl;

		}
		if (!ok) {
			puts("Impossible");
		}
	}
    return 0;
}