#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
class node{
public:
    ll x, y, idx;
}; vector <node> arr[2];
vector <ll> adj[MAX];
ll result[MAX], cnt;

void run(){
    cin >> n; memset(result, 0x3f, sizeof(result));
    for(int i = 1;i <= n;i++){
        char c; ll x, y; cin >> c >> x >> y;
        arr[c == 'N'].push_back({x, y, i});
    }

    sort(all(arr[0]), [](node& l, node& r){
        return l.y < r.y;
    });

    sort(all(arr[1]), [](node& l, node& r){
        return l.x < r.x;
    });

    for(auto& [cx, cy, ci] : arr[0]){
        for(auto& [nx, ny, ni] : arr[1]){
            ll mx = nx, my = cy;
            if(cx > mx || ny > my) continue;

            ll cd = abs(mx - cx) + abs(my - cy);
            if(abs(mx - cx) >= result[ci]) cd = INF;
            ll nd = abs(mx - nx) + abs(my - ny);
            if(abs(my - ny) >= result[ni]) nd = INF;

            if(cd == nd) continue;
            if(cd < nd) result[ni] = min(result[ni], nd);
            else result[ci] = min(result[ci], cd);
        }
    }

    for(int i = 1;i <= n;i++){
        if(result[i] == INF) cout << "Infinity\n";
        else cout << result[i] << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}