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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;

class node{
public:
    ll h[3];
};
pair <vector <ll>, node> a[MAX];
ll fac[MAX], result, mul[MAX];
map <ll, ll> cnt[MAX];
vector <ll> arr;

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            ll x; cin >> x;
            a[i].x.push_back(x);
            cnt[j][a[i].x[j]]++;
        }
    }

    fac[0] = 1;
    for(int i = 1;i < MAX;i++) fac[i] = (fac[i - 1] * i) % MOD;

    for(int j = 0;j < n;j++){
        ll now = 1;
        for(auto& [num, v] : cnt[j]){
            now *= fac[v];
            now %= MOD;
        }

        mul[j] = now;
    }

    bool flag = 1;
    while(m--){
        ll op, idx; cin >> op >> idx; idx--;
        if(op == 1){
            result = mul[idx];
            flag = 0;
            
            for(int i = 0;i < n;i++){
                a[i].y.h[0] = a[i].x[idx] % MOD;
            }
        }
        else{
            if(flag){
                result = 1;
                continue;
            }

            arr.clear();
            ll now = 1; result = 1;
            for(int i = 0;i < n;i++){
                a[i].y.h[0] = (a[i].y.h[0] * 2003 + a[i].x[idx]) % MOD;
                arr.push_back(a[i].y.h[0]);
            }
            sort(all(arr));
            
            for(int i = 1;i < arr.size();i++){
                if(arr[i] == arr[i - 1]) now++;
                else{
                    result *= fac[now];
                    result %= MOD;
                    now = 1;
                }
            }
    
            result *= fac[now];
            result %= MOD;
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}