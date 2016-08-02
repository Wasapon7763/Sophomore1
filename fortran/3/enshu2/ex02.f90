program ex02
  implicit none
  real (8) :: a, e, b=0
  write(*,'(a,$)')'Input the contract ampere capacity : '
  read(*,*)a
  write (*,'(a,$)')'Input electricity consumption : '
  read(*,*)e
  if (a==10) then
     b=b+273
  else if (a==15) then
     b=b+409.5
  else if (a==20) then
     b=b+546
  else if (a==30) then
     b=b+819
  else if (a==40) then
     b=b+1092
  else if (a==50) then
     b=b+1365
  else if (a==60) then
     b=b+1638
  end if
  if (e<120) then
     b=b+(17.87*e)
  else if (120<=e.and.e<=300) then
     b=b+(22.86*e)
  else
     b=b+(24.13*e)
  end if
  write(*,'(a,i0,a)')'Electricity bill : ',int(b),' yen'
  stop
end program ex02
