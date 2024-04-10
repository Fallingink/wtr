#include <iostream>
#include <vector>
using namespace std;

const int N = 101000;
int nums[] = { 0, 31, -41, 59, 26, -53, 58, 97, -93, -23, 84 }; // 数组下标从1开始
int cnt = 10;

int MaxSumOfSub2() {
    int res = INT_MIN;
    vector<int> sum(N, 0);
    for (int i = 1; i <= cnt; ++i) {
        sum[i] = sum[i - 1] + nums[i];
    }
    for (int i = 1; i <= cnt; ++i) {
        for (int j = i; j <= cnt; ++j) {
            res = max(res, sum[j] - sum[i - 1]);
        }
    }
    return res;
}

int main() {
    cout << "最大子段和为：" << MaxSumOfSub2() << endl;
    return 0;
}