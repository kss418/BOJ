#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
bool arr[MAX];

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    cin >> m;
    while(m--){
        ll s, x;
        cin >> s >> x;
        if(s == 1){
            for(int i = x;i <= n;i += x) arr[i] ^= 1;
        }
        else{
            ll mx = 0;
            for(int i = 0;i <= n;i++){
                if(x - i <= 0 || x + i > n) break;
                if(arr[x - i] != arr[x + i]) break;
                if(!i) arr[x] ^= 1;
                else arr[x - i] ^= 1, arr[x + i] ^= 1;
            }
        }
    }

    ll cur = 1;
    while(cur <= n){
        cout << arr[cur];
        if(cur % 20 == 0) cout << "\n";
        else cout << " ";
        cur++;
    }


    return 0;
}