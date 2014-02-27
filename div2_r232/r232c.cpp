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
const int MAXINT = 0x6fffffff;
const ll MAXLONG = (ll) 1 << 63 - 1;
const int MAXN = 505;
const int MOD = 1e9 + 7;

ll arr[MAXN], dp[31 * MAXN][MAXN];
ll res;
int n;

map<ll, ll> facs;
vector<pair<ll, ll>> vec;

void factor(ll x, map<ll, ll> &dictionary) {
  for (ll i = 2; i * i <= x; i++) {
    
    ll pow = 0;
    while (x % i == 0) {
     x /= i;
     pow++;
    }
	if (pow > 0)
    dictionary[i] += pow;
   }
  if (x > 1) { // important
   dictionary[x] += 1;
  }
 }

ll calc(ll a, ll b) {
	ll &res = dp[a][b];
	if (res != -1) {
		return res;
	}
	if (a == b || b == 0) {
		res = 1;
		return res;
	}
	if (b == 1) {
		res = a;
		return a;
	}
	res = calc(a - 1, b) + calc(a - 1, b - 1);
	res %= MOD;
	return res;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

	while (cin >> n) {
		facs.clear();
		up(i, 0, n) {
			ll x;
			cin >> x;
			factor(x, facs);
		}

		map<ll, ll>::iterator it;
		ll res = 1;
		mset(dp, -1);
		for (it = facs.begin(); it != facs.end(); it ++) {
			res = res * calc(n + it->second - 1, n - 1) % MOD;
		}
		cout << res << endl;
	}

    return 0;
}