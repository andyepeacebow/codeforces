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
const int MAXM = 1e5 + 5;

vector<int> dd[MAXM];
ll n, k;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

	while (cin >> n >> k) {

		up(i, 0, n + 1) {
			dd[i].clear();
		}

		up(i, 1, n + 1) {
			int d;
			
			rd1(d);
			dd[d].push_back(i);
		}

		bool ok = true;
		if (dd[0].size() != 1) {
			puts("-1");
			continue;
		}

		up(i, 1, n + 1) {

			ll can = dd[i - 1].size() * k;
			if (i > 1) {
				can -= dd[i - 1].size();
			}
			if (can < dd[i].size()) {
				ok = false;
				break;
			}

			
		}

		if (!ok) {
			puts("-1");
			continue;
		}

		printf("%d\n", n - 1);
		up(i, 1, n + 1) {
			int pre_sz = dd[i - 1].size();
			int idx = 0;
			up(j, 0, pre_sz) {
				int most = i == 1 ? k : k - 1;
				up(h, 0, most) { // at most k edges
					if (idx >= dd[i].size()) {
						break;
					}
					printf("%d %d\n", dd[i - 1][j], dd[i][idx]);
					idx ++;
				}	
			}
		}
	}
    return 0;
}