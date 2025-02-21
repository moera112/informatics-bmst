#include <stdio.h>
#include <math.h>

double Leng(double a, double b, double c, double d)
{
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

double Perimetr(int Xa, int Ya, int Xb, int Yb, int Xc, int Yc)
{
    return Leng(Xa, Ya, Xb, Yb) + Leng(Xb, Yb, Xc, Yc) + Leng(Xa, Ya, Xc, Yc);
}


int main()
{
    
}
