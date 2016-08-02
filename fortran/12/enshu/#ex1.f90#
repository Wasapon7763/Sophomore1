program ex1
  implicit none
  integer::i, j, count
  integer::pascal(1:55)
  pascal(:)=1d0;
  count=5
  do i=3, 10
     do j=2, i-1
        pascal(count)=pascal(count-i)+pascal(count-i+1)
        count=count+1;
     end do
     count=count+3-1
  end do
  count=1;
  do i=1, 10
     do j=1, 10-i
        write(*,'(a, $)')'  '
     end do
     do j=1, i
        write(*,'(i3, a, $)')pascal(count), ' '
        count=count+1;
     end do
     write(*,*)
  end do
end program ex1
