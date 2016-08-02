program a
  implicit none
  integer:: n
  n=1
  n=addone(n)
  write(*,*)n
  call subone(n)
  write(*,*)n
  contains
    integer function addone(a)
      integer, intent(in)::a
      addone=a+1
    end function addone    
end program a

subroutine subone(a)
  integer, intent(inout):: a
  a=a-1
end subroutine subone
