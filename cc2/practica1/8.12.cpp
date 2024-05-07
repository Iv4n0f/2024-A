#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

void moveTortoise(int *T) {
  int n = rand() % 50 + 1;
  if (n <= 25) {
    *T += 3;
    return;
  }
  if (n <= 33) {
    *T -= 6;
    return;
  }
  if (n <= 50) {
    *T += 1;
    return;
  }
}

void moveHare(int *H) {
  int n = rand() % 50 + 1;
  if (n <= 19)
    return;
  if (n <= 27) {
    *H += 11;
    return;
  }
  if (n <= 35) {
    *H -= 9;
    return;
  }
  if (n <= 45) {
    *H += 1;
    return;
  }
  if (n <= 50) {
    *H -= 2;
    return;
  }
}

int main() {
  srand(time(NULL));
  cout << "RACE" << endl;

  int T = 0;
  int H = 0;

  char resultado = '\0';

  for (int i = 0; i <= 100; ++i) {
    moveHare(&H);
    moveTortoise(&T);
    if (T == H && T < 70 && T > 0) {
      cout<<'\r';
      for (int j = 0; j < 70; j++) {
        if (j == T) {
          cout << "OUCH!!!";
          continue;
        }
        cout<<' ';
      }
      cout.flush();

    this_thread::sleep_for(chrono::milliseconds(500));

      continue;
    }
    if (T == H && T >= 70) {
      resultado = 'E';
      break;
    }
    if (T >= 70) {
      resultado = 'T';
      break;
    }
    if (H >= 70) {
      resultado = 'H';
      break;
    }
    if (H < 0)
      H = 0;
    if (T < 0)
      T = 0;
    cout << '\r';
    for (int j = 0; j < 70; j++) {
      if (j == H) {
        cout << 'H';
        continue;
      };
      if (j == T) {
        cout << 'T';
        continue;
      };
      cout << ' ';
    }

    cout.flush();
    this_thread::sleep_for(chrono::milliseconds(80));
  }

  cout<<endl;
  
  if(resultado == 'H'){
    cout<<"HARE WINS!!!"<<endl;
  }
  if(resultado == 'T'){
    cout<<"TORTOISE WINS!!!"<<endl;
  }
  if(resultado == 'E'){
    cout<<"It's a tie"<<endl;
  }
  return 0;
}
