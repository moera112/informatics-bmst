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

void bonus_play(int n, int bet)
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
}



int main()
{
    srand(time(NULL));
    unsigned int bal = 1000, bonus = 0;

    printf("\tHello your balance is %d $\r\n\r\n\tStart game?\r\n\tYes: 1, No: 0\r\n\t input: ",bal);
    char play = getchar() - '0';

    bonus_play(3, 100);

    if(play == 1)
    {
        printf("\r\n\r\n");
        printf("\t GAME STARTING!");

        while (true) // Игровая ссесия
        {
            printf("\r\n\t Whant autoplay?\r\n\t Yes: 1, No: 0\r\n\t Input: ");
            int game_mod;
            scanf("%d",&game_mod);

            if(game_mod == 1) // Автоигра
            {
                link:
                printf("\tEnter count: ");
                int count;
                scanf("%d",&count);

                printf("\r\n\tEnter bet: ");

                int bet;
                scanf("%d",&bet);

                printf("\r\n\tSPEED SPINS?\r\n\tyes: 1 no: 0\r\n\t Input: ");
                int is_speed;
                scanf("%d",&is_speed);

                if(bet * count > bal)
                {
                    printf("\r\n\t To big bet please try again.\r\n");
                    goto link;
                }
                else
                {
                    for(int _ = 0; _ < count; _++) // Цикл автоигры
                    {
                        int win_x = 0;
                        bonus = 0;
                        bool first = false, second = false, therd = false;
                        printf("\t%d game, balance = %d\r\n\r\n",_+1,bal);

                        for(int i = 0; i < 3; i++) // Заполнение массива
                        {
                            printf("\t");
                            for(int j = 0; j< 3; j++)
                            {
                                if (rand() % (rand() % 40 + 7) == 11)
                                {
                                    arr[i][j] = 777;
                                    bonus++;
                                    printf("%d      ",arr[i][j]);
                                    continue;
                                }
                                else if(rand() % 10 == 7)
                                {
                                    arr[i][j] = 10;
                                    printf("%d      ",arr[i][j]);
                                    continue;
                                }
                                arr[i][j] = rand() % 5 + 3;
                                printf("%d      ",arr[i][j]);

                                if (!is_speed) sleep_ms(100);

                            }
                            printf("\r\n\r\n");

                        }

                        bal -= bet;
                        if(bonus >= 3)
                        {

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
                                printf("\t!!!SENSATIONAL WIN!!!\r\n\t!!!500x BET!!!\r\n\t!!!WIN = %d$!!!\r\n\t  YOUR BALANCE IS %d\r\n",bet*500,bal + bet * 500);
                                bal += bet * 500;
                                sleep(1);
                                continue;
                            }
                            else
                            {
                                printf("\t!!!MAX WIN!!!\r\n\t!!!1000x BET!!!\r\n\t!!!WIN = %d$!!!\r\n\t  YOUR BALANCE IS %d\r\n",bet*1000,bal + bet * 1000);
                                bal += bet * 1000;
                                sleep(2);
                                continue;
                            }

                        }
                        if(win_x != 0)
                        {
                            printf("\t You win %d, %dx bet",bet * win_x, win_x);
                            printf("\r\n\tYour balance is %d\r\n\r\n",bal + bet * win_x);
                            bal += bet * win_x;
                        }
                        if (!is_speed) sleep_ms(500);

                    }
                }
            }
            else
            {
                while(true)
                {

                    unsigned int solo_bet, game_count = 0, xbet = 0;
                    link2:
                    printf("\r\n\tEnter bet: ");
                    scanf("%d",&solo_bet);
                    printf("\r\n");
                    if(solo_bet > bal)
                    {
                        printf("\r\n\tTo big bet please try again.");
                        goto link2;
                    }
                    bool first = false, second = false, therd = false;

                    bal -= solo_bet;
                    for(int i = 0; i < 3; i++) // Заполнение массива
                    {
                        printf("\t");
                        for(int j = 0; j< 3; j++)
                        {
                            arr[i][j] = rand() % 5 + 3;
                            printf("%d      ",arr[i][j]);
                        }
                        printf("\r\n\r\n");
                    }
                    if(arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2])
                    {
                        xbet += arr[0][0];
                        first = true;
                    }
                    if(arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2])
                    {
                        xbet += arr[1][1];
                        second = true;
                    }
                    if(arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2])
                    {
                        xbet += arr[2][2];
                        therd = true;
                    }
                    if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
                    {
                        xbet += arr[0][0];
                    }
                    if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
                    {
                        xbet += arr[1][1];
                    }
                    if(first == second && second == therd && second)
                    {
                        if(arr[0][0] != 7)
                        {
                            printf("\t!!!SENSATIONAL WIN!!!\r\n\t!!!500x BET!!!\r\n\t!!!WIN = %d$!!!\r\n\t  YOUR BALANCE IS %d\r\n",solo_bet*500,bal + solo_bet * 500);
                            bal += solo_bet * 500;
                            continue;
                        }
                        else
                        {
                            printf("\t!!!MAX WIN!!!\r\n\t!!!1000x BET!!!\r\n\t!!!WIN = %d$!!!\r\n\t  YOUR BALANCE IS %d\r\n",solo_bet*1000,bal + solo_bet * 1000);
                            bal += solo_bet * 1000;
                            continue;
                        }

                    }
                    if(xbet != 0)
                    {
                        printf("\t You win %d, %dx bet",solo_bet * xbet, xbet);
                        printf("\r\n\tYour balance is %d\r\n\r\n",bal + solo_bet * xbet);
                        bal += solo_bet * xbet;
                    }
                    printf("\tbalance = %d\r\n\r\n",bal);
                    printf("\tContinue? Yes: 1, No: 0\r\n\t   input: ");

                    int cont;
                    scanf("%d",&cont);
                    if(cont == 0)
                    {
                        break;
                    }

                }
            }
            printf("\r\n\r\n\tLeave Game? Yes: 1 No: 0\r\n\t input: ");
            int game;
            scanf("%d",&game);
            if(game == 1)
            {
                break;
            }
            printf("\r\n\r\n");

        }

    }



    return 0;
}


