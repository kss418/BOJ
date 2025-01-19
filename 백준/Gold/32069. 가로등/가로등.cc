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
ll a[MAX];
deque <pll> q;
map <ll, bool> use;

void run(){
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) cin >> a[i], q.push_back({a[i], 0});

    while(1){
        auto [cur, cd] = q.front(); q.pop_front();
        if(use.count(cur)) continue; k--; use[cur] = 1;
        cout << cd << "\n"; if(!k) return;

        if(cur) q.push_back({cur - 1, cd + 1});
        if(cur < n) q.push_back({cur + 1, cd + 1});
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

