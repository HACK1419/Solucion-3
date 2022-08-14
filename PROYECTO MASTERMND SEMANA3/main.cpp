#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, const char* argv[]) {
    stringstream stream1;
    int nums[4] = {};
    string guess;
    int guessedAllowed = 12;

    srand(time(NULL));
    nums[0] = rand() % 6 + 1; // 1 to 6
    nums[1] = rand() % 6 + 1;
    nums[2] = rand() % 6 + 1;
    nums[3] = rand() % 6 + 1;

    void ImprimirTabla(int intento, string clave) { // FUNCION DE IMPRIMIR TABLA: recibe la cantidad de intentos que tendra el juego para asi saber cuantos renglones se ameritan
        LimpiarPantalla();
        cout << " |---------|-------------------------------------| |-------------------------------------|\n";
        cout << " | Puntaje | Calificacion|  A  |  B  |  C  |  D  | |   Intentos  |  A  |  B  |  C  |  D  |\n";
        cout << " |---------|-------------------------------------| |-------------------------------------|\n";
        cout << " |         |             |     |     |     |     | |             |     |     |     |     |\n";
        cout << " |   11    |             |     |     |     |     | |             |     |     |     |     |\n";
        cout << " |   10    |             |     |     |     |     | |             |     |     |     |     |\n";
        cout << " |   9     |             |     |     |     |     | |             |     |     |     |     |\n";
        cout << " |   8     |             |     |     |     |     | |             |     |     |     |     |\n";
        cout << " |   7     |             |     |     |     |     | |             |     |     |     |     |\n";
        cout << " |   6     |             |     |     |     |     | |             |     |     |     |     |\n";
        cout << " |   5     |             |     |     |     |     | |             |     |     |     |     |\n";
        cout << " |   4     |             |     |     |     |     | |             |     |     |     |     |\n";
        cout << " |   3     |             |     |     |     |     | |             |     |     |     |     |\n";
        cout << " |   2     |             |     |     |     |     | |             |     |     |     |     |\n";
        cout << " |   1     |             |     |     |     |     | |             |     |     |     |     |\n";
        cout << " |   0     |             |     |     |     |     | |             |     |     |     |     |\n";
        cout << " |-----------------------------------------------| |-------------------------------------|\n";

        for (int i = 0; i < 4; ++i) {
            stream1 << nums[i]; // put each value into the string stream
        }

        string fullString = stream1.str(); // as a string
        cout << fullString << endl; // remove this later just shows you string

        for (int i = 0; i < guessedAllowed; ++i) {
            int correct = 0;
            cout << "Enter a 4 letter key(xxxx): ";
            getline(cin, guess);
            if (guess.size() != 4) { // to only allow 4 characters.
                cout << "Please enter 4 numbers" << endl;
                i--;
                continue; // so it does not count an invalid num
            }
            if (guess[0] == fullString[0]) {
                cout << "First letter correct" << endl;
                correct++;
            }
            if (guess[1] == fullString[1]) {
                cout << "Second letter correct" << endl;
                correct++;
            }if (guess[2] == fullString[2]) {
                cout << "Third letter correct" << endl;
                correct++;
            } if (guess[3] == fullString[3]) {
                cout << "Last letter correct" << endl;
                correct++;
            }
            if (correct == 4) {
                cout << "You win! Exiting." << endl;
                exit(0);
            }
            if (correct == 0) cout << "NONE CORRECT!" << endl;
        }
        cout << "YOU LOSE D:" << endl;
        return 0;
    }