// This is a program for testing the rpihuang2004 model. It will 
// create a file which contains density along several field lines 

#include <stdio.h>
#include <math.h>

#include "../../include/rpiozhogin2012.H"

int main(int argc, char *argv[]){
  int iL,nL=41,iLambda,nLambda=1001;
  double LMin=1.5,dL=0.5,L,lambda,lambdaMax,dLambda;
  
  RPIOZHOGIN2012 r;

  FILE *fp;
  fp=fopen("../dat/test.dat","w");
  fwrite(&nL,sizeof(int),1,fp);
  fwrite(&nLambda,sizeof(int),1,fp);
  
  for(iL=0,L=LMin;iL<nL;iL++,L+=dL){
    fwrite(&L,sizeof(double),1,fp);
    double lambdaMax=acos(1/sqrt(L))/M_PI*180;
    double dLambda=(2*lambdaMax)/(nLambda-1);
    double density;
    for(iLambda=0,lambda=-lambdaMax;iLambda<nLambda;
	iLambda++,lambda+=dLambda){
      fwrite(&lambda,sizeof(double),1,fp);
      density=r.getDensity(L,lambda);
      fwrite(&density,sizeof(double),1,fp);
    }
  }
  
  fclose(fp);

  return 0;
}
