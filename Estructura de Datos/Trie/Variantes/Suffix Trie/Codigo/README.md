<div align="center">

# Implementacion de Suffix Trie  

 <div align="left">
 
 ### Explicación  
   Si implementamos el algoritmo de Ukkonen como lo explicamos, nos encontramos con el problema de que puede llegar a O(n^3). Esto quiere decir que el algoritmo es pesado y no es eficiente. Entonces, para hacer un programa que construya un Suffix Trie, hay que realizar ciertas modificaciones.  
Todavía trabajaremos con los sufijos de los prefijos del String a insertar. También le añadiremos un caracter especial al final del String original. Sin embargo, esta vez las incersiones se realizarán de manera más directa, recordando los sufijos implícitos (que se encuentran como prefijos de ramas) y uniendo bifurcaciones de distintas ramas.  

Cada vez que cambiemos un prefijo, diremos que hemos cambiado de fase y cada vez que añadamos el sufijo más básico de un prefijo o un acarreo diremos que hemos cambiado de extensión. Las bifurcaciones serán renombradas a nodos internos. Además, no todos los caracteres tendrán un nodo correspondiente, más bien, la mayoría de los nodos tendrá una línea de texto. También tendremos un artefacto 'activo' compuesto por el nodo del que partiremos -nodo activo-, la posición desde el nodo después de la que haremos una incersión -distancia activa- y el caracter del nodo en la posición equivalente a la distancia activa -caracter activo-. Por último, será necesario el uso de un contador de sufijos a añadir.  
