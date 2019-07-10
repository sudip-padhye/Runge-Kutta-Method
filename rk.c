#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define e 2.718282

float rkmethod(float x0,float y0,float h,int order);
float fun(float x,float y);


char func1[1000],func2[1000];
int f1,f2;

void main()
{
    int order;
    float x0,y0,h,res=0;
    char opt;

    printf("\tRunge-Kutta Method for algebraic and exponential functions\n\n\n");
    printf("Enter function f(x) of the form f1(x)/f2(x)\n");
    printf("Is f2 present? (y|n):");
    scanf("%c",&opt);
    opt=tolower(opt);

    if(opt=='n')                                                           //no denominator
        f2=0;
    else
        f2=1;

    printf("Enter functions of the form axn1+byn2+...");

    printf("\nEnter func1\n");
    scanf("%s",func1);
    if(f2)
    {
        printf("Enter func2\n");
        scanf("%s",func2);
    }

    printf("Enter x0, y0 and h\n");
    scanf("%f%f%f",&x0,&y0,&h);

    printf("Enter order of Runge-Kutta method:\n");
    scanf("%d",&order);

    res=rkmethod(x0,y0,h,order);

    printf("\ny(%f)=%f\n",(x0+h),res);
    getch();

}

float rkmethod(float x0,float y0,float h,int order)                       //function to calculate each iteration eg-k0,k1,.....
{
    float k[500],res=0.0,sum=0.0;
    int i;

    k[0]=h*fun(x0,y0);
    printf("\n\tk[0]=%f\n",k[0]);
    sum+=k[0];

    for(i=1;i<order-1;i++)
    {
        k[i]=h*(fun(x0+(h/2),y0+(k[i-1]/2)));
        printf("\tk[%d]=%f\n",i,k[i]);
        sum+=2*k[i];
    }
    k[i]=h*(fun(x0+h,y0+k[i-1]));
    printf("\tk[%d]=%f\n",i,k[i]);
    sum+=k[i];

    res=y0+(sum/6);                                                          //computes the end result and returns back to main function
    return res;
}


float fun(float x,float y)                                                     //computes value of function on substitution
{

float num,den,coeff;
int i,deg,plus,minus;

num=0.0;
den=1.0;
i=0;
deg=0;
coeff=0.0;

if(func1[0]=='-')                                                             //checks whether the first term is -ve
{
    plus=0;
    minus=1;
}
else                                                                          //otherwise first term is +ve
{
    plus=1;
    minus=0;
}

while(1)
{
   coeff=(func1[i]-'0');                                                      //retrieves the initial digit of coefficient
   i++;
   while(isdigit(func1[i]))                                                   //checks whether the coefficient has two or more digits
   {
       coeff=coeff*10+(func1[i]-'0');
       i++;
   }

   if(func1[i]=='x')                                                          //x term
   {
       i++;
       deg=(func1[i]-'0');                                                     //retrieves first digit of degree of x
       i++;

   while(isdigit(func1[i]))                                                    //checks whether the degree has two or more digits
   {
       deg=deg*10+(func1[i]-'0');
       i++;
   }

  if(plus)                                                                      //if the term is +ve then adds to the numerator value
  num=num+(coeff*pow(x,deg));
  else if(minus)                                                                //otherwise subtracts from the value
  num=num-(coeff*pow(x,deg));
   }

   else if(func1[i]=='y')                                                      //y term
   {
      i++;
       deg=func1[i]-'0';                                                       //retrieves first digit of degree of x
       i++;

   while(isdigit(func1[i]))                                                     //checks whether the degree has two or more digits
   {
       deg=deg*10+(func1[i]-'0');
       i++;
   }

  if(plus)                                                                       //if the term is +ve then adds to the numerator value
  num=num+(coeff*pow(y,deg));
  else if(minus)                                                                //otherwise subtracts from the value
  num=num-(coeff*pow(y,deg));

   }

   else if(func1[i]=='e')                                                        //exponent term
   {
       i++;
       if(func1[i]=='x'||func1[i]=='y')                                           //checks whether exponent is either x or y
       {
           if(func1[i]=='x')                                                       //if exponent is x
           {
           if(plus)
          num=num+(coeff*pow(e,x));
          else if(minus)
          num=num-(coeff*pow(e,x));
           }
           else if(func1[i]=='y')                                                 //if exponent is y
           {
            if(plus)
          num=num+(coeff*pow(e,y));
          else if(minus)
          num=num-(coeff*pow(e,y));
           }
           i++;
           goto next;
       }

       deg=func1[i]-'0';                                                         //retrieves first digit of the degree of e
       i++;

   while(isdigit(func1[i]))                                                       //checks for additional digits in degree
   {
       deg=deg*10+(func1[i]-'0');
       i++;
   }

  if(plus)                                                                         //adds the value to existing numerator value
  num=num+(coeff*pow(e,deg));
  else if(minus)                                                                  //otherwise subtracts from numerator value
  num=num-(coeff*pow(e,deg));

   }

next:if(func1[i]=='+')                                                             //checks for sign of next term
   {
      plus=1;
      minus=0;
   }
   else if(func1[i]=='-')
   {
       plus=0;
       minus=1;
   }


   if(func1[i]=='\0')                                                               //checks whether end of string encountered
   {
       break;
   }
   else                                                                             //otherwise goes to coefficient of next term
   {
      i++;
      coeff=0.0;
      deg=0;
   }

}

if(f2)                                                                //computes values for function f2 if present
{
      i=0;
      coeff=0.0;
      deg=0;
      den=0.0;
      if(func2[0]=='-')
{
    plus=0;
    minus=1;
}
else
{
    plus=1;
    minus=0;
}

    while(1)
{
   coeff=func2[i]-'0';
   i++;
   while(isdigit(func2[i]))
   {
       coeff=coeff*10+(func2[i]-'0');
       i++;
   }

   if(func2[i]=='x')
   {
       i++;
       deg=func2[i]-'0';
       i++;

   while(isdigit(func2[i]))
   {
       deg=deg*10+(func2[i]-'0');
       i++;
   }

    if(plus)
  den=den+(coeff*pow(x,deg));
  else if(minus)
  den=den-(coeff*pow(x,deg));
   }

   else if(func2[i]=='y')
   {
      i++;
       deg=func2[i]-'0';
       i++;

   while(isdigit(func2[i]))
   {
       deg=deg*10+(func2[i]-'0');
       i++;
   }

     if(plus)
  den=den+(coeff*pow(y,deg));
  else if(minus)
  den=den-(coeff*pow(y,deg));
   }

     else if(func2[i]=='e')
   {
      i++;
      if(func2[i]=='x'||func2[i]=='y')
       {
           if(func2[i]=='x')
           {
           if(plus)
          den=den+(coeff*pow(e,x));
          else if(minus)
          den=den-(coeff*pow(e,x));
           }
           else if(func2[i]=='y')
           {
            if(plus)
          den=den+(coeff*pow(e,y));
          else if(minus)
          den=den-(coeff*pow(e,y));
           }
           i++;
           goto next1;
       }
       deg=func2[i]-'0';
       i++;

   while(isdigit(func2[i]))
   {
       deg=deg*10+(func2[i]-'0');
       i++;
   }

  if(plus)
  den=den+(coeff*pow(e,deg));
  else if(minus)
  den=den-(coeff*pow(e,deg));

   }

 next1:if(func2[i]=='+')
   {
      plus=1;
      minus=0;
   }
   else if(func2[i]=='-')
   {
       plus=0;
       minus=1;
   }

   if(func2[i]=='\0')
   {
       break;
   }
   else
   {
      i++;
      coeff=0.0;
      deg=0;
   }

}

}

return (num/den);                                                                 //returns the value of func=f1/f2
}
