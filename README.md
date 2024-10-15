
<br />
<div align ="center">
  <a href="https://virtual.upsa.edu.bo/">
    <img src ="https://virtual.upsa.edu.bo/pluginfile.php/1/theme_lambda/logo/1708129513/logo%20UPSA-universidad-03.png">
  </a>
</div>

# si322-second-midterm y sus reglas
Repositorio que contiene el segundo parcial para la materia Laboratorio de Sistemas Operativos II - SI322 escrito en C++

## gitignore
El gitignore **bajo _ninguna_ circunstancia** debe modificarse sin previa autorización de los administradores del repo,
puesto que este archivo previene problemas de compilación, permite una mayor flexibilidad de colaboración,
entre otros.

## Ramas 
Podrá solicitar una nueva rama para contribuir al desarrollo del repositorio siempre
y cuando todos los demás colaboradores estén de acuerdo.

A la rama develop solo irán aquellos aportes **100% funcionales** y que **no** interfieran con el desarrollo
individual de las ramas de los colaboradores, pero que están pendientes de expansión o reducción, junto
con los directorios de clase de los colaboradores.

A la rama main irán todas aquellos aportes **100% funcionales** definitivos, que no necesitarán de 
modificación posterior, junto con los directorios de clases provenientes de los colaboradores.

La rama de cada desarrollador es dibujo libre, sin embargo, **no se aceptarán _pull requests_ que modifiquen
archivos importantes como el _.gitignore_ o el _README.md_** (es decir, el presente documento).

Tampoco se aceptarán pull requests ya sea para el develop o main que modifiquen el archivo **main.cpp**,
puesto que este será el espacio donde cada colaborador podrá realizar distintas pruebas o ejercicios
de manera individual de forma local.
Es decir, la rama main **solo alojará archivos de _clase_, _cabeceras_ y el _ejecutable principal_** una vez se haya constatado que no se requiere otro proceso de compilación.


## Lenguaje
El único lenguaje a utilizarse en este repositorio será **C++**, puesto que es el lenguaje
en el que se optó por desarrollar el presente proyecto

## Herramientas
Se utilizará <a href="https://www.jetbrains.com/clion/download/#section=windows">CLion</a> como IDE principal para el desarrollo del proyecto, incorporando el estándar **C++ 20** debido a que cuenta con la clase semáforo dentro.

## Estructura del proyecto
<div style="text-align: right"><code>src</code>   - Aquí se encontrarán todas las implementaciones de los archivos de cabecera para las clases junto al archivo principal del programa o main.

<code>include</code>   - Aquí se encontrarán todas las definiciones de las clases a usar, los archivos de cabecera.

<code>docs</code>   - Aquí se encontrarán documentos varios que puedan ser de utilidad para el proyecto, como ser explicaciones de código, el presente documento, etc.
</div>

## Contacto
Cualquier duda, sugerencia, o recomendación deberá hacerse contactando de manera presencial o por correo
a los co-dueños:

Dylan Uribe - a2022112008@estudiantes.upsa.edu.bo

Antonio Natusch - a2022111958@estudiantes.upsa.edu.bo

Werner Holters - a2022114973@estudiantes.upsa.edu.bo

Mauricio Flores - a20221112750@estudiantes.upsa.edu.bo

## Problemas a resolver

**10.** En la fábrica de bicicletas MountanenBike, tenemos tres operarios que denominaremos OP1, OP2 y OP3. OP1 monta ruedas, OP2 monta el cuadro de las bicicletas, y OP3, el manillar. Un cuarto operario, el Montador, se encarga de tomar dos ruedas, un cuadro y un manillar, y arma la bicicleta. Sincronizar las acciones de los tres operarios y el Montador utilizando semáforos, en los siguientes casos:

**a)** Los operarios no tienen ningún espacio para almacenar los componentes producidos pero sí tienen espacio para fabricar de a uno, y el Montador no podrá tomar ninguna pieza si esta no ha sido fabricada previamente por el correspondiente operario.

**b)** Los operarios no tienen ningún espacio para almacenar los componentes producidos pero sí tienen espacio para fabricar de a uno, y en el caso de OP1 tiene espacio para fabricar las dos ruedas y el Montador no podrá tomar ninguna pieza si esta no ha sido fabricada previamente por el correspondiente operario.

Restricción: el OP1 sólo produce de a una rueda por vez.

**11.** El problema de los fumadores de cigarrillos (Patil 1971). Considere un sistema con tres procesos fumadores y un proceso agente. Cada fumador está continuamente armando y fumando cigarrillos. Sin embargo, para armar un cigarrillo, el fumador necesita tres ingredientes: tabaco, papel y fósforos. Uno de los procesos fumadores tiene papel, otro tiene el tabaco y el tercero los fósforos. El agente tiene una cantidad infinita de los tres materiales. El agente coloca dos de los ingredientes sobre la mesa. El fumador que tiene el ingrediente restante arma un cigarrillo y se lo fuma, avisando al agente cuando termina. Entonces, el agente coloca dos de los tres ingredientes y se repite el ciclo. Escriba un programa para sincronizar al agente y los fumadores utilizando semáforos.

