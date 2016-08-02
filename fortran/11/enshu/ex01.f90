program ex01
  implicit none
  integer, external::isprime
  integer::num, boo
  common/chekingnumber/num
  num=2**16+1
  write(*,*)num
  call isprime2(boo, num)
  if (boo==1) then
     write(*,*)"prime"
  else
     write(*,*)"not prime"
  end if
end program ex01
integer function isprime()
  implicit none
  integer::i
  integer::num
  common/chekingnumber/num
  isprime=1
  do i=2, num-1
     if (mod(num, i)==0) then
        isprime=0;
     end if
  end do
end function isprime
subroutine isprime2(boo, num)
  integer::i
  integer, intent(in)::num
  integer, intent(out)::boo
  boo=1
  do i=2, num-1
     if (mod(num, i)==0) then
        write(*,*)i
        boo=0;
     end if
  end do
end subroutine isprime2
