module volmod
  implicit none
  contains 
    function dvolfunc(r) result(V)
      real(8), intent(in)::r
      real(8)::pi=acos(-1d0)
      real(8)::V
      V=4d0/3d0*pi*r**3
    end function dvolfunc
    subroutine dvolsub(r, V)
      real(8), intent(in)::r
      real(8)::pi=acos(-1d0)
      real(8), intent(out)::V
      V=4d0/3d0*pi*r**3
    end subroutine dvolsub
end module volmod
