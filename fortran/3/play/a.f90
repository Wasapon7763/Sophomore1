program a
  implicit none
  integer :: i,j
  logical :: lo
  write(*,'(a)')'Please input i and j.'
  read(*,*)i,j
  lo=i<j
  write(*,'(a,)')'i<j is ',lo
end program a
