#include "io.h"


int main()
{
    int x = 0;
  do
    {
        system("cls");
        printf ("\n");
        printf ("0\n");
        printf ("1\n");
        printf ("2\n");
        printf ("3\n");
        printf ("4\n");
        printf ("5\n");
        printf ("6\n");
        printf ("7\n");
        printf ("8\n");
        printf ("9\n");
        printf ("10\n");
        x = IO_readint("Entre com sua opcao\n");
        system("cls");
        switch (x)
        {
        case 1:
        
            break;
        /*case 2:
        
            break;
        case 3:
        
            break;
        case 4:
        
            break;
        case 5:
        
            break;
        case 6:
        
            break;
        case 7:
        
            break;
        case 8:
        
            break;
        case 9:
        
            break;
        case 10:
            break;
        */default:
            break;
        }
    } while (x != 0);
}
