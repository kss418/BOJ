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
constexpr ll MAX = 21; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt[4], mx = -INF, mn = INF;
vector <ll> vec;

ll cal(){
    ll ret = a[0];
    for(int i = 0;i < n - 1;i++){
        if(!vec[i]) ret += a[i + 1];
        else if(vec[i] == 1) ret -= a[i + 1];
        else if(vec[i] == 2) ret *= a[i + 1];
        else ret /= a[i + 1];
    }

    return ret;
}

void bt(){
    if(vec.size() == n - 1){
        ll now = cal();
        mx = max(mx, now); mn = min(mn, now);
        return;
    }

    for(int i = 0;i < 4;i++){
        if(!cnt[i]) continue;
        cnt[i]--; vec.push_back(i);
        bt();
        cnt[i]++; vec.pop_back();
    }
}

void run(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < 4;i++) cin >> cnt[i];
    bt(); cout << mx << "\n" << mn;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

