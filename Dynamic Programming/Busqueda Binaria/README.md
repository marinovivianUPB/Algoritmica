<div align="center">

# Búsqueda Binaria    

 <div align="left">
 
 ### Definición  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Búsqueda Binaria es un algoritmo cuyo propósito es encontrar un objeto en un arreglo o en una secuencia en un tiempo O(log n). Logra esto dividiendo el arreglo en 2 partes de manera consecutiva hasta encontrar la posición en que se supone que debería estar el objeto. El algoritmo puede ser recursivo o iterativo. Por cuestiones de simplicidad, solamente veremos la versión iterativa.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Para dividir el arreglo utilizaremos 3 punteros. Uno que apunte al final de la parte del arreglo que estamos revisando y otra que apunte al principio de esta misma parte. Así, empezamos con inicio=0 y final=tamaño(arreglo) en todas las búsquedas. El último puntero revisa el medio de la parte del arreglo en que nos encontramos. El medio siempre será (inicio+final)/2. Es con el puntero medio con el que revisaremos qué parte del arreglo cumple con los requerimientos establecidos por el problema. Si se cumple con la condición, el inicio o el final cambiarán al medio + 1, medio, o medio -1, dependiendo de qué valor asumimos es el correcto. Con esto último queremos decir que nosotros decidimos si queremos elegir el primer falso o el último verdadero al momento de hacer una búsqueda binaria. El proceso concluirá una vez que inicio ya no sea menor a final.

 #### Ejemplo  
 Imaginemos que buscamos el número equivalente a un número n en un arreglo. En nuestro ejemplo, el arreglo contendrá los números naturales de 1 a n+2 en orden, donde n es 4. En este caso tomaremos el último verdadero, evaluando si el objeto del medio es menor o igual a 4.  
 Entonces, primero tendremos:  
 * inicio = 0  
 * final = 5  
 * medio = 2  
 ![bin0](https://imgur.com/G9S3HC8.png)
 Como el objeto del medio es menor a 4, inicio pasa a ser medio + 1.  
 A continuación tenemos:  
 * inicio = 3 
 * final = 5  
 * medio = 4  
  ![bin1](https://imgur.com/2t1eLT7.png)
 Como el objeto del medio es mayor a 4, final pasa a ser medio - 1.  
 Así tenemos:  
 * inicio = 3  
 * final = 3  
 * medio = 3  
  ![bin2](https://imgur.com/cVm41c2.png)
 El algoritmo nos devuelve la posición 3, asumiendo que es allí donde se encuentra la respuesta correcta.  
 Como podemos observar, es en esa posición en que encontramos a 4.  

   ### Código
  * []()  
  
  ### [Problemas]()  
  * [Longitud de Subsecuencia Más Larga: Sin Subsecuencia]()  
  * Sopa de Letras  
  
  ## Bibliografía  
  Programiz Staff. [Binary Search](https://www.programiz.com/dsa/binary-search). Programiz. 
