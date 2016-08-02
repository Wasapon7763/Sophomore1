program q4
	implicit none
	integer :: m,n
	integer :: gcd, lcm
	write(*,'(A8,$)') 'Input m='
	read(*,*) m
	write(*,'(A8,$)') 'Input n='
	read(*,*) n

	call gcdlcm(m,n,gcd,lcm)

	write(*,*) 'gcd(m,n)=', gcd
	write(*,*) 'lcm(m,n)=', lcm

end program q4

subroutine gcdlcm(m,n,gcd,lcm)
  implicit none
  integer, intent(in)  :: m,n
  integer, intent(out) :: gcd,lcm
  
  ! START EDITING
  integer:: r, a, b
  a=m
  b=n
  do while (mod(a, b)/=0)
     r=mod(a, b)
     a=n
     b=r
  end do

  gcd=b
  lcm=(m*n)/gcd

! END EDITING
end subroutine gcdlcm
