<div align="center">  

# Método Delete  

 <div align="left">  
   
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;El Método Delete se refiere a un método para la estructura de datos Trie. Este método, como indica su nombre, elimina objetos del Trie. En este caso, dichos objetos son los nodos que componen una palabra. Entonces, con el Método Delete, sacamos una palabra del Trie.  
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Para implementar esta herramienta, primero tenemos que implementar la herramienta isEmpty(). Los métodos isEmpty se encargan de indicar si un objeto está vacío o no. En este caso, el método isEmpty() revisará si el array children[] de un nodo está lleno de NULLS. Si encuentra algún nodo almacenado en el array, isEmpty() retornará false. Si llega al final del for sin haber encontrado un nodo inicializado, retornará true.  
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Volviendo al Método Delete, este método será recursivo. Primeo, ingresaremos el nodo root, la palabra que queremos eliminar y un puntero que inicia en 0. A continuación, recorremos los nodos que conforman la palabra. Al llegar al final, pondremos false en isWord y revisareos si el nodo está vacío, de ser este el caso, el nodoActual será eliminado y se volverá nulo. Se devolverá este mismo nodo nulo, para eliminarlo como hijo de su nodo padre. Entonces, se revisará si el nodo padre está vacío y no es final de palabra. De ser este el caso, se eliminará el nodo y se volverá nulo. Cualquiera sea el caso, se devolverá el nodo a su padre para que la modificación se guarde. Y así sucesivamente.  
 
### Código
[Array](https://github.com/marinovivianUPB/Algoritmica/edit/main/Estructura%20de%20Datos/Trie/Variantes/Metodo%20Delete/metodoDeleteArray.cpp)

  ## Bibliografía
  * Mallik, S. (2022). [Delete nodes from trie](https://www.codingninjas.com/codestudio/library/delete-nodes-from-trie). Coding Ninjas: CodeStudio.
  * More, N. (s. f.). [Trie Data Structure | Delete](https://www.ideserve.co.in/learn/trie-delete). IDeserve.
  * TutorialsPoint.dev Staff. [Trie | (Delete)](https://tutorialspoint.dev/data-structure/advanced-data-structures/trie-delete). TutorialsPoint.dev.
