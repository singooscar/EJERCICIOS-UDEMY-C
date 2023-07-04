#include <stdio.h>

int main()
{
    float base, altura;
    
    printf ("Intruduzca la base del rectangulo:  \n");
    scanf ("%f", &base);
    printf ("Intruduzca la altura del rectangulo:  \n");
    scanf ("%f", &altura);
    float area = base*altura;
    

    printf ("El area del rectangulo de base %2.f y altura %2.f es %2.f\n" ,base, altura, area);


    

    return 0;
}
