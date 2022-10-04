<div align="center">

# Union Find  

 <div align="left">
 
 ### Definición  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Union Find es una estructura de datos enfocada a identificar qué elementos de un conjunto se encuentran en un subgrupo especificado. Para entender el objetivo de Union Find, debemos volver al concepto de grafo. Un grafo, en matemática discreta, es un conjunto de objetos que se encuentran interconectados entre sí. Llamaremos a estos objetos, nodos. Entonces, un grafo está compuesto por nodos que tienen conexiones entre ellos. Cabe remarcar que existen nodos que no tienen conexiones, pero no se ahondará en el tema de grafos en esta sección. En Union Find podemos decir que construiremos diversos grafos e identificaremos a qué grafo pertenece qué nodo.  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; En esta estructura, existen nodos padres y nodos hijos. Cada nodo existente tiene un y solo un padre de manera obligatoria y puede o no tener hijos. Varios nodos hijos pueden tener un mismo nodo padre. Un nodo puede ser su propio padre.  
  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Las reglas anteriormente detalladas crean una jerarquía: el superpadre será el nodo que sea su propio padre. Para acortar el método de búsqueda de Union Find y la unión de un nodo con su nuevo padre, nos enfocaremos en el superpadre. Esto se logra haciendo que el nodo superpadre sea padre directo tanto de sus nodos hijos como de los hijos de sus hijos, etc. Esto se logra encontrando a los superpadres del futuro nodo padre y el futuro nodo hijo y creando una relación padre-hijo con los superpadres encontrado.
  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Cabe remarcar que la sintaxis para crear una relación entre nodos en Union Find es: [padre, hijo].
 #### Ejemplo
  
  Tomemos como ejemplo el conjunto A=[0,1,2,3,4,5] y las operaciones [0,1], [1,3], [4,5], [3,4] y [2,3].  
  
  * Al inicializar el Union Find, todos los nodos son padres de sí mismos.  

   ### Código
  * []()
  
  ### Problemas
  * Palabra Compuesta
  * Sopa de Letras
  ### Modificaciones 
  * Suffix Trie
