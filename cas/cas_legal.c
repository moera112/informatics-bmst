// Slots and Casino

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include<windows.h>
#include <unistd.h>
#include <conio.h>
#include <locale.h>

#define NUM_SYMBOLS 9

int arr[3][3] =  // Cлот
{
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};


char getRandomSymbol()
{
    char symbols[NUM_SYMBOLS] = {'A', 'A', '7', 'Y', 'E', 'A', 'W', '$', 'B'};
    return symbols[rand() % NUM_SYMBOLS];

}


void crazy_mode()
{
    int col = rand() % 30;
    switch(col)
    {
        case 0:
            system("color D0");
        case 1:
            system("color 01");
            break;
        case 2:
            system("color 02");
            break;
        case 3:
            system("color 03");
            break;
        case 4:
            system("color 04");
            break;
        case 5:
            system("color 05");
            break;
        case 6:
            system("color 06");
            break;
        case 7:
            system("color 07");
            break;
        case 8:
            system("color 08");
            break;
        case 9:
            system("color 09");
            break;
        case 10:
            system("color 0A");
            break;
        case 11:
            system("color 0B");
            break;
        case 12:
            system("color 0C");
            break;
        case 13:
            system("color 0D");
            break;
        case 14:
            system("color 0E");
            break;
        case 15:
            system("color 0F");
            break;
        case 16:
            system("color 02");
            break;
        case 17:
            system("color 82");
            break;
        case 18:
            system("color 0A");
            break;
        case 19:
            system("color 8A");
            break;
        case 20:
            system("color 30");
            break;
        case 21:
            system("color 5F");
            break;
        case 22:
            system("color 15");
            break;
        case 23:
            system("color 72");
            break;
        case 24:
            system("color 18");
            break;
        case 25:
            system("color 60");
            break;
        case 26:
            system("color 50");
            break;
        case 27:
            system("color F0");
            break;
        case 28:
            system("color B0");
        case 29:
            system("color F0");
            break;
    }

}













void sleep_ms(int milliseconds) // Функция для пауз
{
    usleep(milliseconds * 1000);
}

void info(bool iscrazy)
{


    printf("\r\n\t 3 | 777 = bonus game\r\n\e\n");

    if(iscrazy) crazy_mode();




    printf("\r\n\tLINES\r\n\r\n");

    int arr_info[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };


    for(int i = 0; i < 5; i++)
    {
        int arr_info[3][3] =
        {

            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}

        };

        printf("\r\n\tLINE %d\r\n\r\n",i+1);


        if(i == 0)
        {
            arr_info[0][0] = 77;
            arr_info[0][1] = 77;
            arr_info[0][2] = 77;
        }
        else if(i == 1)
        {
            arr_info[1][0] = 77;
            arr_info[1][1] = 77;
            arr_info[1][2] = 77;

        }
        else if(i == 2)
        {
            arr_info[2][0] = 77;
            arr_info[2][1] = 77;
            arr_info[2][2] = 77;

        }
        else if(i == 3)
        {
            arr_info[0][0] = 77;
            arr_info[1][1] = 77;
            arr_info[2][2] = 77;
        }
        else if(i == 4)
        {
            arr_info[0][2] = 77;
            arr_info[1][1] = 77;
            arr_info[2][0] = 77;
        }

        for(int p = 0; p < 3; p++)
        {
            printf("\t");
            for(int j = 0; j < 3; j++)
            {
                if(iscrazy) crazy_mode();

                printf("%d      ",arr_info[p][j]);
                sleep_ms(200);
            }
            printf("\r\n\r\n");
        }

        sleep_ms(300);
    }

}


int bonus_buy(int bet, bool iscrazy)
{


    srand(time(NULL));

    printf("\r\n\r\n\t!!!YOU WIN 10 FREE SPINS!!!\r\n");
    if(iscrazy) crazy_mode();

    printf("\r\n\tCHOOSE BONUS\r\n");
    if(iscrazy) crazy_mode();

    printf("\r\n\t1: SAVED X\r\n\t2: MORE LINES\r\n\t3: WILDS\r\n\t\r\n\t");
    if(iscrazy) crazy_mode();

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
        min_x = 2;
    }
    unsigned int bonus_win = 0, spins = 10;


    if(bonuse_mode == 1) // Бонуска 1 вариант
    {
        int saved_x = 0;
        for(int _ = 0; _ < spins; _++) // Цикл автоигры
        {
            int win_x = 0;
            bool first = false, second = false, therd = false;
            if(iscrazy) crazy_mode();

            printf("\t%d game, saved x = %d, all win = %d\r\n\r\n",_+1,saved_x, bonus_win);

            for(int i = 0; i < 3; i++) // Заполнение массива
            {
                printf("\t");
                for(int j = 0; j< 3; j++)
                {
                    if(iscrazy) crazy_mode();

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
                    if(iscrazy) crazy_mode();

                    printf("\t!!!SENSATIONAL WIN!!!\r\n\t!!!500x BET!!!\r\n\t!!!WIN = %d$!!!\r\n\t  ALL WIN IS %d\r\n",bet*500,bonus_win + bet * (500 + saved_x));
                    bonus_win += bet * (500 + saved_x);
                    saved_x += 500;
                    sleep(5);
                    continue;
                }
                else
                {
                    if(iscrazy) crazy_mode();

                    printf("\t!!!MAX WIN!!!\r\n\t!!!1000x BET!!!\r\n\t!!!WIN = %d$!!!\r\n\t  ALL WIN IS %d\r\n",bet*500,bonus_win + bet * (1000 + saved_x));
                    bonus_win += bet * (1000 + saved_x);
                    saved_x += 1000;
                    sleep(10);
                    continue;
                }
            }
            if(win_x != 0)
            {
                if(iscrazy) crazy_mode();
                printf("\t You win %d, %dx bet",bet * win_x, win_x);
                if(iscrazy) crazy_mode();
                bonus_win += bet * (win_x + saved_x);

                printf("\r\n\t  ALL WIN = %d\r\n",bonus_win);
                saved_x += win_x;
                sleep(2);
            }
            sleep_ms(600);

            if (rand() % 17 == 4)
            {
                if(iscrazy) crazy_mode();

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
            if(iscrazy) crazy_mode();
            printf("\r\n\t%d game, balance = %d\r\n\r\n",_+1,bonus_win);
            int win_x = 0;
            bool line1 = false, line2 = false, line3 = false;

            for(int i = 0; i < 3; i++)
            {
                printf("\t");
                for(int j = 0; j < 4; j++)
                {
                    if(iscrazy) crazy_mode();

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
                if(iscrazy) crazy_mode();
                printf("\t!!!SENSATIONAL WIN!!!\r\n\t!!!500x BET!!!\r\n\t!!!WIN = %d$!!!\r\n\t  ALL WIN IS %d\r\n",bet*500,bonus_win + bet * 500);
                bonus_win += bet * 500;
                sleep(5);
                continue;
            }

            if(win_x != 0)
            {
                if(iscrazy) crazy_mode();
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
                if(iscrazy) crazy_mode();
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
            if(iscrazy) crazy_mode();
            printf("\r\n\r\n\tBOX ONE: 1\r\n\tBOX TWO : 2\r\n\r\n");
            if(iscrazy) crazy_mode();
            int choose1 = 0;
            printf("\t Yor choose: ");
            scanf("%d",&choose1);

            if(choose1 == 1 && box1 != 0)
            {
                if(iscrazy) crazy_mode();
                printf("\r\n\r\n\tYOU WIN %dX",box1);
                bonus_win += bet * box1;
                printf("\r\n\tBalance = %d $",bonus_win);

            }else if(choose1 == 2 && box2 != 0)
            {
                if(iscrazy) crazy_mode();
                printf("\r\n\r\n\tYOU WIN %dX",box1);
                bonus_win += bet * box2;
                printf("\r\n\tBalance = %d $",bonus_win);
            }else
            {
                if(iscrazy) crazy_mode();
                printf("\r\n\tSORRY, YOU LOSE\r\n");
                printf("\r\n\tALL WIN = %d $",bonus_win);
                break;

            }
        }
    }


    return bonus_win;


}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");

    unsigned int bal = 1000, bonus = 0, bet;

    printf("\tHello your balance is %d $\r\n\r\n\tStart game?\r\n\tYes: 1, No: 0\r\n\t input: ",bal);
    char play = getchar() - '0';

    if(play == 1)
    {
        printf("\r\n\r\n");
        printf("\t GAME STARTING!");

        printf("\r\n\t CHOOSE COLOR \r\n"
               "\r\n\t0 = Черный 8 = Серый\r\n"
                "\r\n\t1 = Синий 9 = Светло-синий\r\n"
                "\r\n\t2 = Зеленый 10 = Светло-зеленый\r\n"
            "\r\n\t3 = Голубой 11 = Светло-голубой\r\n"
                "\r\n\t4 = Красный 12 = Светло-красный\r\n"
            "\r\n\t5 = Лиловый 13 = Светло-лиловый\r\n"
        "\r\n\t6 = Желтый 14 = Светло-желтый\r\n"
    "\r\n\t7 = Белый 15 = Ярко-белый\r\n"
        "\r\n\t30 - ЛУЧШЕ НЕ ВЫБИРАЙТЕ ПОЖАЛУЙСТА\r\n\t"
                 );

        int color;

        bool iscrazy = false;

        printf("\r\n\tВвод: ");
        scanf("%d",&color);

        printf("\r\n\tВыбор %d\r\n\t",&color);

        switch(color)
        {
        case 0:
            break;
        case 1:
            system("color 01");
            break;
        case 2:
            system("color 02");
            break;
        case 3:
            system("color 03");
            break;
        case 4:
            system("color 04");
            break;
        case 5:
            system("color 05");
            break;
        case 6:
            system("color 06");
            break;
        case 7:
            system("color 07");
            break;
        case 8:
            system("color 08");
            break;
        case 9:
            system("color 09");
            break;
        case 10:
            system("color 0A");
            break;
        case 11:
            system("color 0B");
            break;
        case 12:
            system("color 0C");
            break;
        case 13:
            system("color 0D");
            break;
        case 14:
            system("color 0E");
            break;
        case 15:
            system("color 0F");
            break;
        case 30:
            iscrazy = true;
            break;
        }





        if(iscrazy) crazy_mode();


        printf("\r\n\r\n\tWhant info?\r\n\r\n\tYes: 1 No: 0\r\n\r\n\tInput: ");
        int inform;
        scanf("%d",&inform);

        if(inform == 1) info(iscrazy);




        while (true) // Игровая ссесия
        {
            printf("\r\n\tВыберите игру.\r\n\tСлоты 1 Рулетка 2\r\n\t Input: ");
            int game;
            scanf("%d",&game);
            if(game == 2)
            {
                goto roulet;
            }
            if(iscrazy) crazy_mode();
            printf("\r\n\t Whant autoplay?\r\n\t Yes: 1, No: 0\r\n\t Input: ");
            int game_mod;
            scanf("%d",&game_mod);

            if(game_mod == 1) // Автоигра
            {
                link:
                if(iscrazy) crazy_mode();
                printf("\tEnter count: ");
                int count;
                scanf("%d",&count);

                if(iscrazy) crazy_mode();

                printf("\r\n\tEnter bet: ");

                scanf("%d",&bet);

                printf("\r\n\tSPEED SPINS?\r\n\tyes: 1 no: 0\r\n\t Input: ");
                int is_speed;
                scanf("%d",&is_speed);

                if(bet * count > bal)
                {
                    if(iscrazy) crazy_mode();
                    printf("\r\n\t To big bet please try again.\r\n");
                    goto link;
                }
                else
                {
                    for(int _ = 0; _ < count; _++) // Цикл автоигры
                    {
                        if(iscrazy) crazy_mode();
                        int win_x = 0;
                        bonus = 0;
                        bool first = false, second = false, therd = false;
                        printf("\t%d game, balance = %d\r\n\r\n",_+1,bal);

                        for(int i = 0; i < 3; i++) // Заполнение массива
                        {
                            printf("\t");
                            for(int j = 0; j< 3; j++)
                            {
                                if (rand() % (rand() % 40 + 7) == 11 || rand() % 20 == 14)
                                {
                                    if(iscrazy) crazy_mode();
                                    arr[i][j] = 777;
                                    bonus++;
                                    printf("%d      ",arr[i][j]);
                                    continue;
                                }
                                else if(rand() % 10 == 7)
                                {
                                    if(iscrazy) crazy_mode();
                                    arr[i][j] = 10;
                                    printf("%d      ",arr[i][j]);
                                    continue;
                                }
                                if(iscrazy) crazy_mode();
                                arr[i][j] = rand() % 5 + 3;
                                printf("%d      ",arr[i][j]);

                                if (!is_speed) sleep_ms(100);

                            }
                            printf("\r\n\r\n");

                        }

                        bal -= bet;
                        if(bonus >= 3)
                        {
                            if(iscrazy) crazy_mode();
                            int bw = bonus_buy(bet, iscrazy);
                            bal += bw;
                            bw = 0;
                            if(iscrazy) crazy_mode();
                            printf("\r\n\r\n\tALL BALANCE = %d$\r\n\r\n",bal);
                            if(iscrazy) crazy_mode();
                            printf("\r\n\r\n\tWhant continue?\r\n\tYes: 1 No: 0\r\n\r\n\tInput: ");
                            int ont;
                            scanf("%d",&ont);
                            if(ont != 1)
                            {
                                break;
                            }
                            sleep(1);
                            continue;
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
                                if(iscrazy) crazy_mode();
                                printf("\t!!!SENSATIONAL WIN!!!\r\n\t!!!500x BET!!!\r\n\t!!!WIN = %d$!!!\r\n\t  YOUR BALANCE IS %d\r\n",bet*500,bal + bet * 500);
                                bal += bet * 500;
                                sleep(1);
                                continue;
                            }
                            else
                            {
                                if(iscrazy) crazy_mode();
                                printf("\t!!!MAX WIN!!!\r\n\t!!!1000x BET!!!\r\n\t!!!WIN = %d$!!!\r\n\t  YOUR BALANCE IS %d\r\n",bet*1000,bal + bet * 1000);
                                bal += bet * 1000;
                                sleep(2);
                                continue;
                            }

                        }
                        if(win_x != 0)
                        {
                            if(iscrazy) crazy_mode();
                            printf("\t You win %d, %dx bet",bet * win_x, win_x);
                            if(iscrazy) crazy_mode();
                            printf("\r\n\tYour balance is %d\r\n\r\n",bal + bet * win_x);
                            bal += bet * win_x;
                        }
                        if (!is_speed) sleep_ms(500);

                    }
                }
            }
            else
            {
                while(true) // Ручной режим
                {
                    bonus = 0;

                    unsigned int solo_bet, game_count = 0, xbet = 0;
                    link2:
                    printf("\r\n\tEnter bet: ");
                    if(iscrazy) crazy_mode();
                    scanf("%d",&solo_bet);
                    printf("\r\n");
                    if(solo_bet > bal)
                    {
                        if(iscrazy) crazy_mode();
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
                            if (rand() % (rand() % 40 + 7) == 11 || rand() % 20 == 14)
                            {
                                if(iscrazy) crazy_mode();
                                arr[i][j] = 777;
                                bonus++;
                                printf("%d      ",arr[i][j]);
                                continue;
                            }
                            if(iscrazy) crazy_mode();
                            arr[i][j] = rand() % 5 + 3;
                            printf("%d      ",arr[i][j]);
                            sleep_ms(100);
                        }
                        printf("\r\n\r\n");
                    }

                    if(bonus >= 3)
                    {
                        int bw = bonus_buy(solo_bet, iscrazy);
                        bal += bw;
                        bw = 0;
                        if(iscrazy) crazy_mode();
                        printf("\r\n\r\n\tALL BALANCE = %d$\r\n\r\n",bal);
                        sleep(4);
                        continue;

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
                            if(iscrazy) crazy_mode();
                            printf("\t!!!SENSATIONAL WIN!!!\r\n\t!!!500x BET!!!\r\n\t!!!WIN = %d$!!!\r\n\t  YOUR BALANCE IS %d\r\n",solo_bet*500,bal + solo_bet * 500);
                            bal += solo_bet * 500;
                            sleep(1);
                            continue;
                        }
                        else
                        {
                            if(iscrazy) crazy_mode();
                            printf("\t!!!MAX WIN!!!\r\n\t!!!1000x BET!!!\r\n\t!!!WIN = %d$!!!\r\n\t  YOUR BALANCE IS %d\r\n",solo_bet*1000,bal + solo_bet * 1000);
                            bal += solo_bet * 1000;
                            sleep(2);
                            continue;
                        }

                    }
                    if(xbet != 0)
                    {
                        printf("\t You win %d, %dx bet",solo_bet * xbet, xbet);
                        if(iscrazy) crazy_mode();
                        printf("\r\n\tYour balance is %d\r\n\r\n",bal + solo_bet * xbet);
                        if(iscrazy) crazy_mode();
                        bal += solo_bet * xbet;
                    }
                    printf("\tbalance = %d\r\n\r\n",bal);
                    if(iscrazy) crazy_mode();
                    printf("\tContinue? Yes: 1, No: 0\r\n\t   input: ");

                    int cont;
                    scanf("%d",&cont);
                    if(cont == 0)
                    {
                        break;
                    }
                    sleep_ms(500);

                }
            }
            if(false)
            {
                roulet:
                printf("\r\n\t!!!РУЛЕТКА!!!\r\n");
                if(iscrazy) crazy_mode();
                printf("\r\n\t ПРАВИЛА ИГРЫ \r\n\r\n");
                if(iscrazy) crazy_mode();

                printf("\tA - 20x Выплата\r\n"
                        "\tY - 70x Выплата\r\n"
                        "\tE - 120x Выплата\r\n"
                        "\t$ - 200x Выплата\r\n"
                        "\t7 - 1000x Выплата\r\n"
                        "\tW - 777777x Выплата Максвин\r\n"
                        "\tB - Бонусные игры"

                    );
                    if(iscrazy) crazy_mode();

                printf("\r\n\tПример | 7 | 7 | 7 | -^ \r\n");
                if(iscrazy) crazy_mode();
                printf("\r\n\tStart auto?\r\n\t Yes: 1, No: 0\r\n\tInput: ");
                int mode;
                scanf("%d",&mode);
                if(mode == 1)
                {
                    int bw;
                    zan:
                    if(iscrazy) crazy_mode();
                    printf("\r\n\tВведите количество игр: ");
                    int game_count;
                    scanf("%d",&game_count);
                    if(iscrazy) crazy_mode();
                    printf("\r\n\tВведите ставку: ");
                    scanf("%d",&bet);
                    if(game_count * bet > bal)
                    {
                        if(iscrazy) crazy_mode();
                        printf("\r\n\tнедостаточно средств Баланс = %d\r\n",bal);
                        goto zan;
                    }else
                    {
                        for(int _ = 0; _ < game_count; _++)
                        {
                            char l1 = getRandomSymbol();
                            char l2 = getRandomSymbol();
                            char l3 = getRandomSymbol();
                            if(iscrazy) crazy_mode();
                            printf("\r\n\tИгра номер %d, Баланс = %d\r\n\r\n",_+1,bal-bet);
                            bal -= bet;
                            printf("\t | %c |",l1);
                            sleep_ms(200);
                            printf(" %c |",l2);
                            sleep_ms(200);
                            printf(" %c | -^\r\n",l3);
                            if(l1 == l2 && l2 == l3)
                            {
                                switch (l1)
                                {
                                case 'A':
                                    if(iscrazy) crazy_mode();
                                    printf("\r\n\r\n\tВаш выигрыш %d, 20x \r\n",bet*20);
                                    bal += bet * 20;
                                    printf("\t Баланс = %d",bal);
                                    break;
                                case 'Y':
                                    if(iscrazy) crazy_mode();
                                    printf("\r\n\r\n\tВаш выигрыш %d, 70x \r\n",bet * 70);
                                    bal += bet * 70;
                                    printf("\t Баланс = %d",bal);
                                    break;
                                case 'E':
                                    if(iscrazy) crazy_mode();
                                    printf("\r\n\r\n\tВаш выигрыш %d, 120x \r\n",bet * 120);
                                    bal += bet * 120;
                                    printf("\tБаланс = %d",bal);
                                    break;
                                case '$':
                                    if(iscrazy) crazy_mode();
                                    printf("\r\n\r\n\tБольшой выигрыш! %d, 200x \r\n",bet * 200);
                                    bal += bet * 200;
                                    printf("\tБаланс = %d",bal);
                                    break;
                                case '7':
                                    if(iscrazy) crazy_mode();
                                    printf("\r\n\r\n\t!!МЕГА ВЫИГРЫШ!! %d, 1000x \r\n",bet * 1000);
                                    bal += bet * 1000;
                                    printf("\tБаланс = %d",bal);
                                    break;
                                case 'W':
                                    if(iscrazy) crazy_mode();
                                    printf("\r\n\r\n\t!!МАААКСИМАЛЬНЫЙ ВЫИГРЫШ!! %d, 777777x \r\n",bet * 777777);
                                    bal += bet * 777777;
                                    printf("\tБаланс = %d",bal);
                                    break;
                                case 'B':
                                    if(iscrazy) crazy_mode();
                                    bw = bonus_buy(bet, iscrazy);
                                    bal += bw;
                                    printf("\tБаланс = %d",bal);
                                    break;

                                }
                                sleep(1);
                            }
                            sleep(1);
                        }
                    }


                }



            }






            if(iscrazy) crazy_mode();
            printf("\r\n\r\n\tLeave Game? Yes: 1 No: 0\r\n\t input: ");
            int gamee;
            scanf("%d",&gamee);
            if(gamee == 1)
            {
                break;
            }
            printf("\r\n\r\n");

        }














    }



    return 0;
}


