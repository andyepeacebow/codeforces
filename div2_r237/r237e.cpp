#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
typedef long long ll;
#define mset(a, val) memset(a, val, sizeof(a))
#define up(i, s, t) for (ll i = (s); i < (t); i += 1)
#define down(i, s, t) for (ll i = (s); i > (t); i -= 1)
#define rd1(a) scanf("%d", &a)
#define rd2(a, b) scanf("%d %d", &a, &b)
#define rd3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define rd4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define pii pair<int, int>

using namespace std;
const int MAXINT = 0x6fffffff;
const ll MAXLONG = (ll) 1 << 63 - 1;
const int MAXN = 1e6 + 5;

char inst[2 * MAXN];
int n;
int vis[2 * MAXN];

bool judge(int x) {
	int cur = n;
	mset(vis, 0);
	up(i, 0, n) {
		vis[cur] = 1;
		if (inst[i] == 'L') {
			if (cur - 1 != x) {
				cur --;
			}
		} else {
			cur ++;
		}
	}

	bool ret = vis[cur] == 0;
	return ret;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

	while (scanf("%s", inst) != -1) {
		n = strlen(inst);
		if (inst[n - 1] == 'L') {
			up(i, 0, n) {
				if (inst[i] == 'L') {
					inst[i] = 'R';
				} else {
					inst[i] = 'L';
				}
			}
		}

		int lb = 0, ub = n;
		int md;
		while (lb + 1 < ub) {
			md = (lb + ub) >> 1;
			bool ok = judge(md);
			if (ok) {
				ub = md;
			} else {
				lb = md;
			}
		}

		if (judge(ub - 1)) {
			ub --;
		}

		int res = n - ub;
		if (res == n) res = 1;
		cout << res << endl;
	}
    return 0;
}