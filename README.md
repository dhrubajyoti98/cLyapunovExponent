# cLyapunovExponent
A C++ library to calculate Lyapunov Spectrum of a Dynamical System using Gram-Schmidt Procedure.

## Author & Contact 
Dhrubajyoti Biswas, Contact: <dhrubajyoti98@gmail.com>

## Dependencies
This library uses the GNU Scientific Library (GSL), specifically the vector implementation found in gsl_vector.h. Therefore, this has to be installed before using this library. 
**For Ubuntu and similar distros, use: sudo apt-get install gsl-bin libgsl0-dev**

## Usage

* ### To build the library: 
1. git clone this repository.
2. go to the folder 'src'.
3. run 'make'.
4. This should create the library file **libLyaExp.a**.
5. Copy **libLyaExp.a** and **lyaExp.hpp** into the working directory of the code in which you want to use it.
6. For example, if your code is named "logistic.cpp", you should use:

   >**g++ -o logistic logistic.cpp -lm -lgsl -lgslcblas -L . -lLyaExp**
   
* ### To test using sample code provided:
1. git clone this repository
2. go to the folder 'sample'
3. run 'make'
4. run './test'
5. You should get two numbers on as your output on your display as follows:
    >0.60 -2.34
