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
vector <ll> arr;

ll nxt(ll cur){
    ll idx = lower_bound(all(arr), cur) - arr.begin();
    if(idx >= arr.size()) return INF;
    return arr[idx];
}

ll pre(ll cur){
    ll idx = upper_bound(all(arr), cur) - arr.begin();
    if(!idx) return INF;
    return arr[idx - 1];
}

void run(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) {
        ll num; cin >> num;
        arr.push_back(num);
    }
    sort(all(arr));

    ll result = 0;
    while(m--){
        ll x, y; cin >> x >> y;
        ll mn = min(abs(x - pre(x)), abs(nxt(x) - x));
        result += (mn + y <= k);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

