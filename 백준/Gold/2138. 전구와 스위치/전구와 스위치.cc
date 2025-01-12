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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string a, b, ca; ll cnt;

void flip(ll idx){
    if(idx) ca[idx - 1] ^= 1;
    if(idx != n - 1) ca[idx + 1] ^= 1;
    ca[idx] ^= 1; cnt++;
}

void run(){
    cin >> n >> a >> b; ca = a; flip(0);
    for(int i = 1;i < n;i++){
        if(ca[i - 1] == b[i - 1]) continue;
        flip(i);
    }
    
    ll result = (ca == b ? cnt : INF);
    cnt = 0; ca = a;
    for(int i = 1;i < n;i++){
        if(ca[i - 1] == b[i - 1]) continue;
        flip(i);
    }

    result = min(result, (ca == b ? cnt : INF));
    cout << (result == INF ? -1 : result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}