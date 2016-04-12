/*
 * =====================================================================================
 *
 *       Filename:  myselect.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月22日 18时28分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xiaolerzheng (zxl), xiaolerzheng@gmail.com
 *        Company:
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int a[20];

void swap(l, r) {
    int tmp = a[r];
    a[r] = a[l];
    a[l] = tmp;
}

void myselect(int k) {
    int l = 0; int u = 19;
    while (l < u) {
        swap(l, l + rand()%(u - l));
        int m = l;
        int i;
        for (i = l; i < u; i++) {
            if (a[i] < a[l]) {
                m = m+1;
                swap(m, i);
            }
            swap(l, m);
        }
        if (k <= m) u = m - 1;
        if (k >= m) l = m + 1;
    }
}

int main() {
    srand(time(0));
    int i;
    for (i = 0; i < 20; i++) {
        a[i] = rand() % 30;
        printf("%c%d", (i != 0 ? ' ':'\b'), a[i]);
    }
    printf("\n");
    myselect(4);
    for (i = 0; i < 20; i++) {
        printf("%c%d", (i != 0 ? ' ':'\b'), a[i]);
    }
    printf("\n");
    return 0;
}
