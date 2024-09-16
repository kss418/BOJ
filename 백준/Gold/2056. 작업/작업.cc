#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 10101;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], dp[MAX], result;

class _ts {
public:
    ll n; vector<vector<ll>> adj;
    vector<ll> ind, sort;
    _ts(ll n) {
        this->n = n; adj.resize(n + 1);
        ind.resize(n + 1);
    }

    void addsol(ll st, ll en) {
        adj[st].push_back(en);
        ind[en]++;
    }

    void init() {
        deque <ll> q;
        for (int i = 1; i <= n; i++) {
            if (ind[i]) continue;
            q.push_back(i);
            result = max(dp[i], result);
        }

        while (!q.empty()) {
            ll cur = q.front(); q.pop_front();
            sort.push_back(cur);
            dp[cur] += arr[cur];
            result = max(result, dp[cur]);

            for (auto& nxt : adj[cur]) {
                dp[nxt] = max(dp[nxt], dp[cur]);
                if (!--ind[nxt]) q.push_back(nxt);
            }
        }
    }

    vector <ll> ret() { return sort; }
};

int main() {
    fastio;

    cin >> n; _ts ts(n);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i] >> m;
        for (int j = 1; j <= m; j++) {
            cin >> k; ts.addsol(k, i);
        }
    }
    ts.init();

    cout << result;


    return 0;
}