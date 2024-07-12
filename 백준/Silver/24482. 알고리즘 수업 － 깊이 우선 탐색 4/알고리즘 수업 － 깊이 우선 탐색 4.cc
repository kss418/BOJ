#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
vector <ll> arr[MAX];
ll st, d[MAX];

void dfs(ll cur, ll dep) {
    if (d[cur] != -1) return;
    d[cur] = dep;

    for (auto& nxt : arr[cur]) dfs(nxt, dep + 1);
}


int main()
{
    fastio;

    cin >> n >> m >> st;
    for (int i = 1; i <= m; i++) {
        ll a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) sort(arr[i].begin(), arr[i].end()), reverse(arr[i].begin(), arr[i].end());

    memset(d, -1, sizeof(d));
    dfs(st, 0);
    for (int i = 1; i <= n; i++) cout << d[i] << "\n";


    return 0;
}
