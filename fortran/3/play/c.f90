program c
  implicit none
  integer :: i,j
  write(*,'(a,$)')'Input i and j : (i, j) = '
  read(*,*)i
  read(*,*)j
  if ((i>11).and.(i==j)) then
     write(*,*)'True 1'
  else if ((i<10).or.(j>1)) then
     write(*,*)'True 2'
  else
     write(*,*)'False'
  end if
  stop
end program c
