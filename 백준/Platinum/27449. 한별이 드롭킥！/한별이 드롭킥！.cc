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
ll dp[MAX][MAX][2], pre[MAX], suf[MAX], result;
pll a[MAX];
vector <pll> mi, po;

ll solve(ll l, ll r, ll cnt){
    ll& ret = dp[l][r][cnt];
    if(ret != -1) return ret; ret = 0;
    if(!l && !r) return ret = m;
    
    if(cnt && r){
        ll now = solve(l, r - 1, cnt);
        if(abs(po[r].x - po[r - 1].x) < now) ret = max(ret, now + po[r].y - abs(po[r].x - po[r - 1].x));
    
        now = solve(l, r - 1, cnt ^ 1);
        if(abs(po[r].x - mi[l].x) < now) ret = max(ret, now + po[r].y - abs(po[r].x - mi[l].x));
    }   
    else if(!cnt && l){
        ll now = solve(l - 1, r, cnt ^ 1);
        if(abs(mi[l].x - po[r].x) < now) ret = max(ret, now + mi[l].y - abs(mi[l].x - po[r].x));
    
        now = solve(l - 1, r, cnt);
        if(abs(mi[l].x - mi[l - 1].x) < now) ret = max(ret, now + mi[l].y - abs(mi[l].x - mi[l - 1].x));
    }

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        (a[i].x < 0 ? mi : po).push_back(a[i]);
    }

    mi.push_back({0, 0}); po.push_back({0, 0});
    sort(all(po)); sort(all(mi), greater<pll>());
    pre[0] = mi[0].y; suf[0] = po[0].y;
    for(int i = 1;i < mi.size();i++) pre[i] = pre[i - 1] + mi[i].y;
    for(int i = 1;i < po.size();i++) suf[i] = suf[i - 1] + po[i].y;

    for(int i = 0;i < mi.size();i++){
        for(int j = 0;j < po.size();j++){
            ll now = max(solve(i, j, 0), solve(i, j, 1));
            if(!now) continue;
            result = max(result, pre[i] + suf[j] + m);
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}