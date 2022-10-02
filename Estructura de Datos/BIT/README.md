<div align="center">

# BIT  

 <div align="left">
 
 ### Definición  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Un BIT, también conocido como Fenwick Tree, es una estructura de datos que almacena los resultados de un operación -u operaciones- determinada en un intérvalo [0..j]. Esto con el propósito de solamente tener que obtener el resultado de la operación inversa entre los intérvalos [0..i] y [0..j] para poder obtener el resultado de la operación para el intérvalo [i..j].  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Aunque le llamemos Tree, en realidad el árbol como tal no existe. Todos los datos en realidad están guardados en un arreglo. Además, a diferencia de la estructura Segment Tree, no guardamos todos los valores del conjunto dado. Priorizamos el almacenamiento de la operación realizada en intérvalos de tamaños mayores a 1.
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Para poder construir un BIT, Binary Indexed Tree, debemos primero entender la operacion binaria Complemento 1. El complemento 1 de un número binario es aquel que convierte los 1's del original en 0's y los 0's en 1's. Entonces si tenemos 11, su complemento 1 será 00. De esta operación derivará una segunda operación '-n', donde -n = complemento1(n)	<sub> 2 </sub>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
     
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Cabe remarcar que esta estructura de datos se utiliza con grupos. Decimos que un conjunto de números es un grupo si es que es un monoide y además tiene un elemento inverso. Entonces, un conjunto S que es un grupo cumple con las siguientes características:   
    Para que sea un monoide:  
* Para todo par de números (a,b) que pertenecen a S, el resultado de la operación 'o' entre ellos debe también pertenecer a S. Es decir, aob=c y 'c' pertenece a S. Esta es el la propiedad de operación interna.  
* Para toda operación 'o' que se realice con los números (a,b,c) que pertenecen a S, el orden de realización no debe afectar el resultado. Es decir, ao(boc) = (aob)oc. Esta es la propiedad asociativa.  
* Un elemento 'e' debe pertenecer a S tal que la operación entre este elemento y cualquier otro número 'a' del conjunto, nos devuelva el elemento 'a'. Es decir, aoe=a. Esta es la propiedad neutra.  
    Para que sea un grupo:  
* Cada elemento 'a' del conjunto debe tener un inverso 'I' tal que la operación o entre estos dos elementos nos devuelva el elemento neutro 'e'. Es decir, aoI=e y Ioa=e. Esta es la propiedad inversa.  
    
