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
constexpr ll MAX = 8; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dxf[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
ll dyf[8] = {0, -1, -1, -1, 0, 1, 1, 1};
ll dxs[4] = {0, -1, 0, 1}, dys[4] = {-1, 0, 1, 0};

class fish{
public:
    ll y, x, d, live;
}; vector <fish> arr, tmp;
fish shark;
ll a[MAX][MAX], c[MAX][MAX];

bool outrange(ll cy, ll cx){
    return (cy <= 0 || cx <= 0 || cy > 4 || cx > 4);
}

bool orf(ll cy, ll cx){
    if(outrange(cy, cx)) return 1;
    if(cy == shark.y && cx == shark.x) return 1;
    if(a[cy][cx]) return 1;
    return 0;
}

void copy(){ 
    for(auto& i : arr) tmp.push_back(i); 
}

void move_fish(){
    for(auto& i : arr){
        auto& [cy, cx, cd, cl] = i; c[cy][cx]--;
        ll nd = cd;
        while(1){
            ll ny = cy + dyf[nd], nx = cx + dxf[nd];
            if(orf(ny, nx)) nd--, nd = (nd + 8) % 8; 
            else { cy = ny, cx = nx, cd = nd; break; }
            if(nd == cd) break;
        }
        c[cy][cx]++;
    }
}

vector <ll> mv, mxv; ll mx = -1;
bool use[5][5];
ll cnt(vector <ll>& v){
    ll cy = shark.y, cx = shark.x, ret = 0;
    for(auto& i : mv){
        ll ny = cy + dys[i], nx = cx + dxs[i];
        if(outrange(ny, nx)) return -1;
        if(!use[ny][nx]) ret += c[ny][nx];
        use[ny][nx] = 1;
        cy = ny; cx = nx;
    }
    return ret;
}

void bt(){
    if(mv.size() == 3){
        memset(use, 0, sizeof(use));
        ll now = cnt(mv);
        if(now <= mx) return;
        mx = now; mxv = mv; return;
    }

    for(int i = 0;i < 4;i++){
        mv.push_back(i);
        bt();
        mv.pop_back();
    }
}

void move_shark(){
    bt();
    ll cy = shark.y, cx = shark.x;
    for(auto& i : mxv){
        ll ny = cy + dys[i], nx = cx + dxs[i];
        if(c[ny][nx]) a[ny][nx] = 3;
        c[ny][nx] = 0;
        cy = ny; cx = nx;
    }

    shark.y = cy; shark.x = cx;
}

void erase_smell(){
    for(int i = 1;i <= 4;i++){
        for(int j = 1;j <= 4;j++) {
            a[i][j] = max(a[i][j] - 1, 0ll);
        }
    }
}

void paste(){
    for(auto& i : arr) {
        if(!c[i.y][i.x]) continue;
        tmp.push_back(i);
    }
    arr.clear();
    memset(c, 0, sizeof(c));

    for(auto& i : tmp) {
        arr.push_back(i);
        c[i.y][i.x]++;
    }
    tmp.clear();
}

void simulation(){
    copy();
    move_fish();
    mx = -1; move_shark();
    erase_smell();
    paste();
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        ll cy, cx, cd; cin >> cy >> cx >> cd;
        arr.push_back({cy, cx, cd - 1, 1});
        c[cy][cx]++;
    }
    cin >> shark.y >> shark.x;

    while(m--) simulation();
    cout << arr.size();
    
     
    return 0;
}