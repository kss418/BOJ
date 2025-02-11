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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], p[MAX], num[MAX], pos[MAX];
vector <ll> adj[MAX];
priority_queue <ll, vector<ll>, greater<ll>> pq;

void run(){
    cin >> n;
    for(int i = 2;i <= n;i++) cin >> p[i], adj[p[i]].push_back(i);
    for(int i = 1;i <= n;i++) cin >> a[i], pos[a[i]] = i;

    pq.push(a[1]);
    while(!pq.empty()){
        ll cur = pq.top(); pq.pop();
        ll now = pos[cur];
        cout << cur << "\n";

        for(auto& nxt: adj[now]) pq.push(a[nxt]);
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

