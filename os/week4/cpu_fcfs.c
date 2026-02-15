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

int main(void) {
  Process processes [N] = {
    {"P1", 5, 5},
    {"P2", 3, 3},
    {"P3", 8, 8},
    {"P4", 6, 6}
};

  printf(" === FCFS === \n");
  fcfs(processes, N) ;

  return 0;
};