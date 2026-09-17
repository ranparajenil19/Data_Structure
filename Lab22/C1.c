#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        long long first;
        int same = 1;

        for (int i = 1; i <= N; i++) {
            long long W;
            scanf("%lld", &W);

            long long value = i - W;

            if (i == 1)
                first = value;
            else if (value != first)
                same = 0;
        }

        if (same)
            printf("%d\n", N);
        else
            printf("1\n");
    }

    return 0;
}
