#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> num;

ll chk(vector <ll>& v){
    ll now = 1;
    vector <ll> arr, com;
    for(int i = 0;i < v.size();i++){
        if(v[i] != 32) arr.push_back(now), now = i + 2, com.push_back(v[i]);
        else now = 10 * now + i + 2;
    }
    arr.push_back(now);

    ll ret = arr[0];
    for(int i = 0;i < com.size();i++){
        if(com[i] == 43) ret += arr[i + 1];
        else ret -= arr[i + 1];
    }
    
    return ret;
}

void bt(){
    if(num.size() == n - 1){
        if(chk(num)) return;
        cout << 1;
        for(int i = 0;i < n - 1;i++){
            cout << (char)num[i] << i + 2;
        } 
        cout << "\n";
        return;
    }

    for(auto& i : {32, 43, 45}){
        num.push_back(i);
        bt();
        num.pop_back();
    }
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; bt(); cout << "\n";
    }

       
    return 0;
}