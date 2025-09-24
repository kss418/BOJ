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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], b[MAX];
ll pre[MAX][MAX], dp[MAX][MAX];
vector <ll> tr;

ll solve(ll cur, ll cnt){
    if(cnt < 0) return MINF;
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = 0;
    if(!cur) return ret = (cnt ? MINF : 0);

    for(int i = 0;i <= m;i++){
        ll now = solve(cur - 1, cnt - i) + a[cur][i];
        if(ret > now) continue; ret = now;
        pre[cur][cnt] = i;
    }

    return ret;
}

void run(){
    cin >> n >> m; 
    memset(dp, -1, sizeof(dp));
    memset(pre, -1, sizeof(pre));

    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= m;j++) cin >> a[i][j];
    }

    for(int i = 0;i <= m;i++) cin >> b[i];

    ll ret = MINF, sum = -1;
    for(int i = 0;i <= m;i++){
        ll now = solve(n, i) - b[i];
        if(now <= ret) continue;
        ret = now; sum = i;
    }

    cout << ret << "\n";
    for(int i = n;i >= 1;i--){
        ll num = pre[i][sum];
        sum -= num;
        tr.push_back(num);
    }

    reverse(all(tr));
    for(auto& i : tr) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}