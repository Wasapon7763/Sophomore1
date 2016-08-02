program func
  implicit none
  integer ::i, j
  write(*,'(a, $)')"input i->"
  read(*,*)i
  j=square(i)
  write(*,'(a, i0)')'i square is ', j
  stop
  contains
    function square(i)
      integer, intent(in) :: i
      integer ::square
      square=i*i
    end function square
end program func
