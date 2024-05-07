#include <iostream>

using namespace std;

void vaciar(int tablero[8][8])
{
  // Vacia el tablero
  for (int j = 0; j < 8; j++)
  {
    for (int k = 0; k < 8; k++)
    {
      tablero[j][k] = 0;
    }
  }
}
void print(int const tablero[8][8])
{
  cout << "Reinas representadas por X y vacios representados por o" << endl;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      cout << tablero[i][j] << "\t";
    }
    cout << "\n";
  }
  cout << endl;
}

void llenar(int tablero[8][8], int f, int c)
{
  // Revisa la fila
  for (int i = 0; i < 8; i++)
  {

    tablero[f][i] = 1;
  }
  // Revisa la columna
  for (int i = 0; i < 8; i++)
  {
    tablero[i][c] = 1;
  }
  // Revisa desde el punto hacia abajo a la derecha
  int i = f, j = c;
  while (i <= 7 && j <= 7)
  {
    tablero[i][j] = 1;
    i++;
    j++;
  }
  // Revisa desde el punto hacia arriba a la izquierda
  i = f, j = c;
  while (i >= 0 && j >= 0)
  {
    tablero[i][j] = 1;
    i--;
    j--;
  }
  // Revisa desde el punto hacia arriba a la derecha
  i = f, j = c;
  while (i <= 7 && j >= 0)
  {
    tablero[i][j] = 1;
    i++;
    j--;
  }
  // Revisa desde el punto hacia abajo a la izquierda
  i = f, j = c;
  while (i >= 0 && j <= 7)
  {
    tablero[i][j] = 1;
    i--;
    j++;
  }
  tablero[f][c] = 2;
}

int contarLibres(int const tablero[8][8])
{
  int c = 0;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (tablero[i][j] == 0)
        c++;
    }
  }
  return c;
}

void copiar(int a[8][8], int b[8][8])
{

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      a[i][j] = b[i][j];
    }
  }
}

void reinas(int tablero[8][8])
{
  llenar(tablero, 0, 0);
  for (int k = 0; k < 7; k++)
  {
    int libres[8][8];
    vaciar(libres);
    for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
      {
        if (tablero[i][j] == 0)
        {
          int nt[8][8];
          copiar(nt, tablero);
          llenar(nt, i, j);
          libres[i][j] = contarLibres(nt);
        }
      }
    }

    print(libres);
    int mayor = libres[0][0];
    int filaMayor = 0;
    int columnaMayor = 0;

    for (int i = 0; i < 8; ++i)
    {
      for (int j = 0; j < 8; ++j)
      {
        if (libres[i][j] > mayor)
        {
          mayor = libres[i][j];
          filaMayor = i;
          columnaMayor = j;
        }
      }
    }

    std::cout << "El mayor elemento es " << mayor << " en la fila " << filaMayor << " y columna " << columnaMayor << std::endl;

    llenar(tablero, filaMayor, columnaMayor);
  }
}

int main()
{
  int tablero[8][8];
  vaciar(tablero);
  reinas(tablero);
  print(tablero);
}
