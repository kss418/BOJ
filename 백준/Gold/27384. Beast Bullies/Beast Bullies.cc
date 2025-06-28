#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
vector <ll> arr;
map <ll, ll> cnt;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i]; cnt[a[i]]++;
        if(cnt[a[i]] == 1) arr.push_back(a[i]);
    }
    sort(all(arr));

    ll la = arr.back() * cnt[arr.back()];
    ll sum = 0, now = 0, result = cnt[arr.back()];
    arr.pop_back(); reverse(all(arr));

    for(auto& i : arr){
        sum += i * cnt[i]; now += cnt[i];
        if(sum >= la){
            la += sum; result += now;
            now = 0; sum = 0;
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}