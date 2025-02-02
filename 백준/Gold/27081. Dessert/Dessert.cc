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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 21; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt;
vector <ll> vec, num;

ll cal(){
    ll ret = 0, now = 1; num.clear();
    for(int i = 0;i < n - 1;i++){
        if(vec[i] != 2) { 
            num.push_back(now); now = i + 2;
        }
        else{
            if(i + 2 >= 10) now *= 100;
            else now *= 10; now += i + 2;
        }
    }
    num.push_back(now);

    ret = num[0]; ll idx = 1;
    for(int i = 0;i < n - 1;i++){
        if(vec[i] == 2) continue;
        else if(!vec[i]) ret += num[idx++];
        else ret -= num[idx++];
    }

    return ret;
}

void print(){
    for(int i = 0;i < n - 1;i++){
        cout << i + 1 << " ";
        if(vec[i] == 0) cout << "+ ";
        else if(vec[i] == 1) cout << "- ";
        else cout << ". ";
    }
    cout << n << "\n";    
}

void bt(){
    if(vec.size() == n - 1){
        if(cal()) return;
        if(++cnt <= 20) print(); return;
    }

    for(int i = 0;i < 3;i++){
        vec.push_back(i);
        bt();
        vec.pop_back();
    }
}

void run(){
    cin >> n; bt();
    cout << cnt;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

