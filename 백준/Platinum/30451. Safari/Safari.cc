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
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX];

class node{
public:
    ll x, y, s, e;
    bool operator < (const node& ot) const{
        if(s == ot.s) return e < ot.e;
        return s < ot.s;
    }
}; node a[MAX];

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = MINF;
    if(!cur) return ret = 0;

    for(int i = 0;i < cur;i++){
        if(solve(i) == MINF) continue;
        ll dx = abs(a[cur].x - a[i].x);
        ll dy = abs(a[cur].y - a[i].y);
        ll now = max(a[i].e + dx + dy, a[cur].s);
        if(now > a[cur].e) continue;
        ret = max(ret, solve(i) + a[cur].e - now);
    }

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    for(int i = 1;i <= n;i++) cin >> a[i].s >> a[i].e;
    sort(a + 1, a + n + 1);

    ll result = 0;
    for(int i = 1;i <= n;i++){
        result = max(result, solve(i));
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}