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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll ptr[MAX];


int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) cin >> ptr[i];
    
    while(k--){
        string com; ll x, y;
        cin >> com >> x;
        if(com == "assign"){
            cin >> y;
            ptr[x] = ptr[y];
        }
        else if(com == "swap"){
            cin >> y;
            swap(ptr[x], ptr[y]);
        }
        else ptr[x] = 0;
    }

    set <ll> result;
    for(int i = 1;i <= m;i++) if(ptr[i]) result.insert(ptr[i]);

    cout << result.size() << '\n';
    for(auto& i : result) cout << i << '\n';
    
  
    return 0;
}