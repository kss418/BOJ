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
ll a[MAX], cnt;
bool c[MAX];
ll arr[MAX];
vector <ll> able;

void init(){
    for(int i = 1;i <= n;i++) c[i] = arr[i] = 0; 
    able.clear(); cnt = 0;
}

bool chk(){
    ll l = 1, r = n;
    for(int i = 1;i < n;i++){
        if(arr[l] > arr[r]){
            if(arr[++l] != a[i]) return 0;
        }
        else{
            if(arr[--r] != a[i]) return 0;
        }
    }

    return 1;
}

void run(){
    cin >> n; init();
    for(int i = 1;i < n;i++) {
        cin >> a[i]; 
        if(!c[a[i]]) cnt++;
        c[a[i]] = 1;
    }
    if(cnt < n - 2){ cout << -1 << "\n"; return; }

    for(int i = 1;i <= n;i++){
        if(!c[i]) able.push_back(i);
    }

    ll l = 1, r = n; 
    reverse(all(able)); arr[r] = able[0];
    if(able.size() == 2) arr[l] = able[1];
    for(int i = 1;i < n;i++){
        if(arr[l] > arr[r]) l++, arr[l] = a[i];
        else r--, arr[r] = a[i];
    }

    if(chk()) for(int i = 1;i <= n;i++) cout << arr[i] << " ";
    else cout << -1; cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}