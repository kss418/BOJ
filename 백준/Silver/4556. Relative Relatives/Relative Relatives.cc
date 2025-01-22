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
ll cnt;
map <string, vector<pair<string, ll>>> adj;
vector <pair <string, ll>> result;

void init(){
    adj.clear(); result.clear();
}

void dfs(string cur, ll now){
    if(cur != "Ted") result.push_back({cur, now});
    for(auto& nn : adj[cur]){
        auto[nxt, co] = nn;
        dfs(nxt, now + co);
    }
}

void run(){
    cin >> n; init();
    for(int i = 1;i <= n;i++) {
        string a, b; ll c; cin >> a >> b >> c;
        adj[a].push_back({b, -c});
    }
    dfs("Ted", 100);

    sort(all(result), [](pair<string, ll>& a, pair<string, ll>& b){
        if(a.y != b.y) return a.y > b.y;
        return a.x < b.x;
    });
    cout << "DATASET " << ++cnt << "\n";
    for(auto& i : result) cout << i.x << " " << i.y << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

