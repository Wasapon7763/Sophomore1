program test
  implicit none
  integer :: y, i
  write(*,'(a,$)')'Input the Anno Domini (A.D.) : '
  read(*,*)y
  if (mod(y,4)==0) then
      if (mod(y,100)==0) then
         if (mod(y,400)==0) then
            i=1
         else
            i=0
         end if
      else 
         i=1
      end if
   end if
   if (i==1) then
      write(*,'(a,i0, a)')'A.D. ',y,' is a leap year'
   else if (i==0) then
      write(*,'(a,i0, a)')'A.D. ',y,' is not a leap year'
   end if
   stop
end program test
