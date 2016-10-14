
#include <math.h>

/* variation of mass in each regime depending on the scale factor (time)*/

//time is needed

double variation_mass_rate(double a)

{


  double A, B, C, dmda;

  A = 0.0;
  B = 0.0;
  C = 0.0;
  //first check if a is on the correct value (or z ?)
  
  if(a <= 0.3333333333) //a <= 1/3 ; z <= 2  
    
    {
      A = 30.5269;
      B = 0.0565262;
      C = A*B;
      dmda = C * exp(B*a);
      
    }
  
  if( 0.3333333333 < a <= 0.07692307) // 1/3 < a <= 1/13  ; 2 < z < 12
    
    {
      
      A = 8.8119;
      //B = 28.4594;
      dmda = A;

    }

  if(0.07692307 < a < 0.0227273) // 1/13 < a < 1/44 ; 12 < z < 43 
    
    {
      A = 2.23249;
      //B = 27.8532;
      dmda = A; 
    }

  return dmda;

}
