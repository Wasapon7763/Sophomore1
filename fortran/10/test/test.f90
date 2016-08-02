program test
  implicit none
  integer ::n
  real (8)::x, ex
  write(*,'(a, $)')"Input n:"
  read(*,*)n
  write(*,'(a, $)')"Input x:"
  read(*,*)x
  call taylor(n, x, ex)
  write(*,'(a,f20.10)')"e^x=",ex
end program test
subroutine taylor(n, x, ex)
  integer::i
  integer, intent(in)::n
  real (8), intent(in)::x
  real (8), intent(out)::ex
  ex=0
  do i=0, n
     ex=ex+x**i/fact(i)
  end do
contains
  real (8) function fact(i)
    integer, intent(in)::i
    integer::j
    fact=1
    do j=1, i
       fact=fact*real(j)
    end do
  end function fact
end subroutine taylor
