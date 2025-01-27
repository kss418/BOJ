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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 1000;
ll sp[MAX], rp[MAX], sum, result = 1;

void run(){
    ll a, b, c; cin >> a >> b >> c >> n;
    sp[a] = rp[c] = 1; sp[b] = -1;
    for(int i = 0;i <= n;i++){
        sum += sp[i]; result += (sum - rp[i] + MOD) % MOD;
        sum %= MOD; result %= MOD;
        sp[i + a] += sum; sp[i + b] -= sum;
        rp[i + c] += sum;  
    }

    cout << (result + MOD) % MOD;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

