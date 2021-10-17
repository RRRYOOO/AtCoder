/***********************************************************************************
    Date     : 2021.10.17
    Question : ABC_049_C
***********************************************************************************/
#include <stdio.h>
#include <string.h>

int Count_char(char* str);
int Judge_dream(char* start_str);
int Judge_dreamer(char* start_str);
int Judge_erase(char* start_str);
int Judge_eraser(char* start_str);
int Judge_dreamerase(char* start_str);
int Judge_dreameraser(char* start_str);
int Judge_d(char* start_str);
int Judge_e(char* start_str);

void main(void)
{
    char temp[100100];
    char *start_str;
    int step, count = 0, no_flag = 0;;
    
    fgets(temp, sizeof(temp), stdin);
    count = Count_char(temp);
    start_str = temp;

    while (start_str < &temp[count])
    {
        if (*start_str == 'd') {
            step = Judge_d(start_str);
            if (step == 0) {
                no_flag = 1;
                break;
            }
        }
        else if (*start_str == 'e') {
            step = Judge_e(start_str);
            if (step == 0) {
                no_flag = 1;
                break;
            }
        }
        else {
            no_flag = 1;
            break;
        }
        start_str += step;
    }
    
    if (no_flag == 0) {
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}

/* 入力された文字数をカウント */
int Count_char(char* str)
{
    int count = 0;

    while (str[count] != '\n') {
        ++count;
    }

    return count;
}

/* "dream"があるか確認 */
int Judge_dream(char* start_str)
{
    int step = 0;

    if (strncmp(start_str, "dream", 5) == 0) {
        step = 5;
    }

    return step;
}

/* "dreamer"があるか確認 */
int Judge_dreamer(char* start_str)
{
    int step = 0;

    if (strncmp(start_str, "dreamer", 7) == 0) {
        step = 7;
    }

    return step;
}

/* "erase"があるか確認 */
int Judge_erase(char* start_str)
{
    int step = 0;

    if (strncmp(start_str, "erase", 5) == 0) {
        step = 5;
    }

    return step;
}

/* "eraser"があるか確認 */
int Judge_eraser(char* start_str)
{
    int step = 0;

    if (strncmp(start_str, "eraser", 6) == 0) {
        step = 6;
    }

    return step;
}

/* "dreamerase"があるか確認 */
int Judge_dreamerase(char* start_str)
{
    int step = 0;

    if (strncmp(start_str, "dreamerase", 10) == 0) {
        step = 10;
    }

    return step;
}

/* "dreameraser"があるか確認 */
int Judge_dreameraser(char* start_str)
{
    int step = 0;

    if (strncmp(start_str, "dreameraser", 11) == 0) {
        step = 11;
    }

    return step;
}

/* 'd'から始まる指定文字があるか確認 */
int Judge_d(char* start_str)
{
    int step_count = 0;
    int step_temp = 0;

    step_temp = Judge_dream(start_str);
    if (step_temp == 0) {
        return step_temp;
    }
    else {
        step_count = step_temp;
    }

    step_temp = Judge_dreamer(start_str);
    if (step_temp == 0) {
        return step_count;
    }
    else {
        step_count = step_temp;
    }

    step_temp = Judge_dreamerase(start_str);
    if (step_temp == 0) {
        return step_count;
    }
    else {
        step_count = step_temp;
    }

    step_temp = Judge_dreameraser(start_str);
    if (step_temp == 0) {
        return step_count;
    }
    else {
        return step_temp;
    }
}

/* 'e'から始まる指定文字があるか確認 */
int Judge_e(char* start_str)
{
    int step_count = 0;
    int step_temp = 0;

    step_temp = Judge_erase(start_str);
    if (step_temp == 0) {
        return step_temp;
    }
    else {
        step_count = step_temp;
    }

    step_temp = Judge_eraser(start_str);
    if (step_temp == 0) {
        return step_count;
    }
    else {
        return step_temp;
    }
}