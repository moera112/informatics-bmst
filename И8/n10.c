
#include <stdio.h>
#include <math.h>

double Leng(double a, double b, double c, double d)
{
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

double Perimetr(double Xa, double Ya, double Xb, double Yb, double Xc, double Yc)
{
    return Leng(Xa, Ya, Xb, Yb) + Leng(Xb, Yb, Xc, Yc) + Leng(Xa, Ya, Xc, Yc);
}

double Area(double Xa, double Ya, double Xb, double Yb, double Xc, double Yc)
{
    double p = Perimetr(Xa, Ya, Xb, Yb, Xc, Yc) / 2;
    return sqrt(p * (p - Leng(Xa, Ya, Xb, Yb))*(p - Leng(Xa, Ya, Xc, Yc)) * (p - Leng(Xb, Yb, Xc, Yc)));
}

double Dist(double Xa, double Ya, double Xb, double Yb, double Xc, double Yc)
{
    return 2 * Arae(Xa, Ya, Xb, Yb, Xc, Yc) / Leng(Xa, Ya, Xb, Yb);
}
int main()
{
    
}
