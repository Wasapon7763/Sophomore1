program test
  implicit none
  integer :: i, j, n
  real (8):: a, b, x, h, sum, integer
  write(*,'(a, $)')"Input value of a : "
  read(*,*)a
  write(*,'(a, $)')"Input value of b : "
  read(*,*)b
  write(*,'(a, $)')"Input value of n : "
  read(*,*)n

  sum=0
  h=(b-a)/n
  write(*,*)h
  do i=0, n
     x=a+h*i
     if (i==0.OR.i==n) then
        sum=sum+sqrt(dble(x)**2+1))
     else
        sum=sum+2*(sum+sqrt(dble(x)**2+1)))
     end if
  end do
  write(*,'(a, f0.6)')"Integration of SQRT(x**2+1) in area (a,b) : ",h*sum/2
end program test
