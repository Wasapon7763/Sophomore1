program q1
  implicit none
  integer :: i,j
  integer :: pascal(10,10)
  
  ! START EDITING

  do i=0, 9
     do j=0, 9
        pascal(i, j)=1d0;
     end do
  end do
  do i=1, 9
     do j=1, i-1
        pascal(i, j)=pascal(i-1, j-1)+pascal(i-1, j)
     end do
  end do
  
  do i=0, 9
     do j=0, i
        write(*, '(i3, a, $)')pascal(i, j), ' '
     end do
     write(*,*)
  end do
  ! END EDITING
  
end program q1

