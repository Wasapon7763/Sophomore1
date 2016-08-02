module pascal
  implicit none
contains
  integer function comb(n, k, prev)
    integer, intent(in)::n, k, prev
    comb=prev*(n-k+1)/k
  end function comb
end module pascal
