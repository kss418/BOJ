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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

ll dnc(ll s, ll e){
    if(s > e) return 0;
    if(s == e) return a[s];
    ll mid = (s + e) >> 1ll;
    ll pre = dnc(s, mid), nxt = dnc(mid + 1, e), now = 0;

    ll l = mid, r = mid, h = a[mid];
    while(l > s || r < e){
        if(r >= e || a[l - 1] >= a[r + 1]) h = min(h, a[--l]);
        else h = min(h, a[++r]);
        now = max(now, (r - l + 1) * h);
    }

    return max({pre, nxt, now});
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    cout << dnc(1, n);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}