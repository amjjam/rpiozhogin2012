/******************************************************************************
 * This is the class RPIOZHOGIN2012 which implements the Ozhogin et al. 2012      *
 * RPI data based electron number density model of plasmaspheric plasma.      *
 ******************************************************************************/

#include <math.h>

class RPIOZHOGIN2012{
public:
  RPIOZHOGIN2012();
  ~RPIOZHOGIN2012();
  double getDensity(double L, double lambda);
  double getDensity(double L, double lambda, double lambdainv);
private:
  double A,B,C,D,gamma,alpha;
};
