#include <stdio.h>
#include <string.h>

#define N 4

typedef struct {
  char pid [8];
  int burst;
  int remaining;
} Process;

void print_run(const char *pid, int start, int end) {
  printf ("%s runs from %d to %d\n", pid, start, end);
}

void reset_remaining (Process p[], int n) {
  for (int i=0; i<n; i++)
    p[i].remaining = p[i].burst;
}

void fcfs(Process p[], int n) {
  int time = 0;
  for (int i=0; i<n; i++) {
    print_run(p[i].pid, time, time + p[i] .burst);
    time += p[i].burst;
  }
}

void round_robin(Process p[], int n, int quantum) {
    if (quantum <= 0) { 
        printf ("Quantum must be > 0\n"); 
        return;
    }

    reset_remaining(p, n);

    int q[1000]; 
    int head=0, tail=0; 
    int time=0; 
    int finished=0;

    for (int i=0; i<n; i++) 
        q[tail++] = i;

    while (finished < n) { 
        if (head == tail)
            break;

        int idx = q [head++];

        if (p[idx].remaining <= 0) 
            continue;

        int run = (p[idx].remaining < quantum)?p[idx].remaining:quantum;

        print_run(p[idx].pid, time, time+run); 
        time += run; 
        p[idx].remaining -= run;

        if (p[idx].remaining > 0) {
            q[tail++] = idx; 
        } else { 
            finished++; 
        }
    }
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

  printf(" === FCFS === \n");
  fcfs(processes, N) ;

  printf("\n=== SJF ===\n"); sjf (processes, N);

  printf("\n=== Round Robin (q=2) ===\n");
  round_robin(processes, N, 2);

  return 0;
};