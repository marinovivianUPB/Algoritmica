<div align="center">

# Trie  

 <div align="left">
 
 ### Definición  
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Trie es una estructura de datos enfocada a la facilitación de la búsqueda de una secuencia de caracteres dentro de un conjunto de Strings o de caracteres dado. Con esto queremos decir que buscaremos un String A dentro de un conjunto de caracteres B, un conjunto de Strings C o un String S.  
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Realizaremos esta búsqueda construyendo un árbol. Este árbol está compuesto por nodos y cada nodo es un caracter. Los nodos son posicionados de acuerdo a su posición en el String que estamos introduciendo al árbol, iniciando con un vacío. Entonces, del vacío sale la primera letra, de la primera letra sale la segunda y así sucesivamente hasta llegar a un nodo que se marca como el final del String. Al momento de introducir los siguientes Strings, las ramas creadas compartirán una parte de las ramas previamente añadidas si es que tienen prefijos en común. Por ejemplo, si tenemos los Strings "ahorcar" y "ahogar", compartirán la rama A-H-O y continuarán en bifurcaciones distintas.  
 
 #### Ejemplo
  
  ![trie1]([http://url/to/img.png](https://imgur.com/rTFrmYO))
