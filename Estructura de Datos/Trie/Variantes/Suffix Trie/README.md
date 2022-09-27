
<div align="center">

# Suffix Trie  

 <div align="left">
 
 ### Definición  
  Habiendo explicado Trie, la definición de un Suffix Trie no es difícil de entender. En este caso tomamos un String -o un conjunto de Strings- e incluimos en el Trie todos los posibles sufijos que podemos obtener. Esto quiere decir que tomaremos el String entero, lo posicionaremos, y luego tomaremos el String desde la posición $i$ hasta el caracter final en un bucle hasta que lleguemos al vacío. En este caso el vacío será representado por un caracter extra que añadiremos al String original. Esto siempre nos dará un árbol con $m$ hojas, donde $m$ es el número de caracteres que tiene el String más el caracter especial añadido.  
  Para construir un Suffix Trie se utiliza el algoritmo de 
Ukkonen. Este algoritmo indica que construiremos un Suffix Trie para cada prefijo del String. Para realizar cada sub Suffix Trie existen tres reglas:  

* Si ya existe el principio del sufijo a introducir, revisamos las letras consecutivas y las comparamos con las del sufijo. Si faltan letras para formar el sufijo, simplemente se añaden los caracteres correspondientes.  
* Si no existe el principio del sufijo, se crea un nuevo nodo.  
* Si el sufijo ya existe como prefijo de alguna de las ramas del trie, no se hace nada.  
  
 #### Ejemplo  
  
  Veamos un ejemplo con el String A=abbcba:  

Primero, como dijimos en la definición, añadiremos un caracter especial. Entonces, tenemos: A=abbcba$.  
  
  A continuación utilizaremos el algoritmo de Ukkonen:  
1. Tomamos el prefijo $a$ e introduciremos todos sus sufijos: S=[a].  
  Aplicamos la segunda regla con [a].

  ![st1](https://imgur.com/yaLrvky.png)

- Tomamos el prefijo $ab$ e introduciremos todos sus sufijos: S=[ab, b].

.. Aplicamos la primera regla con [ab].
.. Aplicamos la segunda regla con [b].

\begin{figure}[h]
\begin{center}
\includegraphics[scale=0.4]{st2}
\end{center}
\end{figure}

\clearpage

\item Tomamos el prefijo $abb$ e introduciremos todos sus sufijos: $S=[abb, bb, b]$.

Aplicamos la primera regla con $abb$ y $bb$.\\
Aplicamos la tercera regla con $b$.

\begin{figure}[h]
\begin{center}
\includegraphics[scale=0.3]{st3}
\end{center}
\end{figure}

\item Tomamos el prefijo $abbc$ e introduciremos todos sus sufijos: $S=[abbc, bbc, bc, c]$.

Aplicamos la primera regla con $abbc$, $bbc$ y $bc$.\\
Aplicamos la segunda regla con $c$.

\begin{figure}[h]
\begin{center}
\includegraphics[scale=0.3]{st4}
\end{center}
\end{figure}

\item Tomamos el prefijo $abbcb$ e introduciremos todos sus sufijos: $S=[abbcb, bbcb, bcb, cb, b]$.

Aplicamos la primera regla con $abbcb$, $bbcb$, $bcb$ y $cb$.\\
Aplicamos la tercera regla con $b$.

\begin{figure}[h]
\begin{center}
\includegraphics[scale=0.2]{st5}
\end{center}
\end{figure}

\item Tomamos el prefijo $abbcba$ e introduciremos todos sus sufijos: $S=[abbcba, bbcba, bcba, cba, ba, a]$.

Aplicamos la primera regla con $abbcba$, $bbcba$, $bcba$, $cba$ y $ba$.\\
Aplicamos la tercera regla con $a$.

\begin{figure}[h]
\begin{center}
\includegraphics[scale=0.2]{st6}
\end{center}
\end{figure}

\item Tomamos el prefijo $abbcba\$$ e introduciremos todos sus sufijos: $S=[abbcba\$, bbcba\$, bcba\$, cba\$, ba\$, a\$, \$]$.

Aplicamos la primera regla con todos los sufijos, excepto con $\$$ con el cual aplicamos la segunda regla.\\

\begin{figure}[h]
\begin{center}
\includegraphics[scale=0.2]{st7}
\end{center}
\end{figure}

\end{enumerate}

   ### Código  
  * []()
  
  ### Problemas  
  
  ## Bibliografía  
  * Enjoy Computer Science Staff. (s. f.).[Suffix Tree Data Structure](https://www.enjoyalgorithms.com/blog/suffix-tree-data-structure). Code Algorithms Pvt. Ltd. : Enjoy Computer Science.  
  * Geeks for Geeks Staff. (2021).[Ukkonen’s Suffix Tree Construction – Part 1](https://www.geeksforgeeks.org/ukkonens-suffix-tree-construction-part-1/). Geeks for Geeks. 
  * Langmead, B. (s.f.). [Tries and suffix tries](https://www.cs.jhu.edu/~langmea/resources/lecture_notes/tries_and_suffix_tries.pdf). Johns Hopskins Whiting School of Engineering.
