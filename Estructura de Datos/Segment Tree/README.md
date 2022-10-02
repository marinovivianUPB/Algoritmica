
<div align="center">

# Segment Tree  

 <div align="left">
 
 ### Definición  
 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Un Segment Tree es una estructura de datos en la que almacenamos los datos de un conjunto y los resultados de las operaciones permitidas entre ellos en distintos nodos que se encuentran en un árbol. Lo que queremos decir con esto es que generalmente se utiliza esta estructura de datos para poder encontrar la respuesta a operaciones entre un conjunto de números dado. La razón por la que se le da este uso es porque encontrar una respuesta a una operación de esta manera toma un tiempo de O(log(n)).  
 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Construiremos un Segment Tree con un formato binario. Con esto queremos decir que cada nodo tendrá como máximo solo dos nodos derivados. Estos nodos derivados representarán las dos mitades que forman el intérvalo de su nodo padre. Entonces, el nodo 0 tiene un intérvalo de [0..N], el nodo 1 de [0..N/2], el nodo 2 de [N/2+1..N], y así sucesivamente hasta llegar a nodos que tienen un intérvalo de tamaño 1.  
 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Una vez que se haya construido el árbol con todos los nodos necesarios, empezaremos a guardar resultados. Los nodos con un intérvalo de tamaño 1 -con un intérvalo [i]- simplemente guardarán en cada uno de sus atributos el valor del conjunto dado que les corresponde. Por ejemplo, el nodo con intérvalo [0] guardará dentro de todos sus atributos el número que se encuentre en la posición 0 del conjunto original dado. Los nodos que tengan un intérvalo mayor a 1, guardarán los resultados de las operaciones entre los valores correspondientes de los nodos que direven de ellos. Por ejemplo, el nodo con el intérvalo [0..1] guardará el resultado de las operaciones a llevar a cabo entre los números almacenados en los nodos con los intérvalos [0] y [1].  
 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Para encontrar el resultado de un intérvalo, tomaremos los índices inicial y final. Como cada nodo representa un intérvalo, buscaremos el resultado solamente en los nodos que se encuentren dentro del intérvalo que estamos buscando. Si el resultado que buscamos ya se encuentra en un nodo, devolveremos ese mismo nodo. Si necesitamos unir dos nodos, entonces realizaremos operaciones entre los atributos de estos nodos y devolveremos el nodo resultante.  
 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Para actualizar el valor de uno de los números del conjunto dado, buscaremos el intérvalo en que se encuentra el nuevo valor y actualizaremos a todos los nodos por encima del nodo cuyo valor modificaremos. Este procedimiento es similar al de la introducción inicial de datos.  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Cabe remarcar que esta estructura de datos se utiliza con monoides. Decimos que un conjunto de números es un monoide si es que es un semigrupo y además tiene un elemento neutro. Entonces, un conjunto S que es un monoide cumple con las siguientes características: 
    Para que sea un semigrupo:
    * Para todo par de números (a,b) que pertenecen a S, el resultado de la operación 'o' entre ellos debe también pertenecer a S. Es decir, aob=c y 'c' pertenece a S. Esta es el la propiedad de operación interna.  
    * Para toda operación 'o' que se realice con los números (a,b,c) que pertenecen a S, el orden de realización no debe afectar el resultado. Es decir, ao(boc) = (aob)oc. Esta es la propiedad asociativa.  
    Para que sea un monoide:
    * Un elemento 'e' debe pertenecer a S tal que la operación entre este elemento y cualquier otro número 'a' del conjunto, nos devuelva el elemento 'a'. Es decir, aoe=a.
 
 #### Ejemplo  
 
 Veamos un ejemplo con un conjunto A={1,3,5,7,9} y la operación de adición. Nuestros nodos tendrán el atributo 'suma'.  
 
 * Nuestro nodo 0 tendrá un intérvalo [0,4]. Como su intérvalo no tiene un tamaño 1, crearemos a sus hijos: los nodos 1 y 2.  
   La mitad de este intérvalo es: 2.  
 * Nuestro nodo 1 tendrá un intérvalo [0,2]. Como su intérvalo no tiene un tamaño 1, crearemos a sus hijos: los nodos 3 y 4.  
   La mitad de este intérvalo es: 1.  
 * Nuestro nodo 3 tendrá un intérvalo [0,1]. Como su intérvalo no tiene un tamaño 1, crearemos a sus hijos: los nodos 7 y 8.  
   La mitad de este intérvalo es: 0.  
 * Nuestro nodo 7 tendrá un intérvalo [0,0]. Como su intérvalo es de un tamaño 1, almacenaremos A[0] en él, que en este caso es 1.  
 ![st1](https://imgur.com/obal63J.png)
 * Nuestro nodo 8 tendrá un intérvalo [1,1]. Como su intérvalo es de un tamaño 1, almacenaremos A[1] en él, que en este caso es 3.  
 ![st2](https://imgur.com/gOgLFJk.png)
 * Guardamos los valores correspondientes en los hijos del nodo 3. Entonces, almacenaremos los resultados de la operación entre los nodos 7 y 8, que en este caso es 4.
  ![st3](https://imgur.com/024fyxb.png)
 * Nuestro nodo 4 tendrá un intérvalo [2,2]. Como su intérvalo es de un tamaño 1, almacenaremos A[2] en él, que en este caso es 5.    
 ![st4](https://imgur.com/Ph1dbay.png)
 * Guardamos los valores correspondientes en los hijos del nodo 1. Entonces, almacenaremos los resultados de la operación entre los nodos 3 y 4, que en este caso es 9. 
  ![st5](https://imgur.com/WOgdsf7.png)
 * Nuestro nodo 2 tendrá un intérvalo [3,4]. Como su intérvalo no tiene un tamaño 1, crearemos a sus hijos: los nodos 5 y 6.  
   La mitad de este intérvalo es: 3  
 * Nuestro nodo 5 tendrá un intérvalo [3,3]. Como su intérvalo es de un tamaño 1, almacenaremos A[3] en él, que en este caso es 7.  
 ![st6](https://imgur.com/IUaCC1N.png)
 * Nuestro nodo 6 tendrá un intérvalo [4,4]. Como su intérvalo es de un tamaño 1, almacenaremos A[4] en él, que en este caso es 9.
 ![st7](https://imgur.com/PWg4gpn.png)
 * Guardamos los valores correspondientes en los hijos del nodo 2. Entonces, almacenaremos los resultados de la operación entre los nodos 5 y 6, que en este caso es 16.  
 ![st8](https://imgur.com/n9AWuNY.png)
 * Guardamos los valores correspondientes en los hijos del nodo 0. Entonces, almacenaremos los resultados de la operación entre los nodos 1 y 2, que en este caso es 25.  
 ![st9](https://imgur.com/6jqZLDg.png)
   ### Código  
  * []()  
  
  ### Problemas  
  * Palabra Compuesta  
  * Sopa de Letras  
  ### Modificaciones   
  * Suffix Trie  
  
  ## Bibliografía  
  * Sharma, A. (s. f.). [Segment Trees](https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/). HackerEarth.
  * Algorithms for Competitive Programming. (2022). [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html). Competitive Programming Algorithms.
  * 
