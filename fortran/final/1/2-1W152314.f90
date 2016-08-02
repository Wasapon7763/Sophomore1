program q2
  implicit none
  integer :: i,j
  
  ! START EDITING

  do i=0, 9
     do j=0, i
        write(*,'(i3, a, $)')fact(i)/(fact(j)*fact(i-j)), ' '
     end do
     write(*,*)
  end do

  contains
    function fact(n)
      integer, intent(in)::n
      integer :: u, fact
      fact=1
      do u=1, n
         fact=fact*u
      end do
    end function fact
    
  ! END EDITING
  
end program q2
