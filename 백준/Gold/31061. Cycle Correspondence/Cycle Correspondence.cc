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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], out;
ll ca[MAX], cb[MAX], c[MAX];

void run(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++) cin >> a[i], ca[a[i]] = i;
    for(int i = 1;i <= m;i++) cin >> b[i], cb[b[i]] = i;

    ll cnt = 0, mx = 0;
    for(int i = 1;i <= n;i++){
        if(!ca[i] && !cb[i]) out++;
        if(!ca[i] || !cb[i]) continue;
        ll d = ca[i] - cb[i];
        if(d < 0) d += m; c[d]++;
    }

    for(int i = 0;i < m;i++) mx = max(mx, c[i]);
    memset(c, 0, sizeof(c));
    reverse(b + 1, b + m + 1); cnt = 0;
    for(int i = 1;i <= m;i++) cb[b[i]] = i;

    for(int i = 1;i <= n;i++){
        if(!ca[i] || !cb[i]) continue;
        ll d = ca[i] - cb[i]; 
        if(d < 0) d += m; c[d]++;
    }

    for(int i = 0;i < m;i++) mx = max(mx, c[i]);
    ll diff = m - mx;

    cout << mx + out;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}