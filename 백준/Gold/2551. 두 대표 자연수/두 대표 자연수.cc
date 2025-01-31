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
constexpr ll MAX = 5010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll cnt[10101], rs, rp, ns = INF, np = INF;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> m, cnt[m]++;
    
    for(int i = 1;i <= 10000;i++){
        ll s = 0, p = 0;
        for(int j = 1;j <= 10000;j++){
            s += abs(i - j) * cnt[j];
            p += (i - j) * (i - j) * cnt[j];
        }

        if(s < ns) ns = s, rs = i;
        if(p < np) np = p, rp = i;
    }

    cout << rs << " " << rp;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

