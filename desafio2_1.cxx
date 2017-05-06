#include <iostream>
#include <string>
#include <vector>

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
  std::vector<std::vector<char> > descricao_VV(size, std::vector<char>(1));

  for (size_t i = 0; i < size; i++) {
    descricao_VV[i][0] = descricao[i];
  }
  /* ----------------MODIFICAÇĀO--------------------*/
  char s;
  int l = 2;
  for (size_t i = 0; i < size; i++) {
    if (descricao_VV[i][0] == '^' || descricao_VV[i][0] == '&' ||  descricao_VV[i][0] == '|') {
      s = descricao_VV[i][0];

      if(i != size-1) {
        descricao_VV[i][0]='(';
      }

      if(descricao_VV[i-l][0]=='-') {
        while(descricao_VV[i-l][0]=='-') {
          l++;
        }
      }

      if(i != size-1) {
        descricao_VV[i].insert(descricao_VV[i].end(), descricao_VV[i-l].begin(), descricao_VV[i-l].end());
      }

      else{
        descricao_VV[i] = descricao_VV[i-l];
      }

      descricao_VV[i-l][0] = '-';
      descricao_VV[i].push_back(s);
      descricao_VV[i].insert(descricao_VV[i].end(), descricao_VV[i-1].begin(), descricao_VV[i-1].end());
      descricao_VV[i-1][0] = '-';

      if(i != size-1) {
        descricao_VV[i].push_back(')');
      }
      l=2;
    }
  }

  for (size_t i = 0; i < descricao_VV[size-1].size(); i++) {
    std::cout << descricao_VV[size-1][i];
  }

  std::cout << '\n';

  /* ----------------MODIFICAÇĀO--------------------*/

  for (size_t i = 0; i < size; i++) {
    if (descricao[i] == '^') {
      descricao_v[i] = -1;
    }
    else if (descricao[i] == '&') {
      descricao_v[i] = -2;
    }
    else if (descricao[i] == '|') {
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
    for (size_t j = 0; j < n_variaveis; j++) {
      std::cin >> b_entrada;
      for (size_t k = 0; k < size; k++) {
        if(descricao_v[k]==j) {
          v_subs[k] = b_entrada;
        }
        if(descricao_v[k]<0) {
          v_subs[k] = descricao_v[k];
        }
      }
    }

    v = 2;
    for (size_t k = 0; k < size; k++) {
      if (v_subs[k]<0) {
        if(v_subs[k-v] == VAZIO) {
          while(v_subs[k-v] == VAZIO) {
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
