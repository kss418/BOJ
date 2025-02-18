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
ll diff, sw;

char solve(ll cy, ll cx){
    if(!diff) return (cy == cx ? 'Y' : 'N');
    if(cy == cx) return 'N';
    if(cy - cx < 0) return 'N';
    if((cy - cx) % diff == 0) return 'Y';

    for(int i = diff;i < MAX;i <<= 1ll){
        for(int j = i;j < MAX;j <<= 1ll){
            if((cy - cx) % (i + j)) continue;
            return 'Y';
        }
    }

    return 'N';
}

void run(){
    cin >> n >> m; diff = n - m;
    if(diff < 0) diff *= -1, sw = 1;
    while(!(diff & 1) && diff) diff >>= 1ll;
    for(int i = 1;i <= 5;i++){
        ll cy, cx; cin >> cy >> cx;
        if(sw) swap(cy, cx);
        cout << solve(cy, cx) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

