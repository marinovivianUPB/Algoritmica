
<div align="center">

# Backtracking  

 <div align="left">
 
 ### Definición  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Backtracking se refiere a un método de construcción de algoritmos. Este método es considerado como un sucesor de la recursividad. Sin embargo, a pesar de derivar de la recursividad, no es un método de Fuerza Bruta.
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Fuerza Bruta es un tipo de estilo de programación que busca forzar la obtención de la respuesta correcta por cualquier medio necesario. De este estilo viene la técnica de recursividad. Esta técnica es empleada cuando se tienen múltiples opciones disponibles para poder construir una respuesta.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Para entender mejor a qué nos referimos, imaginemos que tenemos que encontrar un camino que lleve al objeto A al destino B habiendo tomado N caminos y teniendo múltiples caminos con múltiples bifurcaciones. Si aplicamos recursividad, haremos que A vaya por todas las combinaciones de caminos posible. De los múltiples resultados obtenidos, seleccionaremos N, si existe, y, sino, retornaremos que no existe.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Backtracking aplica una lógica similar, pero con un cambio esencial para reducir el tiempo O(n!) de la recursividad. Dadas múltiples opciones para construir una respuesta, solamente se explorarán las opciones posibles. Con esto queremos decir que el algoritmo identificará ramas que nos darán resultados érroneos antes de explorarlas y las eliminará.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Backtracking usualmente se aplica a problemas en los que tenemos múltiples decisiones que tomar y delimitaciones claras para lo que queremos obtener. Además, resuelve por excelencia problemas de este tipo que además tienen un enfoque en la incrementación o decrementación recursiva de un resultado.
 #### Ejemplo
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Volvamos al ejemplo del objeto A, el destino B y la cantidad de caminos N.  
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Usando recursividad, exploramos caminos que obviamente están mal, porque exceden N.  
 ![ej1](https://imgur.com/Im2mTeU.png) 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Mientras que, aplicando Backtracking, podemos eliminar las ramas en que el número de caminos utilizados exceda N, de manera que solamente exploremos los caminos que todavía tienen posibilidad de darnos la respuesta correcta.
 ![ej2](https://imgur.com/l0MmIrG.png)
 

   ### Código
  * []()
  
  ### Problemas
  * Geppetto  
  * Good Morning!  
