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
ll a[MAX];
vector <pll> st;
deque <ll> num;
pll b[MAX];

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    cin >> m;
    for(int i = 1;i <= m;i++){
        cin >> b[i].x >> b[i].y;
        while(!st.empty() && st.back().x <= b[i].x) st.pop_back();
        st.push_back({b[i].x, 0});

        while(!st.empty() && st.back().x <= b[i].y) st.pop_back();
        st.push_back({b[i].y, 1});
    }

    for(int i = 1;i <= st[0].x;i++) num.push_back(a[i]);
    sort(all(num));
    st.push_back({0, 0});

    for(int i = 0;i < st.size() - 1;i++){
        auto [v, op] = st[i];
        if(op == 0){
            for(int j = v;j > st[i + 1].x;j--){
                a[j] = num.back();
                num.pop_back();
            }
        }
        else{
            for(int j = v;j > st[i + 1].x;j--){
                a[j] = num.front();
                num.pop_front();
            }
        }
    }

    for(int i = 1;i <= n;i++) cout << a[i] << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

