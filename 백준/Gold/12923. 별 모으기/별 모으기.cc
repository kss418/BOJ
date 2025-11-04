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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ll result, cnt;
bool flag = 1;

void simulate(){
    ll now = -1;
    for(int i = 1;i <= n;i++){
        if(a[i].y > cnt) continue;
        now = i; break;
    }

    if(now != -1){
        a[now].x = a[now].y = INF;
        result++; cnt += 2; return;
    }

    now = -1;
    for(int i = 1;i <= n;i++){
        if(a[i].x > cnt) continue;
        if(now != -1 && a[now].y > a[i].y) continue;
        now = i;
    }
    
    if(now == -1) return;
    a[now].x = a[now].y; a[now].y = INF;
    result++; cnt++;
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;

    for(int i = 1;i <= 2 * n;i++) simulate();
    if(cnt != 2 * n) cout << "Too Bad";
    else cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
