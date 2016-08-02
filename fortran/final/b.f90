program b
  implicit none
  integer::i, j
  integer::a(1:4)=(/1, 2, 3, 4/)
  integer::aa(3, 3)=reshape((/1, 2, 3, 4, 5, 6, 7, 8, 9/), (/3, 3/))
  do i=1, 3
     do j=1, 3
        write(*,'(i0, a, $)')aa(i, j), ' '
     end do
     write(*,*)
  end do
end program b
