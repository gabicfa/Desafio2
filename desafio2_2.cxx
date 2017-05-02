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
  int menor_distancia[n_academicos];

  for (size_t i = 0; i < n_academicos; i++) {
    visitados[i] = -1;
    menor_distancia[i]= 0;
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


      if(grafo.conexoes[node].size() == 0){
        menor_distancia[a] = cont;
      }

      cont++;

      for (int i = 0; i < grafo.conexoes[node].size(); i++) {
        if(visitados[grafo.conexoes[node][i]]==-1){
          fim = (fim + 1) % n_academicos;
          fila[fim] = grafo.conexoes[node][i];
          visitados[grafo.conexoes[node][i]] = cont;
        }
        else{
          cont+=menor_distancia[grafo.conexoes[node][i]];
          if(menor_distancia[a]==0){
            menor_distancia[a] = cont;
          }
          else if(cont< menor_distancia[a]){
            menor_distancia[a] = cont;
          }
        }
      }
    }

    std::cout << academicos[a] << ": " << menor_distancia[a] <<'\n';
    
    inic = 0;
    fim = 0;
    cont = 0;
  }
  return 0;
}
