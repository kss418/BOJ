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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 52; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], r, g, cnt;
ll result, dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
ll v[MAX][MAX], cur, nxt[MAX][MAX];
vector <ll> vec;
pll num[11]; 

class node{
public:
    ll y, x, c;
};

void init(){
    memset(v, 0, sizeof(v)); cur = 0;
    memset(nxt, 0, sizeof(nxt));
}

bool outrange(ll cy, ll cx){
    if(cy <= 0 || cx <= 0 || cy > n || cx > m) return 1;
    if(!a[cy][cx]) return 1;
    return 0;
}

void simulation(){
    deque <node> cq, nq;
    for(int i = 0;i < vec.size();i++){
        if(!vec[i]) continue;
        cq.push_back({num[i].x, num[i].y, vec[i]});
    }

    while(!cq.empty() || !nq.empty()){
        if(cq.empty()){
            while(!nq.empty()) {
                auto[cy, cx, cc] = nq.front(); nq.pop_front();
                if(v[cy][cx]) continue;
                if(nxt[cy][cx] == 3){ 
                    v[cy][cx] = 1;
                    cur++; continue; 
                }
                cq.push_back({cy, cx, cc});
            }
            memset(nxt, 0, sizeof(nxt));
        }
        if(cq.empty()) break;
        auto[cy, cx, cc] = cq.front(); cq.pop_front();
        if(v[cy][cx]) continue; v[cy][cx] = cc;

        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            if(v[ny][nx]) continue;
            if(!nxt[ny][nx]) nq.push_back({ny, nx, cc});
            nxt[ny][nx] |= cc; 
        }
    }
}

ll use[3];
void bt(){
    if(vec.size() == cnt){
        init();
        simulation();
        result = max(result, cur);
        return;
    }

    for(int i = 0;i <= 2;i++){
        if(!use[i]) continue;
        use[i]--; vec.push_back(i);
        bt();
        vec.pop_back(); use[i]++;
    }
}

int main() {
    fastio;

    cin >> n >> m >> use[1] >> use[2]; 
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) num[cnt++] = {i, j};
        }
    }
    use[0] = cnt - use[1] - use[2];

    bt(); cout << result;
    
     
    return 0;
}