#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 11;
ll n, m, a[MAX];

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];

    ll result = 0;
    for(int i = n;i >= 1;i--){
        ll div = m / a[i];
        result += div;
        m -= div * a[i];
    }

    cout << result;
    return 0;
}