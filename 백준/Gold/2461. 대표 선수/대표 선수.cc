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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], mn = INF, result = INF;
class node{
public:
    ll cur, idx, num;
    bool operator < (const node& ot) const{
        return num < ot.num;
    }
};
priority_queue <node> pq;

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) cin >> a[i][j];
        sort(a[i] + 1, a[i] + m + 1);
        pq.push({i, m, a[i][m]});
        mn = min(mn, a[i][m]);
    }

    while(!pq.empty()){
        auto[cur, idx, num] = pq.top(); pq.pop();
        result = min(result, num - mn);
        if(idx == 1) break;
        mn = min(mn, a[cur][idx - 1]);
        pq.push({cur, idx - 1, a[cur][idx - 1]});
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

