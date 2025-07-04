#include <iostream>
#include "dibujo_lineas.h"

using namespace std;




void lineaSuperior(){
    for(int i = 0; i< 80; i++){
        if(i == 0){
            cout << (char)201;
        }else if(i == 79){
            cout << (char)187;
        }else{
            cout <<(char)205;
        }
    }
    cout << endl;
}


void lineaTitulo(){
    for(int i= 0; i<18; i++){
        if(i == 0){
            cout << (char)186;
        }else{

        cout <<(char)205;
        }
    };
    cout << " E   N   F   R   E   N   D   A   D   O   S ";
     for(int i= 0; i<19; i++){
        if(i == 18){
        cout << (char)186;
        }else{
        cout <<(char)205;
        }
    };
    cout << endl;
}

void lineaInferior(){
for(int i = 0; i< 80; i++){
        if(i == 0){
            cout << (char)200;
        }else if(i == 79){
            cout << (char)188;
        }else{
            cout <<(char)205;
        }
    }
    cout << endl;

}



void lineaMedio(){
    for(int i = 0; i< 80; i++){
        if(i == 0){
            cout << (char)186;
        }else if(i == 79){
            cout << (char)186;
        }else{
            cout <<(char)205;
        }
    }
    cout << endl;
}
