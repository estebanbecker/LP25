#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int solve_2nd_degre(float a,float b,float c,float*x1,float*x2,float*i1,float*i2);

//Programme tath take in paramèter a,b and c and print the imaginary roots of the equation ax^2+bx+c=0
int main(int argc, char *argv[])
{
    float a,b,c,x1,x2,i1,i2;

    a=atof(argv[1]);
    b=atof(argv[2]);
    c=atof(argv[3]);

    solve_2nd_degre(a,b,c,&x1,&x2,&i1,&i2);
}

/**Fucntion that solve the equation ax^2+bx+c=0 in the complexe space
 * @param a
 * @param b
 * @param c
 * @param *x1
 * @param *x2
 * @param *i1
 * @param *i2
 * @return x1,x2,i1,i2
*/
int solve_2nd_degre(float a,float b,float c,float*x1,float*x2,float*i1,float*i2)
{
    float delta;

    if(a == 0)
    {
        if(b == 0)
        {
            printf("The equation has no solution.\n");
            return 0;
        }
        else
        {
            *x1=-c/b;
            printf("The equation has one solution: %f\n",*x1);
            return 0;
        }
    }

    delta=b*b-4*a*c;

    if(delta<0)
    {
        *x1=-b/(2*a);
        *i1=sqrt(-delta)/(2*a);
        *x2=-b/(2*a);
        *i2=-sqrt(-delta)/(2*a);

        printf("x1=%f+%fi\n",*x1,*i1);
        printf("x2=%f+%fi\n",*x2,*i2);

    }else if(delta==0)

    {
        *x1=-b/(2*a);
        
        printf("x1=x2=%f\n",*x1);
    }else
    {
        *x1=(-b+sqrt(delta))/(2*a);
        *x2=(-b-sqrt(delta))/(2*a);

        printf("x1=%f\n",*x1);
        printf("x2=%f\n",*x2);
    }

    return 0;
}