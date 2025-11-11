#include <iostream>
#include <ctime>
#include <limits>
#include "Board.h"
#include "Player.h"
using namespace std;

static char playerSymbol(PlayerType type) {
    switch (type) {
        case PlayerType::PLAYER1: return 'x';
        case PlayerType::PLAYER2: return 'o';
        default: return '.';
    }
}

static void shortPause(int milliseconds) {
    clock_t start = clock();
    while (static_cast<int>((clock() - start) * 1000 / CLOCKS_PER_SEC) < milliseconds) {
    }
}

class Game {
private:
    Board board;
    Player p1;
    Player p2;
    PlayerType current;
    int moveCount;

public:
    Game() : p1("", PlayerType::PLAYER1), p2("", PlayerType::PLAYER2), current(PlayerType::PLAYER1), moveCount(0) {}

    void run() {
        while (true) {
            showMenu();
            string choice;
            cout << "Selecciona una opcion: ";
            cin >> choice;

            if (choice == "1") {
                startGame();
            } else if (choice == "2") {
                showRules();
            } else if (choice == "3") {
                cout << "Saliendo del juego. Hasta luego!" << endl;
                break;
            } else {
                cout << "Opcion invalida. Intenta nuevamente.\n";
            }
        }
    }

private:
    void showMenu() {
        cout << "\n====================\n";
        cout << " Damas Internacionales\n";
        cout << "====================\n";
        cout << "1. Iniciar partida\n";
        cout << "2. Ver reglas del juego\n";
        cout << "3. Salir del programa\n\n";
    }

    void showRules() {
        cout << "\n--- Reglas del juego ---\n";
        cout << "1. El tablero es de 10x10 y las piezas se mueven en diagonal sobre las casillas oscuras.\n";
        cout << "2. Las piezas simples avanzan una casilla y capturan saltando en diagonal sobre el rival.\n";
        cout << "3. La captura es valida solo si la casilla de aterrizaje esta libre.\n";
        cout << "4. Al llegar a la fila opuesta la pieza se corona como dama y puede moverse en ambos sentidos.\n";
        cout << "5. La partida termina cuando un jugador se queda sin piezas.\n";
        cout << "6. Introduce coordenadas como: fila columna (ejemplo: 6 1). Las filas y columnas van de 0 a 9.\n";
        cout << "   Las casillas validas son las oscuras, mostradas con piezas o con puntos en el tablero.\n";
        cout << "------------------------\n\n";
    }

    void startGame() {
        string name1, name2;
        cout << "\nIngresa el nombre del Jugador 1: ";
        cin >> name1;
        cout << "Ingresa el nombre del Jugador 2: ";
        cin >> name2;

        resetGame(name1, name2);
        playTurns();
    }

    void resetGame(const string &name1, const string &name2) {
        p1 = Player(name1, PlayerType::PLAYER1);
        p2 = Player(name2, PlayerType::PLAYER2);
        board = Board();
        current = PlayerType::PLAYER1;
        moveCount = 0;
    }

    void playTurns() {
        cout << "\nConsejo rapido: escribe primero la fila y luego la columna, ambos del 0 al 9, separados por un espacio (ejemplo: 6 1).\n";
        while (true) {
            board.display();
            cout << "Movimientos completados: " << moveCount << "\n";

            if (!board.hasMoves(current)) {
                const Player &winner = (current == PlayerType::PLAYER1) ? p2 : p1;
                showWinMessage(winner);
                cout << "Movimientos totales realizados: " << moveCount << "\n\n";
                break;
            }

            int x1, y1, x2, y2;
            const Player &active = (current == PlayerType::PLAYER1) ? p1 : p2;
            cout << "Turno de " << active.name << " (" << playerSymbol(active.type) << ").\n";
            readCoordinate("Ingresa las coordenadas de la pieza (fila columna): ", x1, y1);
            readCoordinate("Ingresa las coordenadas de destino (fila columna): ", x2, y2);

            if (!board.movePiece(x1, y1, x2, y2, current)) {
                cout << "Movimiento invalido. Intenta nuevamente.\n";
                continue;
            }

            moveCount++;
            current = (current == PlayerType::PLAYER1) ? PlayerType::PLAYER2 : PlayerType::PLAYER1;
        }
    }

    void showWinMessage(const Player &winner) const {
        string banner = "*** " + winner.name + " (" + string(1, playerSymbol(winner.type)) + ") gana! ***";
        for (char c : banner) {
            cout << c << flush;
            shortPause(60);
        }
        cout << "\nSigue brillando con la corona, " << winner.name << "!\n";
    }

    void readCoordinate(const string &prompt, int &x, int &y) {
        while (true) {
            cout << prompt;
            if (!(cin >> x >> y)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada invalida. Usa solo numeros enteros del 0 al 9 separados por un espacio.\n";
                continue;
            }
            if (x < 0 || x >= 10 || y < 0 || y >= 10) {
                cout << "Coordenadas fuera de rango. Deben estar entre 0 y 9.\n";
                continue;
            }
            break;
        }
    }
};

int main() {
    Game game;
    game.run();
    return 0;
}
