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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], mn = INF, cnt;

void run(){
    ll y1, y2; cin >> n >> m >> y1 >> y2;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) cin >> b[i];
    sort(a + 1, a + n + 1); sort(b + 1, b + m + 1);
    b[0] = MINF; b[m + 1] = INF;

    for(int i = 1;i <= n;i++){
        ll lb = lower_bound(b, b + m + 2, a[i]) - b - 1;
        ll ub = lower_bound(b, b + m + 2, a[i]) - b;
        mn = min({mn, a[i] - b[lb], b[ub] - a[i]});
    }

    mn += abs(y2 - y1);
    cout << mn << " ";

    for(int i = 1;i <= n;i++){
        ll lb = lower_bound(b, b + m + 2, a[i]) - b - 1;
        ll ub = lower_bound(b, b + m + 2, a[i]) - b;
        if(a[i] - b[lb] + abs(y2 - y1) == mn) cnt++;
        if(b[ub] - a[i] + abs(y2 - y1) == mn) cnt++;
    }

    cout << cnt;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}