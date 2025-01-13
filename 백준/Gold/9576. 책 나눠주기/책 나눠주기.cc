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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ll ind[MAX], idx[MAX];
set <ll> adj[MAX];

void init(){
    memset(ind, 0, sizeof(ind)); ind[0] = INF;
    for(int i = 1;i <= n;i++) adj[i].clear();
}

void run(){
    cin >> n >> m; init();
    for(int i = 1;i <= m;i++) {
        cin >> a[i].x >> a[i].y; 
        for(int j = a[i].x;j <= a[i].y;j++) adj[j].insert(i), ind[i]++;
    }
    for(int i = 1;i <= n;i++) idx[i] = i;

    ll result = 0;
    for(int i = 1;i <= n;i++){
        sort(idx + i, idx + n + 1, [](ll& a, ll& b){
            return adj[a].size() < adj[b].size();
        });

        ll now = idx[i], mn = 0;
        for(auto& nxt : adj[now]) {
            mn = (ind[mn] >= ind[nxt] ? nxt : mn);
            ind[nxt]--;
        }

        if(!mn) continue; result++;
        for(int j = a[mn].x;j <= a[mn].y;j++) adj[j].erase(mn);
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}