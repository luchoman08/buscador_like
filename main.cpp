#include "matrix.hpp"
#include <stdio.h>
#include "Lectura.cpp"
using namespace std;

int char_a_int(string entrada)
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
int main (int argv, char** args)
{
	matrix *matris = new matrix();
	Lectura *lectura = new Lectura();
	lectura->Leer("in.txt");
	printf("%ld\n",lectura->getPalabras().size());
   // char x = 'o';  ejemplo de como se toma ñ
   // string y[0] = x; ejemplo de como se toma ñ
	//matrix *m = new matrix();
	char_a_int("ñ");
	bitset <4> bit_prueba(std::string("1111"));
	bit_prueba.set(bit_prueba.size()-0-4,0);//ejemplo de poner naturalmente un set en el bit set
	//matris->matris[0][0] = &bit_prueba;
//	printf("%s",matris->matris[0][0]->to_string().c_str());

/* comienza lo serio */
     matris->inicializar_matriz();
     printf("%s",matris->matris[26][22]->to_string().c_str());
    int palabras_size=lectura->getPalabras().size();
    for(int i = 0; i < palabras_size;i++)
    {
		
	}
	
	return 0;
}
