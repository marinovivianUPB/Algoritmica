<div align="center">

# Máximo Flujo  

 <div align="left">
 
 ### Definición  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Máximo Flujo se refiere a un problema en el que teniendo un sistema de cañerías compuesto por cañerías con una capacidad máxima y puntos de conexión entre ellas, queremos saber cuánta agua puede llegar del punto inicial S al punto final T si S envía una cantidad infinita de agua. La cantidad de agua que llegará a T será el resultado de la exploración de todos los caminos posibles que lleguen a T. Un camino quedará obsoleto una vez que las cañerías que lo conectan a T hayan llegado a su máxima capacidad.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Queda claro que se puede aplicar teoría de grafos a este problema. Entonces, tendremos un grafo donde cada punto de conexión es un nodo y cada cañería es una arista direccionada con peso. De esta manera, la exploración de los caminos se puede realizar con los algoritmos de exploración BFS y DFS, con ciertas modificaciones. Cada que se recorra un camino, la cantidad de agua que llegó al punto T por medio de este se restará a todas las aristas que lo componen, simbolizando la capacidad ocupada de cada cañería. Esta cantidad de agua se encontrará buscando la mínima capacidad de entre las cañaerías que componen el camino. Además, se accionarán los algoritmos de búsqueda hasta que se hayan explorado todos los caminos posibles para obtener la máxima cantidad de agua que puede llegar al punto T.  

 #### Ejemplo  
 
 Utilicemos el grafo siguiente:  
 
  ![ej](https://imgur.com/iSH5C5G.png)  
 
 ##### BFS - Edmonds Karp  
 
  En este caso, se visitarán todos los nodos vecinos del nodo actual. Entonces, visitaremos A, B y C primero.  
  ![ed0](https://imgur.com/OQQhFTT.png)  
  A continuación, visitamos D a partir de A y E a partir de B. 
  ![ed1](https://imgur.com/qGApQhZ.png)  
  Entonces, llegamos a T por medio de D. En el camino S->A->D->T, el valor mínimo es 18, entonces, restaremos 18 a todas las aristas del camino y sumaremos 18 al total de T. Entonces: total=18.  
  ![ed2](https://imgur.com/oDAINpJ.png)  
  Entonces, ahora la arista de A a D queda inhabilitada. Cuando iniciamos nuevamente la búsqueda, visitamos A, B y C primero, como en el anterior recorrido, pero como la arista A-D ya no puede usarse, visitaremos D y E por medio de B, y llegaremos a T pormedio de D. 
  ![ed3](https://imgur.com/gjKspDO.png)  
  Ahora, como la capacidad mínima es 2, restamos 2 a todas las aristas en el camino S->B->D->T y sumamos 2 al total de T. Entonces: total=20.
  ![ed4](https://imgur.com/tiIaOhj.png)  
  Ahora queda bloqueado un camino a T.  
  Entonces, reiniciamos el recorrido. Nuevamente, visitamos A, B y C primero.   
  ![ed5](https://imgur.com/njoDU6P.png)  
  Ahora, visitaremos D y E por medio de B, como la última vez.  
  ![ed6](https://imgur.com/OJEnJIO.png)  
  Sin embargo, como el camino de D a T queda bloqueado, llegaremos a T por medio de E. Ya que la capacidad mínima del camino S->B->E->T es 10, restaremos 10 a todas las aristas del recorrido y sumaremos 10 al total de T. Entonces: total=30.  
  ![ed7](https://imgur.com/SeH4TvE.png)  
  Como podemos observar, todos los caminos que llevan a T han quedado clausurados. Entonces, la máxima cantidad de agua que podemos tener en T es 30.  
  ![ed8](https://imgur.com/y7uoMRY.png)  
  
 ##### DFS - Ford Fulkerson  
  
  Visitaremos los primeros nodos que estén disponibles hasta llegar a T.  
  Entonces, iremos por A, luego por D y llegaremos a T. Como la capacidad mínima del recorrido es 18, restaremos este valor a todas las aristas del camino. Sumaremos 18 al total de T. Entonces: total = 18.  
  ![f0](https://imgur.com/p7MLRZV.png)  
  El grafo se verá de la siguiente manera:  
  ![f1](https://imgur.com/TBozJXa.png)  
  El algoritmo intentará ir por A, pero el único camino de A está clausurado, entonces pasaremos directamente a B.  
  ![f2](https://imgur.com/ToYLLl0.png)  
  Ahora, iremos desde B hasta D para llegar a T. Como la capacidad mínima del recorrido es 2, restaremos este valor a todas las aristas del camino. Sumaremos 2 al total de T. Entonces: total = 20.  
  ![f3](https://imgur.com/stDdNpi.png)  
  El grafo se verá de la siguiente manera:  
  ![f4](https://imgur.com/U03w777.png)  
  Ahora, iremos desde B hasta E para llegar a T, evadiendo nodos que lleven a caminos clausurados. Como la capacidad mínima del recorrido es 10, restaremos este valor a todas las aristas del camino. Sumaremos 10 al total de T. Entonces: total = 30.  
  ![f5](https://imgur.com/LLRgNC0.png)  
  El grafo se verá de la siguiente manera:  
  ![f6](https://imgur.com/CMzMq7e.png)  
  Como todos los caminos a T han quedado clausurados: la máxima cantidad de agua que podemos tener en T es 30.  
   ### Código
  * [Código Ford Fulkerson](https://github.com/marinovivianUPB/Algoritmica/tree/main/Teoria%20de%20Grafos/Maximo%20Flujo/Ford%20Fulkerson/main.cpp)  
  * [Código Edmomds Karp](https://github.com/marinovivianUPB/Algoritmica/blob/main/Teoria%20de%20Grafos/Maximo%20Flujo/Edmonds%20Karp/main.cpp)  
  
## Bibliografía  
Algorithms for Competitive Programming. [Maximum flow - Ford-Fulkerson and Edmonds-Karp](https://cp-algorithms.com/graph/edmonds_karp.html). Algorithms for Competitive Programming.  
Downey, T. [finding max flow using the ford-fulkerson algorithm and matthew mcconaughey](https://downey.io/blog/max-flow-ford-fulkerson-algorithm-explanation/). Downey.  
HackerEarth. [Maximum flow](https://www.hackerearth.com/practice/algorithms/graphs/maximum-flow/tutorial/). HackerEarth.  
WilliamFiset. [Max Flow Ford Fulkerson | Network Flow | Graph Theory](https://www.youtube.com/watch?v=LdOnanfc5TM). YouTube.  
Yadav, P. [Ford-Fulkerson Algorithm for Maximum Flow Problem](https://www.scaler.com/topics/data-structures/ford-fulkerson-algorithm-for-maximum-flow-problem/). Scaler Topics.  
