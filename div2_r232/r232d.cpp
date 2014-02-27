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
const int MAXN = 1e5 + 5;

int isp[MAXN];
ll pri[MAXN];
int pn;

void init_pri() {
	fill(isp, isp + MAXN, 1);
	pn = 0;
	up(i, 2, MAXN) {
		if (!isp[i]) continue;

		pri[pn] = i, pn ++;

		for (int j = 2 * i; j < MAXN; j += i) {
			isp[j] = 0;
		}
	}
}

bool judge_pri(ll x) {
	for (ll i = 0; pri[i] * pri[i] <= x; i ++) {
		if (x % pri[i] == 0) return false;
	}
	return true;
}

template <typename T>
T gcd (T a, T b) {
	while (b != 0) {
		T t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

	init_pri();
	int t;
	cin >> t;
	while (t --) {
		ll n;
		cin >> n;
		
		ll a, b;
		for (ll i = n; ; i --) {
			if (judge_pri(i)) {
				a = i;
				break;
			}
		}
		for (ll i = n + 1; ; i ++) {
			if (judge_pri(i)) {
				b = i;
				break;
			}
		}

		ll offset = b - n - 1;
		ll ab = a * b;
		ll de = 2 * ab;
		ll no = ab - 2 * a - 2 * offset;
		ll g = gcd(de, no);
		de /= g;
		no /= g;
		printf("%I64d/%I64d\n", no, de);
	}
    return 0;
}