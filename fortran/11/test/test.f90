program test
  implicit none
  integer::i, num(0:2)
  call input3(num)
  write(*,'(a, $)')"Output   : "
  do i=0, 2
     write(*,'(i0, a, $)')num(i), " "
  end do
  write(*,*)""
  call order3(num)
  write(*,'(a, $)')"Output   : "
  do i=0, 2
     write(*,'(i0, a, $)')num(i), " "
  end do
  write(*,*)""
end program test
subroutine input3(num)
  implicit none
  integer::i
  integer, intent(out)::num(0:2)
  do i=0, 2
     write(*,'(a, i0, a, $)')"Input #", i, " : "
     read(*,*)num(i)
  end do
end subroutine input3
subroutine order3(num)
  implicit none
  integer::i, j, hoge
  integer, intent(inout)::num(0:2)
  write(*,'(a)')"Sorted"
  do i=0, 2
     do j=1, 2
        if (num(j-1)>num(j)) then
           hoge=num(j-1)
           num(j-1)=num(j)
           num(j)=hoge
        end if
     end do
  end do
end subroutine order3
