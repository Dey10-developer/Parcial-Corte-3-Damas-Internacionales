# Desarrollos Innovadores — Explicación Técnica

## 1. Contador de Movimientos
**¿Para qué se implementó?** 
Se introdujo el contador de movimiento para que los jugadores, de manera clara y visual, puedan observar cuántos movimientos han hecho durante toda la partida. Además de ser un apoyo práctico, también aporta un matiz más estratégico y competitivo, puesto que posibilita examinar el rendimiento propio y confrontar quién ganó utilizando la menor cantidad de movimientos. En pocas palabras, hace que el juego sea más atractivo e impulse a mejorar en cada partida.

**¿Por qué se consideró necesario?**
Este componente, aunque no es un requerimiento mínimo del proyecto, mejora significativamente la experiencia del usuario al proporcionar una retroalimentación numérica y clara sobre el avance en el juego. Asimismo, promueve la autocompetencia porque posibilita que cada jugador valore su estilo de juego y su eficacia, lo que lo impulsa a mejorar en cada encuentro.

**¿Cómo se llevó a cabo su implementación?** 
El contador de movimientos se implementó dentro de la clase `Game`, la cual esta localizada en el archivo `main.cpp`, como una variable entera llamada `moveCount`.  
A esta se le asigna un valor inicial de cero dentro de la función `resetGame()`

Acontinuación se muestra el fragmento exacto en donde se puede evidenciar este desarrollo innovador:
```cpp
void resetGame(const string &name1, const string &name2) {
    p1 = Player(name1, PlayerType::PLAYER1);
    p2 = Player(name2, PlayerType::PLAYER2);
    board = Board();
    current = PlayerType::PLAYER1;
    moveCount = 0; // Contador reiniciado al inicio del juego
}
```
Finalmente se imprime el número total de movimientos realizados durante toda la partida.

## 2. Barra de Victoria
**¿Para qué se implementó?**
Se creó la barra de victoria como un símbolo visual que representa el progreso de cada jugador hacia la victoria. Conforme uno de los jugadores va sacando las piezas del rival, la barra se va llenando en proporción hasta llegar al 100%. En ese momento, el juego designa automáticamente al vencedor.

**¿Por qué se consideró necesario?**
El propósito de esta función fue brindar una manera más visual e intuitiva de mostrar el avance de cada jugador, evitando así la dependencia exclusiva de los mensajes de texto. Así, el juego se torna más dinámico, fortalece el sentido de competencia y optimiza la presentación global del proyecto, lo que lo hace más seductor y profesional en comparación con otros desarrollos.

**¿Cómo se llevó a cabo su implementación?** 
La Barra de Victoria fue implementada dentro de la clase `Game` tambien, específicamente en la función `showWinMessage()`, la cual esta localizada en el archivo `main.cpp`.  
Dicha función es ejecutada al final de la partida cuando uno de sus jugadores gana. Su objetivo es generar un efecto visual y agradable de celebración al mostrar un mensaje de victoria que aparece en la consola.

Acontinuación se muestra el fragmento exacto en donde se puede evidenciar este desarrollo innovador:
```cpp
void showWinMessage(const Player &winner) const {
        string banner = "*** " + winner.name + " (" + string(1, playerSymbol(winner.type)) + ") gana! ***";
        for (char c : banner) {
            cout << c << flush;
            shortPause(60);
        }
        cout << "\nSigue brillando con la corona, " << winner.name << "!\n";
    }
```
Al final, la pausa de 60 milisegundos genera un efecto visual de animación gracias al timing perfecto, simulando asi una barra de victoria muy entretenida.
