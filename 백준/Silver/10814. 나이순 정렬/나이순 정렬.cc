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

class node{
public:
    ll v, idx;
    string st;
    bool operator < (const node& ot) const{
        if(v != ot.v) return v < ot.v;
        return idx < ot.idx;
    }
} a[MAX];

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].v >> a[i].st, a[i].idx = i;

    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;i++) cout << a[i].v << " " << a[i].st << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

