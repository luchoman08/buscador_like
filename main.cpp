#include "matrix.hpp"
#include <stdio.h>
#include "Lectura.cpp"
using namespace std;

int matrix::char_a_int(string entrada)
{
	if(entrada == "ñ")
	return 14;
	switch(entrada.at(0)){
		case 'a':return 0;break;
		case 'b':return 1;break;
		case 'c':return 2;break;
		case 'd':return 3;break;
		case 'e':return 4;break;
		case 'f':return 5;break;
		case 'g':return 6;break;
		case 'h':return 7;break;
		case 'i':return 8;break;
		case 'j':return 9;break;
		case 'k':return 10;break;
		case 'l':return 11;break;
		case 'm':return 12;break;
		case 'n':return 13;break;
		case 'o':return 15;break;
		case 'p':return 16;break;
		case 'q':return 17;break;
		case 'r':return 18;break;
		case 's':return 19;break;
		case 't':return 20;break;
		case 'u':return 21;break;
		case 'v':return 22;break;
		case 'w':return 23;break;
		case 'x':return 24;break;
		case 'y':return 25;break;
		case 'z':return 26;break;
		default: return -1;

	}
	
}

vector <int> matrix::palabras_resultantes(string p_entrada)
{
vector <int> palabras_resultantes;
string caracter_actual="";
std::bitset<89000>  resultado;	
resultado.set();
resultado.set();
int p_entrada_size = p_entrada.size(), resultado_size = 0;
for(int i =0; i < p_entrada_size;i++)
{
caracter_actual=p_entrada.at(i);	
resultado&=*matris[i][matrix::char_a_int(caracter_actual)];
caracter_actual="";
}
resultado_size=resultado.size();
for(int i =0;i<resultado_size;i++)
{
	if(resultado[i]==1)
	{
		palabras_resultantes.push_back(88999 - i);
	}
}
return palabras_resultantes;
}

void matrix::insertar_palabra(std::string palabra, int posicion)
{
int  palabra_size;
std::string caracter ="";

palabra_size = palabra.size();
for(int i =0; i<palabra_size;i++)
{
caracter = caracter += palabra.at(i);
this->matris[i][matrix::char_a_int(caracter)]->set(88999-posicion,1);//ejemplo de poner naturalmente un set en el bit set
caracter = "";
}
}


void matrix::inicializar_matriz()
{
	string ceros ="";
	for(int i =0; i< 89000;i++)
	{
		ceros +="0";
	}
	
	
	for(int i = 0; i < 27;i++)
	{
		for(int j = 0; j <= 22; j++)
		{
			std::bitset<89000> *bitset = new std::bitset<89000> (ceros);
			this->matris[i][j] = bitset;
		}
	}
}
matrix::matrix()
{
}
void imprimir_matris(std::bitset<89000>*  matris[4][4])
{
    for(int i =0; i<4;i++)
    {
     for(int j = 0; j < 4; j++)
     {
         cout << matris[i][j]->to_string().c_str()<<" ";
     }
     cout << endl;
    }
}
int main (int argv, char** args)
{
	matrix *matris = new matrix();
	Lectura *lectura = new Lectura();
	lectura->Leer("in_short.txt");
	
   // char x = 'o';  ejemplo de como se toma ñ
   // string y[0] = x; ejemplo de como se toma ñ

	
	bitset <4> bit_prueba;
    bit_prueba&=bit_prueba;
	bit_prueba.set();
	bit_prueba.set();
	//matris->matris[0][0] = &bit_prueba;
//	printf("%s",matris->matris[0][0]->to_string().c_str());

/* comienza lo serio */
     matris->inicializar_matriz();
    printf("%ld\n",lectura->getPalabras().size());
    int palabras_size=lectura->getPalabras().size();

    
        clock_t start = clock();
        int contador = 0;
   for(int i =0; i< palabras_size-10;i++)
    {
		matris->insertar_palabra(lectura->getPalabras().at(i), i);
		
	}
	clock_t stop = clock();
	//printf("%s",matris->matris[0][0]->to_string().c_str());
	printf("%s",bit_prueba.to_string().c_str());
	printf("%d\n",contador);
	 vector <int> palabras_resultantes = matris->palabras_resultantes("ab");
	
	 double elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f ", elapsed);
    for(int i =0; i < palabras_resultantes.size();i++)
	 {
		 printf("%s\n",lectura->getPalabras().at(palabras_resultantes.at(i)).c_str());
		  //printf("%d\n",palabras_resultantes.at(i));
	 }
	return 0;
}
