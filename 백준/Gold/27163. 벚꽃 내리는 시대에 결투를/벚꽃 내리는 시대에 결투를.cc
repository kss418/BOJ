#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 5010;
ll dp[MAX][MAX];
pair<ll, ll> track[MAX][MAX];
vector <char> result;
char ch[MAX][MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	ll a, l;
	cin >> n >> a >> l;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= l; j++) {
			dp[i][j] = -INF;
		}
	}

	dp[0][l] = a;
	for (int i = 0; i < n; i++) {
		ll ea, el;
		cin >> ea >> el;	

		for (int j = 0; j <= l; j++) {
			ll ret = dp[i][j];
			if (ret < 0) {
				continue;
			}

			if (el >= 0 && ea >= 0) {
				if (ret >= ea) {
					if (dp[i + 1][j] < ret - ea) {
						dp[i + 1][j] = ret - ea;
						track[i + 1][j] = { i,j };
						ch[i + 1][j] = 'A';
					}
				}
				else {
					if (j - el > 0) {
						if (dp[i + 1][j - el] < dp[i][j]) {
							dp[i + 1][j - el] = dp[i][j];
							track[i + 1][j - el] = { i,j };
							ch[i + 1][j - el] = 'L';
						}
					}
				}

				if (j - el > 0) {
					if (dp[i + 1][j - el] < dp[i][j]) {
						dp[i + 1][j - el] = dp[i][j];
						track[i + 1][j - el] = { i,j };
						ch[i + 1][j - el] = 'L';
					}
				}
			}

			else if (ea >= 0) {
				if (dp[i + 1][j] < max(0LL, ret - ea)) {
					dp[i + 1][j] = max(0LL, ret - ea);
					track[i + 1][j] = { i,j };
					ch[i + 1][j] = 'A';
				}
			}

			else {
				if (j - el > 0) {
					if (dp[i + 1][j - el] < dp[i][j]) {
						dp[i + 1][j - el] = dp[i][j];
						track[i + 1][j - el] = { i,j };
						ch[i + 1][j - el] = 'L';
					}
				}
			}
		}
	}

	int cur = -1;
	for (int i = 1; i <= l; i++) {
		if (dp[n][i] >= 0) {
			cur = i;
			break;
		}
	}

	if (cur == -1) {
		cout << "NO";
		return 0;
	}
	else {
		cout << "YES" << "\n";
	}

	string str;
	int pos = n;
	while (1) {
		str.push_back(ch[pos][cur]);
		int a = pos, b = cur;
		pos = track[a][b].first;
		cur = track[a][b].second;
		if (pos == 0) {
			break;
		}
	}

	reverse(str.begin(), str.end());
	cout << str;


	return 0;
}