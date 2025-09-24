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
constexpr ll MAX = 202; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll cy, cx, rx, ry;
vector <ll> vy, vx;
ll oy[2 * MAX], ox[2 * MAX];
map <ll, ll> my, mx;
ll a[2 * MAX][2 * MAX];

class node{
public:
    ll x1, x2, y1, y2;
}; deque <node> num;

void init(){
    my.clear(); mx.clear();
    vy.clear(); vx.clear();
    rx = ry = -1; num.clear();
    memset(a, 0, sizeof(a));
}

void run(){
    cin >> n >> m >> k; init();
    for(int i = 1;i <= n;i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2; 
        vx.push_back(x1); vx.push_back(x2);
        vy.push_back(y1); vy.push_back(y2);
        num.push_back({x1, x2, y1, y2});
    }
    
    cin >> cx >> cy;
    vy.push_back(0); vx.push_back(0);
    vy.push_back(k); vx.push_back(m);

    sort(all(vx)); sort(all(vy)); 
    vx.erase(unique(all(vx)), vx.end());
    vy.erase(unique(all(vy)), vy.end());

    for(int i = 0;i < vx.size();i++) ox[i + 1] = vx[i], mx[vx[i]] = i + 1;
    for(int i = 0;i < vy.size();i++) oy[i + 1] = vy[i], my[vy[i]] = i + 1;
    
    for(auto& [x1, x2, y1, y2] : num){
        x1 = mx[x1]; x2 = mx[x2]; 
        y1 = my[y1]; y2 = my[y2];
    }
    
    for(auto& [x1, x2, y1, y2] : num){
        for(int i = y1;i < y2;i++){
            for(int j = x1;j < x2;j++) a[i][j] = 1;
        }
    }

    for(int i = vy.size() - 1;i >= 1;i--){
        ll cnt = 0;
        for(int j = vx.size() - 1;j >= 1;j--){
            a[i][j] = (!a[i][j] ? a[i + 1][j] + oy[i + 1] - oy[i] : 0);
            cnt = (a[i][j] >= cy ? cnt + ox[j + 1] - ox[j] : 0);
            
            if(cnt < cx) continue;
            rx = ox[j]; ry = oy[i];
        }
    }

    if(rx == -1 && ry == -1) cout << "Fail!\n";
    else cout << rx << " " << ry << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}