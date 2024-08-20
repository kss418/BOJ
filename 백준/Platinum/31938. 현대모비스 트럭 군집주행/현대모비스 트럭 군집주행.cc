#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
vector <pll> adj[MAX];
ll dist[MAX], pre[MAX], v[MAX];
priority_queue<pll, vector<pll>, greater<pll>> pq;
deque <ll> q;
ll ind[MAX], dp[MAX], mn[MAX];
map <pll, ll> num;


int main()
{
    fastio;
    cin >> n >> m;
    while (m--) {
        ll st, en;
        cin >> st >> en >> k;
        adj[st].push_back({ en, k });
        adj[en].push_back({ st, k });
        num[{min(st, en), max(st, en)}] = k;
    }
    memset(dist, 0x3f, sizeof(dist));
    memset(mn, 0x3f, sizeof(mn));
    dist[1] = 0;
    pq.push({ 0, 1 });
    
    while (!pq.empty()) {
        ll cn = pq.top().second; ll cd = pq.top().first;
        pq.pop(); if (v[cn]) continue;
        v[cn] = 1;

        for (auto& nxt : adj[cn]) {
            ll nn = nxt.first, nd = nxt.second;
            if (dist[nn] < cd + nd) continue;
            if (dist[nn] == cd + nd && mn[nn] < nd) continue;
            mn[nn] = nd;
            dist[nn] = cd + nd;
            pq.push({ dist[nn], nn });
            pre[nn] = cn;
        }
    }

    for (int i = 1; i <= n; i++) ind[pre[i]]++;
    for (int i = 1; i <= n; i++) if (!ind[i]) q.push_back(i);

    memset(v, 0, sizeof(v));
    while (!q.empty()) {
        ll cur = q.front(); q.pop_front();
        if (!cur || v[cur]) continue;
        v[cur] = 1;
        dp[cur]++; ll nxt = pre[cur];
        dp[nxt] += dp[cur];
        if(!--ind[nxt]) q.push_back(nxt);
    }

    ll result = 0;
    for (ll i = 1; i <= n; i++) result += (9 * dp[i] + 1) * num[{min(i, pre[i]), max(i, pre[i])}] / 10;
    cout << result;


    return 0;
}