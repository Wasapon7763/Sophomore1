program area
  implicit none
  real(8)::a,b,c,s,p
  read(*,*)a,b,c
  p=(a+b+c)/2
  s=p*(p-a)*(p-b)*(p-c)
  write(*,*)'area=',s  
  stop
end program area
