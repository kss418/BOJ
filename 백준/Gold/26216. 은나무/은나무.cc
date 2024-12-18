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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll all;
 
ll d(ll a, ll b){
    ll cur = (all + 1) / (n + 1), ret = 0;
    ll flag = 1;
    while(cur){
        ll na = 2 * (a / cur) - 1, nb = 2 * (b / cur) - 1;
        if(a % cur) na++; if(b % cur) nb++;

        if(na != nb) flag = 0;
        if(!flag){
            if(a % ((n + 1) * cur)) ret++;
            if(b % ((n + 1) * cur)) ret++;
        }
        cur /= (n + 1);
    }
    
    return ret;
}

int main() {
    fastio;

    cin >> n >> m >> k; ll cur = n;
    for(int i = 1;i <= m;i++){
        all += cur; cur *= n + 1;
    }

    while(k--){
        ll a, b; cin >> a >> b;
        if(b > all) cout << -1 << "\n";
        else cout << d(a, b) << "\n";
    }

     
    return 0;
}