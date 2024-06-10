#include <iostream>
#include <string>

using namespace std;

class Observer {
public:
  virtual void update(string[], int) = 0;
  virtual string getNombre() = 0;
};

class Alumno : public Observer {
public:
  string nombre;
  string historial[100];
  int h_size;
  Alumno(string a) {
    this->nombre = a;
    h_size = 0;
  }
  string getNombre() { return nombre; }
  void update(string historial_global[], int hg_size) {
    h_size = hg_size;
    for (int i = 0; i < hg_size; i++) {
      historial[i] = historial_global[i];
    }
  }
  void showHistorial() {
    cout << "Historial de " << nombre << " :" << endl;
    for (int i = 0; i < h_size; i++) {
      for(char c : historial[i]){
        if(c == '_'){
          cout<<endl;
          break;
        }
        cout<<c;
      }
    }
    cout << "----------------" << endl;
  }
  void showHistorial_emisor(){
    cout<<"Historial completo de "<<nombre<<" :" <<endl;
    for (int i = 0; i < h_size; i++) {
      cout<<historial[i]<<endl;
    }
    cout << "----------------" << endl;
  }
};

class Chat {
public:
  Observer *userList[100];
  int u_size;
  string historial_global[100];
  int hg_size;
  Chat() {
    u_size = 0;
    hg_size = 0;
  }
  void registerUser(Observer *_user) {
    userList[u_size] = _user;
    u_size++;
  }
  void send(string mensaje, string autor) {
    string m_completo = mensaje + "_" + autor;
    historial_global[hg_size] = m_completo;
    hg_size++;
    for (int i = 0; i < u_size; i++) {
      userList[i]->update(historial_global, hg_size);
      cout << autor << " dice " << mensaje << " a " << userList[i]->getNombre()
           << endl;
    }
  }
};

int main() {
  Chat chat;

  Alumno alumno1("Jesus");
  Alumno alumno2("Sofia");
  chat.registerUser(&alumno1);
  chat.registerUser(&alumno2);

  chat.send("Hola", "Ivan");
  chat.send("Adios", "Otra persona");

  alumno1.showHistorial();
  alumno2.showHistorial_emisor();
}
