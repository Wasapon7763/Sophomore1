program reidai
  implicit none
  integer ::i, j, k
  i=10;
  call addtime(i, j, k)
  write(*,'(i0, a, i0, a, i0)')i, ' ', j, ' ', k
  stop
  contains
    subroutine addtime(i, j, k)
      integer, intent(in) ::i
      integer, intent(out)::j, k
      j=i+10
      k=i*10
    end subroutine
end program reidai
