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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], adj[MAX][MAX];
priority_queue <pll> pq;
vector <ll> q;

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i], pq.push({a[i], i});
    
    while(!pq.empty()){
        auto[num, now] = pq.top(); pq.pop();
        while(!pq.empty() && a[now]){
            auto[num, nxt] = pq.top(); pq.pop();
            a[now]--; a[nxt]--;
            adj[nxt][now] = adj[now][nxt] = 1;
            q.push_back(nxt);
        }

        while(!q.empty()){
            auto idx = q.back(); q.pop_back();
            if(!a[idx]) continue;
            pq.push({a[idx], idx});
        }
    }
    
    ll flag = 1;
    for(int i = 1;i <= n;i++) if(a[i]) flag = 0;

    if(flag) for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cout << adj[i][j] << " ";
        cout << "\n";
    }
    else cout << -1;


    return 0;
}