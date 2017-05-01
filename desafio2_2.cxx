#include<iostream>
#include "grafo.cxx"

int main(){

  int n_academicos, n_conexoes,academico1,academico2;
  std::cin >> n_academicos;
  Grafo grafo(n_academicos);

  std::string academicos[n_academicos];
  std::string academico;
  std::getline(std::cin, academico);

  for (size_t i = 0; i < n_academicos; i++) {
    std::getline(std::cin, academico);
    academicos[i] = academico;
  }

  std::cin >> n_conexoes;

  for (size_t i = 0; i < n_conexoes; i++) {
    std::cin >> academico1;
    std::cin >> academico2;
    grafo.adicionarConexoes(academico1,academico2);
  }

  int visitados[n_academicos];
  for (size_t i = 0; i < n_academicos; i++) {
    visitados[i] = -1;
  }

  int fila[n_academicos];
  int inic = 0;
  int fim  = 0;
  int cont = 0;
  int node;
  int academico_avaliado;

  std::cout << n_academicos << '\n';

  for (size_t a = 0; a < n_academicos; a++) {

    academico_avaliado = a;
    fim++;
    fila[fim] = academico_avaliado;
    visitados[academico_avaliado]=cont;

    while (inic!=fim) {
      inic = (inic + 1) % n_academicos;
      node = fila[inic];
      cont++;

      for (int i = 0; i < grafo.conexoes[node].size(); i++) {
        if(visitados[grafo.conexoes[node][i]]==-1){
          fim = (fim + 1) % n_academicos;
          fila[fim] = grafo.conexoes[node][i];
          visitados[grafo.conexoes[node][i]] = cont;
        }
      }
    }

    std::cout << academicos[a] << ": " << visitados[0] <<'\n';

    inic = 0;
    fim = 0;
    cont = 0;

    for (size_t i = 0; i < n_academicos; i++) {
      visitados[i] = -1;
    }
  }
  return 0;
}
