program gauss
  implicit none
  integer::i, j
  real(8)::eq(3, 3)!=reshape((/2, 3, 5, 4, 8, 7, 6, 7, 21/),(/3, 3/))
  real(8)::num(1:3)!=(/6, 15, 24/)
  do i=1, 3
     do j=1, 3
        write(*,'(a, i0, a, i0, a, $)')"eq(",i," ,",j,") = "
        read(*,*)eq(i, j)
     end do
  end do
  do i=1, 3
     write(*,'(a, i0, a, $)')"num(", i, ") = "
     read(*,*)num(i)
  end do
  call fe(eq, num)
  call bs(eq, num)
end program gauss
subroutine fe(eq, num)
  integer::i, j, k
  real(8)::mult
  real(8), intent(inout)::eq(3, 3)
  real(8), intent(inout)::num(1:3)
  write(*,'(a)')"Foward Elimination"
  do i=1, 2
     do j=i+1, 3
        mult=eq(j, i)/eq(i, i)
        do k=1, 3
           eq(j, k)=eq(j, k)-mult*eq(i, k)
        end do
        num(j)=num(j)-mult*num(i)
        call disp(eq, num)
     end do
  end do
end subroutine fe
subroutine bs(eq, num)
  integer::i, j, k
  real(8)::mult
  real(8), intent(inout)::eq(3, 3)
  real(8), intent(inout)::num(1:3)
  write(*,'(a)')"Backward Substitution"
  do i=3, 1, -1
     num(i)=num(i)/eq(i, i)
     mult=num(i)
     eq(i, i)=1d0
     do j=1, i-1
       num(j)=num(j)-mult*eq(j, i)
       eq(j, i)=0d0
    end do
    call disp(eq, num)
  end do
end subroutine
subroutine disp(eq, num)
  integer::i, j
  real(8), intent(in)::eq(3, 3)
  real(8), intent(in)::num(1:3)
  do i=1, 3
     do j=1, 3
        write(*,'(f10.3, a, $)')eq(i, j), " "
     end do
     write(*,'(f10.3)')num(i)
  end do
  write(*,*)
end subroutine disp
