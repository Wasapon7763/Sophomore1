program test
  implicit none
  integer :: a, b, c, i, x, y, r, hoge
  
  write(*,'(a, $)')"Input a : "
  read(*,*)a
  write(*,'(a, $)')"Input b : "
  read(*,*)b
  write(*,'(a, $)')"Input c : "
  read(*,*)c

  do i=0, 2

     if (a>b) then
        x=a
        y=b
     else 
        y=a
        x=b
     end if
     
     r=mod(x, y)
     
     do while (r/=0)
        hoge=y
        x=y
        y=r
        r=mod(x, y)
     end do

     a=y
     b=c

  end do
  
  write(*, '(a, i0)')"G.C.M of a, b, c : ",y
  
end program test
