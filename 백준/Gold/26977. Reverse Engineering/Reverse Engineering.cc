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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
bool v[MAX], ret[MAX], use[MAX], cnt[2];

void init(){
    memset(v, 0, sizeof(v));
    memset(use, 0, sizeof(use));
}

void run(){
    cin >> n >> m; init();
    for(int i = 0;i < m;i++) cin >> st[i] >> ret[i];

    for(int i = 0;i < n;i++){
        ll idx = -1, num = -1, mx = -1;
        for(int j = 0;j < 2 * n;j++){
            ll div = j / n, cur = j % n, c = 0;
            if(use[cur]) continue;
            cnt[0] = cnt[1] = 0;
            for(int k = 0;k < m;k++){
                if(v[k]) continue;
                if(st[k][cur] - '0' != div) continue;
                cnt[ret[k]] = 1; c++;
            }

            if(c < mx || (cnt[0] && cnt[1])) continue;
            mx = c; idx = cur; num = div;
        }  
        
        use[idx] = 1;
        for(int j = 0;j < m;j++){
            if(st[j][idx] - '0' == num) v[j] = 1;
        }
    }
    
    use[0] = use[1] = 0;
    for(int i = 0;i < m;i++){
        if(v[i]) continue;
        use[ret[i]] = 1;
    }

    cout << (use[0] && use[1] ? "LIE" : "OK") << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}