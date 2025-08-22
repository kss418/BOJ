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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;

class node{
public:
    ll v, pre;
}; node a[MAX];
ll cnt, now;

void run(){
    cin >> n; a[0] = {-1, 0};
    for(int i = 1;i <= n;i++){
        char c; cin >> c;
        if(c == 'a'){
            ll v; cin >> v;
            cnt++;
            a[cnt] = {v, now};
            now = cnt;
        }
        else if(c == 's'){
            ll pre = a[now].pre;
            cnt++;
            a[cnt] = {a[pre].v, a[pre].pre};
            now = cnt;
        }
        else{
            ll v; cin >> v;
            now = v - 1;
            cnt++;
            a[cnt] = {a[now].v, a[now].pre};
        }

        cout << a[cnt].v << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}