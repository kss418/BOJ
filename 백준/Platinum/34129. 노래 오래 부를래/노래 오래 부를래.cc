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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
bitset <101010> dp[MAX];
vector <ll> result;

void run(){
    cin >> n >> m; ll mx = 0;
    for(int i = 1;i <= n;i++) cin >> a[i].x, a[i].y = i;
    sort(a + 1, a + n + 1);

    dp[0].set(0);
    for(int i = 1;i < n;i++){
        dp[i] |= dp[i - 1];
        if(a[i].x >= m) continue;
        dp[i] |= (dp[i - 1] << a[i].x);
    }

    for(int i = m - 1;i >= 0;i--){
        if(!dp[n - 1][i]) continue;
        mx = i; break;
    }

    ll cnt = mx, sum = mx + a[n].x;
    for(int i = n - 1;i >= 1;i--){
        if(dp[i - 1][cnt]) continue;
        cnt -= a[i].x; result.push_back(a[i].y);
    }

    sort(all(result));
    result.push_back(a[n].y);
    cout << result.size() << " " << sum << "\n";
    for(auto& i : result) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}