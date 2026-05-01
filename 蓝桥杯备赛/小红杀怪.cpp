#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int ans = 1e9;

    // i：对第一只怪使用单攻次数
    // j：对第二只怪使用单攻次数
    // k：使用群攻次数
    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 20; j++) {
            for (int k = 0; k <= 20; k++) {
                // 判断是否能杀死两只怪
                if (i * x + k * y >= a && j * x + k * y >= b) {
                    ans = min(ans, i + j + k);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}