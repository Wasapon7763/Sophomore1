program gauss
  implicit none
  integer::i, j
  real(8)::a(3, 3)!=reshape((/2, 3, 5, 4, 8, 7, 6, 7, 21/),(/3, 3/))
  real(8)::b(1:3)!=(/6, 15, 24/)
  do i=1, 3
     do j=1, 3
        write(*,'(a, i0, a, i0, a, $)')"a(",i," ,",j,") = "
        read(*,*)a(i, j)
     end do
  end do
  do i=1, 3
     write(*,'(a, i0, a, $)')"b(", i, ") = "
     read(*,*)b(i)
  end do
  call fe(a, b)
  call bs(a, b)
end program gauss

subroutine fe(a, b)
  integer::i, j, k
  real(8)::mult
  real(8), intent(inout)::a(3, 3)
  real(8), intent(inout)::b(1:3)
  write(*,'(a)')"Foward Elimination"
  do i=1, 2
     do j=i+1, 3
        mult=a(j, i)/a(i, i)
        do k=1, 3
           a(j, k)=a(j, k)-mult*a(i, k)
        end do
        b(j)=b(j)-mult*b(i)
        call disp(a, b)
     end do
  end do
end subroutine fe

subroutine bs(a, b)
  integer::i, j, k
  real(8)::mult
  real(8), intent(inout)::a(3, 3)
  real(8), intent(inout)::b(1:3)
  write(*,'(a)')"Backward Substitution"
  do i=3, 1, -1
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
  do i=1, 3
     do j=1, 3
        write(*,'(f10.3, a, $)')a(i, j), " "
     end do
     write(*,'(f10.3)')b(i)
  end do
  write(*,*)
end subroutine disp
