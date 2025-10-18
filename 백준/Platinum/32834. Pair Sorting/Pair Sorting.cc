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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX];
class node{
public:
    ll idx, l, r;
}; vector <node> result;


void sw(ll idx, bool pre, bool nxt){
    result.push_back({idx, pre ? a[idx] : b[idx], nxt ? a[idx + 1] : b[idx + 1]});
    swap(pre ? a[idx] : b[idx], nxt ? a[idx + 1] : b[idx + 1]);
}

ll pos(ll cur){
    for(int i = 1;i <= n;i++) if(i != cur && (a[i] == cur || b[i] == cur)) return i;
    return -1;
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) a[i] = b[i] = n - i + 1;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 2;j++){
            ll p = pos(i);
            if(p == -1) break;
            while(p > i){
                sw(p - 1, a[p - 1] >= b[p - 1], a[p] == i);
                p--;
            }

            while(p < i){
                sw(p, a[p] == i, a[p + 1] <= b[p + 1]);
                p++;
            }
        }
    }
    
    cout << result.size() << "\n";
    for(auto& [idx, l, r] : result) cout << idx << " " << l << " " << r << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}