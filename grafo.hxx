#include <vector>

#ifndef GRAFO_HXX
#define GRAFO_HXX

class Grafo
{
	int n_academicos;

public:
	std::vector<int> *conexoes;
	std::vector<std::string> *conexoes_nome;
	Grafo(int n_academicos);
	void adicionarConexoes(int academico1, int academico2);
};

#endif
