#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010;
constexpr ll MOD = 1e9 + 7;
string st[MAX];
ll dp[MAX][MAX][11];
ll dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };

class node{
public:
    ll y, x, c, d;
};
deque <node> q;

int main() {
    fastio;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> st[i];
    memset(dp, 0x3f, sizeof(dp));
    q.push_back({ 0,0,0,1 });
   
    while (!q.empty()) {
        auto [cy, cx, cc, cd] = q.front(); q.pop_front();
        if (dp[cy][cx][cc] <= cd) continue;
        dp[cy][cx][cc] = cd;

        for (int i = 0; i < 4; i++) {
            ll nx = cx + dx[i], ny = cy + dy[i], nc = cc;
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (st[ny][nx] == '1') nc++;
            if (nc > k) continue;

            q.push_back({ ny,nx,nc,cd + 1 });
        }
    }

    ll result = INF;
    for (int i = 0; i <= k; i++) result = min(result, dp[n - 1][m - 1][i]);

    if (result == INF) cout << -1;
    else cout << result;

    return 0;
}