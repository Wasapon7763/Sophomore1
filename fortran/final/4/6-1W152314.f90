program q6
  implicit none
  ! START EDITING
  integer:: i, j, k
  integer:: pascal(10, 10, 10)
  
  do i=1, 10
     do j=1, 10
        do k=1, 10
           pascal(i, j, k)=1d0
        end do
     end do
  end do

  do i=3, 10

     do j=1, i
        
        do k=1, j
           if ((k==1.or.k==j)) then
              pascal(i, j, k)=fact(i-1)/(fact(j-1)*fact(i-j))
           else
              pascal(i, j, k)=pascal(i-1, i, j-1)+pascal(i-1, i-1, j)+pascal(i-1, i, j)
           end if

        end do

     end do

  end do

  do i=1, 10
     write(*, '(a, i0)')'i = ', i
     do j=1, i

        do k=1, j
           write(*,'(i0, a, $)')pascal(i, j, k), ' '
        end do
        write(*,*)
        
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
end program q6
