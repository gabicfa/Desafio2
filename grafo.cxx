#include "grafo.hxx"
#include <vector>


Grafo::Grafo(int n_academicos){
  this->n_academicos= n_academicos;
  conexoes = new std::vector<int>[n_academicos];
  conexoes_nome = new std::vector<std::string> [n_academicos];
}

void Grafo::adicionarConexoes(int academico2, int academico1) {
  if(academico1<academico2){
    conexoes[academico2].push_back(academico1);
  }
  else{
    conexoes[academico1].push_back(academico2);
  }
}
