program a
  implicit none
  integer :: m,n
  write(*,'(a,$)')'Input an integer : m = '
  read(*,*)m
  write(*,'(a,$)')'Input an integer : n = '
  read(*,*)n
  write(*,'(a,i0,a,i0,a,i0)')'(1) ',m,' * ',n,' = ',m*n
  write(*,'(a,i0,a,i0,a,i0)')'(1) ',m,' / ',n,' = ',m/n
  stop
end program a
