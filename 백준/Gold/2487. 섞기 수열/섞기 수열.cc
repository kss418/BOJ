#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 20101;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], v[MAX], cnt;
vector<ll> num[MAX];

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
    num[cnt].push_back(cur); dfs(arr[cur]);
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    _gcd gcd;

    for (int i = 1; i <= n; i++) {
        if (v[i]) continue;
        cnt++; dfs(i);
    }

    ll result = 1;
    for (int i = 1; i <= cnt; i++) {
        ll g = gcd.ret(result, num[i].size());
        result *= num[i].size();
        result /= g;
    }

    cout << result;


    return 0;
}