program ex01
  implicit none
  real (8)::a, b, c, s
  write(*,'(a, $)')"a->"
  read(*,*)a
  write(*,'(a, $)')"b->"
  read(*,*)b
  write(*,'(a, $)')"c->"
  read(*,*)c
  call getArea(a, b, c, s)
  write(*,'(f10.6)')s
  stop
  contains
    subroutine getArea(a, b, c, s)
      implicit none
      real (8)::p
      real (8), intent(in)::a, b, c
      real (8), intent(out)::s
      p=(a+b+c)/2
      s=sqrt(p*(p-a)*(p-b)*(p-c))
      return
    end subroutine
end program ex01
