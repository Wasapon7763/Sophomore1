program ex02
  integer :: n, i, fct
  real (8):: x
  write(*,'(a, $)')"Input values of n : "
  read(*,*)n
  write(*,'(a, $)')"Input values of x : "
  read(*,*)x
  
  fct=1
  e=0
  do i=0, n
     if (i==0) then
        fct=1
     else
        fct=fct*i
     end if
     e=e+(x**i)/fct
  end do
  write(*,'(a,f5.3,a,f10.8)')"e^",x," = ",e
end program ex02
