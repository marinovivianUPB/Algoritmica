<div align="center">

# Algoritmo PRIM    

 <div align="left">
 
 ### Definición  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;El algoritmo PRIM busca encontrar los caminos con el menor costo posible de un nodo especificado A a todos los otros nodos del grafo. Realiza esta tarea considerando todos los posibles caminos en orden del más pequeño al más grande. Para entender el funcionamiento de PRIM, veamos un ejemplo:  

 #### Ejemplo  
   
   Tomemos el siguiente grafo:  
   ![prim0](https://imgur.com/oN2l8bu.png)  
   Dado este grafo, iniciemos con el nodo B:  
   * Caminos: B  
   * Posibilidades: (B,D,3), (B,F,4)  
   ![prim1](https://imgur.com/TGKn73k.png)  
   Tomemos el camino más corto y visitemos D:  
   * Caminos: B-D  
   * Posibilidades: (B,F,4), (D,E,4), (D,F,5), (D,A,7) 
   ![prim2](https://imgur.com/TN1ip5p.png)  
   Tomemos el camino más corto y visitemos F desde B, con eso descartamos cualquier otro camino que lleve a F:  
   * Caminos: B-D, B-F  
   * Posibilidades: (D,E,4), (D,A,7)      
   ![prim3](https://imgur.com/tXrTZEz.png)  
   Tomemos el camino más corto y visitemos E, por medio de D:  
   * Caminos: B-D-E, B-F  
   * Posibilidades: (E,C,6), (D,A,7)      
   ![prim4](https://imgur.com/04j3D44.png)  
   Tomemos el camino más corto y visitemos C, por medio de E:  
   * Caminos: B-D-E-C, B-F  
   * Posibilidades: (D,A,7)  
   * No añadimos ningún camino porque D ya fue visitado.  
   ![prim5](https://imgur.com/3PZ1J4G.png)  
   Tomemos el último camino posible y visitemos A por medio de D:  
   * Caminos: B-D-E-C, B-F, B-D-A  
   * Nuevamente, no añadimos ningún camino porque B y C ya fueron visitados.  
   ![prim6](https://imgur.com/kB4L6I4.png)  
   
   Así, tenemos todos los caminos más cortos del nodo B a todos los demás nodos.  
   
   
   ### Código
  * [Sin Cola de Prioridad](https://github.com/marinovivianUPB/Algoritmica/blob/main/Teoria%20de%20Grafos/Algoritmo%20PRIM/Sin%20Cola%20de%20Prioridad/prim.cpp)  
  * [Con Cola de Prioridad](https://github.com/marinovivianUPB/Algoritmica/blob/main/Teoria%20de%20Grafos/Algoritmo%20PRIM/Con%20Cola%20de%20Prioridad/prim.cpp)  
  
  ### Problemas
  * Palabra Compuesta
  * Sopa de Letras
  ### Modificaciones 
  * Suffix Trie
