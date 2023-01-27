
# include <iostream>
# include <omp.h>

# define N 1000 // Cantidad de elementos a manejar en los arreglos
# define chunk 100 // Tamaño que tendrán los pedazos de los arreglos para que cada hilo creado se encargue de esta cantidad de elementos
# define mostrar 10 // Cantidad de datos a imprimir

void imprimeArreglo(float *d);

int main()
{
    std::cout << "Sumando Arreglos en Paralelo!\n";

    // Definir variables
    float a[N], b[N], c[N];
    int i;

    // Llenar los arreglos
    for (i = 0; i < N; i++)
    {
        a[i] = i % 6;
        b[i] = i % 3;
    }

    int pedazos = chunk;

    //  Definir For Paralelo
# pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule (static, pedazos)

    // Suma de arreglos
    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    // Imprimiendo Arreglos
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);
}

void imprimeArreglo(float *d)
    {
        for (int x = 0; x < mostrar; x++)
            std::cout << d[x] << " - ";
        std::cout << std::endl;
    }


