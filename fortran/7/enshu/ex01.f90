program ex01
  implicit none
  integer :: n, i
  real (8):: ave, sum, x(100)
  sum=0
  write(*, '(a, $)')"Input value of n (n <= 100) : "
  read(*,*)n
  if (n>100) then
     write(*,'(a)')"Error: n is over 100"
     stop
  end if
  do i=1,n
     write(*,'(a, i0, a, $)')"Input value x_", i, " : "
     read(*,*)x(i)
     sum=sum+x(i)
  end do
  ave=(sum+0.0)/n
  write(*, '(a, f10.6)')"average : ", ave
  sum=0
  do i=1,n
     sum=sum+(x(i)-ave)**2
  end do
  write(*, '(a, f10.6)')"standard deviation : ", sqrt(sum/n)
end program ex01
