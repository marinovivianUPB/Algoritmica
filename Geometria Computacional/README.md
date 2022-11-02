<div align="center">

# Geometría Computacional  

 <div align="left">
 
 ### Definición  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Geometría Computacional se refiere a la aplicación de conceptos geométricos a la programación para poder resolver problemas de esta materia por medio de una computadora.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;En esta materia el enfoque estará en el plano cartesiano de dos dimensiones e interacciones entre puntos, rectas y vectores.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Para empezar, un punto y un vector, a pesar de ser dos objetos distintos, pueden ser representados de la misma manera en código:  
  <pre>
  <code>
   Point(double a,double b) {
        x = a;
        y = b;
    } 
    double angle() {
        return atan2(y,x);
    }
    double mod() {
        return sqrt(x*x+y*y);
    }
  </code>
</pre>  
   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Es decir, un punto y un vector serán definidos por sus coordenadas correspondientes y ambos tendrán acceso a un ángulo y un módulo. Esto quiere decir que en geometría computacional podemos tratar a un punto como si en realidad fuera un vector.  
 #### Ejemplo

   ### Código
  * []()  

