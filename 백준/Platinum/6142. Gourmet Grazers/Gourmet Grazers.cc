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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll c[MAX], g[MAX];
ll idx = 1, result, flag;
multiset <ll> num;

bool cmp(pll &a, pll& b){
    if(a.y != b.y) return a.y > b.y;
    return a.x < b.x;
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> c[i].x >> c[i].y;
    for(int i = 1;i <= m;i++) cin >> g[i].x >> g[i].y;
    sort(c + 1, c + n + 1, cmp); sort(g + 1, g + m + 1, cmp);

    for(int i = 1;i <= n;i++){
        while(idx <= m && g[idx].y >= c[i].y){
            num.insert(g[idx].x); idx++;
        }

        auto it = num.lower_bound(c[i].x);
        if(it == num.end()) flag = 1;
        else{
            result += *it;
            num.erase(it);
        }
    }

    cout << (flag ? -1 : result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}