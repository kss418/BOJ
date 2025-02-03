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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
vector <pll> arr;
vector <ll> num, dp;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> m >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1, [](pll& a, pll & b){
        if(a.x != b.x) return a.x < b.x;
        return a.y > b.y;
    });

    arr.push_back(a[1]);
    for(int i = 2;i <= n;i++){
        if(a[i].x == a[i - 1].x && a[i].y == a[i - 1].y) continue;
        arr.push_back(a[i]);
    }
    for(auto& i : arr) num.push_back(-i.y);

    for(auto& i : num){
        auto it = upper_bound(all(dp), i);
        if(it == dp.end()) dp.push_back(i);
        else *it = i;
    }

    cout << dp.size();
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}