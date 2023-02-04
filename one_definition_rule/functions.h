template<typename Scalar_type>
auto square(Scalar_type x){
  return x*x;
}

template<typename Scalar_type>
auto cube(Scalar_type x){
  return square(x)*x;
}