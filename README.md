# Runge-Kutta-Method
## RUNGE-KUTTA METHOD FOR Ordinary Differential Equations (ODE)
In numerical analysis, the Runge–Kutta methods are an important family of iterative methods, which are used in approximation of solutions of ordinary differential equations. These techniques were developed around 1900 by the German mathematicians C. Runge and M. W. Kutta.

Runge-kutta method for 4th order-
Given,
> dy/dx=f(x,y)  and  y(x0)=y0
We can approximate the value of y(x0+h) as,
> k1=h.f(x0,y0)

> k2=h.f(x0+h/2,y0+k1/2)

> k3=h.f(x0+h/2,y0+k2/2)

> k4=h.f(x0+h,y0+k3)

> y(x0+h)=y0+1/6 (k1+2k2+2k3+k4)

## Description-
The equations (numerator & denominator) are taken in terms of a string. 

## Functions-
1. main( ) : void -
Accepts the numerator and denominator(if any) functions alongwith x0, y0,  h and order values. Later on computation prints the final result.

2. float rkmethod(float x0,float y0,float h,int order) : float -
Computes the values of ki  based on the order entered. Finally it returns the result back to main(  ).

3. float fun(float x,float y) : float -
The fun( ) accepts values of x and y & substitutes them into equations of numerator and denominator (if any) and finds the value of function. It returns this value to rkmethod( ) which helps in calculation of ki .
