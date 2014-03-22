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
int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

	double a, d;
	int n;
	
	while (cin >> a >> d >> n) {
		double cur = 0.0;
		up(i, 0, n) {
			cur = fmod(cur + d, 4 * a);
			if (0.0 <= cur && cur <= a) {
				printf("%lf %lf\n", cur, 0.0);
			} else if (a <= cur && cur <= 2 * a) {
				printf("%lf %lf\n", a, cur - a);
			} else if (2 * a <= cur && cur <= 3 * a) {
				printf("%lf %lf\n", 3 * a - cur, a);
			} else if (3 * a <= cur && cur <= 4 * a) {
				printf("%lf %lf\n", 0.0, 4 * a - cur);
			}
		}
	}
    return 0;
}