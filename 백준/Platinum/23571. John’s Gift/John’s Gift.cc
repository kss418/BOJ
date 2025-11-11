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
ll a[MAX], b[MAX];
ll pre[MAX][2], suf[MAX][2];

ll diff(ll idx, ll cnt){
    return abs(a[idx] - b[idx + cnt]);
}

ll solve1(ll cur, ll cnt){
    ll& ret = pre[cur][cnt];
    if(ret != -1) return ret; ret = INF;
    if(!cur) return ret = 0;

    if(!cnt) ret = min(ret, max(solve1(cur - 1, 0), diff(cur, 0)));
    else{
        ret = min(ret, max(solve1(cur - 1, 1), diff(cur, 1)));
        ret = min(ret, max(solve1(cur - 1, 0), diff(cur, 1)));
    }

    return ret;
}

ll solve2(ll cur, ll cnt){
    ll& ret = suf[cur][cnt];
    if(ret != -1) return ret; ret = INF;
    if(cur == n + 1) return ret = 0;

    if(!cnt) ret = min(ret, max(solve2(cur + 1, 0), diff(cur, 0)));
    else{
        ret = min(ret, max(solve2(cur + 1, 1), diff(cur, -1)));
        ret = min(ret, max(solve2(cur + 1, 0), diff(cur, -1)));
    }

    return ret;
}

void run(){
    cin >> n; memset(pre, -1, sizeof(pre));
    memset(suf, -1, sizeof(suf));
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    sort(a + 1, a + n + 1); sort(b + 1, b + n + 1);

    ll mn = INF, result = 0;
    for(int i = 1;i <= n;i++){
        ll l0 = solve1(i - 1, 0), l1 = solve1(i - 1, 1);
        ll r0 = solve2(i + 1, 0), r1 = solve2(i + 1, 1);

        ll now = min(max(l0, r1), max(l1, r0));
        now = min(now, max(l0, r0));
        if(now < mn) mn = now, result = a[i];
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}