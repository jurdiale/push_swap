*Este proyecto ha sido creado como parte del currículo de 42 por jurdiale y pabfajar.*

## Descripción

`push_swap` es un proyecto de ordenación. Dado un conjunto de enteros en la pila A, el programa los ordena utilizando un conjunto limitado de operaciones sobre dos pilas (A y B), intentando reducir el número de operaciones.

El proyecto implementa cuatro estrategias de ordenación seleccionables mediante flags. La estrategia adaptativa puede seleccionar automáticamente el algoritmo más apropiado según el nivel de desorden de la entrada.

## Compilación

```text
make        → compila push_swap
make bonus  → compila checker
make clean  → elimina los archivos objeto (.o)
make fclean → elimina los archivos objeto y los ejecutables
make re     → recompila push_swap desde cero
```

## Uso

```text
./push_swap [--simple|--medium|--complex|--adaptive] numero1 numero2 ...
```

Ejemplos:

```text
./push_swap 3 1 2 4 5
./push_swap --simple 3 1 2 4 5
./push_swap --medium 3 1 2 4 5
./push_swap --complex 3 1 2 4 5
./push_swap --adaptive 3 1 2 4 5
./push_swap --bench 3 1 2 4 5
```

La estrategia adaptativa se utiliza por defecto cuando no se especifica ningún algoritmo.

## Comprobación del resultado

El `checker` del bonus permite comprobar que la secuencia de operaciones generada por `push_swap` ordena correctamente las pilas:

```bash
ARG="3 1 2 4 5"
./push_swap $ARG | ./checker $ARG
```

Si la pila A queda ordenada y la pila B está vacía, el checker muestra:

```text
OK
```

En caso contrario muestra:

```text
KO
```

Una entrada no válida o una instrucción no válida produce:

```text
Error
```

También se pueden introducir las operaciones manualmente:

```bash
./checker 3 1 2
ra
pb
pa
Ctrl+D
```

## Funciones autorizadas

El proyecto utiliza únicamente las funciones autorizadas por el subject:

```text
read
write
malloc
free
exit
ft_printf
```

## Estrategias de ordenación

### Algoritmo Simple — `--simple`

La estrategia Simple está basada en un enfoque de tipo insertion sort y tiene una complejidad en el peor caso de `O(n²)`.

El algoritmo mantiene tres elementos en A y empuja el resto de elementos a B. Los tres elementos restantes se ordenan mediante `order_3()`. Después, los elementos almacenados en B se vuelven a insertar en A calculando el coste de inserción.

Esta estrategia resulta especialmente útil para entradas con poco desorden o de tamaño reducido, donde la sencillez del algoritmo puede compensar su mayor complejidad teórica.

### Algoritmo Medium — `--medium`

La estrategia Medium es un algoritmo basado en chunks con una complejidad esperada de `O(n√n)`.

El tamaño de cada chunk se calcula a partir del tamaño de la entrada:

```text
chunk_size = 5√n
```

con un tamaño mínimo de 20 elementos.

El algoritmo procesa la entrada por chunks. Los elementos pertenecientes al chunk actual se empujan desde A hacia B. Cuando el elemento que se busca no está en la cima de A, se localiza su posición y se utiliza la dirección de rotación más corta:

```text
ra
```

o:

```text
rra
```

Esto permite reducir rotaciones innecesarias durante el procesamiento de cada chunk.

Cuando quedan únicamente tres elementos en A, se ordenan mediante `order_3()`.

A continuación, los elementos de B se vuelven a insertar en A. Para cada inserción se calculan los costes disponibles y se selecciona un elemento con un coste bajo de inserción. Cuando es posible, se utilizan rotaciones simultáneas:

```text
rr
rrr
```

Finalmente, A se rota hasta colocar el elemento con el índice mínimo en la cima.

El tamaño `5√n` se eligió como un equilibrio práctico entre el número de chunks y el trabajo necesario para procesar cada uno. El mínimo de 20 evita que, para entradas pequeñas, se generen chunks excesivamente pequeños.

### Algoritmo Complex — `--complex`

La estrategia Complex está basada en una adaptación de radix sort LSD aplicada sobre los índices normalizados.

El algoritmo procesa los bits de cada índice desde el menos significativo hasta el más significativo.

Para cada bit:

* los elementos cuyo bit actual es `0` se envían de A a B;
* los elementos cuyo bit actual es `1` permanecen en A y se rotan;
* después de procesar el bit, todos los elementos de B vuelven a A.

El proceso se repite para todos los bits necesarios.

Radix sort proporciona un comportamiento predecible para entradas grandes y tiene una complejidad de `O(n log n)` cuando el número de bits procesados es proporcional a `log n`.

### Algoritmo Adaptive — `--adaptive`

La estrategia Adaptive selecciona el algoritmo de ordenación según el nivel de desorden de la entrada.

El desorden se divide en tres rangos:

```text
disorder < 0.2  → Simple
disorder < 0.5  → Medium
disorder >= 0.5 → Complex
```

Los umbrales son parámetros de decisión seleccionados experimentalmente para adaptar el algoritmo a la estructura de la entrada.

Para entradas con poco desorden, Simple evita el coste adicional de las estrategias más complejas.

Para un desorden intermedio, Medium aprovecha los chunks y la inserción basada en costes.

Para entradas muy desordenadas, Complex utiliza radix sort, cuyo comportamiento es más estable para entradas grandes.

Los umbrales no modifican la complejidad teórica de cada algoritmo; únicamente determinan qué estrategia selecciona el modo Adaptive.

## Índice de desorden

Antes de ordenar, el programa calcula el índice de desorden de la entrada.

Se cuenta el número de pares que aparecen en un orden incorrecto:

```text
disorder = mistakes / total_pairs
```

donde `mistakes` representa el número de pares en los que un índice mayor aparece antes que uno menor.

El valor se encuentra entre:

```text
0.0 → entrada ordenada
1.0 → entrada completamente invertida
```

Este valor se utiliza en el modo Adaptive para seleccionar la estrategia de ordenación.

## Modo Benchmark — `--bench`

La opción `--bench` muestra información sobre el proceso de ordenación mediante `stderr`, una vez generadas las operaciones.

El benchmark muestra:

* porcentaje de desorden;
* estrategia seleccionada;
* complejidad teórica;
* número total de operaciones;
* número de operaciones de cada tipo.

Por ejemplo:

```text
Disorder: 51.04%
Strategy: Adaptive / O(n*log(n))
Total Operations: 6784
sa: 0 sb: 0 ss: 0
pa: 2284 pb: 2284
ra: 2216 rb: 0 rr: 0
rra: 0 rrb: 0 rrr: 0
```

El benchmark proporciona información de diagnóstico y no modifica las operaciones enviadas por la salida estándar.

## Complejidad algorítmica

El proyecto utiliza tres enfoques principales:

| Estrategia | Complejidad                           | Técnica principal                   |
| ---------- | ------------------------------------- | ----------------------------------- |
| Simple     | `O(n²)`                               | ordenación tipo inserción           |
| Medium     | `O(n√n)`                              | chunks + inserción basada en costes |
| Complex    | `O(n log n)`                          | radix sort LSD                      |
| Adaptive   | depende de la estrategia seleccionada | selección basada en desorden        |

La estrategia Medium utiliza chunks de tamaño `O(√n)`. El número exacto de operaciones depende de la distribución de los elementos y de sus posiciones en las dos pilas.

La estrategia Complex procesa un número de bits proporcional a `log n`, y cada pasada procesa los `n` elementos, dando una complejidad de `O(n log n)`.

## Complejidad espacial

Las pilas contienen un nodo por cada elemento de entrada, por lo que almacenar la entrada requiere `O(n)` memoria.

Los algoritmos utilizan una cantidad constante de datos auxiliares, aparte de las dos pilas. Por tanto, el espacio adicional utilizado por los algoritmos es `O(1)`, mientras que el espacio total necesario para representar las pilas es `O(n)`.

## Operaciones sobre las pilas

El programa implementa las operaciones requeridas por el subject:

```text
sa   intercambia los dos primeros elementos de A
sb   intercambia los dos primeros elementos de B
ss   realiza sa y sb simultáneamente
pa   mueve el primer elemento de B a A
pb   mueve el primer elemento de A a B
ra   rota A hacia arriba
rb   rota B hacia arriba
rr   rota A y B simultáneamente hacia arriba
rra  rota A hacia abajo
rrb  rota B hacia abajo
rrr  rota A y B simultáneamente hacia abajo
```

Las operaciones combinadas `ss`, `rr` y `rrr` se contabilizan como una única operación en el benchmark.

## Estructura del proyecto

```text
push_swap/
├── algorithms/
│   ├── simple.c
│   ├── medium.c
│   ├── complex.c
│   └── adaptive.c
│
├── operations/
│   ├── swap.c
│   ├── push.c
│   ├── rotate.c
│   └── reverse_rotate.c
│
├── parse/
│   ├── validate.c
│   ├── normalize.c
│   ├── error.c
│   ├── parse_flags.c
│   ├── stack_utils_1.c
│   └── stack_utils_2.c
│
├── stack/
│   ├── stack_ops_1.c
│   ├── stack_ops_2.c
│   └── stack_ops_3.c
│
├── bonus/
│   ├── checker.c
│   ├── checker_utils.c
│   ├── get_next_line.c
│   └── get_next_line_utils.c
│
├── push_swap.c
├── bench.c
├── push_swap_utils_1.c
├── push_swap_utils_2.c
├── push_swap_utils_3.c
├── push_swap.h
└── Makefile
```

## Validación y normalización de la entrada

La entrada se valida antes de comenzar la ordenación.

El programa comprueba:

* caracteres no válidos;
* representaciones incorrectas de enteros;
* valores fuera del rango de `int`;
* valores duplicados;
* argumentos vacíos o no válidos.

Después de la validación, los valores se normalizan convirtiéndolos en índices. Los algoritmos trabajan sobre estos índices en lugar de utilizar directamente los valores originales.

Esto permite utilizar radix sort y proporciona a todos los algoritmos un rango compacto de índices.

## Bonus: Checker

La parte bonus implementa un checker capaz de leer las operaciones generadas por `push_swap` y aplicarlas a las pilas de entrada.

El checker comprueba el estado final:

```text
A está ordenada
B está vacía
```

y muestra `OK` o `KO`.

También valida las instrucciones recibidas por la entrada estándar y muestra `Error` cuando la entrada o una instrucción no son válidas.

## Contribuciones

### jurdiale

* Checker (bonus)
* Ordenación de dos elementos
* Algoritmo Complex (radix sort)
* Algoritmo Adaptive
* Modo Benchmark (`--bench`)
* Utilidades de push_swap
* Cabecera, junto con pabfajar
* Operaciones de las pilas
* README

### pabfajar

* `get_next_line`
* Parseo y validación de la entrada
* Normalización e índice de desorden
* Utilidades de las pilas
* Ordenación de tres elementos
* Algoritmo Simple
* Algoritmo Medium (basado en chunks)
* Cabecera, junto con jurdiale
* Main
* Makefile
* Gestión de errores

## Recursos

* Referencia de complejidad Big-O: https://bigocheatsheet.com
* Radix sort: https://en.wikipedia.org/wiki/Radix_sort

## Uso de IA

Se utilizaron herramientas de inteligencia artificial como apoyo durante el aprendizaje y desarrollo del proyecto para comprender algoritmos de ordenación, analizar costes de inserción, estudiar las rotaciones simultáneas, analizar la complejidad algorítmica y ayudar en la estructuración y depuración de diferentes partes del proyecto.

La implementación final, las pruebas y las decisiones tomadas sobre el proyecto fueron realizadas por los autores.
