#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 11;
constexpr ll MOD = 1e9 + 7;
vector <tll> adj[MAX];
ll v[MAX], result[MAX]; deque <ll> q;
pll num[MAX];
class _gcd {
public:
    _gcd() {}

    tuple <ll, ll, ll> init(ll a, ll b) {
        if (!b) return { a, 1, 0 };
        auto [g, x, y] = init(b, a % b);
        return { g, y, x - a / b * y };
    }

    ll ret(ll a, ll b) {
        return get<0>(init(a, b));
    }

    ll inv(ll a, ll mod) {
        auto [g, x, y] = init(a, mod);
        if (!a || g != 1) return -1;
        return (x < 0 ? x + mod : x);
    }
};

void dfs(ll cur) {
    if (v[cur]) return; v[cur] = 1;

    for (auto& edge : adj[cur]) {
        auto [nxt, div, mul] = edge;
        if (v[nxt]) continue;
        num[nxt].first = num[cur].first * mul;
        num[nxt].second = num[cur].second * div;
        dfs(nxt);
    }
}

int main() {
    fastio;

    _gcd gcd;
    cin >> n;
    for (int i = 1; i < n; i++) {
        ll s, e, x, y, g;
        cin >> s >> e >> x >> y;
        g = gcd.ret(x, y); x /= g; y /= g;
        adj[s].push_back({ e,x,y });
        adj[e].push_back({ s,y,x });
    }

    num[0] = { 1,1 }; dfs(0);
    ll l = 1, g = 0;
    for (int i = 1; i < n; i++) {
        g = gcd.ret(num[i].second, l);
        l = (l * num[i].second) / g;
    }

    for (int i = 0; i < n; i++) result[i] = num[i].first * l / num[i].second;
    g = 0; for (int i = 0; i < n; i++) g = gcd.ret(g, result[i]);

    for (int i = 0; i < n; i++) cout << result[i] / g << " ";

    return 0;
}