#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>


enum { w = 65, h = 25 }; // Ширина и высота поля
char ar[h][w + 1];      // поле
char saveP[h][w+1];    // Сохраненная карта чтобы не считывать каждый иаз из файла
int Ncount, Mcount; // Максимальное кол-во ударов и текущее кол-во ударов

void readMap(FILE* stream) {    // Функция чтения карты из файла 
    for (int i = 0; i < h; i++) {
        fgets(saveP[i], w+1, stream);
        char* ptr = strchr(saveP[i], '\n');
        if (ptr != NULL)
            *ptr = '\0';
        fgetc(stream);

    }
}

typedef struct {    // Шар - основной объект
    float x, y;     // Вещественные координаты
    int xi, yi;     // Целочисленные координаты
    float alpha, speed;     // Угол альфа и скорость
} TBall;

typedef struct {    // Ракетка
    int x, y, w;    // Координаты х у и ширина
} TRacket;

// Создаем объекты
TBall ball;
TRacket racket;



void putBall() { // Помещаем шар на карту
    ar[ball.yi][ball.xi] = '*';
}

void moveBall(float x, float y) { // Передвижение мяча по карте
    ball.x = x;
    ball.y = y;
    ball.xi = (int)round(ball.x);
    ball.yi = (int)round(ball.y);
}

void initBall() {       // Инициализация мяча
    moveBall(2, 2);     // Устанавливаем координаты 2 2
    ball.alpha = -1;
    ball.speed = 0.5;
}

void initRacket() { // Инициализация ракетки
    racket.w = 7;
    racket.x = (w - racket.w) / 2;
    racket.y = h - 1;
}

void init(char pole[][w+1]) { // Инициализация поля
    if(pole == NULL) {        //Если указатель pole равен NULL то инициализируем дефолтной картой
        for (int i = 0; i < w; i++)
            ar[0][i] = '#';
        ar[0][w] = 0;
        strncpy(ar[1], ar[0], w + 1);
        for (int i = 1; i < w - 1; i++)
            ar[1][i] = ' ';
        for (int i = 2; i < h; i++)
            strncpy(ar[i], ar[1], w + 1);
        return;
    }
    for(int i = 0; i < h; i++) // Иначе копируем карту из массива pole
        strncpy(ar[i], pole[i], w+1);
}

void PutRacket() { // Помещаем ракетку на карту
    for (int i = 0; i < racket.w; i++)
        ar[racket.y][racket.x + i] = '@';

}

void showPole() { // Вывод поля на экран

    for (int i = 0; i < h; i++) {
        printf("%s", ar[i]);
        if(i == 3)
            printf("    Now Hits -> %d ",Ncount);
        if(i == 4)
            printf("    Max Hits -> %d ",Mcount);
        if(i < h-1)
            printf("\n");


    }
}

void moveRacket(int x) { // Передвижение ракетки
    racket.x = x;
    if (x < 1)
        racket.x = 1;
    if (x + racket.w >= w)
        racket.x = w - 1 - racket.w;
}

void setcur(int x, int y) { // Устанавливаем позицию курсора в точку с координатами x, y
                            // Используется для очистки консоли установкой курсора в точки 0 0
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void AutoMoveBall() { // ПИЗДЕЦ
    if(ball.alpha < 0) ball.alpha += M_PI * 2; // Проверяем выыход за гран радиан
    if(ball.alpha > M_PI * 2) ball.alpha -= M_PI * 2;

    TBall bl = ball; // Сохраняем текущее состояние

    moveBall(ball.x + cos(ball.alpha) * ball.speed, // Устанавливаем координаты
        ball.y + sin(ball.alpha) * ball.speed);
    if(ar[ball.yi][ball.xi] == '#' || ar[ball.yi][ball.xi] == '@'){
            if(ar[ball.yi][ball.xi] == '@') // Если шарик отразился от ракетки прибавляем 1 к счетчику улдаров
                Ncount++;

    //--------------------------------------------------------------------------------
    // Обработка столкновения шара со стеной или с рокеткой
    // Меняем координаты и направление шара в зависимости от того под каким углом произошло столкновение
    // Для этого проверяем какие координаты шара изменились всего 3 случая
    // 1 -> Изменил обе координаты | 2 -> Изменил только х | 3 -> Изменил только y
    //--------------------------------------------------------------------------------

        if(ball.xi != bl.xi && ball.yi != bl.yi){   // Если изменились обе координаты
            if(ar[bl.yi][ball.xi] == ar[ball.yi][bl.xi])
                bl.alpha += M_PI;
            else
            {
                if(ar[bl.yi][ball.xi] == '#')
                    bl.alpha = (2 * M_PI - bl.alpha) + M_PI;
                else
                    bl.alpha = (2 * M_PI - bl.alpha);
            }
        }
        else if(ball.yi == bl.yi)    // Шар двигался по горизонтали отражаем по вертикали
            bl.alpha = (2 * M_PI - bl.alpha) + M_PI;
        else                       // Шар двигался по вертикали отражаем по горизонтали
            bl.alpha = (2 * M_PI - bl.alpha);

        ball = bl;
        AutoMoveBall();
    }


}

void GameStream(FILE* stream){ // ВКлючает в себя основные функции  нициализации и отображения
    setcur(0, 0);
    //readMap(stream);
    init(NULLw);
    PutRacket();
    putBall();
    showPole();
}

int main() {
    bool run = false;
    FILE* stream = fopen("player_anim.txt", "r");
    initRacket(); // Инициализация ракетки
    initBall();
    readMap(stream);
    do
    {
        if (run)
            AutoMoveBall();
        if(ball.yi > h){
            run = false;
            if(Ncount > Mcount)
                Mcount = Ncount;
            Ncount = 0;
        }
        GameStream(stream);
        if (GetKeyState('A') < 0) moveRacket(racket.x - 1);
        if (GetKeyState('D') < 0) moveRacket(racket.x + 1);
        if (GetKeyState('W') < 0) run = true;

        if(!run)
            moveBall(racket.x + racket.w / 2, racket.y - 1);

        Sleep(10);
    } while (GetKeyState(VK_ESCAPE) >= 0);

    fclose(stream);

}

