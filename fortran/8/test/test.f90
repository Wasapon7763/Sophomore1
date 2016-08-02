program test
  implicit none
  integer :: i, j
  integer :: pascal(0:9, 0:9)
  pascal(:,:)=1d0
  do i=1, 9
     do j=1, i-1
        pascal(i, j)=pascal(i-1, j-1)+pascal(i-1, j)
     end do
  end do
  do i=0, 9
     do j=0, 9-i
        write(*,'(a, $)')'  '
     end do
     do j=0, i
        write(*,'(i3, a, $)')pascal(i,j), ' '
     end do
     write(*,*)
  end do
end program test
