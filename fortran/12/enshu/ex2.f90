program ex2
  implicit none
  integer::i, j, l
  integer::n, k, comb
  do i=0, 9
     do j=0, 9-i
        write(*,'(a, $)')'  '
     end do
     do j=0, i
        write(*,'(i3, a, $)')comb(i, j),' '
     end do
     write(*,*)
  end do
end program ex2
integer function comb(n, k)
  implicit none
  integer, intent(in)::n, k
  comb=fact(n)/(fact(k)*fact(n-k))
  contains 
    function fact(n)
      integer::i, fact
      integer, intent(in)::n
      fact=1
      do i=1, n
         fact=fact*i
      end do
    end function fact
end function comb
