<div align="center">

# Implementacion de Suffix Trie  

 <div align="left">
 
### Explicación  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Si implementamos el algoritmo de Ukkonen como lo explicamos, nos encontramos con el problema de que puede llegar a O(n^3). Esto quiere decir que el algoritmo es pesado y no es eficiente. Entonces, para hacer un programa que construya un Suffix Trie, hay que realizar ciertas modificaciones.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Todavía trabajaremos con los sufijos de los prefijos del String a insertar. También le añadiremos un caracter especial al final del String original. Sin embargo, esta vez las incersiones se realizarán de manera más directa, recordando los sufijos implícitos (que se encuentran como prefijos de ramas) y uniendo bifurcaciones de distintas ramas.  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Cada vez que cambiemos un prefijo, diremos que hemos cambiado de fase y cada vez que añadamos el sufijo más básico de un prefijo o un acarreo diremos que hemos cambiado de extensión. Las bifurcaciones serán renombradas a nodos internos. Además, no todos los caracteres tendrán un nodo correspondiente, más bien, la mayoría de los nodos tendrá una línea de texto. También tendremos un artefacto 'activo' compuesto por el nodo del que partiremos -nodo activo-, la posición desde el nodo después de la que haremos una incersión -distancia activa- y el caracter del nodo en la posición equivalente a la distancia activa -caracter activo-. Por último, será necesario el uso de un contador de sufijos a añadir.  

### Reglas

* Cada cambio de fase sumamos uno al contador de sufijos a añadir. Cada cambio de extensión restamos uno al contador de sufijos a añadir.
* Cada fase añadimos el nuevo caracter tomado al final de todos los caminos existentes.
* Cada cambio de fase añadimos el caracter del String original en la posición equivalente a la fase en que nos encontramos a los sufijos acarreados.  
* Cada que creemos un nodo interno en una fase, el nodo creado anteriormente apuntará a este nuevo nodo, a menos que el nodo anterior sea nulo.   
* Si el sufijo a insertar no existe después del caracter activo en la distancia activa dentro del nodo activo, lo añadiremos y hacemos un cambio de extensión. Aquí, si nos encontramos en el nodo inicial -root-, el nuevo caracter activo será el primer caracter del siguiente sufijo a ingresar y la distancia activa reduce en uno.   
* Si ya existe un caracter distinto en el lugar en que debería ir este nuevo sufijo, crearemos un nodo interno que marque la bifurcación.  
* Si una parte del sufijo a insertar existe después del caracter activo en la distancia activa del nodo activo, sumamos uno a la distancia activa por cada caracter ya presente. Si de pronto la distancia excede en número de caracteres dentro del nodo, saltamos al nodo interno que sigue.    
* Si el sufijo a insertar ya existe por completo en una rama, pasamos a la siguiente fase sin restar el contador de sufijos a añadir.  

### Ejemplo  
  1. Tomamos [a].  
  Contador de sufijos = 1  
  activo(root,'&nbsp;',0)  
  Añadimos [a] como un nuevo nodo.  
  Restamos uno al contador de sufijos.  
  Contador de sufijos = 0  
  
  ![i1](https://imgur.com/V8BX1ni.png)

  2. Tomamos [ab].       
  Contador de sufijos = 1  
  activo(root,'&nbsp;',0)  
  Añadimos [b] como un nuevo nodo.  
  Restamos uno al contador de sufijos.  
  Contador de sufijos = 0  
  
  ![i2](https://imgur.com/qVDB9zK.png)

  3. Tomamos [abb].      
  Contador de sufijos = 1  
  activo(root,'&nbsp;',0)  
  nuevo activo(root, 'b', 1)  
  
  ![i3](https://imgur.com/l5EuvPR.png)

  4. Tomamos [abbc].  
  Acarreamos [bc].  
  Contador de sufijos = 2  
  activo(root,'b', 1)  
  Añadimos [c] después de la posición 1 que corresponde a 'b' en el nodo root.  
  Creamos un nuevo nodo interno.
  Restamos uno al contador de sufijos. 
  nuevo activo(root, 'c', 0)  
  Añadimos [c] como un nuevo nodo.  
  Restamos uno al contador de sufijos.  
  Contador de sufijos = 0  
  
  ![i4](https://imgur.com/jnWnNmk.png)
  

  5. Tomamos [abbcb].        
  Contador de sufijos = 1  
  activo(root,'c', 0)  
  nuevo activo(root, 'b', 1)   
  
  ![i5](https://imgur.com/E7BZQhS.png)

  6. Tomamos [abbcba].      
  Acarreamos [ba].  
  Contador de sufijos = 2  
  activo(root,'b', 1)  
  Añadimos [a] después de la posición 1 que corresponde a 'b' en el nodo root.  
  Restamos uno al contador de sufijos. 
  nuevo activo(root, 'a', 0)  
  nuevo activo(root, 'a', 1)  
  Contador de sufijos = 1  
  
  ![i6](https://imgur.com/qyYX2xe.png)

  7. Tomamos [abbcba$].      
  Acarreamos [a$].  
  Contador de sufijos = 2  
  activo(root,'a', 1)  
  Añadimos [$] después de la posición 1 que corresponde a 'a' en el nodo root.  
  Creamos un nuevo nodo interno.  
  Restamos uno al contador de sufijos. 
  nuevo activo(root, '$', 0)  
  Añadimos [$] como un nuevo nodo. 
  
  ![i7](https://imgur.com/XKYj9Sa.png)  
  
  ### Código
  * [Java](https://github.com/marinovivianUPB/Algoritmica/tree/main/Estructura%20de%20Datos/Trie/Variantes/Suffix%20Trie/Codigo/SuffixTree.java)  
  * [C++](https://github.com/marinovivianUPB/Algoritmica/tree/main/Estructura%20de%20Datos/Trie/Variantes/Suffix%20Trie/Codigo/suffixTree.cpp)  
  
  ## Bibliografía
  
  Tushar Roy- Coding Made Simple. (2015). [Suffix Tree using Ukkonen's algorithm](https://www.youtube.com/watch?v=aPRqocoBsFQ). YouTube.  
  StackOverflow User. (2019). [Ukkonen's suffix tree algorithm in plain English](https://stackoverflow.com/questions/9452701/ukkonens-suffix-tree-algorithm-in-plain-english). Stack Exchange, Inc.: StackOverflow.   
  
