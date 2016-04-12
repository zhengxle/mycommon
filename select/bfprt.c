/*
 * =====================================================================================
 *
 *       Filename:  bfprt.c
 *
 *    Description:  http://blog.csdn.net/adong76/article/details/10071297
 *
 *        Version:  1.0
 *        Created:  2014年06月21日 21时19分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaoliang (zxl), xiaoliang.zxl@taobao.com
 *        Company:  Taobao.com
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 20

#define N 20
int a[N];

void bubble(int a[], int first, int end) {
    int i, j;
    for (i = first; i <= end; i++) {
        for (j = end; j > i; j--) {
            if (a[j] < a[j-1]) {
                int t = a[j];
                a[j]  = a[j-1];
                a[j-1] = t;
            }
        }
    }
}

int partition_modify(int p, int r, int t) {
    int i, j;
    for (i = p, j = r; i < j; i++) {
        if (a[i] >= t) {
            while (i < j && a[j] >= t) {
                j--;
            }
            if (i != j) {
                int t = a[i];
                a[i]  = a[j];
                a[j]  = t;
                j--;
            }
            break;
        }
    }
    if (a[i] >= t && i > p) {
        return i - 1;
    }
    return i;
}

int select_modify(int p, int r, int k) {
    int i;
    if (r - p < 5) {
        bubble(a, p, r);
        return a[p+k-1];
    }
    for (i = 0; i < (r - p + 1)/5; i++) {
        int s = p + 5 * i, t = s + 4;
        bubble(a, s, t);
        int tmp = a[p+i];
        a[p+i] = a[s+2];
        a[s+2] = tmp;
    }
    int x = select_modify(p, p+(r-p+1)/5-1, (r-p+6)/10);
    i     = partition_modify(p, r, x);
    int j = i - p + 1;
    if (k <= j) {
        return select_modify(p, i, k);
    }
    return select_modify(i+1, r, k - j);
}

int main() {
    srand(time(0));
    int i;
    for (i = 0; i < N; i++) {
        a[i] = rand() % 20;
        printf("%d ", a[i]);
    }
    printf("\n");
    int n = 4;
    printf("the no [%d] is %d\n", n, select_modify(0, N-1, n));
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
