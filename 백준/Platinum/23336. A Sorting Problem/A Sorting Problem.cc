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
ll a[MAX], idx[MAX];
vector <ll> arr;

ll dnc(ll s, ll e){
    if(s == e) return 0;
    ll mid = (s + e) >> 1ll;
    ll ret = dnc(s, mid) + dnc(mid + 1, e);

    vector <ll> tmp;
    ll l = s, r = mid + 1;
    while(l <= mid && r <= e){
        if(arr[l] <= arr[r]){
            tmp.push_back(arr[l++]);
        }
        else{
            ret += mid - l + 1;
            tmp.push_back(arr[r++]);
        }
    }

    while(l <= mid) tmp.push_back(arr[l++]);
    while(r <= e) tmp.push_back(arr[r++]);
    
    for(int i = s;i <= e;i++) arr[i] = tmp[i - s];
    return ret;
}

void run(){
    cin >> n; 
    for(int i = 1;i <= n;i++) cin >> a[i], idx[a[i]] = i;
    for(int i = 1;i <= n;i++) arr.push_back(idx[i]);

    cout << dnc(0, n - 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}