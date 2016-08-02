program ex3
  implicit none
  integer::i, j, l
  integer::n, k, comb, prev
  do i=0, 19
     prev=1
     do j=0, 19-j
        write(*,'(a, $)')'   '
     end do
     write(*,'(i5, a, $)')prev, '  '
     do j=1, i
        write(*,'(i5, a, $)')comb(i, j, prev), ' '
        prev=comb(i, j, prev)
     end do
     write(*,*)
  end do
end program ex3
integer function comb(n, k, prev)
  implicit none
  integer, intent(in)::n, k, prev
  comb=prev*(n-k+1)/k
end function comb
