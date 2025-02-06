#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cy, sum[MAX];

ll f(ll num){
    if(!num) return 0;
    return sum[num % cy];
}

void run(){
    cin >> n; ll now = 0;
    for(int i = 0;i < n;i++) cin >> a[i], now ^= a[i];
    a[n] = now; cy = n + 1;
    for(int i = 1;i <= cy;i++) sum[i] = sum[i - 1] ^ a[i - 1];

    cin >> m;
    while(m--){
        ll s, e; cin >> s >> e;
        if(n == 1) cout << (((e - s + 1) % 2) ? a[0] : 0) << "\n";
        else cout << (f(e) ^ f(s - 1)) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}