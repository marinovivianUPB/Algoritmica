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
   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Es decir, un punto y un vector serán definidos por sus coordenadas correspondientes y ambos tendrán acceso a un ángulo y un módulo. Esto quiere decir que en geometría computacional podemos tratar a un punto como si en realidad fuera un vector. Las rectas serán la resta entre dos puntos de tal manera que la recta BA sea equivalente a A-B. Un vector también puede estar definido por la resta entre dos puntos.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A continuación codificaremos las operaciones básicas entre vectores:  
   <pre>
  <code>
   Point operator +(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator -(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y-b.y); 
}
  </code>
</pre> 
  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;La adición y la substracción son simples. Simplemente la aplicaremos entre las coordenadas x y y por separado para obtener un nuevo punto/vector.  
  <pre>
  <code>
  Point operator *(const Point &a, double k) {
    return Point(a.x*k,a.y*k); 
}

Point operator /(const Point &a, double k) {
    return Point(a.x/k, a.y/k); 
}
  </code>
  </pre>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;La multiplicación y división solamente pueden realizarse entre un punto y un escalar, es decir, entre un punto y un número entero. Nuevamente, esto nos devolverá un nuevo punto/vector.  
  <pre>
  <code>
  Point ort()   { 
  return Point(-y, x); 
  }
      Point unit() {
        double modulo = mod();
        return Point(x/modulo, y/modulo);
    }
    
    double dot(const Point &A, const Point &B) {
    return A.x * B.x + A.y * B.y; 
}

double cross(const Point &V, const Point &U) {
    return V.x * U.y - V.y * U.x;
}
double dist(const Point &A, const Point &B) {
    return hypot(A.x-B.x,A.y - B.y);
}
  </code>
  </pre>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Las operaciones específicas de vectores son más complejas:  
  * Para obtener un vector ortogonal, utilizaremos ort(). Simplemente devolveremos un punto cuyas coordenadas sean -y en x y x en y.  
  * Tenemos unit() que se refiere al vector unitario. Un vector unitario es aquel cuyo módulo es equivalente a 1. Para hallar un vector unitario a partir de otro simplemente se deben dividir las componentes del vector por su módulo.  
  * El método dot() se refiere al producto punto de dos vectores. El producto punto es la multiplicación entre dos vectores. También se denomina producto escalar. De este segundo nombre, podemos deducir correctamente que esta operación nos devuelve un escalar.  
  * El método cross() se refiere al productor cruz entre dos vectores. Esta operación nos devuelve un vector que forma un ángulo recto con el plano definido por los vectores de los que proviene. El área de este plano es equivalente a la magnitud del vector resultante. Entonces, como solamente se está trabajando con dos dimensiones, el producto cruz nos devolverá un escalar que es equivalente al área entre los vectores que utilizamos en la operación. Algo a denotar del producto cruz es que su valor puede ser negativo o positivo. Si es que el primer vector debe ir en sentido antihorario para alcanzar el segundo vector, el valor del producto cruz será positivo. Caso contrario será negativo.  
  * El método dist() se refiere a encontrar la distnacia entre dos puntos. Esta distancia estará definida por el módulo del vector que se forma con los dos puntos.  
  <pre>
  <code>
  double areaP(const Point &V, const Point &U) {
    return abs(cross(V,U));
} 

double area(const Point &A, const Point &B, const Point &C) {
    return cross(B - A, C - A); // 1
}


double areaTriangulo(const Point &A, const Point &B, const Point &C) {
    return abs(area(A,B,C))/2.; 
}
  </code>
  </pre>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Las operaciones de figuras pueden parecer difíciles, pero solamente derivan de operaciones que ya se vieron anteriormente. Primero, areaP() se refiere al área del paralelogramo que forman dos vectores, por lo cual simplemente devuelve el valor absoluto del punto cruz entre ellos. A continuación area() utiliza tres puntos para formar dos rectas y encontrar el punto cruz entre ellas. Por último, areaTriangulo() toma los tres puntos que forman un triángulo, los envía al método area() y divide el resultado entre dos.  
    <pre>
  <code>
  Point lineIntersection(const Point &A,const Point &B,const Point &C,const Point &D) {
    return A+(B-A)*(cross(C-A,D-C)/cross(B-A,D-C));
}
  </code>
  </pre>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A continuación veamos un problema simple: encontremos el punto de intersección entre dos rectas. Recordemos que:  
  <div align="center">  
   P(x,y)= A+k<sub>1</sub>AB
  <div align="left">  
   Con esto queremos decir que podemos obtener cualquier punto de una recta si tenemos un punto inicial, un vector AB y un valor k<sub>1</sub> llamado parámetro.  
   En nuestro caso tenemos el vector y el punto inicial, por lo cual debemos encontrar el valor de k<sub>1</sub>. Como estamos buscando el punto de intersección entre dos rectas, sabemos que podemos obtener este punto de intersección a partir de cualquiera de las ecuaciones de las rectas. Así, las igualaremos:  
<div align="center">  
A+k<sub>1</sub>AB=C+k<sub>2</sub>CD <br> 
k<sub>1</sub>AB-k<sub>2</sub>CD=C-A  <br>
k<sub>1</sub>AB-k<sub>2</sub>CD=AC //xCD  <br>
k<sub>1</sub>ABxCD=ACxCD  <br>
k<sub>1</sub>=(ACxCD)/(ABxCD)  <br>
<div align="left">  
    <pre>
  <code>
  </code>
  </pre>
  
    <pre>
  <code>
  </code>
  </pre>
  #### Ejemplo

   ### Código
  * []()  

