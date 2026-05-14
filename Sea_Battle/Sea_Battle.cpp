#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include <string.h>

using namespace std;

char PlayerOne[12][12][3], PlayerTwo[12][12][3];
char s, ychar;
int IdNaveOne[12][12], nave[4] = { 0 };
int x, y, l, idShip = 1;

// plasarea Navelor
void punemNavaPlayerOne() {
ErrorImput:

    if (!(cin >> x >> ychar >> l >> s)) {
        cout << "Input invalid.\n";

        cin.clear();
        cin.ignore(1000, '\n');

        goto ErrorImput;
    }

    // regulile de plasare a flotei
    switch (ychar) {
    case 'A':
    case 'a':
        y = 1;
        break;
    case 'B':
    case 'b':
        y = 2;
        break;
    case 'C':
    case 'c':
        y = 3;
        break;
    case 'D':
    case 'd':
        y = 4;
        break;
    case 'E':
    case 'e':
        y = 5;
        break;
    case 'F':
    case 'f':
        y = 6;
        break;
    case 'G':
    case 'g':
        y = 7;
        break;
    case 'H':
    case 'h':
        y = 8;
        break;
    case 'I':
    case 'i':
        y = 9;
        break;
    case 'J':
    case 'j':
        y = 10;
        break;
    default:
        cout << "Nu puteti plasa acolo\n";
        goto ErrorImput;
    }
    if (x < 1 || x > 10) {
        cout << "X e introdus gresit.\n";
        goto ErrorImput;
    }
    if (l < 1 || l > 4) {
        cout << "lungimea navei e introdus gresit.\n";
        goto ErrorImput;
    }
    if (s != 'o' && s != 'v') {
        cout << "Starea navei e introdus gresit.\n";
        goto ErrorImput;
    }
    // Evidenta flotei
    if (l == 4 && nave[3] >= 1) {
        cout << "Limita navelor de aceasta lungine a fost atinsa\n";
        goto ErrorImput;
    }
    if (l == 3 && nave[2] >= 2) {
        cout << "Limita navelor de aceasta lungine a fost atinsa\n";
        goto ErrorImput;
    }
    if (l == 2 && nave[1] >= 3) {
        cout << "Limita navelor de aceasta lungine a fost atinsa\n";
        goto ErrorImput;
    }
    if (l == 1 && nave[0] >= 4) {
        cout << "Limita navelor de aceasta lungine a fost atinsa\n";
        goto ErrorImput;
    }
    
    if (s == 'v') {
        if (x + (l - 1) > 10) {
            cout << "Nava nu poate fi plasata aici.\n";
            goto ErrorImput;
        }
        if (PlayerOne[x][y][2] == '#') {
            cout << "Nava nu poate fi plasata aici.\n";
            goto ErrorImput;
        }
        if (PlayerOne[x + l - 1][y][2] == '#') {
            cout << "Nava nu poate fi plasata aici.\n";
            goto ErrorImput;
        }
        //plasarea navei
        for (int i = 0; i < l; i++) {
            PlayerOne[x + i][y][1] = '*';
        }
        for (int i = 0; i < l; i++) {
            IdNaveOne[x + i][y] = idShip;
        }
        idShip++;
        //actualizam "collision layer"
        for (int i = 0; i < (l + 2); i++) {
            PlayerOne[x - 1 + i][y - 1][2] = '#';
            PlayerOne[x - 1 + i][y][2] = '#';
            PlayerOne[x - 1 + i][y + 1][2] = '#';
        }
        // actualizam evidenta flotei
        if (l == 1) {
            nave[0]++;
        }
        if (l == 2) {
            nave[1]++;
        }
        if (l == 3) {
            nave[2]++;
        }
        if (l == 4) {
            nave[3]++;
        }
    }
    if (s == 'o') {
        if (y + (l - 1) > 10) {
            cout << "Nava nu poate fi plasata aici.\n";
            goto ErrorImput;
        }
        if (PlayerOne[x][y][2] == '#') {
            cout << "Nava nu poate fi plasata aici.\n";
            goto ErrorImput;
        }
        if (PlayerOne[x][y + l - 1][2] == '#') {
            cout << "Nava nu poate fi plasata aici.\n";
            goto ErrorImput;
        }
        //plasarea navei
        for (int i = 0; i < l; i++) {
            PlayerOne[x][y + i][1] = '*';
        }
        for (int i = 0; i < l; i++) {
            IdNaveOne[x][y + i] = idShip;
        }
        idShip++;
        //actualizam "collision layer"
        for (int i = 0; i < (l + 2); i++) {
            PlayerOne[x + 1][y - 1 + i][2] = '#';
            PlayerOne[x][y - 1 + i][2] = '#';
            PlayerOne[x - 1][y - 1 + i][2] = '#';
        }
        // actualizam evidenta flotei
        if (l == 1) {
            nave[0]++;
        }
        if (l == 2) {
            nave[1]++;
        }
        if (l == 3) {
            nave[2]++;
        }
        if (l == 4) {
            nave[3]++;
        }

    }
}


int main()
{
    cout << "Hello World!\n";
}

