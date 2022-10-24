<div align="center">

# Algoritmo Kruskal  

 <div align="left">
 
 ### Definición    

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;El Algoritmo de Kruskal busca posicionar solamente las aristas esenciales para unir a todos los nodos de un grafo. Las aristas a posicionar dependen del criterio que se esté utilizando. Los criterios que Kruskal utiliza son: de menor a mayor y de mayor a menor.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Para posicionar las aristas, estas son almacenadas en una cola de prioridad. Son ordenadas en base al criterio definido. Kruskal tomará las aristas dentro de la cola de prioridad y las posicionará si es que los nodos que son unidos por la arista no están unidos. Esto se verifica con ayuda de la estructura de datos Union Find vista en el primer capítulo de este repositorio.  

 #### Ejemplo  
  Tomemos los siguientes nodos:  
  ![k0](https://imgur.com/MKc0cZn.png)  
  Tomemos las siguientes aristas:  
  (A,B,3), (D,C,6), (A,C,6), (B,D,7), (E,F,8), (A,E,9), (B,F,10)  
  Al posicionar la primera, tenemos que A y B no tienen un mismo superpadre, por lo tanto, los unimos con (A,B,3):  
  ![k1](https://imgur.com/scoqlpE.png)  
  Al posicionar la segunda, tenemos que D y C no tienen un mismo superpadre, por lo tanto, los unimos con (D,C,6):  
  ![k2](https://imgur.com/tkt4mUB.png)  
  Al posicionar la tercera, tenemos que A y C no tienen un mismo superpadre, por lo tanto, los unimos con (A,C,6) de tal manera que C sea superpadre de B:  
  ![k3](https://imgur.com/33w9Qlg.png)  
  Al posicionar la cuarta, tenemos que B y D tienen un mismo superpadre. No tomamos en cuenta la arista.  
  Al posicionar la quinta, tenemos que E y F tienen un mismo superpadre, por lo tanto, los unimos con (E,F,8):  
  ![k4](https://imgur.com/5eMmCx4.png)  
  Al posicionar la sexta, tenemos que A y E no tienen un mismo superpadre, por lo tanto, los unimos con (A,E,9) de tal manera que C sea superpadre de E:  
  ![k5](https://imgur.com/QCmy8qU.png)  
  Al posicionar la última, tenemos que B y F tienen un mismo superpadre. No tomamos en cuenta la arista.
  Así tenemos que los caminos más cortos en general son:  
  A --3--> B  
  A --7--> C   
  D --6--> C  
  E --8--> F  
  A --9--> E  
  
   ### Código  
  * [Código](https://github.com/marinovivianUPB/Algoritmica/blob/main/Teoria%20de%20Grafos/Algoritmo%20Kruskal/kruskal/kruskal.cpp)  
  
## Bibliografía  

