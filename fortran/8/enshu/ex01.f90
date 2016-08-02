program ex01
  implicit none
  integer :: i
  real (8):: A(3,3)
  real (8):: B(3,3)
  real (8):: C(3,3)
  A=reshape((/(i, i=1, 9)/), (shape(A)))
  B=reshape((/(i, i=1, 9)/), (shape(B)))
  C=A*B
  write(*,*)C
  stop
end program ex01
