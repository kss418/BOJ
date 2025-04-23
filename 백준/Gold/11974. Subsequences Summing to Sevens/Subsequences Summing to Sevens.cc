#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 50101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], sum[MAX];
ll mn[MAX], mx[MAX], result;

void run(){
    cin >> n; memset(mn, 0x3f,sizeof(mn));
    for(int i = 1;i <= n;i++) cin >> a[i];

    mn[0] = 0;
    for(ll i = 1;i <= n;i++) {
        sum[i] = (sum[i - 1] + a[i]) % 7;
        mx[sum[i]] = max(mx[sum[i]], i);
        mn[sum[i]] = min(mn[sum[i]], i);
    }

    for(int i = 0;i < 7;i++) result = max(result, mx[i] - mn[i]);
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}