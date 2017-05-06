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

  std::vector<std::string> *conexoes_nome;
  int fila[n_academicos];
  int inic = 0;
  int fim  = 0;
  int cont = 0;
  int node;

  std::cout << n_academicos << '\n';

  for (size_t a = 0; a < n_academicos; a++) {
    fim++;
    fila[fim] = a;
    visitados[a]=cont;

    while (inic!=fim) {
      inic = (inic + 1) % n_academicos;
      node = fila[inic];

      if(grafo.conexoes[node].size() == 0){
        menor_distancia[a] = cont;
        grafo.conexoes_nome[a].push_back(academicos[a]) ;
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
            grafo.conexoes_nome[a]=grafo.conexoes_nome[grafo.conexoes[node][i]];
            grafo.conexoes_nome[a].push_back(academicos[a]);
          }
          else if(cont< menor_distancia[a]){
            menor_distancia[a] = cont;
            grafo.conexoes_nome[a]=grafo.conexoes_nome[grafo.conexoes[node][i]];
            grafo.conexoes_nome[a].push_back(academicos[a]);
          }
        }
      }
    }

    for (size_t k = 0; k < grafo.conexoes_nome[a].size(); k++){
      if(k != grafo.conexoes_nome[a].size() - 1){
        std::cout << grafo.conexoes_nome[a][k] << " -> "  ;
      }
      else{
        std::cout << grafo.conexoes_nome[a][k] << ": " ;
      }
    }

    std::cout << menor_distancia[a] <<'\n';
    inic = 0;
    fim = 0;
    cont = 0;
  }
  return 0;
}
