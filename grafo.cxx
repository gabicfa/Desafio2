#include "grafo.hxx"
#include <vector>


Grafo::Grafo(int n_academicos){
  this->n_academicos= n_academicos;
  conexoes = new std::vector<int>[n_academicos];
}

void Grafo::adicionarConexoes(int academico2, int academico1) {
  conexoes[academico1].push_back(academico2);
}
