#include <iostream>

using namespace std;

const int MAX_PILHA = 10;

class PilhaInt
{ 
  public:

    PilhaInt() { // PilhaInt sth;
      for( int i = 0; i < MAX_PILHA; i++ )
        tab[i] = 0;
      atual = 0;
    } 

    PilhaInt( const PilhaInt& p ) { // construtor de cópia -> PilhaInt sth = p;
        atual = p.atual;
        for (int i = 0; i < p.atual; i++){
            tab[i] = p.tab[i];
        }
    }
    
    void empilha( int valor ){
        tab[atual++] = valor;
    }
    
    int desempilha(){
        return tab[--atual];
    }

    const PilhaInt& operator = ( const PilhaInt& p ){ // Cópia -> sth = p
        if (this != &p) {
            atual = p.atual;
            for (int i=0 ; i < p.atual ; i++){
                tab[i] = p.tab[i];
            }    
        }
        return p;
    }

    PilhaInt& operator << (int valor) {
        empilha(valor);
        return *this; // DÚVIDA: como funciona esse *
    }
    
    void imprime( ostream& o ) const { // const aqui indica que o this é cte
        for ( int i = 0 ; i < atual ; i++ ){
            o << tab[i] << " ";
        }
    }

  private:
    int tab[MAX_PILHA];
    int atual;
};

ostream& operator << ( ostream& o, const PilhaInt& p){
    p.imprime( o );
    return o;
}


template <typename T> // class <=> typename
    inline const T& Max (const T& a, const T& b){ // inline é para não chamar função, e sim colocar direto no código -> se fiver um for não vai fazer inline
        // const ref para não fazer uma cópia desnecessária, se os objetos são pequenos, não precisa
        return a > b ? a : b;
    }


int main(){
    PilhaInt q;
    q.empilha(5);

    PilhaInt p;
    // p.empilha(3);

    p = q;

    q.empilha(7);
    
    cout << p << endl;
    cout << q << endl;
    

    cout << Max(3,5) << endl;         
    cout << Max<int>(3.14, 2.71) << endl;  
    cout << Max<double>(3.14, 4) << endl;  
    cout << Max("abc", "xyz") << endl;

}

// g++ TestMe.cpp -o TestMe
// ./TestMe.exe
