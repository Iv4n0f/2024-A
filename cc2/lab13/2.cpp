#include <iostream>
template<int Index, typename T, std::size_t N>
constexpr int find_element(const T(&array)[N], const T& value) {
    // Si el índice es igual al tamaño del array, significa que no se encontró el elemento
    if constexpr (Index == N) {
        return -1; // Elemento no encontrado
    } else {
        // Si se encuentra el elemento en la posición actual, devolver el índice
        if (array[Index] == value) {
            return Index;
        } else {
            // Continuar buscando en el siguiente índice
            return find_element<Index + 1>(array, value);
        }
    }
}

int main() {
    constexpr int array[] = {1, 2, 3, 4, 5};
    constexpr int value = 3;
    
    // Llamar a la función de búsqueda en tiempo de compilación
    constexpr int index = find_element<0>(array, value);
    
    if (index != -1) {
        std::cout << "El elemento " << value << " se encuentra en el índice " << index << std::endl;
    } else {
        std::cout << "El elemento " << value << " no se encuentra en el array" << std::endl;
    }
    
    return 0;
}

