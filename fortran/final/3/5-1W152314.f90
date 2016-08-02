program q5
  implicit none
  integer :: n
  
  write(*,'(A8,$)') 'Input n='
  read(*,*) n
  write(*,*) 'S=', integral(0.0, 1.0, n);
  
contains
  
  real function func(x)
    implicit none
    real, intent(in) :: x
    func = sqrt(x*x+1.0)
    return
  end function func
  
  real function integral(a,b,n)
    implicit none

    ! START EDITING
    integer:: i
    integer, intent(in):: n
    real, intent(in):: a, b
    real:: h, sum, x
    h=(b-a)/n
    sum=0
    do i=0, n
       x=a+h*i
       if ((i==0).or.(i==n)) then
          sum=sum+func(x)
       else
          sum=sum+2*func(x)
       end if
    end do
    integral=(h*sum)/2
  
    ! END EDITING
    return
  end function integral
  
end program q5
