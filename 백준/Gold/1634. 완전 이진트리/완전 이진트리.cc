#include <bits/stdc++.h>
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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX];

ll dnc(ll s, ll e, ll idx){
    if(s > e) return 0;
    if(s == e) return a[s] == b[idx];

    ll mid = (s + e) >> 1ll, pl = (e - s + 1) / 2;
    ll pre = dnc(s, mid, idx) + dnc(mid + 1, e, idx + pl);
    ll nxt = dnc(s, mid, idx + pl) + dnc(mid + 1, e, idx);

    return max(pre, nxt);
}

void run(){
    cin >> n;
    for(int i = 1;i <= 1 << (n - 1);i++) cin >> a[i];
    for(int i = 1;i <= 1 << (n - 1);i++) cin >> b[i];
    cout << dnc(1, 1 << (n - 1), 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}