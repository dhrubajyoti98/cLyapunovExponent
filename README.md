![GitHub repo size](https://img.shields.io/github/repo-size/dhrubajyoti98/cLyapunovExponent)

# cLyapunovExponent
A C++ library to calculate Lyapunov Spectrum of a Dynamical System using Gram-Schmidt Procedure.

Details of the numerical method used can be found in the book: *Practical Numerical Algorithms for Chaotic Systems* by *Parker and Chua*, Chapter 3. See <https://www.springer.com/gp/book/9781461281214>.

## Dependencies
This library uses the GNU Scientific Library (GSL), specifically the vector implementation found in gsl_vector.h. Therefore, this has to be installed before using this library. 
**For Ubuntu and similar distros, use: sudo apt-get install gsl-bin libgsl0-dev**

## Usage
Make sure you have the GSL Library installed and configured.

* ### To build the library: 
0. Please go through the sample code provided to learn how to use the library before proceeding.
1. git clone this repository.
2. go to the folder 'src'.
3. run 'make'.
4. This should create the library file **libLyaExp.a**.
5. Copy **libLyaExp.a** and **lyaExp.hpp** into the working directory of the code in which you want to use it.
6. For example, if your code is named "logistic.cpp", you should use:

   >**g++ -o logistic logistic.cpp -lm -lgsl -lgslcblas -L . -lLyaExp**
   
* ### To test using sample code provided (Lyapunov Spectrum of Henon Map):
1. git clone this repository
2. go to the folder 'sample'
3. run 'make'
4. run './test'
5. You should get two numbers on as your output on your display as follows:
    >0.60 -2.34
    
## Authors & Contact 
Dhrubajyoti Biswas, Contact: <dhrubajyoti98@gmail.com>

Rahul Sundar, Contact: <rahul.sundar95@gmail.com>

## Other examples/features/functionalities to be added:
- [ ] Sample codes for some other simple maps and non-linear ODEs. (Example: Logistic, lorentz, forced duffing) 
- [ ] Comments and cleaning up of the code base for user friendliness
- [ ] Orthonormalisation methods: householder transformation, givens rotation, cholesky decomposition, modified gram schmidt process.
- [ ] Wolfe's algorithm for Lyapunov exponents if possible given just a time series
