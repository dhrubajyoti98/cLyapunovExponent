#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<gsl/gsl_vector.h>
#include "lyaExp.hpp"



    

    
    gsl_vector* lyaExp::scale_vector(gsl_vector *v, double factor)
    {
        gsl_vector* tmp=gsl_vector_calloc(dim);
        double val=0;
        for(int i=0;i<dim;i++)
        {
            val=factor*(gsl_vector_get(v,i));
            gsl_vector_set(tmp,i,val);
        }
        return tmp;
    }
    gsl_vector* lyaExp::div_vector(gsl_vector *v, double factor)
    {
        gsl_vector* tmp=gsl_vector_calloc(dim);
        double val=0;
        for(int i=0;i<dim;i++)
        {
            val=(gsl_vector_get(v,i))/factor;
            gsl_vector_set(tmp,i,val);
        }
        return tmp;
    }
    double lyaExp::vector_mod(gsl_vector *a)
    {
        double mod=0;
        for(int i=0;i<dim;i++)
        {
            mod=mod+pow(gsl_vector_get(a,i),2);
        }
        return sqrt(mod);
    }
    double lyaExp::inner_product_vector(gsl_vector *a, gsl_vector *b)
    {
        double dprod=0;
        for(int i=0;i<dim;i++)
        {
            dprod=dprod+gsl_vector_get(a,i)*gsl_vector_get(b,i);
        }
        return dprod;
    }

    void lyaExp::init(int d, int m, double ts)
    {
        dim=d;
        mode=m; 
        timeStep=ts;
        stepCounter=0;
        LE=new double[dim];
        for(int i=0;i<dim;i++)
        {
            LE[i]=0;
        }
    }
    void lyaExp::cleanup()
    {
        delete(LE);
    }

    void lyaExp::getLyapunovSpectrum(double x[])
    {
        for(int i=0;i<dim;i++)
            x[i]=LE[i]/stepCounter;
    }

    void lyaExp::update(gsl_vector *dx[])
    {
        gsl_vector *v[dim], *u[dim];

        for(int i=0;i<dim;i++)
        {
            v[i]=gsl_vector_calloc(dim);
            u[i]=gsl_vector_calloc(dim);

            if(i!=0)
            {
                gsl_vector *accum=gsl_vector_calloc(dim);
                for(int j=0;j<=i-1;j++)
                {
                    double dprod=inner_product_vector(dx[i],u[j]);
                    gsl_vector_add(accum,scale_vector(u[j],-1*dprod));
                }
                gsl_vector_add(v[i],accum);
                gsl_vector_free(accum);
            }
            gsl_vector_add(v[i],dx[i]);
            double modvi=vector_mod(v[i]);
            gsl_vector_add(u[i],div_vector(v[i],modvi));
            
            if(mode==1)
            {
                LE[i]=LE[i]+log2(modvi);
            }
            else if(mode==2)
            {
                LE[i]=LE[i]+(1.0/timeStep)*log2(modvi);
            }
            
            for(int j=0;j<dim;j++)
            {
                gsl_vector_set(dx[i],j,gsl_vector_get(u[i],j));
            }
        }

        /********MEMORY-FREE-UP********/
        for(int i=0;i<dim;i++)
        {
            gsl_vector_free(v[i]);
            gsl_vector_free(u[i]);
        }
        /******************************/
        stepCounter++;
    }


void copy(gsl_vector *v, double V[], int dim)
{
    for(int i=0;i<dim;i++)
        V[i]=gsl_vector_get(v,i);
}

void copy(double V[], gsl_vector *v, int dim)
{
    for(int i=0;i<dim;i++)
        gsl_vector_set(v,i,V[i]);
}