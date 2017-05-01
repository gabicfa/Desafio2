#include <iostream>
#include <string>

# define VAZIO -4

int main() {

  int n_variaveis, m_entrada, b_entrada, v;
  std::string descricao;

  std::cin >> n_variaveis;

  char variaveis[n_variaveis];

  for (size_t i = 0; i < n_variaveis; i++) { //Coloca variaveis em uma lista (variaveis)
    std::cin >> variaveis[i];
  }

  std::cin >> descricao;
  int size = descricao.size();
  int descricao_v[size];//cria um lista(descricao_v) com o mesmo tamanho da string (descricao)

  for (size_t i = 0; i < size; i++) {//descricao_v é uma "traducao" da string para int
    if (descricao[i] == '^'){ // simbolos sao numeros menores que 0
      descricao_v[i] = -1;
    }
    else if (descricao[i] == '&'){
      descricao_v[i] = -2;
    }
    else if (descricao[i] == '|'){
      descricao_v[i] = -3;
    }
    else{
      for (size_t j = 0; j < n_variaveis; j++) { // variaveis sao o seu indice na lista "variaveis"
        if (descricao[i]==variaveis[j]) {
          descricao_v[i] = j;
          break;
        }
      }
    }
  }

  std::cin >> m_entrada;
  std::cout << m_entrada << '\n';
  int v_subs[size];// cria lista para fazer as operacoes

  for (size_t i = 0; i < m_entrada; i++) {// a cada linha da entrada
    for (size_t j = 0; j < n_variaveis; j++){
      std::cin >> b_entrada;
      for (size_t k = 0; k < size; k++) {//coloca o b_entrada no v_subs correspondente ao indice do descricao_v
        if(descricao_v[k]==j){
          v_subs[k] = b_entrada;
        }
        if(descricao_v[k]<0){
          v_subs[k] = descricao_v[k];// se nao for um bit, copia o simbolo
        }
      }
    }

    v = 2;
    for (size_t k = 0; k < size; k++) {
      if (v_subs[k]<0) {
        if(v_subs[k-v] == VAZIO){ //checa se as duas casas antes do simbolo sao numeros
          while(v_subs[k-v] == VAZIO){// se nao for procura ultimo numero
            v++;
          }
        }
        if (v_subs[k] == -1) {// faz a conta
          v_subs[k] = v_subs[k-v] ^ v_subs[k-1];
        }
        else if (v_subs[k] == -2) {
          v_subs[k] = v_subs[k-v] & v_subs[k-1];
        }
        else if (v_subs[k] == -3) {
          v_subs[k] = v_subs[k-v] | v_subs[k-1];
        }
        v_subs[k-1] = VAZIO;// coloca vazio nos bits que ja fizeram conta
        v_subs[k-v] = VAZIO;
      }
      v = 2;
    }
    std::cout << v_subs[size-1] << '\n';// printa resultado para aquela linha
  }
  return 0;
}
