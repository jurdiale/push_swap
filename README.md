*Este proyecto ha sido creado como parte del currículo de 42 por jurdiale y pabfajar.*

## Descripción

push_swap es un proyecto de ordenación. Dado un conjunto de enteros en la pila A, los ordena usando un conjunto limitado de operaciones sobre dos pilas (A y B) minimizando el número de operaciones.

El programa implementa cuatro estrategias de ordenación distintas seleccionables mediante flags, y elige automáticamente la más eficiente según el índice de desorden de la entrada.

## Instrucciones

make        → compila y genera push_swap y checker
make clean  → elimina los archivos objeto (.o)
make fclean → elimina los .o y los ejecutables
make re     → recompila todo desde cero

Uso:
    ./push_swap [--simple|--medium|--complex|--adaptive] numero1 numero2 ...
    ./push_swap 3 1 2 4 5
    ./push_swap --medium 3 1 2 4 5
    ./push_swap --bench 3 1 2 4 5

Verificar con el checker:
    ARG="3 1 2 4 5"
    ./push_swap $ARG | ./checker $ARG

## Funciones autorizadas

read, write, malloc, free, exit, ft_printf

## Estrategias de ordenación

### Algoritmo lineal O(n)
Busca inversiones locales y las corrige con sa/ra. Solo se usa en el modo adaptativo cuando disorder < 0.2 — la pila está casi ordenada y solo necesita ajustes menores.

### Algoritmo simple O(n²) — --simple
Adaptación del insertion sort. Empuja todos los elementos a b excepto 3, ordena los 3 restantes y va insertando de b a a eligiendo siempre el mínimo. Adecuado para entradas pequeñas o muy desordenadas con pocos elementos.

### Algoritmo medio O(n√n) — --medium
Algoritmo turco basado en chunks. Divide los índices en grupos y los empuja a b optimizando la posición con rb. Luego inserta de b a a eligiendo siempre el elemento de menor coste de inserción, aprovechando rotaciones simultáneas (rr/rrr). Adecuado para entradas medianas.

### Algoritmo complejo O(n log n) — --complex
Adaptación del radix sort LSD. Procesa los índices bit a bit del menos significativo al más significativo. En cada pasada los elementos con bit 0 rotan en a y los de bit 1 van a b, luego se vuelcan a a. Adecuado para entradas grandes.

### Algoritmo adaptativo — --adaptive (por defecto)
Selecciona automáticamente el algoritmo según el índice de desorden:
- disorder < 0.2  → O(n)       casi ordenado, solo ajustes locales
- disorder < 0.5  → O(n√n)     turco con chunks
- disorder >= 0.5 → O(n log n) radix sort

## Índice de desorden

Se calcula antes de ordenar contando los pares en orden incorrecto:

    disorder = mistakes / total_pairs

Donde mistakes es el número de veces que un índice mayor aparece antes que uno menor. 0.0 = ordenado, 1.0 = completamente invertido.

## Modo benchmark (--bench)

Muestra por stderr tras la ordenación:
- Índice de desorden
- Estrategia usada y su complejidad
- Total de operaciones
- Operaciones por tipo

## Checker (bonus)

El checker verifica que las operaciones generadas por push_swap ordenan correctamente la pila.

Uso:
    ARG="3 1 2 4 5"
    ./push_swap $ARG | ./checker $ARG

O manualmente introduciendo operaciones por teclado:
    ./checker 3 1 2
    ra
    pb
    pa
    Ctrl+D

Si tras ejecutar todas las operaciones la pila a está ordenada y b está vacía imprime OK. En caso contrario imprime KO.

## Contribuciones

jurdiale:
- Checker (bonus)
- Ordena 2 y ordena 3
- Algoritmo complejo (radix sort)
- Algoritmo lineal
- Algoritmo adaptativo
- Modo benchmark (--bench)
- Utilidades de push_swap
- Header (con pabfajar)
- Operaciones de pila
- README

pabfajar:
- get_next_line
- Parseo y validación de entrada
- Normalización e índice de desorden
- Utilidades de pila
- Algoritmo simple y algoritmo medio
- Header (con jurdiale)
- Main
- Makefile
- Error

## Recursos

- Documentación de complejidad algorítmica: https://bigocheatsheet.com
- Radix sort: https://en.wikipedia.org/wiki/Radix_sort
- IA utilizada: Claude para entender los algoritmos de ordenación, calcular costes de inserción, optimizar rotaciones simultáneas y estructurar el proyecto.