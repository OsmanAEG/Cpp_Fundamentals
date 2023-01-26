class int_arr{
public:
  int* data;
  int size;

  int_arr(int size){
    data = new int[size];
    this->size = size;
  }

  ~int_arr(){delete[] data;}

  // deep copy - copy construtor
  int_arr(int_arr &o){
    data = new int[o.size];
    size = o.size;

    for(int i = 0; i < size; ++i){
      data[i] = o.data[i];
    }
  }
};