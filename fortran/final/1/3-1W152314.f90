program q3
  implicit none
  integer :: i,j
  integer :: pascal(55)
  
  
  ! START EDITING
  integer::c
  do i=0, 55
     pascal(i)=1d0
  end do
  c=5
  do i=3, 10
     do j=2, i-1
        pascal(c-1)=pascal(c-i-1)+pascal(c-i)
        c=c+1;
     end do
     c=c+3-1
  end do
  c=1;

  do i=1, 10
     do j=1, i
        write(*,'(i3, a, $)')pascal(c-1), ' '
        c=c+1;
     end do
     write(*,*)
  end do 


  ! END EDITING

end program q3
