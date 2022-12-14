
<div align="center">

# Suffix Trie  

 <div align="left">
 
 ### Definición  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Habiendo explicado Trie, la definición de un Suffix Trie no es difícil de entender. En este caso tomamos un String -o un conjunto de Strings- e incluimos en el Trie todos los posibles sufijos que podemos obtener. Esto quiere decir que tomaremos el String entero, lo posicionaremos, y luego tomaremos el String desde la posición $i$ hasta el caracter final en un bucle hasta que lleguemos al vacío. En este caso el vacío será representado por un caracter extra que añadiremos al String original. Esto siempre nos dará un árbol con $m$ hojas, donde $m$ es el número de caracteres que tiene el String más el caracter especial añadido.  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Para construir un Suffix Trie se utiliza el algoritmo de 
Ukkonen. Este algoritmo indica que construiremos un Suffix Trie para cada prefijo del String. Para realizar cada sub Suffix Trie existen tres reglas:  

* Si ya existe el principio del sufijo a introducir, revisamos las letras consecutivas y las comparamos con las del sufijo. Si faltan letras para formar el sufijo, simplemente se añaden los caracteres correspondientes.  
* Si no existe el principio del sufijo, se crea un nuevo nodo.  
* Si el sufijo ya existe como prefijo de alguna de las ramas del trie, no se hace nada.  
  
 #### Ejemplo  
  
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Veamos un ejemplo con el String A=abbcba:  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Primero, como dijimos en la definición, añadiremos un caracter especial. Entonces, tenemos: A=abbcba$.  
  
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; A continuación utilizaremos el algoritmo de Ukkonen:  
1. Tomamos el prefijo a e introduciremos todos sus sufijos: S=[a].  
  Aplicamos la segunda regla con [a].

  ![st1](https://imgur.com/yaLrvky.png)

2. Tomamos el prefijo ab e introduciremos todos sus sufijos: S=[ab, b].  
  Aplicamos la primera regla con [ab].  
  Aplicamos la segunda regla con [b].

  ![st2](https://imgur.com/fXrmP4T.png)

3. Tomamos el prefijo abb e introduciremos todos sus sufijos: S=[abb, bb, b].  
  Aplicamos la primera regla con [abb, bb].  
  Aplicamos la tercera regla con [b].

![st3](https://imgur.com/ne0lAgN.png)

4. Tomamos el prefijo abbc e introduciremos todos sus sufijos: S=[abbc, bbc, bc, c].  
  Aplicamos la primera regla con [abbc, bbc, bc].  
  Aplicamos la segunda regla con [c].

![st4](https://imgur.com/lwr8GQj.png)
  
5. Tomamos el prefijo abbcb e introduciremos todos sus sufijos: S=[abbcb, bbcb, bcb, cb, b].  
  Aplicamos la primera regla con [abbcb, bbcb, bcb, cb].  
  Aplicamos la tercera regla con [b].

![st5](https://imgur.com/BM4slWg.png)

6. Tomamos el prefijo abbcba e introduciremos todos sus sufijos: S=[abbcba, bbcba, bcba, cba, ba, a].  
  Aplicamos la primera regla con [abbcba, bbcba, bcba, cba, ba].  
  Aplicamos la tercera regla con [a].

![st6](https://imgur.com/LfCGEPZ.png)

7. Tomamos el prefijo abbcba$ e introduciremos todos sus sufijos: S=[abbcba$, bbcba$, bcba$, cba$, ba$, a$, $].  
  Aplicamos la primera regla con todos los sufijos, excepto con [$] con el cual aplicamos la segunda regla.

![st7](https://imgur.com/Iz4lKwj.png)

   ### Código  
  * [Implementacion](https://github.com/marinovivianUPB/Algoritmica/tree/main/Estructura%20de%20Datos/Trie/Variantes/Suffix%20Trie/Codigo)  
  * [Java](https://github.com/marinovivianUPB/Algoritmica/tree/main/Estructura%20de%20Datos/Trie/Variantes/Suffix%20Trie/Codigo/SuffixTree.java)
  * [C++](https://github.com/marinovivianUPB/Algoritmica/tree/main/Estructura%20de%20Datos/Trie/Variantes/Suffix%20Trie/Codigo/suffixTree.cpp)

  
  ## Bibliografía  
  * Enjoy Computer Science Staff. (s. f.).[Suffix Tree Data Structure](https://www.enjoyalgorithms.com/blog/suffix-tree-data-structure). Code Algorithms Pvt. Ltd. : Enjoy Computer Science.  
  * Geeks for Geeks Staff. (2021).[Ukkonen’s Suffix Tree Construction – Part 1](https://www.geeksforgeeks.org/ukkonens-suffix-tree-construction-part-1/). Geeks for Geeks. 
  * Langmead, B. (s.f.). [Tries and suffix tries](https://www.cs.jhu.edu/~langmea/resources/lecture_notes/tries_and_suffix_tries.pdf). Johns Hopskins Whiting School of Engineering.
