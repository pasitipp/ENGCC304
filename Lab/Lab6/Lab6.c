#include <stdio.h>

int main() {
    int N;

    printf("กรุณากรอกตัวเลขจำนวนเต็ม: ");

    if (scanf("%d", &N) != 1) {
        printf("ไม่ใช่ตัวเลข\n");
        return 1;
    }

    if (N % 2 == 0) {
        printf("เลขคู่ :  ");
        for (int i = N; i >= 0; i -= 2) {
            printf("%d ", i);
        }
    } else {
        printf("เลขคี่ : ");
        for (int i = 1; i <= N; i += 2) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
