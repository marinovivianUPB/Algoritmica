#include <bits/stdc++.h> 
using namespace std;

int derecha(int x) {
  if (x > 0){
    return (x - 1) / 3;
  }else{
    return 3;
  }
}

int abajo(int x) {
  if (x > 0){
    return (x - 1) % 3;
  }else{
    return 1;
  }
}

bool aprox(int sec) {
  assert(0 < sec && sec <= 200);
  if (sec < 10){
    return true;
  }else{
    return derecha((sec / 10) % 10) <= derecha(sec % 10) && abajo((sec / 10) % 10) <= abajo(sec % 10);
  }
}

int main() {
  int m;
  cin >> m;
  while (m--) {
    int sec;
    cin >> sec;
    int inicio = 0;
    while (true) {
      if (aprox(sec + inicio)) {
        cout << sec + inicio << endl;
        break;
      }
      if (aprox(sec - inicio)) {
        cout << sec - inicio << endl;
        break;
      }
      inicio++;
    }
  }
}
