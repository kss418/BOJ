#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
map <ll, set<ll>> sx, sy;

ll pre(set <ll>& num, ll idx){
    auto lb = num.lower_bound(idx);
    if(lb == num.begin()) return MINF;
    return *--lb;
}

ll nxt(set <ll>& num, ll idx){
    auto lb = num.upper_bound(idx);
    if(lb == num.end()) return INF;
    return *lb;
}

void run(){
    cin >> n >> m >> s;
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        ll x = a[i].x + a[i].y;
        ll y = a[i].x - a[i].y;
        a[i] = {x, y};
        sx[y].insert(x);
        sy[x].insert(y);
    }

    pll now = {a[1].x, a[1].y};
    for(auto& i : s){
        auto&[cx, cy] = now;
        ll ox = cx, oy = cy;
        if(i == 'A'){
            ll nx = nxt(sx[cy], cx);
            if(nx == INF) continue;
            cx = nx;
        }
        else if(i == 'B'){
            ll ny = nxt(sy[cx], cy);
            if(ny == INF) continue;
            cy = ny;
        }
        else if(i == 'C'){
            ll ny = pre(sy[cx], cy);
            if(ny == MINF) continue;
            cy = ny;
        }
        else{
            ll nx = pre(sx[cy], cx);
            if(nx == MINF) continue;
            cx = nx;
        }

        sx[oy].erase(sx[oy].find(ox));
        sy[ox].erase(sy[ox].find(oy));
    }

    cout << (now.x + now.y) / 2 << " " << (now.x - now.y) / 2 << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}