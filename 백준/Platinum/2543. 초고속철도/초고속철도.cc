#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 20070713;
vector <pll> a;
vector <ll> v;
ll dp[MAX];

ll solve(ll cur){
    ll& ret = dp[cur];
    if(cur < 0) return 1;
    if(ret != -1) return ret; ret = 0;

    ret += solve(cur - 1); ret %= MOD;

    ll ub = upper_bound(all(v), a[cur].x) - v.begin() - 1;
    ret += solve(ub); ret %= MOD;

    return ret %= MOD;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) {
        ll l, r; cin >> l >> r;
        a.push_back({l, r});
        v.push_back(r);
    }

    sort(all(a), [](pll& a, pll& b){
        return a.y < b.y;
    });
    sort(all(v));

    cout << solve(n - 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

