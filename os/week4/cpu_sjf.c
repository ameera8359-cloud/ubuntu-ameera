#include <stdio.h>
#include <string.h>

#define N 4

typedef struct {
    char pid [8];
    int burst;
    int remaining;
} Process;

void print_run(const char *pid, int start, int end) {
    printf("%s runs from %d to %d\n", pid, start, end);
}

void reset_remaining (Process p[], int n) {
    for (int i=0; i<n; i++)
        p[i].remaining = p[i].burst;
}

void sjf (Process p[], int n) {
    int done [N] = {0};
    int time = 0;
    int finished = 0;

    while (finished < n) {
        int best = -1;
        for (int i=0; i<n; i++) {
            if (done [i])
                continue;
            if (best == -1) {
                best = i;
            } else {
                if (p[i].burst < p[best].burst){
                    best = i;
                }
            }
    }
    print_run(p[best].pid, time, time + p[best].burst);
    time += p[best].burst;
    done [best] = 1;
    finished++;
    }
}
int main(void) {
    Process processes [N] = {
        {"P1", 5, 5},
        {"P2", 3, 3},
        {"P3", 8, 8},
        {"P4", 6, 6}
    };

    printf("\n=== SJF ===\n"); sjf (processes, N);

    return 0;
}
