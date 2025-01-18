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
ll cy[MAX][MAX], cx[MAX][MAX], d[MAX][MAX];
ll dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
class node{
public:
    ll y, x, num;
    bool operator >(const node& ot) const{
        return num > ot.num;
    }
};
priority_queue <node, vector<node>, greater<node>> pq;

bool outrange(ll y, ll x){
    return y <= 0 || y > n || x <= 0 || x > m;
}


void run(){
    cin >> n >> m >> k;
    for(int i = 0;i <= n + 1;i++){
        for(int j = 0;j <= m + 1;j++) d[i][j] = k;
    }

    for(int i = 0;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> cy[i][j];
    }

    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= m;j++) cin >> cx[i][j];
    }

    for(int i = 1;i <= n;i++) pq.push({i, 0, 0}), pq.push({i, m + 1, 0});
    for(int i = 1;i <= m;i++) pq.push({0, i, 0}), pq.push({n + 1, i, 0});
    
    while(!pq.empty()){
        auto[y, x, num] = pq.top(); pq.pop();
        if(d[y][x] <= num) continue; d[y][x] = num;

        for(int i = 0;i < 4;i++){
            ll ny = y + dy[i], nx = x + dx[i], v;
            if(outrange(ny, nx)) continue;
            if(i == 0) v = cx[y][x];
            else if(i == 1) v = cx[y][x - 1];
            else if(i == 2) v = cy[y][x];
            else v = cy[y - 1][x];

            if(v == -1) continue;
            pq.push({ny, nx, max(num, v)});
        }
    }

    ll result = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) result += d[i][j];
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}