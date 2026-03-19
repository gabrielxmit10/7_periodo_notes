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
        for (int i ; i < p.atual ; i++){
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

// void imprime (PilhaInt p){
// }

ostream& operator << ( ostream& o, const PilhaInt& p){

    p.imprime( o );

    return o;
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
    
}