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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
constexpr int sq = sqrt(MAX);
int mn[MAX], mx[MAX];
vector <int> arr;

void run(){
    cin >> n >> m; memset(mx, -1, sizeof(mx));
    memset(mn, 0x3f, sizeof(mn));
    for(int i = 1;i <= n;i++) cin >> k, arr.push_back(k);
    sort(all(arr));
   
    while(m--){
        int k; cin >> k;
        if(mx[k] != -1){
            cout << mn[k] << " " << mx[k] << "\n";
            continue;
        }

        if(k < sq){
            for(int i = 0;i < n;i++){
                mx[k] = max(mx[k], arr[i] % k);
                mn[k] = min(mn[k], arr[i] % k);
            }
        }
        else{
            for(int i = 0;i <= arr.back();i += k){
                int lo = lower_bound(all(arr), i) - arr.begin();
                int hi = upper_bound(all(arr), i + k - 1) - arr.begin() - 1;
                mn[k] = min(mn[k], arr[lo] % k);
                mx[k] = max(mx[k], arr[hi] % k);
            }
        }

        cout << mn[k] << " " << mx[k] << "\n";
    }
}

int main() {
    fastio; //cin >> t;
    while(t--) run(); 

    return 0;
}

