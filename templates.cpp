#include <iostream>

  template<typename Type>
void Print(Type value) {
  std::cout << value << std::endl;
}

template<typename T, int N>

class Array {
  private:
  T m_Array[N];

  public:
  int GetSize() 
    const { return N;}
  
  T Get(int index) 
    const { return m_Array[index];}

  void Set(int index, T value) {
    m_Array[index] = value;
  }
};

int main(){
  Array<int, 5> array;
  std::cout << array.GetSize() << std::endl;
  array.Set(0, 10);
  std::cout<< array.Get(0) << std::endl;

  array.Set(6, 15);
  std::cout<< array.Get(6) << std::endl; // should throw an exception, but works?

  // Print(5);
  // Print(5.0f);
  // Print("Hello");
  // Print(3.5f);



}