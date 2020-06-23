#include<gsl/gsl_vector.h>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include "lyaExp.hpp"

/*double f(double x[], double dx[], double a, double b, int mark)
{
    if(mark==0)
        return a*x[0]*(1-x[0]);
    if(mark==1)
        return a*x[1]*(1-x[1]);
}
double fp(double x[], double dx[], double a, double b, int mark)
{
    if(mark==0)
        return a*dx[0]*(1-2*x[0]);
    if(mark==1)
        return a*dx[1]*(1-2*x[1]);
}*/

double f(double x[], double dx[], double a, double b, int mark)
{
    if(mark==0)
        return 1-a*pow(x[0],2)+x[1];
    if(mark==1)
        return b*x[0];
}
double fp(double x[], double dx[], double a, double b, int mark)
{
    if(mark==0)
        return -2*a*x[0]*dx[0]+dx[1];
    if(mark==1)
        return b*dx[0];
}


void func(gsl_vector* x, gsl_vector* dx, double a, double b, int dim)
{
    double X[dim], TX[dim];
    double DX[dim], TDX[dim];
    copy(x,X,dim);
    copy(dx,DX,dim);

    for(int i=0;i<dim;i++)
    {
        TX[i]=f(X,DX,a,b,i);
        TDX[i]=fp(X,DX,a,b,i);
    }

    copy(TX,x,dim);
    copy(TDX,dx,dim);
}

int main(int argc, char *argv[])
{
    srand48(time(NULL));
    int dim=2;
    
    double LE[dim];
    lyaExp LEX;
    LEX.init(dim,1);

    double a=1.4,b=0.3;
    
    gsl_vector *x[dim];
    gsl_vector *dx[dim];

    for(int i=0;i<dim;i++)
    {
        x[i]=gsl_vector_calloc(dim);
        dx[i]=gsl_vector_calloc(dim);
    }

    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
            gsl_vector_set(x[i],j,0.3);
        }
        gsl_vector_set_basis(dx[i],i);
    }

    int n=0;
    while(n<=100000)
    {
        for(int i=0;i<dim;i++)
        {
            func(x[i],dx[i],a,b,dim);
        }
        LEX.update(dx);
        n++;
    }
    LEX.getLyapunovSpectrum(LE);
    printf("%lf %lf\n",LE[0],LE[1]);
    LEX.cleanup();

    return 0;
}