program ex01
  implicit none
  real (8) :: h,w,b
  write(*,'(a,$)')'Input the height (cm) and weight (kg) -> '
  read (*,*)h,w
  h=h/100;
  b=w/(h*h)
  write(*,'(a,f0.1,a,$)')'BMI -> ',b,','
  if (b<18.5) then
     write(*,'(a)')' Underweight'
  else if (18.5<=b.and.b<25) then
     write(*,'(a)')' Normal'
  else if (25<=b.and.b<30) then
     write(*,'(a)')' Overweight'
  else
     write(*,'(a)')' Obese'
  end if
  stop
end program ex01
