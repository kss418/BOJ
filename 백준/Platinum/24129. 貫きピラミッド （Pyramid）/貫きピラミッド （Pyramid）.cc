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
constexpr ll MAX = 3010; // SET MAX SIZE
constexpr ll MOD = 998244353;
class node{
public:
    ll y, x, h;
    bool operator < (const node& ot) const{
        return h < ot.h;
    }
};
vector <node> arr;
ll result[MAX][MAX], ret;
ll dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
ll dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
deque <node> q;

bool outrange(ll cy, ll cx){
    return cy < 0 || cx < 0 || cx >= m || cy >= n;
}

void run(){
    cin >> n >> m >> k; memset(result, -1, sizeof(result));
    for(int i = 1;i <= k;i++) {
        ll y, x, h; cin >> y >> x >> h;
        arr.push_back({y, x, h});
    }
    sort(all(arr));

    q.push_back(arr.back()); arr.pop_back();
    while(!q.empty()){
        auto[cy, cx, ch] = q.front(); q.pop_front();
        if(result[cy][cx] >= ch) continue;
        result[cy][cx] = ch;

        while(!arr.empty() && arr.back().h == ch){
            q.push_back(arr.back());
            arr.pop_back();
        }
        
        for(int i = 0;i < 8;i++){
            ll ny = dy[i] + cy, nx = dx[i] + cx;
            if(outrange(ny, nx)) continue;
            q.push_back({ny, nx, max(ch - 1, 0ll)});
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) ret += result[i][j];
    }

    cout << ret;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}