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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 501010;
constexpr ll MOD = 998244353;
vector <ll> adj[MAX];
ll a[MAX], ind[MAX];
ld dp[MAX][51];
deque <ll> q;

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> a[i];
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e); ind[e]++;
    }

    q.push_back(0); dp[0][1] = a[0];
    ld result = a[0]; 
    while(!q.empty()){
        ll cur = q.front(); q.pop_front();
        for(auto& nxt : adj[cur]){
            for(int i = 1;i <= 50;i++){
                ld now = dp[cur][i - 1] + (a[nxt] / (ld)(1ll << (i - 1)));
                dp[nxt][i] = max(now, dp[nxt][i]);
                dp[nxt][i] = max(dp[nxt][i], dp[cur][i]);
                result = max(result, dp[nxt][i]);
            }

            if(!--ind[nxt]) q.push_back(nxt);
        }
    }

    cout.precision(20);
    cout << result;
    
    
    return 0;
}