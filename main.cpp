#include <iostream>

using namespace std;
class Stack{
private:
  int* p ; // allouer de la mémoire pour un élément
  int top; // contient l’indice du dernier élément ajouté à la pile
  int capacity; // capacite du stack


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
  Stack(const Stack& st):capacity(st.capacity), top(st.top){
    p = new i nt[capacity];
    for (int i=0;i<top;i++){
      p[i] = st.p[i];
    }
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
  int tab [] = {1,6,7,87,8};
  Stack st2(tab, 5);
  st2.print();
      
return 0;
}