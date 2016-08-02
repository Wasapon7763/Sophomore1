program ex2
  implicit none
  integer :: a
  real (8):: sina, cosa, tana, pi
  pi=acos(-1.0)
  write(*,'(a,3x,a,7x,a,7x,a)')"angle","sin","cos","tan"
  DO a=0,180,10
     sina=sin(real(a)*pi/180)
     cosa=cos(real(a)*pi/180)
     tana=tan(real(a)*pi/180)
     if (a/=90) then
        write(*,"(i5, 1x, f10.6, f10.6, f10.6)")a, sina, cosa, tana
     else
        write(*,"(i5, 1x, f10.6, f10.6)")a, sina, cosa
     end if
  END DO
  stop
end program ex2
