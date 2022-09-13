#include <iostream>
using namespace std;
int n;
int a[46], b[46];

int main(){
    cin >> n;
    a[1] = 0;
    b[1] = 1;

    for (int i = 2; i <= 45; i++) {
        b[i] = a[i - 1] + b[i - 1];
        a[i] = b[i - 1];
    }

    cout << a[n] << " " << b[n];

    return 0;
}
