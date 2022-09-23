<div align="center">

# Trie  

 <div align="left">
 
 ### Definición  
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Trie es una estructura de datos enfocada a la facilitación de la búsqueda de una secuencia de caracteres dentro de un conjunto de Strings o de caracteres dado. Con esto queremos decir que buscaremos un String A dentro de un conjunto de caracteres B, un conjunto de Strings C o un String S.  
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Realizaremos esta búsqueda construyendo un árbol. Este árbol está compuesto por nodos y cada nodo es un caracter que pertenece a un universo definido U. Los nodos son posicionados de acuerdo a su posición en el String que estamos introduciendo al árbol, iniciando con un vacío. Entonces, del vacío sale la primera letra, de la primera letra sale la segunda y así sucesivamente hasta llegar a un nodo que se marca como el final del String. Al momento de introducir los siguientes Strings, las ramas creadas compartirán una parte de las ramas previamente añadidas si es que tienen prefijos en común. Por ejemplo, si tenemos los Strings "ahorcar" y "ahogar", compartirán la rama A-H-O y continuarán en bifurcaciones distintas.  
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;En código, este árbol estará compuesto por mapas o por arrays. Si utilizamos arrays, la búsqueda de nodos será más rápida, pero cada caracter no utilizado en las bifurcaciones de un nodo será marcado como nulo y estaremos sacrificando memoria. Y si utilizamos mapas, no tendremos nodos nulos, pero la búsqueda será de O(n).
 #### Ejemplo
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Introduzcamos el conjunto de Strings C = [AHORCAR, AHOGAR, BOTAR]
  1. Introducimos 'AHORCAR' después de haber creado el nodo vacío. Introducimos cada caracter y marcamos el fin de palabra.
  ![trie1](https://imgur.com/gopoyFK.png)

  2. Ahora, introducimos 'AHOGAR'. Como ya existe el prefijo 'AHO' en el árbol, solamente creamos un nuevo nodo desde 'O' e introducimos 'GAR'. Igualmente, marcamos el fin de palabra.

  ![trie2](https://imgur.com/G1fL3Ab.png)

  3. Por último, ingresamos 'BOTAR'. Como no existen ninguno de los prefijos de 'BOTAR', creamos una nueva rama desde el nodo inicial.

  ![trie3](https://imgur.com/93wwXS1.png)

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Y ya tenemos nuestro Trie.

   ### Código
  * [Mapa](https://github.com/marinovivianUPB/Algoritmica/blob/1a45c7bb83e0090c5acc73a806b567b5588bdc51/Estructura%20de%20Datos/Trie/trieMap.cpp)
  * [Array](https://github.com/marinovivianUPB/Algoritmica/blob/caec4a4a9857d6ca48046b6dbc583d9eb979755e/Estructura%20de%20Datos/Trie/trieArray.cpp)
  
  ### Problemas
  * Palabra Compuesta
  * Sopa de Letras
  ### Modificaciones 
  * Suffix Trie
