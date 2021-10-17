/***********************************************************************************
    Date     : 2021.10.17
    Question : ABC_086_C
***********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int t;
    int x;
    int y;
} distination;

int Judge_can_go(distination start, distination goal);

void main(void)
{
    int cycle, i, go_flag;
    distination data[2];
    
    scanf("%d", &cycle);
    data[0].t = 0;
    data[0].x = 0;
    data[0].y = 0;

    for (i = 0; i < cycle; i++) { 
       scanf("%d %d %d", &data[1].t, &data[1].x, &data[1].y);
       go_flag = Judge_can_go(data[0], data[1]);
       if (go_flag == 0) {
           printf("No\n");
           exit(0);
       }
       data[0] = data[1];
    }
    printf("Yes\n");
}

/* ˆÚ“®‰Â”\‚©”»’è */
int Judge_can_go(distination start, distination goal)
{
    int step, distance_x, distance_y, calc;

    step = goal.t - start.t;
    distance_x = abs(goal.x - start.x);
    distance_y = abs(goal.y - start.y);
    calc = step - (distance_x + distance_y);

    if (calc < 0) {
        return 0;
    }
    else if (calc % 2 != 0) {
        return 0;
    }
    return 1;
}