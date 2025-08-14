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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result[MAX];
ll dp[MAX][50];
vector <ll> fib;
map <ll, ll> org;

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 0;i < n;i++) cin >> a[i];

    ll l = 1, r = 2; 
    fib.push_back(1); fib.push_back(2);
    while(r < 3e9){
        fib.push_back(l + r);
        ll tmp = l + r;
        l = r; r = tmp;
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < 50;j++){
            ll now = fib[j];
            auto lb = org.find(now - a[i]);
            if(i) dp[i][j] = dp[i - 1][j];

            if(lb == org.end()) continue;
            dp[i][j] = max(dp[i][j], lb->y);
        }

        org[a[i]] = i;
    }

    for(int i = 1;i <= m;i++){
        ll s, e; cin >> s >> e;
        ll now = 0;
        for(int j = 0;j < 50;j++){
            ll a = dp[e][j];
            if(a >= s) now++;
        }

        cout << now << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}