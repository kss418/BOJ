#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 3010;
const ll INF = 1e12;
ll n, m, k;

ll dnc(ll cur, ll cy, ll cx){
    if(cur == 1) return 2 * cy + cx;
    ll len = (1ll << (cur - 1));
    ll dy = cy / len, dx = cx / len;
    return dnc(cur - 1, cy % len, cx % len) + (2 * dy + dx) * len * len;
}

int main(){
    cin >> n >> m >> k;
    cout << dnc(n, m, k);
    return 0;
}