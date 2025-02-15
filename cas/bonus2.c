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


int bonus_buy(int bet)
{

    srand(time(NULL));

    printf("\r\n\r\n\t!!!YOU WIN 10 FREE SPINS!!!\r\n");
    printf("\r\n\tCHOOSE BONUS\r\n");
    printf("\r\n\t1: SAVED X\r\n\t2: MORE LINES\r\n\t3: WILDS\r\n\t\r\n\t");
    int bonuse_mode;
    printf("\r\n\tINPUT: ");
    scanf("%d",&bonuse_mode);
    int random_acces1, min_x;

    random_acces1 = 25;
    min_x = 16;

    int r1 = rand();

    if(r1 % 3 == 1 || r1 % 3 == 0)
    {
        random_acces1 = 8;
        min_x = 4;
    }
    unsigned int bonus_win = 0, spins = 10;


    if(bonuse_mode == 1) // Бонуска 1 вариант
    {
        int saved_x = 0;
        for(int _ = 0; _ < spins; _++) // Цикл автоигры
        {
            int win_x = 0;
            bool first = false, second = false, therd = false;
            printf("\t%d game, saved x = %d, all win = %d\r\n\r\n",_+1,saved_x, bonus_win);

            for(int i = 0; i < 3; i++) // Заполнение массива
            {
                printf("\t");
                for(int j = 0; j< 3; j++)
                {
                    arr[i][j] = rand() % random_acces1;
                    arr[i][j] += arr[i][j] > min_x ? 0 : min_x-arr[i][j];
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
                if(arr[0][0] != 20)
                {
                    printf("\t!!!SENSATIONAL WIN!!!\r\n\t!!!500x BET!!!\r\n\t!!!WIN = %d$!!!\r\n\t  ALL WIN IS %d\r\n",bet*500,bonus_win + bet * (500 + saved_x));
                    bonus_win += bet * (500 + saved_x);
                    saved_x += 500;
                    sleep(5);
                    continue;
                }
                else
                {
                    printf("\t!!!MAX WIN!!!\r\n\t!!!1000x BET!!!\r\n\t!!!WIN = %d$!!!\r\n\t  ALL WIN IS %d\r\n",bet*500,bonus_win + bet * (1000 + saved_x));
                    bonus_win += bet * (1000 + saved_x);
                    saved_x += 1000;
                    sleep(10);
                    continue;
                }
            }
            if(win_x != 0)
            {
                printf("\t You win %d, %dx bet",bet * win_x, win_x);
                bonus_win += bet * (win_x + saved_x);
                printf("\r\n\t  ALL WIN = %d\r\n",bonus_win);
                saved_x += win_x;
                sleep(2);
            }
            sleep_ms(600);

            if (rand() % 10 == 4)
            {
                printf("\r\n\tYOU WIN MORE FREE SPINS\r\n\r\n\t+5 FREE SPINS\r\n\r\n");
                spins+=5;
                sleep(3);
            }
        }
    }else if(bonuse_mode == 2)
    {
        int arr_b[3][4] =
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        };


        for(int _ = 0; _ < spins; _++)
        {
            printf("\r\n\t%d game, balance = %d\r\n\r\n",_+1,bonus_win);
            int win_x = 0;
            bool line1 = false, line2 = false, line3 = false;

            for(int i = 0; i < 3; i++)
            {
                printf("\t");
                for(int j = 0; j < 4; j++)
                {
                    arr_b[i][j] = rand() % random_acces1;
                    arr_b[i][j] += arr_b[i][j] > min_x ? 0 : min_x-arr_b[i][j];
                    printf("%d     ",arr_b[i][j]);
                    sleep_ms(100);
                }
                printf("\r\n\r\n");
            }



            if(arr_b[0][0] == arr_b[0][1] && arr_b[0][1] == arr_b[0][2] && arr_b[0][2] == arr_b[0][3]) // line1
            {
                win_x += arr_b[0][0];
                line1 = true;
            }
            if(arr_b[1][0] == arr_b[0][1] && arr_b[1][1] == arr_b[1][2] && arr_b[1][2] == arr_b[1][3]) // line2
            {
                win_x += arr_b[1][0];
                line2 = true;
            }
            if(arr_b[2][0] == arr_b[2][1] && arr_b[2][1] == arr_b[2][2] && arr_b[2][2] == arr_b[2][3]) // line 3
            {
                line3 = true;
                win_x += arr_b[2][1];
            }
            if(arr_b[0][0] == arr_b[1][1] && arr_b[1][1] == arr_b[0][2] && arr_b[0][2] == arr_b[1][3]) // line 4
            {
                win_x += arr_b[0][0];
            }
            if(arr_b[1][0] == arr_b[0][1] && arr_b[0][1] == arr_b[1][2] && arr_b[1][2] == arr_b[0][3]) // line 5
            {
                win_x += arr_b[1][0];
            }
            if(arr_b[2][0] == arr_b[1][1] && arr_b[1][1] == arr_b[2][2] && arr_b[2][2] == arr_b[1][3]) // line 6
            {
                win_x += arr_b[2][0];
            }
            if(arr_b[1][0] == arr_b[2][1] && arr_b[2][1] == arr_b[1][2] && arr_b[1][2] == arr_b[2][3]) // line 7
            {
                win_x += arr_b[1][0];
            }
            if(arr_b[2][0] == arr_b[0][1] && arr_b[0][1] == arr_b[2][2] && arr_b[2][2] == arr_b[0][3]) // line 8
            {
                win_x += arr_b[2][0];
            }
            if(arr_b[0][0] == arr_b[2][1] && arr_b[2][1] == arr_b[0][2] && arr_b[0][2] == arr_b[2][3]) // line 9
            {
                win_x += arr_b[0][0];
            }
            if(arr_b[2][0] == arr_b[1][1] && arr_b[1][1] == arr_b[1][2] && arr_b[1][2] == arr_b[2][3]) // line 10
            {
                win_x += arr_b[2][0];
            }
            if(arr_b[1][0] == arr_b[2][1] && arr_b[2][1] == arr_b[2][2] && arr_b[2][2] == arr_b[1][3]) // line 11
            {
                win_x += arr_b[1][0];
            }
            if(arr_b[0][0] == arr_b[1][1] && arr_b[1][1] == arr_b[1][2] && arr_b[1][2] == arr_b[0][3]) // line 12
            {
                win_x += arr_b[0][0];
            }
            if(arr_b[1][0] == arr_b[0][1] && arr_b[0][1] == arr_b[0][2] && arr_b[0][2] == arr_b[1][3]) // line 13
            {
                win_x += arr_b[1][0];
            }

            if(line1 == line2 && line2 == line3 && line1)
            {
                printf("\t!!!SENSATIONAL WIN!!!\r\n\t!!!500x BET!!!\r\n\t!!!WIN = %d$!!!\r\n\t  ALL WIN IS %d\r\n",bet*500,bonus_win + bet * 500);
                bonus_win += bet * 500;
                sleep(5);
                continue;
            }

            if(win_x != 0)
            {
                printf("\r\n\r\n\tYou win %d, %dx bet\r\n\tBalance = %d\r\n",bet*win_x,win_x,bonus_win + bet*win_x);
                sleep_ms(400);
                bonus_win += bet * win_x;

            }
            sleep_ms(200);
        }
    }else if(bonuse_mode == 3)
    {
        while (true)
        {
            printf("\r\n\tCHOOSE BOX\r\n\t");

            int box1, box2, ranom = rand() % 30;

            if(ranom >= 15)
            {
                int delitel = rand() % 10 > 4 ? 30 : 50;
                if(rand() % 25 == 12) delitel = 10000;
                box1 = rand() % 2 == 0 ?  rand() % delitel : 0;
                box2 = box1 == 0 ? rand() % delitel + 1 : 0;

            }else
            {
                int delitel = rand() % 10 <= 4 ? 30 : 50;
                if(rand() % 25 == 12) delitel = 10000;
                box1 = rand() % 2 == 0 ?  rand() % delitel : 0;
                box2 = box1 == 0 ? rand() % delitel + 1 : 0;
            }

            printf("\r\n\r\n\tBOX ONE: 1\r\n\tBOX TWO : 2\r\n\r\n");

            int choose1 = 0;
            printf("\t Yor choose: ");
            scanf("%d",&choose1);
            if(choose1 == 1 && box1 != 0)
            {
                printf("\r\n\r\n\tYOU WIN %dX",box1);
                bonus_win += bet * box1;
                printf("\r\n\tBalance = %d $",bonus_win);

            }else if(choose1 == 2 && box2 != 0)
            {
                printf("\r\n\r\n\tYOU WIN %dX",box1);
                bonus_win += bet * box2;
                printf("\r\n\tBalance = %d $",bonus_win);
            }else
            {
                printf("\r\n\tSORRY, YOU LOSE\r\n");
                printf("\r\n\tALL WIN = %d $",bonus_win);
                break;

            }
        }
    }


    return bonus_win;


}
