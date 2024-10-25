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
rope <char> rp;

int main() {
    fastio;

    cin >> s >> m;
    for(auto& i : s) rp.push_back(i);

    while(m--){
        ll x, y; cin >> n >> x;
        if(n == 1){
            cin >> y;
            rp = rp.substr(x, y - x + 1) + rp.substr(0, x) + rp.substr(y + 1, s.size() - y + 1); 
        }
        else if(n == 2){
            cin >> y;
            rp = rp.substr(0, x) + rp.substr(y + 1, s.size() - y + 1) + rp.substr(x, y - x + 1);
        }
        else cout << rp[x] << "\n";
    }
    
    
    return 0;
}