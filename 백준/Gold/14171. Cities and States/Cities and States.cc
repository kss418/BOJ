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
string a[MAX], b[MAX];
class node{
public:
    string a, b;
    bool operator < (const node& ot) const{
        if(a != ot.a) return a < ot.a;
        return b < ot.b;
    }
}; map <node, ll> cnt;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> b[i];
        a[i] = a[i].substr(0, 2);
        if(a[i] == b[i]) continue;
        cnt[{a[i], b[i]}]++;
    }

    ll result = 0;
    for(int i = 1;i <= n;i++){
        if(!cnt.count({b[i], a[i]})) continue;
        result += cnt[{b[i], a[i]}];
    }

    cout << (result >> 1ll);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

