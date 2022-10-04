<div align="center">

# Union Find  

 <div align="left">
 
 ### Definición  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Union Find es una estructura de datos enfocada a identificar qué elementos de un conjunto se encuentran en un subgrupo especificado. Para entender el objetivo de Union Find, debemos volver al concepto de grafo. Un grafo, en matemática discreta, es un conjunto de objetos que se encuentran interconectados entre sí. Llamaremos a estos objetos, nodos. Entonces, un grafo está compuesto por nodos que tienen conexiones entre ellos. Cabe remarcar que existen nodos que no tienen conexiones, pero no se ahondará en el tema de grafos en esta sección. En Union Find podemos decir que construiremos diversos grafos e identificaremos a qué grafo pertenece qué nodo.  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; En esta estructura, existen nodos padres y nodos hijos. Cada nodo existente tiene un y solo un padre de manera obligatoria y puede o no tener hijos. Varios nodos hijos pueden tener un mismo nodo padre. Un nodo puede ser su propio padre.  
  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Las reglas anteriormente detalladas crean una jerarquía: el superpadre será el nodo que sea su propio padre. Para acortar el método de búsqueda de Union Find y la unión de un nodo con su nuevo padre, nos enfocaremos en el superpadre. Esto se logra haciendo que el nodo superpadre sea padre directo tanto de sus nodos hijos como de los hijos de sus hijos, etc. Esto se logra encontrando a los superpadres del futuro nodo padre y el futuro nodo hijo y creando una relación padre-hijo con los superpadres encontrado.
  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Cabe remarcar que la sintaxis para crear una relación entre nodos en Union Find es: [hijo, padre].
 #### Ejemplo
  
  Tomemos como ejemplo el conjunto A=[0,1,2,3,4,5] y las operaciones [1,0], [3,1], [5,4], [4,3] y [3,2].  
  
  * Al inicializar el Union Find, todos los nodos son padres de sí mismos.  
  ![uf0](https://imgur.com/5hHlQ5q.png)
  * [1,0]: Ahora 0 será padre de 1. El superpadre de 0 es 0 y el de 1 es 1. Ahora 0 es padre de 1.  
  ![uf1](https://imgur.com/g2ZSmqN.png)
  * [3,1]: Ahora 1 será padre de 3. El superpadre de 1 es 0 y el de 3 es 3. Ahora 0 es padre de 3.  
  ![uf2](https://imgur.com/t6SHCOB.png)
  * [5,4]: Ahora 4 será padre de 5. El superpadre de 4 es 4 y el de 5 es 5. Ahora 4 es padre de 5.  
  ![uf3](https://imgur.com/UtihrlN.png)
  * [4,3]: Ahora 3 será padre de 4. El superpadre de 3 es 0 y el de 4 es 4. Ahora 0 es padre de 4.  
  * Actualizamos el padre de 5, que ahora es 0. 
  ![uf4](https://imgur.com/90fYXHs.png)
  * [3,2]: Ahora 2 será padre de 3. El superpadre de 2 es 2 y el de 3 es 0. Ahora 2 es padre de 0.  
  * Actualizamos el padre de 1, 3, 4 y 5, que ahora es 2. 
  ![uf5](https://imgur.com/6WmA5Cr.png)
  
   ### Código
  * []()
  
  ### Problemas
  * Palabra Compuesta
  * Sopa de Letras
  ### Modificaciones 
  * Suffix Trie
