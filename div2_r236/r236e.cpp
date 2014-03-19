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
const int MAXN = 2005;

int gra[MAXN][MAXN];
int vis[MAXN];
int n;
vector<int> seq;

void dfs(int u) {
	vis[u] = 1;
	up(i, 1, n + 1) {
		if (gra[u][i] && !vis[i]) {
			dfs(i);
		}
	}
	seq.push_back(u);
}

void rdfs(int u) {
	vis[u] = 1;
	up(i, 1, n + 1) {
		if (gra[i][u] && !vis[i]) {
			rdfs(i);
		}
	}
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

	while (cin >> n) {
		up(i, 1, n + 1) {
			up(j, 1, n + 1) {
				scanf("%d", &gra[i][j]);
			}
		}

		seq.clear();
		mset(vis, 0);
		up(i, 1, n + 1) {
			if (vis[i]) continue;

			dfs(i);
		}

		int num = 0;
		mset(vis, 0);
		down(i, seq.size() - 1, -1) {
			if (vis[seq[i]]) continue;

			num ++;
			rdfs(seq[i]);
		}

		string ans = num == 1 ? "YES" : "NO";
		cout << ans << endl;
	}
    return 0;
}