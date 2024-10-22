#include "io.h"
void metodo11a(int x)
{
    if (x>0)
    {
        int result = 0;
        metodo11a(x-1);
        result = x*7;
        printf("%d\n",result);
    }else{
        printf("1\n");
    }
}
void metodo11( )
{
    int x = 5;
    metodo11a(x);
}
int main ( )
{
    double x = 10.00;
    int y = 2;
    double result = 0.00;
    result = pow (x,y);
    printf("result = %lf\n",result);
    result = pow (result,-1);
    printf("result = %lf",result);
    return( 0 );
}
