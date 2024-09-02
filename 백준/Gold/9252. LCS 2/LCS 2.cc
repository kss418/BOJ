#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010101;
constexpr ll MOD = 1e9 + 7;

class _lcs {
public:
	string a, b; vector<vector<ll>> dp;
	ll n, m;
	
	_lcs(string a, string b) {
		this->a = a; this->b = b;
		this->n = a.size(), this->m = b.size();
		dp.resize(n + 1, vector<ll>(m + 1, 0));
	}

	void init() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] == b[j]) {
					dp[i + 1][j + 1] = dp[i][j] + 1;
				}
				else {
					dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
				}
			}
		}
	}
	
	ll ret() {
		return dp[n][m];
	}

	ll ret(ll n, ll m) {
		return dp[n][m];
	}

	string track() {
		string ret;
		ll cy = n, cx = m;
		while (cy && cx) {
			if (a[cy - 1] == b[cx - 1]) {
				ret.push_back(a[cy - 1]); cy--; cx--;
			}
			else if (dp[cy - 1][cx] > dp[cy][cx - 1]) cy--;
			else cx--;
		}

		reverse(ret.begin(), ret.end());
		return ret;
	}
};

int main() {
    fastio;

	string a, b;
	cin >> a >> b;

	_lcs lcs(a, b); lcs.init();
	cout << lcs.ret() << "\n";
	cout << lcs.track();

    return 0;
}