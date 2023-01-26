template<typename T>
class Container{
private:
  T element;
public:
  Container(const T element_in) : element(element_in) {}

  T increment(){
    return ++element;
  }
};

template<>
class Container<char>{
private:
  char element;
public:
  Container(const char element_in) : element(element_in) {}
  char uppercase(){
    return toupper(element);
  }
};