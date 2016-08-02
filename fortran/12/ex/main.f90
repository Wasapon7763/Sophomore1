program vol
  use volmod
  implicit none
  real(8)::r, V
  r=2d0
  V=dvolfunc(r)
  write(*,*)V
  call dvolsub(r, V)
  write(*,*)V
  stop
end program vol
