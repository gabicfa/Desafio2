#include <iostream>
#include <string>

# define VAZIO -4

int main() {

  int n_variaveis, m_entrada, b_entrada, v;
  std::string descricao;

  std::cin >> n_variaveis;

  char variaveis[n_variaveis];

  for (size_t i = 0; i < n_variaveis; i++) {
    std::cin >> variaveis[i];
  }

  std::cin >> descricao;
  int size = descricao.size();
  int descricao_v[size];

  for (size_t i = 0; i < size; i++) {
    if (descricao[i] == '^'){
      descricao_v[i] = -1;
    }
    else if (descricao[i] == '&'){
      descricao_v[i] = -2;
    }
    else if (descricao[i] == '|'){
      descricao_v[i] = -3;
    }
    else{
      for (size_t j = 0; j < n_variaveis; j++) {
        if (descricao[i]==variaveis[j]) {
          descricao_v[i] = j;
          break;
        }
      }
    }
  }

  std::cin >> m_entrada;
  std::cout << m_entrada << '\n';
  int v_subs[size];

  for (size_t i = 0; i < m_entrada; i++) {
    for (size_t j = 0; j < n_variaveis; j++){
      std::cin >> b_entrada;
      for (size_t k = 0; k < size; k++) {
        if(descricao_v[k]==j){
          v_subs[k] = b_entrada;
        }
        if(descricao_v[k]<0){
          v_subs[k] = descricao_v[k];
        }
      }
    }

    v = 2;
    for (size_t k = 0; k < size; k++) {
      if (v_subs[k]<0) {
        if(v_subs[k-v] == VAZIO){
          while(v_subs[k-v] == VAZIO){
            v++;
          }
        }
        if (v_subs[k] == -1) {
          v_subs[k] = v_subs[k-v] ^ v_subs[k-1];
        }
        else if (v_subs[k] == -2) {
          v_subs[k] = v_subs[k-v] & v_subs[k-1];
        }
        else if (v_subs[k] == -3) {
          v_subs[k] = v_subs[k-v] | v_subs[k-1];
        }
        v_subs[k-1] = VAZIO;
        v_subs[k-v] = VAZIO;
      }
      v = 2;
    }
    std::cout << v_subs[size-1] << '\n';
  }
  return 0;
}
