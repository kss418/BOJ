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
constexpr ll MAX = 21; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], result = INF;
vector <ll> vec, dis;
bool cnt[MAX];

void cal(){
    ll fi = 0, se = 0; memset(cnt, 0, sizeof(cnt)); dis.clear();
    for(auto& i : vec) cnt[i] = 1;
    for(int i = 1;i <= n;i++) if(!cnt[i]) dis.push_back(i);

    for(int i = 0;i < n / 2;i++){
        for(int j = 0;j < n / 2;j++){
            if(i == j) continue;
            fi += a[vec[i]][vec[j]]; se += a[dis[i]][dis[j]];
        }
    }

    result = min(result, abs(fi - se));
}

void bt(){
    if(vec.size() == n / 2){ cal(); return; }
    for(int i = (vec.empty() ? 1: vec.back() + 1);i <= n;i++){
        vec.push_back(i);
        bt();
        vec.pop_back();
    }
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }

    bt(); cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

