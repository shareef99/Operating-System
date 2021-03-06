#include<stdio.h>

struct process {
  int burst, wait, comp, f;
} p[20] = { 0,0 };

int main() {
  int n, i, j, quantum, totalwait = 0, totalturn = 0, time = 0, flag = 1;

  printf("\nEnter The No Of Process :");
  scanf("%d", &n);

  printf("\nEnter The Quantum time (in ms) :");
  scanf("%d", &quantum);

  for (i = 0;i < n;i++) {
    printf("Enter The Burst Time (in ms) For Process #%d :", i + 1);
    scanf("%d", &p[i].burst);
    p[i].f = 1;
  }

  printf("\nOrder Of Execution \n");
  printf("\nProcess Starting Ending Remaining");
  printf("\n\t\tTime \tTime \t Time");

  while (flag == 1) {
    flag = 0;
    for (i = 0;i < n;i++) {
      if (p[i].f == 1) {
        flag = 1;
        j = quantum;

        if ((p[i].burst - p[i].comp) > quantum)
          p[i].comp += quantum;
        else {
          p[i].wait = time - p[i].comp;
          j = p[i].burst - p[i].comp;
          p[i].comp = p[i].burst;
          p[i].f = 0;
        }

        printf("\nprocess # %d %d %d %d", i + 1, time, time + j, p[i].burst - p[i].comp);
        time += j;
      }
    }
  }

  printf("\n\n------------------");
  printf("\nProcess \t Waiting Time TurnAround Time ");

  for (i = 0;i < n;i++) {
    printf("\nProcess # %d %d %d", i + 1, p[i].wait, p[i].wait + p[i].burst);
    totalwait += p[i].wait;
    totalturn += p[i].wait + p[i].burst;
  }

  printf("\n\nAverage\n------------------ ");
  printf("\nWaiting Time: %d ms", totalwait / n);
  printf("\nTurnAround Time : %d ms\n\n", totalturn / n);

  return 0;
}
