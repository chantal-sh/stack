#include <iostream>

using namespace std;
class Stack{
private:
  int* p ; // allouer de la mémoire pour un élément
  int top; // contient l’indice du dernier élément ajouté à la pile
  int capacity; // capacite du stack
 void resizeStack(int new_max){
      int* new_p = new int[new_max];
    for (int i = 0; i <= top; ++i) {
        new_p[i] = p[i];
    }
    delete[] p;
    p = new_p;
    capacity = new_max;
    cout << "Stack is resized. Maximal Capacity is " << new_max << std::endl;
}
 

public:
  Stack(int capacity, int top = -1):capacity(capacity), top(top),p(new int[capacity]){
    cout << "Objet Stack cree" << endl;
  }
  Stack(int tab[], int n){
    p = new int[n];
    capacity = n;
    top = n-1;
    for (int i = 0; i< n;i++){
       p[i] = tab[i];
    }
  }
  ~Stack(){delete[] p; p = nullptr;}
  void push(int value){
      if (top >= capacity - 1) {
        resizeStack(capacity * 2);
    }
    top++;
    p[top] = value;
    std::cout << value << " is pushed to stack" << std::endl;
}

  void print(){
    if (top == -1){
        cout << "Stack empty" << endl;
    }
    else{
       cout << "Stack contains:" << endl;
    for (int i = 0; i <= top; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;
    }
   
  }


};


int main(){
  Stack st1(1);
  st1.print();
  st1.push(8);
  st1.push(7);
  st1.print();
  int tab [] = {1,6,7,87,8};
  Stack st2(tab, 5);
  st2.print();
return 0;
}