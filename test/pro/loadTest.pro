function loadTest,filename
  
  openr,un,filename,/get_lun
  
  nL=0l
  nLambda=0l
  readu,un,nL,nLambda

  L=dblarr(nL)
  
  density=dblarr(nLambda,nL)
  lambda=dblarr(nLambda,nL)

  xL=0d
  xLambda=0d
  xDensity=0d

  for iL=0l,nL-1 do begin
     readu,un,xL
     L[iL]=xL
     for iLambda=0l,nLambda-1 do begin
        readu,un,xLambda,xDensity
        lambda[iLambda,iL]=xLambda
        density[iLambda,iL]=xDensity
     endfor
  endfor
  
  
  free_lun,un

  return,{nL:nL,nLambda:nLambda,L:L,lambda:lambda,density:density}
end
