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
constexpr ll MAX = 251010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt[MAX];

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    ll result = 0;
    for(int i = 2;i <= n;i++){
        ll now = ceil(log2l((ld)a[i - 1] / (ld)a[i])) + cnt[i - 1];
        if(now <= 0) continue;
        cnt[i] += now; result += now;
    }
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

