program ex01
  implicit none
  integer :: i, j, n, fct
  real(8) :: e, x
  write(*,'(a, $)')"Input values of n : "
  read(*,*)n
  write(*,'(a, $)')"Input values of x : "
  read(*,*)x
  
  e=0
  do i=0, n
     fct=1
     do j=1, i
        fct=fct*j
     end do
     e=e+(x**i)/fct
  end do
  write(*,'(a,f5.3,a,f10.8)')"e^", x, " = ",e
end program ex01
