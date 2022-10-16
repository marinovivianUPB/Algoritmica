<div align="center">

# Dynamic Programming  

 <div align="left">
 
 ### Definición  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;La Programación Dinámica (DP) es un método de programación que busca la solución más eficaz y eficiente para un problema complejo. Esta solución es encontrada de tal manera que cumpla los siguientes requirimientos: divide problemas grandes en problemas más pequeños hasta llegar a casos base, guarda la solución de los problemas pequeños y resuelve todo sub-problema una sola vez. Para asegurar que una solución sea DP también deberemos construirla con 4 pasos en mente: visualizar, identificar sub-problemas, encontrar la relación entre subproblemas e implementar la solución.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Para considerar un algoritmo como de tipo DP, tiene que cumplir los tres requirimientos detallados anteriormente. Con el primero, nos referimos a que todo caso de prueba está compuesto de otros casos de prueba. Si queremos encontrar el factorial de 5, debemos encontrar el factorial de 4; si queremos encontrar el factorial de 4, debemos encontrar el factorial de 3; por ejemplo. Así, la solución a un problema específico estará compuesto de las soluciones de los sub-problemas que lo componen. El segundo requerimiento simplemente hace más fácil el acceso a información. Si ya tenemos el factorial de 3, no sería óptimo recalcularlo cada vez que tengamos que consultar el factorial de un número mayor a él. Entonces, las soluciones de todos los subproblemas se guardarán, generalmente, en un arreglo que puede tener más de dos dimensiones. El tercer requirimiento está unido al segundo. Una vez que calculamos la solución a un sub-problema, como ya tenemos una respuesta, no volveremos a repetir el proceso para ese mismo subproblema.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Cabe remarcar que existen dos tipos de algoritmos DP: los Bottom Up y los Top Down. Se diferencian en que con Bottom Up partimos del sub-problema más pequeño para hallar la solución al problema original, mientras que con Top Down iniciamos con el problema original y lo vamos diviendo en sub-problemas más pequeños hasta hallar un caso base.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Los pasos se describen a sí mismos con sus títulos. Al visualizar un problema, lo graficamos para entender cómo calculamos la solución. Para identificar un sub-problema, simplemente analizamos el gráfico y reconocemos los distintos caminos que podemos tomar. Para encontrar la relación entre subproblemas, deberemos ver cómo las soluciones se relacionan entre ellas. Por último, al implementar la solución transformaremos nuestro análisis en código. Para entender mejor este proceso, a continuación un ejemplo:  

 #### Ejemplo  

  
  ### [Problemas]()
  * [Subset Sum]()   
  * [Digit DP]()  
  * [Búsqueda Binaria]()  
  * [Subsecuencia Incremental Más Larga]()  
  
  ## Bibliografía  

  * Reducible. (2020). [5 Simple Steps for Solving Dynamic Programming Problems](https://www.youtube.com/watch?v=aPQY__2H3tE). YouTube.  
  * 
