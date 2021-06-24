/**
 * @file rutasaereas.cpp
 * @author Alberto Llamas, Elena Ortega
 * @date Enero 2021
 */
#include "Imagen.h"
#include "Almacen_Rutas.h"
#include "Paises.h"
#include "Punto.h"
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

/** 
 * @brief Obtiene una nueva imagen que es la versión rotada de una imagen de entrada
 * @param Io: imagen de entrada
 * @param angulo: angulo a rotar la imagen de entrada. Debe estar en radianes.
 * @return Una nueva imagen que es la versión rotada de Io.
 * */
void Pintar(int f1, int f2, int c1, int c2, Imagen &I, const Imagen &avion, int mindisf, int mindisc);

/** 
 * @brief Obtiene una nueva imagen que es la versión rotada de una imagen de entrada
 * @param Io: imagen de entrada
 * @param angulo: angulo a rotar la imagen de entrada. Debe estar en radianes.
 * @return Una nueva imagen que es la versión rotada de Io.
 * */
Imagen Rota(const Imagen &Io, double angulo);

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cout << "Los parametros son:" << endl;
        cout << "1.-Fichero con la informacion de los paises" << endl;
        //cout << "2.-Nombre de la imagen con el mapa del mundo" << endl;
        cout << "2.-Directorio con las banderas" << endl;
        cout << "3.-Fichero con el almacen de rutas" << endl;

        exit(-1);
    }
    Paises Pses;
    ifstream f(argv[1]);
    f >> Pses;
    cout << "\nSe ha abierto el fichero con la información de los países:" << endl;
    cout << Pses;

    //Leemos el mapa    
    Imagen I;
    int opcion_mapa; char *modelo_mapa;
    cout << "\nElige tu mapa (1--> mapa1.ppm // 2--> mapa2.ppm): ";
    cin >> opcion_mapa;
    switch (opcion_mapa){
        case 1:
			modelo_mapa = "datos/imagenes/mapas/mapa1.ppm";
            break;
        case 2:
			modelo_mapa = "datos/imagenes/mapas/mapa2.ppm";
            break;
        default:
            modelo_mapa = "datos/imagenes/mapas/mapa1.ppm";
    }

    I.LeerImagen(modelo_mapa);
    cout << "\nSe ha leido el mapa correctamente" << endl;

    //Leemos el avion
    Imagen avion;
    int opcion_avion; char *modelo_avion; string mascara;
    cout << "\nElige tu avion (1-6): ";
    cin >> opcion_avion;
    switch (opcion_avion){
        case 1:
			modelo_avion = "datos/imagenes/aviones/avion1.ppm";
            mascara = "datos/imagenes/aviones/mascara_avion1.pgm";
            break;
        case 2:
			modelo_avion = "datos/imagenes/aviones/avion2.ppm";
            mascara = "datos/imagenes/aviones/mascara_avion2.pgm";
            break;
        case 3:
			modelo_avion = "datos/imagenes/aviones/avion3.ppm";
            mascara = "datos/imagenes/aviones/mascara_avion3.pgm";
            break;
        case 4:
			modelo_avion = "datos/imagenes/aviones/avion4.ppm";
            mascara = "datos/imagenes/aviones/mascara_avion4.pgm";
            break;
        case 5:
			modelo_avion = "datos/imagenes/aviones/avion5.ppm";
            mascara = "datos/imagenes/aviones/mascara_avion5.pgm";
            break;
        case 6:
			modelo_avion = "datos/imagenes/aviones/avion6.ppm";
            mascara = "datos/imagenes/aviones/mascara_avion6.pgm";
            break;
        default:
            modelo_avion = "datos/imagenes/aviones/avion2.ppm";
            mascara = "datos/imagenes/aviones/mascara_avion2.pgm";
    }
    
    avion.LeerImagen(modelo_avion,mascara);
    cout << "\nSe ha leido el avion correctamente" << endl;

    Almacen_Rutas Ar;
    f.close();
    f.open(argv[3]);
    cout << "\nSe ha abierto almacen de rutas correctamente:" << endl;
    f >> Ar;
    cout << "Las rutas: " << endl
         << Ar;
    cout << "\nDime el codigo de una ruta" << endl;
    string ruta_escogida;
    cin >> ruta_escogida;
    Ruta R = Ar.GetRuta(ruta_escogida);
    cout << "\n\nInformacion de la ruta " << R.getCode() << " :"<< endl;
    cout << R;

    string directorio_banderas = argv[2];
    Ruta::iterator it_ruta_p1 = R.begin(), it_anterior;
    Paises::iterator it_pais_actual;
    Paises::iterator it_pais_anterior;
    it_pais_actual = it_pais_anterior = Pses.end();

    cout << "\n\nLa ruta " << R.getCode() << " pasa por los paises:"<< endl;

    while (it_ruta_p1 != R.end())
    {
        //Guardo el punto actual
        Punto punto_actual = (*it_ruta_p1);
        //Busco los paises correspondientes a los puntos
        it_pais_anterior = it_pais_actual;
        it_pais_actual = Pses.find(punto_actual);

        //Leo la bandera del directorio (bandera del pais actual)
        Imagen bandera;

        string pathBanderas = directorio_banderas + (*it_pais_actual).GetBandera();
        bandera.LeerImagen(pathBanderas.c_str());

        //Mostramos el pais actual tal como nos pide el guion
        cout << " --> " << (*it_pais_actual).GetPais() ;

        //Trasladamos la posicion del pais actual al mapa (Para pintar los aviones y la ultima bandera)
        int i_lat = (int)((I.num_filas() / 180.0) * (90 - punto_actual.getLatitud()));
        int j_long = (int)((I.num_cols() / 360.0) * (180 + punto_actual.getLongitud()));

        if (it_pais_anterior != Pses.end())
        {
            //Calculamos la posicion del pais anterior
            int i_lat_anterior = (int)((I.num_filas() / 180.0) * (90 - (*it_anterior).getLatitud()));
            int j_long_anterior = (int)((I.num_cols() / 360.0) * (180 + (*it_anterior).getLongitud()));
            //Pintamos la ruta del avion del pais inicial al final
            Pintar(i_lat_anterior - avion.num_filas() / 2, i_lat - avion.num_filas() / 2, j_long_anterior - avion.num_cols() / 2, j_long - avion.num_cols() / 2, I, avion, 50, 50);
        }

        //Ponemos en el mapa la bandera
        I.PutImagen(i_lat - bandera.num_filas() / 2, j_long - bandera.num_cols() / 2, bandera, BLENDING);

        //Guardamos la posicion del punto anterior para despues utilizarlo para pintar el avion
        it_anterior = it_ruta_p1;
        ++it_ruta_p1;
    }

    string imagenSalida = ruta_escogida + ".ppm";
    cout << "\n\nGenerando la nueva imagen con la ruta indicada..." << endl;
    I.EscribirImagen(imagenSalida.c_str());
}

void Pintar(int f1, int f2, int c1, int c2, Imagen &I, const Imagen &avion, int mindisf, int mindisc)
{

    int fila, col;
    if (abs(f2 - f1) >= mindisf || abs(c2 - c1) >= mindisc)
    {

        if (c1 != c2)
        {
            double a, b;
            a = double(f2 - f1) / double(c2 - c1);
            b = f1 - a * c1;
            col = (int)(c1 + c2) / 2;
            fila = (int)rint(a * col + b);
        }
        else
        {
            col = c1;
            fila = (f1 + f2) / 2;
        }

        double angulo = atan2((f2 - f1), (c2 - c1));
        Imagen Irota = Rota(avion, angulo);

        I.PutImagen(fila, col, Irota);

        angulo = atan2((f2 - fila), (c2 - col));
        Irota = Rota(avion, angulo);

        I.PutImagen(f2, c2, Irota);
        angulo = atan2((fila - f1), (col - c1));
        Irota = Rota(avion, angulo);

        I.PutImagen(f1, c1, Irota);
    }
}
Imagen Rota(const Imagen &Io, double angulo)
{
    double rads = angulo;
    double coseno = cos(angulo);
    double seno = sin(angulo);
    //Para obtener las dimensiones de la imagen
    int rcorners[4], ccorners[4];
    int newimgrows, newimgcols;
    double new_row_min, new_col_min, new_row_max, new_col_max;
    double inter, inter1;
    rcorners[0] = 0;
    rcorners[1] = 0;
    ccorners[0] = 0;
    ccorners[2] = 0;
    rcorners[2] = Io.num_filas() - 1;
    rcorners[3] = Io.num_filas() - 1;
    ccorners[1] = Io.num_cols() - 1;
    ccorners[3] = Io.num_cols() - 1;
    new_row_min = 0;
    new_col_min = 0;
    new_row_max = 0;
    new_col_max = 0;
    newimgrows = 0;
    newimgcols = 0;
    for (int count = 0; count < 4; count++)
    {
        inter = rcorners[count] * coseno + ccorners[count] * seno;

        if (inter < new_row_min)
            new_row_min = inter;
        if (inter > new_row_max)
            new_row_max = inter;
        inter1 = -rcorners[count] * seno + ccorners[count] * coseno;

        if (inter1 < new_col_min)
            new_col_min = inter1;
        if (inter1 > new_col_max)
            new_col_max = inter1;
    }

    newimgrows = (unsigned)ceil((double)new_row_max - new_row_min);
    newimgcols = (unsigned)ceil((double)new_col_max - new_col_min);
    
    Imagen Iout(newimgrows, newimgcols);
    Iout.LimpiarTransp(); //
    for (int rows = 0; rows < newimgrows; rows++)
    {   
        for (int cols = 0; cols < newimgcols; cols++)
        {   
            float oldrowcos = ((float)rows + new_row_min) * cos(-rads);
            float oldrowsin = ((float)rows + new_row_min) * sin(-rads);
            float oldcolcos = ((float)cols + new_col_min) * cos(-rads);
            float oldcolsin = ((float)cols + new_col_min) * sin(-rads);
            float old_row = oldrowcos + oldcolsin;
            float old_col = -oldrowsin + oldcolcos;
            old_row = ceil((double)old_row);
            old_col = ceil((double)old_col);
            if ((old_row >= 0) && (old_row < Io.num_filas()) &&
                (old_col >= 0) && (old_col < Io.num_cols()))
            {
                Iout(rows, cols) = Io(old_row, old_col);
            }
            else
                Iout(rows, cols).r = Iout(rows, cols).g = Iout(rows, cols).b = 255;
        }
    }
    return Iout;
}
