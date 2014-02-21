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
const int MAXN = 1005;

int res[MAXN][MAXN];
int cnt[3];
int n, m;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

	while (rd2(n, m) != -1) {
		mset(cnt, 0);
		up(i, 0, n) {
			up(j, 0, m) {
				char buf[3];
				scanf("%s", buf);
				int val = buf[0] - '0' + buf[1] - '0';
				cnt[val] ++;
			}
		}

		mset(res, 0);
		int i1 = 0, i2 = 0;
		while (cnt[2] > 0) {
			res[i1][i2] = 2;
			i2 ++;
			if (i2 >= m) {
				i2 = 0;
				i1 ++;
			}
			cnt[2] --;
		}

		int dir = 0;
		while (cnt[1] > 0) {
			if (i1 == 0 || res[i1 - 1][i2] == -1) {
				res[i1][i2] = 1;
			} else {
				res[i1][i2] = -1;
			}

			if (dir == 0) {
				i2 ++;
				if (i2 >= m) {
					i2 = m - 1;
					i1 ++;
					dir = 1;
				}
			} else {
				i2 --;
				if (i2 < 0) {
					i2 = 0;
					i1 ++;
					dir = 0;
				}
			}
			cnt[1] --;
		}

		up(i, 0, n) {
			up(j, 0, m) {
				if (res[i][j] == 2) {
					printf("11");
				} else if (res[i][j] == 1) {
					printf("01");
				} else if (res[i][j] == -1) {
					printf("10");
				} else {
					printf("00");
				}
				printf("%c", j + 1 == m ? '\n' : ' ');
			}
		}
	}
    return 0;
}