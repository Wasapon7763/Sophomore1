program test1
  implicit none
  integer :: i, n
  real (8):: x(100), max, min
  
  write(*,'(a, $)')"Input value of n (n<-100) : "
  read(*,*)n
  
  if (n>100) then
     write(*,'(a)')"Error: n is over 100"
     stop
  end if
  
  do i=1, n
     
     write(*,'(a, i0, a, $)')"Input value x_", i, " --> : "
     read(*,*)x(i)
     
     if (i==1.or.x(i)>max) then
        max=x(i)
     end if
     if (i==1.or.x(i)<min) then
        min=x(i)
     end if

  end do
  write(*,'(a, f10.6)')"Maximun value : ", max
  write(*,'(a, f10.6)')"Minimun value : ", min
end program test1
