#ifndef matrix_hpp
#define matrix_hpp
#include <bitset>
#include <string>
#include <vector>
class matrix{
	
	public :
	matrix();
	~matrix();
	std::bitset<89000>*  matris[27][22];
    void inicializar_matriz();
    void insertar_palabra(std::string palabra, int posicion);
    int char_a_int(std::string entrada);
    std::vector <int> palabras_resultantes(std::string p_entrada);
};


#endif
