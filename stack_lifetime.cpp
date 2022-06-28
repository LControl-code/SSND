#include <iostream>
#include <string>

class Entity {

  public:
    Entity() {
      std::cout << "Entity created" << std::endl;
    }
    ~Entity() {
      std::cout << "Entity destroyed" << std::endl;
    }
};

class ScopedPointer {
  private:
    Entity* m_Ptr;
  public:
  ScopedPointer (Entity* ptr): m_Ptr(ptr) {}

  ~ScopedPointer() {
    delete m_Ptr;
  }

};

int* CreateArray() {
  int* array = new int[50];
  return array;
}

int main() {

  // int* arr = CreateArray();
  {
    ScopedPointer scoped_entity = new Entity();
    Entity* entity = new Entity();
  }


  return 0;
}