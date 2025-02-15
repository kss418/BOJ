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
constexpr ll MAX = 4010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt[MAX], sum[MAX];

void run(){
    cin >> n >> m >> k; 
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            ll v; cin >> v;
            if(v < i) v += n;
            cnt[i]++; cnt[v]--;
        }
    }
    for(int i = 1;i <= 2 * n;i++) sum[i] = sum[i - 1] + cnt[i];

    ll result = 1;
    for(int i = 1;i <= n;i++){
        ll a = sum[i];
        ll b = sum[i + n];
        if(b == k) result = 0;
        if(a + b > k) result = 0;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

