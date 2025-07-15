#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

void sl(ll idx, ll v){
    if(!idx || v <= 0) return;
    ll mn = min(a[idx], v);
    a[idx] += mn; v -= mn;
    sl(idx - 1, v);
}

void sr(ll idx, ll v){
    if(idx == n + 1 || v <= 0) return;
    ll mn = min(a[idx], v);
    a[idx] += mn; v -= mn;
    sr(idx + 1, v);
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    cin >> m;
    while(m--){
        ll op, idx; cin >> op >> idx;
        if(op == 1){
            ll v; cin >> v;
            sl(idx, v);
            sr(idx + 1, v);
        }
        else cout << a[idx] << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}