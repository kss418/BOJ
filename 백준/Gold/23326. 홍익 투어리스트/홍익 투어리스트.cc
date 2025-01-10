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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
set <ll> num;

void run(){
    cin >> n >> m; ll cur = 0;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        if(a[i]) num.insert(i);
    }

    while(m--){
        ll op, v; cin >> op;
        if(op == 1){
            cin >> v; v--; a[v] ^= 1;
            if(a[v]) num.insert(v);
            else num.erase(num.find(v));
        }
        else if(op == 2) cin >> v, cur = (cur + v) % n;
        else{
            ll nxt = INF;
            if(num.lower_bound(cur) != num.end()) nxt = *num.lower_bound(cur);
            else if(num.lower_bound(0) != num.end()) nxt = *num.lower_bound(0) + n;
            
            cout << (nxt - cur >= 1e9 ? -1 : nxt - cur) << "\n";
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

