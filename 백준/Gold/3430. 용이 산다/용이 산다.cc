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
ll n, m, k, t = 4; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], flag;
bool in[MAX];
vector <ll> result, idx[MAX];
priority_queue <pll, vector<pll>, greater<pll>> water;

void init(){
    result.clear(); flag = 0;
    while(!water.empty()) water.pop();
    for(int i = 0;i <= n;i++) idx[i].clear();
}

ll ub(const vector <ll>& v, ll num){
    return v[upper_bound(all(v), num) - v.begin()];
}

void run(){
    cin >> n >> m; init();
    for(int i = 1;i <= m;i++) cin >> a[i], idx[a[i]].push_back(i);
    for(int i = 1;i <= n;i++) {
        idx[i].push_back(INF);
        water.push({idx[i][0], i});
        in[i] = 1;
    }

    for(int i = 1;i <= m;i++){
        if(a[i]){
            if(in[a[i]]) flag = 1;
            else water.push({ub(idx[a[i]], i), a[i]}), in[a[i]] = 1;
        }
        else{
            if(!water.empty()){
                auto [cd, cur] = water.top(); water.pop();
                result.push_back((cd >= INF) ? 0 : cur); in[cur] = 0;
            }
            else result.push_back(0);
        }
    }

    if(flag) cout << "NO\n";
    else{
        cout << "YES\n";
        for(auto& i : result) cout << i << " "; 
        cout << "\n";
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}