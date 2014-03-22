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
const int MOD = 1e9 + 7;

ll dp[MAXN][5];
char arr[MAXN];
int n;


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

	while (scanf("%s", arr) != -1) {
		n = strlen(arr);
		mset(dp, 0);

		ll res = 1;
		if (arr[0] == '0' || arr[0] == '?') {
			dp[0][0] = 1;
		} 
		if (arr[0] == '1' || arr[0] == '?') {
			dp[0][1] = 1;
		}
		if (arr[0] == '2') {
			puts("0");
			continue;
		}
		if (arr[0] == '*' || arr[0] == '?') {
			dp[0][4] = 1;
		}

		up(i, 0, n) {
			up(j, 0, 5) {
				dp[i][j] %= MOD;
			}
			if (arr[i] == '0' || arr[i] == '?') {
				dp[i + 1][0] += dp[i][0];
				dp[i + 1][1] += dp[i][0];
			}
			if (arr[i] == '1' || arr[i] == '?') {
				dp[i + 1][0] += dp[i][2];
				dp[i + 1][1] += dp[i][2];

				dp[i + 1][4] += dp[i][1];
			} 
			if (arr[i] == '2' || arr[i] == '?') {
				dp[i + 1][4] += dp[i][3];
			} 
			if (arr[i] == '*' || arr[i] == '?') {
				dp[i + 1][3] += dp[i][4];
				dp[i + 1][2] += dp[i][4];
				dp[i + 1][4] += dp[i][4];
			}
		}

		dp[n - 1][1] = dp[n - 1][3] =  0; // impossible
		res = 0;
		if (arr[n - 1] == '?') {
			up(i, 0, 5) {
				res = (res + dp[n - 1][i]) % MOD;
			}
		} else {
			if (arr[n - 1] == '0') {
				res = dp[n - 1][0];
			} else if (arr[n - 1] == '1') {
				res = dp[n - 1][2];
			} else if (arr[n - 1] == '*') {
				res = dp[n - 1][4];
			}
		}

		cout << res << endl;
	}
    return 0;
}