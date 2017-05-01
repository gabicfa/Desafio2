#include <vector>

#ifndef GRAFO_HXX
#define GRAFO_HXX


class Grafo
{
	int n_academicos;
	// std::vector<int> *conexoes;

public:
  std::vector<int> *conexoes;
	Grafo(int n_academicos);
	void adicionarConexoes(int academico1, int academico2);
};

#endif
