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
#include <unordered_set>
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
const int MAXV = 1e9 + 5;
const int SQMAXV = 1e5;
const int MAXM = 5005;

vector<int> primes, arr, vg;
unordered_map<int, int> bad;
int isBad[SQMAXV], dp[MAXM];
int n, m;

void find_prime() {
	bool isPrime[SQMAXV];
	fill(isPrime, isPrime + SQMAXV, true);
	for (ll i = 2; i * i <= MAXV; i ++) {
		if (!isPrime[i]) continue;

		primes.push_back(i);
		for (ll j = 2 * i; j * j <= MAXV; j += i) {
			isPrime[j] = false;
		}
	}
}

template <typename T>
T gcd(T a, T b) {
  while (b != 0) {
    T t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int calc(int x) {

	int pn = primes.size();
	int ret = 0;
	up(i, 0, pn) {
		int prime = primes[i];
		while (x % prime == 0) {
			x /= prime;
			if (bad[prime]) {
				ret --;
			} else {
				ret ++;
			}
		}
	}

	if (x > 1) {
		if (bad[x]) {
			ret --;
		} else {
			ret ++;
		}
	}

	return ret;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

	find_prime();


	while (cin >> n >> m) {
		arr.clear();
		up(i, 0, n) {
			int v;
			rd1(v);
			arr.push_back(v);
		}

		bad.clear();
		up(i, 0, m) {
			int v;
			rd1(v);
			bad[v] = 1;
		}

		int pn = primes.size();
		
		vg.clear();
		int g = arr[0];
		up(i, 0, n) {
			g = gcd(g, arr[i]);
			
			vg.push_back(g);
		}
		
		int res = 0;
		int last = 1;
		down(i, n - 1, -1) {
			int once = calc(vg[i] / last);
			if (once < 0) {
				last = vg[i];
			}

			arr[i] /= last;

			res += calc(arr[i]);
		}

		cout << res << endl;
	}
    return 0;
}