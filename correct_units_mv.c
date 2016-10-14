
#include <math.h>

/* variation of mass in each regime depending on the scale factor (time)*/

//time is needed

double variation_mass_rate(double a)

{

  double A, B, c, dm_t;
  double m_DM,sol,fcu;

  //m_DM = 8.96430367e55; //M_sun
  m_DM = 8.96430367e-65; //1e10M_sun

  sol = 300000; //km s^-1 

  fcu = m_DM * sol * sol;

  A = 0.0;
  B = 0.0;

  //first check if a is on the correct value (or z ?)
  
  if(a <= 0.3333333333) //a <= 1/3 ; z <= 2  
    
    {
      A = 30.5269;
      B = 0.0565262;
      c = A*B;
      //dm_t = c * exp(B*a);
      dm_t = -(c * exp(B*a) * fcu);      
    }
  
  if( 0.3333333333 < a <= 0.07692307) // 1/3 < a <= 1/13  ; 2 < z < 12
    
    {
      
      A = 8.8119;
      //B = 28.4594;
      dm_t = -(A * fcu);

    }

  if(0.07692307 < a < 0.0227273) // 1/13 < a < 1/44 ; 12 < z < 43 
    
    {
      A = 2.23249;
      //B = 27.8532;
      dm_t = -(A* fcu); 
    }

  return dm_t;

}
