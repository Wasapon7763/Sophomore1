program ex02
  implicit none
  integer ::i, j
  real (8)::A(3,3)
  real (8)::B(3,3)
  real (8)::C(3,3)
  A=reshape((/(i, i=1, 9)/), (shape(A)))
  B=reshape((/(i, i=1, 9)/), (shape(B)))
  do i=1, 3
     do j=1, 3
        C(i, j)=A(i, j)*B(i, j)
     end do
  end do
  write(*,*)C
end program ex02
