program test
  implicit none
  integer :: m,n
  write(*,'(a,$)')'Input an integer : m = '
  read(*,*)m
  write(*,'(a,$)')'Input an integer : n = '
  read(*,*)n
  if (n==0) then
     write(*,'(a)')'Error: Divided by 0'
     stop
  end if
  write(*,'(i0,a,i0,a,i0,a,i0)')m,' / ',n,' = ', m/n, ' ... ',m-n*(m/n)
end program test

