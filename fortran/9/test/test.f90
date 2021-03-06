program test
  implicit none
  integer ::y, b
  write(*,'(a, $)')'Input the Anno Domini (A.D.) -> '
  read(*,*)y
  b=isleap(y)
  if (b==1) then
     write(*,'(a,i0, a)')'A.D. ',y,' is a leap year'
  else if (b==0) then
     write(*,'(a,i0, a)')'A.D. ',y,' is not a leap year'
  end if
contains
  function isleap(y)
    implicit none
    integer::isleap
    integer, intent(in)::y
    if (mod(y,4)==0) then
      if (mod(y,100)==0) then
         if (mod(y,400)==0) then
            isleap=1
         else
            isleap=0
         end if
      else
         isleap=1
      end if
   else
      isleap=0
   end if
  end function isleap
end program test


