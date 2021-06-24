/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * @file: imagen.h
 * @brief: implementacion del TDA imagen
 * @author: Elena Ortega, Alberto Llamas
 *
 */

#include "imagen.h"
#include <cassert>
#include <iostream>

void Imagen::Copiar(const Imagen &I){
    assert(I.filas==filas && I.cols==cols);
    for(int i=0; i<filas; i++)
        for(int j=0; j<cols; j++)
            img[i][j]=I.img[i][j];
}

void Imagen::Borrar(){
    if(img!=0){
        delete[] img[0];
        delete[] img;
    }
    filas=cols=0;
    img=0;
}


void Imagen::Reservar(int filas, int cols){
    assert(filas>=0 && cols >= 0);
    this->filas=filas;
    this->cols=cols;
    if (filas>0 && cols > 0){
        img=new byte*[filas];
        img[0]=new byte [filas*cols];
        for (int i=1; i<filas;i++)
            img[i]=img[i-1]+cols;
    }
    else
        img=0;
}


Imagen::Imagen() {
    filas = 0;
    cols = 0;
    img = 0;
}

Imagen::Imagen(int nf, int nc){
    Reservar(nf,nc);
}

Imagen::Imagen(const Imagen &I) {
    Reservar(I.numfilas(), I.numcolumnas());
    Copiar(I);
}

Imagen::~Imagen() {
    Borrar();
}

Imagen & Imagen::operator=(const Imagen &I){
    if (this != &I){
        Borrar();
        Reservar(I.filas,I.cols);
        Copiar(I);
    }
    
    return (*this);
}

void Imagen::asigna_pixel(int f, int c, byte v){
    assert(f>=0 && f<=filas-1 && c>=0 && c<=cols-1 && 0<=v && v<=255);
    img[f][c]=v;
}

byte Imagen::get_pixel(int f, int c) const{
    assert(f>=0 && f<=filas-1 && c>=0 && c<=cols-1);
    return img[f][c];
}

byte & Imagen::operator()(int i, int j){
    assert(i>=0 && i<=filas-1 && j>=0 && j<=cols-1);
    return img[i][j];
}

const byte & Imagen::operator()(int i, int j) const{
    assert(i>=0 && i<=filas-1 && j>=0 && j<=cols-1);
    return img[i][j];
}

bool Imagen::CargarImagen(const char * nombre){
    TipoImagen t = LeerTipoImagen (nombre);
    if (t==IMG_PGM){
        int f,c;
        unsigned char *buf=LeerImagenPGM(nombre,f,c);
        if (buf!=0){
            Imagen aux(f,c);
            for (int i=0;i<f;i++)
                for (int j=0;j<c;j++){
                    aux(i,j)=buf[i*c+j];
                }
            delete[]buf;
            *this=aux;
            return true;
        }
        else{
            std::cout << "No se ha podido cargar la imagen " << std::endl;
            return false;
        }
    }
    else{
        std::cout << "Formato de imagen incorrecto " << std::endl;
        return false;
    }
}

bool Imagen::SaveImagen(const char * nombre){
    TipoImagen t = LeerTipoImagen (nombre);
//    if (t==IMG_PGM){
        unsigned char *buf = new unsigned char[filas*cols];
        for (int i=0;i<filas;i++)
            for (int j=0;j<cols;j++){
                buf[i*cols+j]=img[i][j];
            }
    
        bool resultado=EscribirImagenPGM(nombre, buf, filas, cols);
        if(buf!=0 && resultado==true){
            delete[]buf;
            return true;
        }
        else{
            delete[] buf;
            std::cout << "No se ha podido guardar la imagen " << std::endl;
            return false;
        }  
}
 
