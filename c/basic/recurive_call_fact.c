#include <stdio.h>

/* 階乗 */

/* for文 */

// int factorial(int n) {
//     int i, f;
//     f = 1;
//     for (i = 1; i <= n; i++) {
//         f = i * f;
//     }
//     return f;
// }

/* 再帰 */

int factorial(int n) {
    if(n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
