program ex02
  implicit none
  real(8) ::a, b, c, s
  write(*,'(a,$)')'a='
  read(*,*)a
  write(*,'(a,$)')'b='
  read(*,*)b
  write(*,'(a,$)')'c='
  read(*,*)c
  s=getarea(a, b, c, (a+b+c)/2)
  write(*,'(f10.6)')s
  stop
contains
  function getarea(a, b, c, p)
    implicit none
    real(8) ::a, b, c, p, s
    real(8) ::getarea
    getarea=sqrt(p*(p-a)*(p-b)*(p-c))
  end function getarea
end program ex02
