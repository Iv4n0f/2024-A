#include <iostream>
#include <vector>

using namespace std;

bool in(char k, const char *v) {
  const char * aux = v;
  int i = 0;
  while (aux[i] != '\0') {
    if(aux[i] == k) return  true;
    aux++;
  }
  return false;
}

void mostrar(vector<const char *> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

vector<const char *> numericos(vector<const char *> v) {
  vector<const char*> nv;
  const char* numeros = {"1234567890"};
  for(int i = 0; i<v.size(); i++){
    const char* aux = v[i];
    int j = 0;
    while(aux[j] != '\0'){
      if(in(aux[j], numeros)){
        nv.push_back(aux);
        break;
      }
      j++;
    }
  }
  return nv;
}

int main() {
  vector<const char *> info = {
      "green23",         "black",         "blue42",
      "yellow7",         "purple99",      "orange123",
      "pink8",           "brown56",       "silver100",
      "gold777",         "teal2021",      "maroon",
      "violet999",       "lime25",        "indigo1234",
      "coral567",        "turquoise333",  "magenta",
      "beige123456",     "navy7777",      "crimson12345",
      "ivory987",        "lavender",      "chartreuse456",
      "salmon789",       "khaki1234",     "azure567",
      "olive111",        "fuchsia9876",   "plum",
      "cyan654",         "tan",           "orchid234",
      "aquamarine7890",  "peru123",       "tomato567",
      "thistle1234",     "bisque987",     "wheat",
      "seashell789",     "papayaWhip123", "linen",
      "mistyRose1234",   "honeydew",      "mintCream456",
      "antiqueWhite789", "oldLace",       "cornsilk567",
      "snow1234",        "floralWhite789"};

  cout<<"Antes de procesar:"<<endl;
  mostrar(info);
  vector<const char*> nv = numericos(info);
  cout<<endl;
  cout<<"Solo cadenas que contengan numeros:"<<endl;
  mostrar(nv);
}
