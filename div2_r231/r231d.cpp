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
const int MAXN = 1e3 + 5;
const int MAXV = 3 * 1e4;
int n;
int arr[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

	while (cin >> n) {
		up(i, 0, n) {
			rd1(arr[i]);
		}
		sort(arr, arr + n);

		int res = MAXINT, res_step, res_first;
		up(step, 0, MAXV) {
			int lo = MAXV, hi = - MAXV;
			int now = 0;
			up(j, 0, n) {
				int dif = arr[j] - now;
				lo = min(lo, dif);
				hi = max(hi, dif);
				now += step;
			}

			int once = (hi - lo + 1) / 2;
			if (once < res) {
				res = once;
				res_step = step;
				res_first = lo + once;
			}
		}

		cout << res << endl;
		printf("%d %d\n", res_first, res_step);
	}

    return 0;
}