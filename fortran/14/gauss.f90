program gauss
  implicit none
  integer::i, j
  real(8)::a(3, 3)=reshape((/1, 2, -1, 0, 1, 3, 2, 3, -5/),(/3, 3/))
  real(8)::b(1:3)=(/-1, -1, 4/)
  !do i=1, 4
  !   do j=1, 4
  !      write(*,'(a, i0, a, i0, a, $)')"a(",i," ,",j,") = "
  !      read(*,*)a(i, j)
  !   end do
  !end do
  !do i=1, 4
  !   write(*,'(a, i0, a, $)')"b(", i, ") = "
  !   read(*,*)b(i)
  !end do
  call fe(a, b)
  call bs(a, b)
end program gauss

subroutine fe(a, b)
  integer::i, j, k
  real(8)::mult
  real(8), intent(inout)::a(3, 3)
  real(8), intent(inout)::b(1:3)
  write(*,'(a)')"Foward Elimination"
  do i=1, 3
     call piv(i)
     do j=i+1, 4
        mult=a(j, i)/a(i, i)
        do k=1, 4
           a(j, k)=a(j, k)-mult*a(i, k)
        end do
        b(j)=b(j)-mult*b(i)
        call disp(a, b)
     end do
  end do

  contains

    subroutine piv(n)
      integer::u, max, n
      real(8)::temp
      max=n
      do u=n, 4
         if (a(u, n)>a(max, n)) max=u
      end do
      do u=n, 4
         temp=a(max, u)
         a(max, u)=a(n, u)
         a(n, u)=temp
      end do
      temp=b(n)
      b(n)=b(max)
      b(max)=temp
    end subroutine piv

end subroutine fe

subroutine bs(a, b)
  integer::i, j, k
  real(8)::mult
  real(8), intent(inout)::a(3, 3)
  real(8), intent(inout)::b(1:3)
  write(*,'(a)')"Backward Substitution"
  do i=4, 1, -1
     b(i)=b(i)/a(i, i)
     mult=b(i)
     a(i, i)=1d0
     do j=1, i-1
       b(j)=b(j)-mult*a(j, i)
       a(j, i)=0d0
    end do
    call disp(a, b)
  end do
end subroutine

subroutine disp(a, b)
  integer::i, j
  real(8), intent(in)::a(3, 3)
  real(8), intent(in)::b(1:3)
  do i=1, 4
     do j=1, 4
        write(*,'(f10.3, a, $)')a(i, j), " "
     end do
     write(*,'(f10.3)')b(i)
  end do
  write(*,*)
end subroutine disp
