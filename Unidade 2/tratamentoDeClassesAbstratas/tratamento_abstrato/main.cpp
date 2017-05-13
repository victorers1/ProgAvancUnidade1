#include <iostream>
#include <fstream>
#include <cstring>

#include "figurageometrica.h"
#include "circulo.h"
#include "reta.h"
#include "retangulo.h"


using namespace std;

int main(void){
    ifstream entra;
    ofstream saida;
    Screen tela;
    char comando[10];


    int x0,y0, x1,y1, l, a, r; //ponto 0, ponto 1, largura, altura e raio
    bool fillmode; //preenchimento do circulo
    char b; //pincel
    entra.open("C:/Users/Suporte/Downloads/DCA1202-programacaoAvancada-master/Unidade 2/tratamentoDeClassesAbstratas/tratamento_abstrato/comandos.txt");
    if(!entra.is_open()){
        cout<<"nao abriu arquivo\n";
        exit(0);
    }

    entra>>comando;


    while(entra){ //enquanto a leitura não retornar
        if(!strcmp("rectangle", comando)){

            entra>>x0>>y0>>l>>a;
            Retangulo ret(x0,y0, l, a);
            ret.draw(tela);
            cout<<"Retangulo com vertice em : ("<<x0 <<", "<< y0<<"); largura: "<< l << " e altura: "<< a <<endl;

        } else if(!strcmp("circle", comando)){

            entra>>x0>>y0>>r>>fillmode;
            Circulo cir(x0,y0, r, fillmode);
            cir.draw(tela);

        } else if(!strcmp("line", comando)){

            entra>>x0>>y0>>x1>>y1;
            Reta reta(x0,y0,x1,y1);

        } else if(!strcmp("brush", comando)){

            entra>>b;
            tela.setBrush(b);
            cout<<"Pincel: "<<b<<endl;

        } else if(!strcmp("dim", comando)){

            entra>>x0>>y0;
            tela.dim(x0,y0);
            cout<<"dimensao: "<<x0<<" "<<y0<<endl;
        }
        entra>>comando;
    }
    entra.close();

    saida.open("C:/Users/Suporte/Downloads/DCA1202-programacaoAvancada-master/Unidade 2/tratamentoDeClassesAbstratas/tratamento_abstrato/desenho.txt");
    if(!saida.is_open()){
        cout<<"nao abriu arquivo\n";
        exit(0);
    }
    saida<<tela;

    saida.close();
    return 0;
}