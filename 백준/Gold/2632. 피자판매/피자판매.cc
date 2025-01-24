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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], sa[MAX], sb[MAX];
vector <ll> aa, ba;

ll ub(ll cur, vector <ll>& v){
    return upper_bound(all(v), cur) - v.begin();
}

ll lb(ll cur, vector <ll>& v){
    return lower_bound(all(v), cur) - v.begin();
}

void run(){
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) cin >> a[i];
    for(int i = m + 1;i <= 2 * m;i++) a[i] = a[i - m];
    for(int i = 1;i <= 2 * m;i++) sa[i] = sa[i - 1] + a[i];

    for(int i = 1;i <= k;i++) cin >> b[i], sb[i] = sb[i - 1] + b[i];
    for(int i = k + 1;i <= 2 * k;i++) b[i] = b[i - k];
    for(int i = 1;i <= 2 * k;i++) sb[i] = sb[i - 1] + b[i];

    aa.push_back(0); ba.push_back(0);
    aa.push_back(sa[m]); ba.push_back(sb[k]);
    for(int i = 1;i < 2 * m;i++){
        for(int j = max(i - m + 1, 0ll);j < min<ll>(i, m);j++) aa.push_back(sa[i] - sa[j]);
    }

    for(int i = 1;i < 2 * k;i++){
        for(int j = max(i - k + 1, 0ll);j < min<ll>(i, k);j++) ba.push_back(sb[i] - sb[j]);
    }
    sort(all(aa)); sort(all(ba)); ll result = 0;

    for(auto& i : aa){
        ll now = n - i;
        result += ub(now, ba) - lb(now, ba);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

