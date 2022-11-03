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
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Con esto queremos decir que podemos obtener cualquier punto de una recta si tenemos un punto inicial, un vector AB y un valor k<sub>1</sub> llamado parámetro.  
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;En nuestro caso tenemos el vector y el punto inicial, por lo cual debemos encontrar el valor de k<sub>1</sub>. Como estamos buscando el punto de intersección entre dos rectas, sabemos que podemos obtener este punto de intersección a partir de cualquiera de las ecuaciones de las rectas. Así, las igualaremos:  
<div align="center">  
A+k<sub>1</sub>AB=C+k<sub>2</sub>CD <br> 
k<sub>1</sub>AB-k<sub>2</sub>CD=C-A  <br>
k<sub>1</sub>AB-k<sub>2</sub>CD=AC //xCD  <br>
k<sub>1</sub>ABxCD=ACxCD  <br>
k<sub>1</sub>=(ACxCD)/(ABxCD)  <br>
<div align="left">  
 Entonces, k<sub>1</sub>=cross(C-A,D-C)/cross(B-A,D-C). Y así obtenemos:  A+(B-A)*(cross(C-A,D-C)/cross(B-A,D-C))  
    <pre>
  <code>
  bool onSegment(const Point &A, const Point&B, const Point &P) {
    return areaTriangulo(A,B,P) == 0 && 
        (P.x >= min(A.x,B.x) && P.x <= max(A.x,B.x)) && 
        (P.y >= min(A.y,B.y) && P.y <= max(A.y,B.y));
  }
  </code>
  </pre>
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Si un punto se encuentra en una recta, entonces:  
   * No podrá formar un triángulo con ella, porque no se puede tener un triángulo con área 0.  
   * No podrá ser más grande o más pequeño que ninguno de los dos extremos de la recta. Con esto queremos decir que sus coordenadas se encontrarán en un rango específico. Es decir: A.x||B.x<=P.x<=A.x||B.x && A.y||B.y<=P.y<=A.y||B.y  
  <pre>
  <code>
bool intersectsSegment(const Point &A,const Point &B,const Point &C,const Point &D) {
    double A1 = area(C,D,A); 
    double A2 = area(C,D,B);   
    double A3 = area(A,B,C);   
    double A4 = area(A,B,D);   

    if(((A1 > 0 && A2 < 0) || (A1<0 && A2>0)) && 
        ((A3 > 0 && A4 < 0) || (A3<0 && A4>0)))  {
            return true;
    }

    if(A1 == 0 && onSegment(C,D,A)) {
        return true;
    }

    if(A2 == 0 && onSegment(C,D,B)) {
        return true;
    }

    if(A3 == 0 && onSegment(A,B,C)) {
        return true;
    }

    if(A4 == 0 && onSegment(A,B,D)) {
        return true;
    }

    return false;
}
  </code>
  </pre>  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Para que dos rectas intersecten:  
  * Los puntos que las componen estarán en lados opuestos. Con esto queremos decir que los cuatro extremos se encontrarán alrededor de un punto.  
  * O, algún extremo de alguna de las rectas estará dentro de la otra.  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Así definimos que para que los cuatro extremos estén en lados opuestos, usando una recta como pivote, los productos cruz entre esta recta y los extremos de la otra deben tener signos opuestos. O, en todo caso, el área entre una recta y un extremo debe ser 0 y el extremo debe encontrarse dentro de la recta.  
  <pre>
  <code>
  bool isConvex(const vector<Point> &polign) {
    int nroPoints = polign.size();    // 1
    int areasPositive =  0, areasNegative = 0; // 2
    for(int i = 0; i < nroPoints ;i++) {  // n
        double areaPoints = area(polign[i],polign[(i+1)%nroPoints],polign[(i+2)%nroPoints]);  // 3
        if(areaPoints>0) {  // 3
           areasPositive++; // 2
        } else if(areaPoints<0) {
           areasNegative++; // 2
        }
    }
    return areasPositive == 0 || areasNegative == 0; // 3 
}
  </code>
  </pre>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Definimos un polígono convexo como un polígono cuyos vértices no tienen un ángulo mayor o igual a 180º. Podemos también decir que si múltiples rectas dividieran el polígono, ellas solo intersectarían con dos puntos. Una última manera común de definir un polígono convexo es decir que sus puntas apuntan hacia fuera de la figura y no dentro de ella.  
  ![geo0](https://imgur.com/eRMaU6P.png)  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;En geometría computacional definimos un polígono convexo como aquel polígono cuyos sentidos de giro tienen el mismo signo. La operación que nos indica el giro es cross(), pero la operación que nos devuelve esta respuesta cuando especificamos tres puntos es area(). Así, para cada vértice del polígno V<sub>i</sub>, realizaremos la operación: area(V<sub>i</sub>,V<sub>i+1</sub>V<sub>i+2</sub>). Si el resultado es positivo, aumentará el contador positivo, caso contrario aumentará el contador negativo. Al final del método devolveremos si alguno de los contadores se mantuvo en 0.  
      <pre>
  <code>
  double areaPoligono(const vector<Point> &poligono) {
    int nroPoints = poligono.size(); 
    double areaTotal = 0; 
    for(int i = 1; i < nroPoints - 1; i++) {
        areaTotal += area(poligono[0],poligono[i],poligono[i+1]); 
    }
    return abs(areaTotal/2);
}
  </code>
  </pre>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Para calcular el área de un polígono basta con partir de un punto cualquiera y calcular las rectas que lo llevan a los demás puntos. Así, dividimos el polígono en múltiples triángulos. Entonces, podemos aplicar la operacion areaTriangulo() o podemos aplicar area() y dividr el total en dos cuando ya hayamos obtenido la suma de las áreas.   
    ![geo1](https://imgur.com/7sptQUC.png)  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Entonces, para un punto V<sub>0</sub>, realizaremos la operación area(V<sub>0</sub>,V<sub>i</sub>,V<sub>i+1</sub>) y sumaremos el resultado al área total hasta que i=n-1, donde n es el número de puntos que componen el polígono.  
  <pre>
  <code>
  vector<Point> convexHull(vector<Point> &points) {
    sort(points.begin(),points.end());
    int k = 0;
    Point hulls[points.size()+100];
    
    for(int i = 0; i<points.size();i++){
        while(k>=2 && area(hulls[k-2],hulls[k-1],points[i])<=0) {
            k--; // stack.pop();
        }
        hulls[k++] = points[i];
    }
    
    for(int i = points.size()-2, t = k;i>=0; i--) {
        while( k > t && area(hulls[k-2],hulls[k-1],points[i])<= 0){
            k--;
        }
        hulls[k++] = points[i];
    }
    
    return vector<Point> (hulls,hulls+k-1);
}
  </code>
  </pre>
  
   ### Código
  * []()  

## Bibliografía  
A, A. (s. f.). [Scalar Product of Vectors](http://hyperphysics.phy-astr.gsu.edu/hbase/vsca.html). HyperPhysics.  
Easy Math. (2017). [10. Unit vectors, what are they and how to calculate them? With graphic | vector calculus](https://www.youtube.com/watch?v=cfe-IS-gNoU). YouTube.  
Lambers, J. (2009-2010). [Equations of Lines](https://www.math.usm.edu/lambers/mat169/fall09/lecture25.pdf). The University of Southern Mississippi: School of Mathematics and Natural Sciences.   
Math's Fun. (s. f.). [Cross Product](https://www.mathsisfun.com/algebra/vectors-cross-product.html). Rod Pierce.  
