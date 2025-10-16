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
ll ti, sy, sx, ey, ex;

bool dnc(ll cy, ll cx, ll sz){
    if(!sz) return 0;
    bool pre = dnc(cy / n, cx / n, sz - 1);
    if(pre) return 1;
    
    ll my = cy % n, mx = cx % n;
    return my >= (n - k) / 2 && my < (n + k) / 2 && mx >= (n - k) / 2 && mx < (n + k) / 2;
}

void run(){
    cin >> ti >> n >> k >> sy >> ey >> sx >> ex;
    for(int i = sy;i <= ey;i++){
        for(int j = sx;j <= ex;j++) cout << dnc(i, j, ti);
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}