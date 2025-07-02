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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
set <ll> pre, suf;
vector <pll> mid;

void run(){
    cin >> n >> m >> k;
    ll mx = MINF, mn = INF;
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        if(a[i].x <= m) pre.insert(a[i].y);
        else if(a[i].y >= k) suf.insert(a[i].x);
        else mid.push_back(a[i]);
    }
    pre.insert(INF); suf.insert(MINF);

    ll result = INF;
    for(auto& [s, e] : mid){
        ll lb = *pre.lower_bound(s);
        ll ub = *--suf.upper_bound(e);

        if(lb == INF || ub == MINF) continue;
        ll mn = e - s;
        result = min(result, min(lb - s, mn) + min(e - ub, mn) + max(lb - ub, 0ll));
    }

    for(auto& s : pre){
        ll ub = *--suf.upper_bound(s);
        if(ub == MINF || s == INF) continue;
        result = min(result, s - ub);
    }

    cout << (result >= INF ? -1 : result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

