#include "../include/rpiozhogin2012.H"

/*=============================================================================
  RPIOZHOGIN2012() - constructor
  ============================================================================*/
RPIOZHOGIN2012::RPIOZHOGIN2012(){
  A=4.4693;
  B=-0.4903;
  C=-0.75;
  D=1.01;
}


/*=============================================================================
  ~RPIOZHOGIN2012() - destructor
  ============================================================================*/
RPIOZHOGIN2012::~RPIOZHOGIN2012(){

}


/*=============================================================================
  double getDensity(double L, double lambda) - get the density, in
  cm^-3 as a function of L-shell and magnetic latitude of a point on
  the field line.
  
  double L - L-shell in Earth radii
  double lambda - magnetic latitude in degrees
  ============================================================================*/
double RPIOZHOGIN2012::getDensity(double L, double lambda){
  double lambdainv=acos(1.0/sqrt(L))/M_PI*180;
  return getDensity(L,lambda,lambdainv);
}


/*=============================================================================
  double getDensity(double L, double lambda, double lambdainv) - get
  the densit, in cm^-3 as a function of L-shell and magnetic latitude
  of a point on the field line and invariant latitude of the field
  line. If the field line is dipolar then simply use the call form
  that does not include invariant latitude as it is then computed
  using a dipole model.

  double L - L-shell in Earth radii
  double lambda - magnetic latitude of point on field line in degrees
  double labdainv - invariant latitude of field line in degrees
  ============================================================================*/
double RPIOZHOGIN2012::getDensity(double L, double lambda, double lambdainv){
  
  double lambdamax=acos(sqrt(8371/(L*6371)))/M_PI*180;
  
  if(lambda<-lambdamax)
    lambda=-lambdamax;
  else if(lambda>lambdamax)
    lambda=lambdamax;
  
  double NEQ=exp(log(10)*(A+B*L));
  
  return NEQ*pow(cos(M_PI/2*D*lambda/lambdainv),C);
}
