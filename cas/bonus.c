// Slots and Casino
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include<windows.h>
#include <unistd.h>

int arr[3][3] =
{
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};



void sleep_ms(int milliseconds)
{
    usleep(milliseconds * 1000);
}

int bonus_play(int n, int bet)
{
    if(n == 3)
    {
        printf("\r\n\r\n\t!!!YOU WIN 10 FREE SPINS!!!\r\n");
        printf("\r\n\tCHOOSE BONUS\r\n");
        printf("\r\n\t1: SAVED X\r\n\t2: MORE LINES\r\n\t3: WILDS\r\n\t4: RANDOM X\r\n\t");
        int bonuse_mode;
        printf("\r\n\tINPUT: ");
        scanf("%d",&bonuse_mode);
        if(bonuse_mode == 1)
        {
            int spins = 10;
            for(int _ = 0; _ < spins; _++) // Цикл автоигры
            {
                int win_x = 0, saved_x = 0, bonus_win = 0;
                bool first = false, second = false, therd = false;
                printf("\t%d game, saved x = %d, all win = %d\r\n\r\n",_+1,saved_x, bonus_win);

                for(int i = 0; i < 3; i++) // Заполнение массива
                {
                    printf("\t");
                    for(int j = 0; j< 3; j++)
                    {
                        arr[i][j] = rand() % 20;
                        arr[i][j] += arr[i][j] > 15 ? 0 : 15-arr[i][j];
                        printf("%d      ",arr[i][j]);
                        sleep_ms(100);

                    }
                    printf("\r\n\r\n");

                }

                if(arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2])
                {
                    win_x += arr[0][0];
                    first = true;
                }
                if(arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2])
                {
                    win_x += arr[1][1];
                    second = true;
                }
                if(arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2])
                {
                    win_x += arr[2][2];
                    therd = true;
                }
                if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
                {
                    win_x += arr[0][0];
                }
                if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
                {
                    win_x += arr[1][1];
                }
                if(first == second && second == therd && second)
                {
                    if(arr[0][0] != 7)
                    {
                        printf("\t!!!SENSATIONAL WIN!!!\r\n\t!!!500x BET!!!\r\n\t!!!WIN = %d$!!!\r\n\t  ALL WIN IS %d\r\n",bet*500,bonus_win + bet * (500 + saved_x));
                        bonus_win += bet * (500 + saved_x);
                        saved_x += 500;
                        sleep(1);
                        continue;
                    }
                    else
                    {
                        printf("\t!!!MAX WIN!!!\r\n\t!!!1000x BET!!!\r\n\t!!!WIN = %d$!!!\r\n\t  ALL WIN IS %d\r\n",bet*500,bonus_win + bet * (1000 + saved_x));
                        bonus_win += bet * (1000 + saved_x);
                        saved_x += 1000;
                        sleep(2);
                        continue;
                    }
                }
                if(win_x != 0)
                {
                    printf("\t You win %d, %dx bet",bet * win_x, win_x);

                    bonus_win += bet * (win_x + saved_x);
                    saved_x += win_x;
                }
                sleep_ms(500);

                if (rand() % 30 == 15)
                {
                    printf("\r\n\tYOU WIN MORE FREE SPINS\r\n\r\n\t+5 FREE SPINS\r\n\r\n");
                    spins+=5;
                }
            }
        }
        else if(n == 4)
        {

        }
        return 0;
}

