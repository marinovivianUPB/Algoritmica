<div align="center">

# Máximo Flujo  

 <div align="left">
 
 ### Definición  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Máximo Flujo se refiere a un problema en el que teniendo un sistema de cañerías compuesto por cañerías con una capacidad máxima y puntos de conexión entre ellas, queremos saber cuánta agua puede llegar del punto inicial S al punto final T si S envía una cantidad infinita de agua. La cantidad de agua que llegará a T será el resultado de la exploración de todos los caminos posibles que lleguen a T. Un camino quedará obsoleto una vez que las cañerías que lo conectan a T hayan llegado a su máxima capacidad.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Queda claro que se puede aplicar teoría de grafos a este problema. Entonces, tendremos un grafo donde cada punto de conexión es un nodo y cada cañería es una arista direccionada con peso. De esta manera, la exploración de los caminos se puede realizar con los algoritmos de exploración BFS y DFS, con ciertas modificaciones. Cada que se recorra un camino, la cantidad de agua que llegó al punto T por medio de este se restará a todas las aristas que lo componen, simbolizando la capacidad ocupada de cada cañería. Esta cantidad de agua se encontrará buscando la mínima capacidad de entre las cañaerías que componen el camino. Además, se accionarán los algoritmos de búsqueda hasta que se hayan explorado todos los caminos posibles para obtener la máxima cantidad de agua que puede llegar al punto T.  

 #### Ejemplo  
 
 Utilicemos el grafo siguiente:  
 
 ##### BFS - Edmonds Karp  
 

 ##### DFS - Ford Fulkerson  

   ### Código
  * [Código Ford Fulkerson](https://github.com/marinovivianUPB/Algoritmica/tree/main/Teoria%20de%20Grafos/Maximo%20Flujo/Ford%20Fulkerson/main.cpp)  
  * [Código Edmomds Karp](https://github.com/marinovivianUPB/Algoritmica/blob/main/Teoria%20de%20Grafos/Maximo%20Flujo/Edmonds%20Karp/main.cpp)  
  
