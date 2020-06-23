class lyaExp
{
    private:

    //timeStep= timestep value for ODE mode only, default 1.0
    //dim=dimension of the original system
    //mode=1 means map, mode=2 means ODE.
    int dim; 
    int mode; 
    int stepCounter;
    double timeStep; 
    double *LE;

    
    gsl_vector* scale_vector(gsl_vector *v, double factor);
    
    gsl_vector* div_vector(gsl_vector *v, double factor);
    
    public:
    double vector_mod(gsl_vector *a);
    
    double inner_product_vector(gsl_vector *a, gsl_vector *b);
    
    void init(int d, int m, double ts=1.0);
    
    void cleanup();
    

    void getLyapunovSpectrum(double x[]);
    

    void update(gsl_vector *dx[]);
    
};

void copy(gsl_vector *v, double V[], int dim);

void copy(double V[], gsl_vector *v, int dim);
