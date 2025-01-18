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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
vector <ll> arr;

void run(){
    for(int i = 0;i < 9;i++) cin >> a[i];
    for(int i = 0;i < (1ll << 9);i++){
        ll cnt = 0, sum = 0;
        for(int j = 0;j < 9;j++){
            if(i & (1ll << j)) cnt++, sum += a[j];
        }

        if(cnt != 7 || sum != 100) continue;
        for(int j = 0;j < 9;j++){
            if(i & (1ll << j)) arr.push_back(a[j]);
        }
        
        sort(all(arr));
        for(auto& i : arr) cout << i << "\n"; return;
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

