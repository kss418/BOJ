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
constexpr ll MAX = 16; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll result = INF, a[MAX][6], now[6];
vector <ll> vec, tr;

bool chk(){
    for(int i = 1;i <= 4;i++) if(a[0][i] > now[i]) return 0;
    return 1;
}

void bt(ll sz){
    if(vec.size() == sz){
        if(!chk() || now[5] > result) return;
        if(result == now[5]) tr = min(tr, vec);
        else tr = vec; result = now[5]; 
        return;
    }

    for(int i = (vec.empty() ? 1 : vec.back() + 1);i <= n;i++){
        vec.push_back(i); 
        for(int j = 1;j <= 5;j++) now[j] += a[i][j];
        bt(sz);
        for(int j = 1;j <= 5;j++) now[j] -= a[i][j];
        vec.pop_back();
    }
}

void run(){
    cin >> n; for(int i = 1;i <= 4;i++) cin >> a[0][i];
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= 5;j++) cin >> a[i][j];
    }
    for(int i = 1;i <= n;i++) bt(i);
    cout << (result >= INF ? -1 : result) << "\n";
    for(auto& i : tr) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

