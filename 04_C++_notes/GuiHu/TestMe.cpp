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


template <typename Tipo>
class Pilha{
    public:
        Pilha(): atual(0) { } // inicialização na lista de inicialização, é mais eficiente do que fazer dentro do corpo do construtor; ou você pode fazer {atual = 0}, mas para classes num geral é pior    
        void empilha( const Tipo& valor ){ // o parâmetro valor de empilha se adapta ao tipo usado; const ref porque pilha de pilha pode ser grantde
            tab[atual++] = valor;
        }
        Tipo desempilha(){         // o retorno do desempilha tambem
            return tab[--atual];
        }

    private:
        const static int MAX_PILHA = 10; // const static para ser uma constante de classe, ou seja, compartilhada por todas as instâncias da classe
        Tipo tab[MAX_PILHA]; // o tipo do vetor se adapta ao tipo usado
        int atual;
};

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


    Pilha<int> p1;
    Pilha<double> p2;
    Pilha< Pilha<int> > p3;

    p1.empilha(8);
    p2.empilha(11.5);
    p3.empilha(p1); // não é possível empilhar p2 pois isso é uma pilha de pilhas Instância


}

// g++ TestMe.cpp -o TestMe
// ./TestMe.exe
