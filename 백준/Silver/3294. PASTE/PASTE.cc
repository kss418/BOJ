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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;


int main() {
    fastio;

    cin >> n >> m; rope <ll> rp;
    for(int i = 1;i <= n;i++) rp.push_back(i);

    while(m--){
        ll l, r, idx; cin >> l >> r >> idx; 
        l--; r--;

        rope <ll> mid = rp.substr(l, r - l + 1);
        rp.erase(l, r - l + 1);
        rp.insert(idx, mid);
    }

    for(int i = 0;i < 10;i++) cout << rp[i] << "\n";

    
    return 0;
}