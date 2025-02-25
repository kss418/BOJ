#include <bits/stdc++.h>
#include <ext/rope>
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
class node{
public:
    ll h, a, t;
}; node a[MAX];


void run(){
    cin >> n; ll mx = INF, mn = 0;
    for(int i = 1;i <= n;i++) cin >> a[i].h;
    for(int i = 1;i <= n;i++) cin >> a[i].a;
    for(int i = 1;i <= n;i++) cin >> a[i].t;
    sort(a + 1, a + n + 1, [](node& a, node& b){
        return a.t > b.t;
    });

    for(int i = 2;i <= n;i++){
        if(a[i].a > a[i - 1].a){
            ll da = a[i].a - a[i - 1].a;
            ll dh = max(a[i - 1].h - a[i].h + 1, 0ll); 
            ll now = dh / da + (dh % da ? 1 : 0);
            mn = max(mn, now);
        }   
        else if(a[i].a < a[i - 1].a){
            ll da = a[i - 1].a - a[i].a;
            ll dh = max(a[i].h - a[i - 1].h - 1, 0ll);
            if(a[i - 1].h > a[i].h) continue;

            ll now = dh / da;
            mx = min(mx, now);
        }
        else{
            if(a[i].h > a[i - 1].h) continue;
            mn = INF; mx = 0;
        }
    }
    
    cout << (mx >= mn ? mn : -1) << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

