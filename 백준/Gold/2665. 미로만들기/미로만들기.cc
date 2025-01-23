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
constexpr ll MAX = 51; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll d[MAX][MAX];
ll dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};

class node{
public:
    ll y, x, d;
    bool operator < (const node& ot) const{
        return d > ot.d;
    }
};
priority_queue <node> pq;

bool outrange(ll cy, ll cx){
    return cy < 0 || cx < 0 || cy >= n || cx >= n;
}

void run(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >> st[i];
    pq.push({0, 0, 0}); memset(d, 0x3f, sizeof(d));

    while(!pq.empty()){
        auto[cy, cx, cd] = pq.top(); pq.pop();
        if(d[cy][cx] <= cd) continue;
        d[cy][cx] = cd;

        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            pq.push({ny, nx, cd + (st[cy][cx] == '1' ? 0 : 1)});
        }
    }

    cout << d[n - 1][n - 1];
}   

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

