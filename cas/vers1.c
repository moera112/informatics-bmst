// Slots and Casino
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[3][3] =
{
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};



int main()
{
    srand(time(NULL));
    unsigned int bal = 1000;

    printf("\tHello your balance is %d $\r\n\r\n\tStart game?\r\n\tYes: 1, No: 0\r\n\t input: ",bal);
    char play = getchar() - '0';

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
                        bool first = false, second = false, therd = false;
                        printf("\t%d game, balance = %d\r\n\r\n",_+1,bal);

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
                        bal -= bet;
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
                                continue;
                            }
                            else
                            {
                                printf("\t!!!MAX WIN!!!\r\n\t!!!1000x BET!!!\r\n\t!!!WIN = %d$!!!\r\n\t  YOUR BALANCE IS %d\r\n",bet*1000,bal + bet * 1000);
                                bal += bet * 1000;
                                continue;
                            }

                        }
                        if(win_x != 0)
                        {
                            printf("\t You win %d, %dx bet",bet * win_x, win_x);
                            printf("\r\n\tYour balance is %d\r\n\r\n",bal + bet * win_x);
                            bal += bet * win_x;
                        }

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





}
