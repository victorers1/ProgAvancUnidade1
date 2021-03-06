#include "screen.h"
#include <vector>

Screen::Screen(){

}

void Screen::dim(int x, int y){
    int i,j;
    this->nlin = x;
    this->ncol = y;
    //dimencionando mat
    mat.resize(x);
    for(i=0; i<x; i++){
        mat[i].resize(y);
    }
    //preenchimento inicial
    for(i=0; i<x; i++){
        for(j=0; j<y; j++){
            mat[i][j] = ' '; //espaços vazios
        }
    }
}

int Screen::getLin(){
    return nlin;
}

int Screen::getCol(){
    return ncol;
}

void Screen::setPixel(int x, int y){
    mat[x][y] = brush;
}

void Screen::clear(){
    for(int i=0; i<nlin; i++){
        for(int j=0; j<ncol; j++){
            mat[i][j] = ' ';
        }
    }
}

void Screen::setBrush(char brush){
    this->brush = brush;
}

ostream &operator<<(ostream &os, Screen &t){

    for(int i=0; i<t.nlin; i++){
        for(int j=0; j<t.ncol; j++){
            os<<t.mat[i][j]<<' ';
        }
        os<<endl;
    }
    /*este metodo não convém nesse caso
    vector<char>::iterator it;
    for(it = t.mat.begin(); it = t.mat.end(); it++){
        os<<*it<<' ';
    }*/
}
