program b
  implicit none
  integer :: i, j
  logical :: lo
  write(*,'(a,$)')'i = '
  read(*,*)i
  write(*,'(a,$)')'j = '
  read(*,*)j
  lo=(i<10).eqv.(j>1)
  write(*,*)'lo = ',lo
  stop
end program b
