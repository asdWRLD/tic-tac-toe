#include "iostream"
#include "cstdlib"
using namespace std;

bool game = true;
char arr[3][3];
int sum = 0;


//dot filling
void table() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = '.';
        }
    }
}

//print
void print() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

//player turn
void player() {
    int x, y = 0;
    cout << "enter coordinates: ";
    cin >> x >> y;
    while (x > 2 || x < 0 || y > 2 || y < 0 || arr[x][y] == 'x' || arr[x][y] == 'o' || cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "wrong coordinates" << endl << "enter norm coordinates: ";
        cin >> x >> y;
        cout << endl;
    }
    arr[x][y] = 'x';
    cout << endl;
    print();
    sum++;
}

//game replay
void play () {
    sum = 0;
    table();
    string temp;
    cout << "retry? [Y/n]";
    cin >> temp;
    cout << endl;
    if (temp == "n" || temp == "no" || temp == "No" || temp == "N" || temp == "NO") {
        exit(0);
    }

    else if (temp == "Y" || temp == "Yes" || temp == "yes" || temp == "y" || temp == "YES") {
        game = true;
    }

    else {
        while (true) {
            cout << "error input, pls try again: ";
            cin >> temp;
            if (temp == "n" || temp == "no" || temp == "No" || temp == "N" || temp == "NO") {
                exit(0);
            }

            else if (temp == "Y" || temp == "Yes" || temp == "yes" || temp == "y" || temp == "YES") {
                game = true;
                break;
            }
        }
    }
}

//wins
void Win() {
    //player win
    for (int i = 0; i < 3; i++) {
        int xSumHorizontal = 0;
        int xSumVertical = 0;

        for (int j = 0; j < 3; j++) {

            if (arr[i][j] == 'x') {
                xSumHorizontal++;
            }
            if (arr[j][i] == 'x') {
                xSumVertical++;
            }
        }

        if (xSumVertical == 3) {
            cout << "PLAYER WIN !" << endl;
            game = false;
            play();
        }

        if (xSumHorizontal == 3) {
            cout << "PLAYER WIN !" << endl;
            game = false;
            play();
        }

        if ((arr[0][0] == 'x' && arr[1][1] == 'x' && arr[2][2] == 'x') ||
            (arr[2][0] == 'x' && arr[1][1] == 'x' && arr[0][2] == 'x')) {
            cout << "PLAYER WIN !" << endl;
            game = false;
            play();
        }
    }

    //pc win
    for (int i = 0; i < 3; i++) {
        int oSumHorizontal = 0;
        int oSumVertical = 0;

        for (int j = 0; j < 3; j++) {

            if (arr[i][j] == 'o') {
                oSumHorizontal++;
            }
            if (arr[j][i] == 'o') {
                oSumVertical++;
            }
        }

        if (oSumVertical == 3) {
            cout << "PC WIN !" << endl;
            game = false;
            play();
        }

        if (oSumHorizontal == 3) {
            cout << "PC WIN !" << endl;
            game = false;
            play();
        }
    }

    if ((arr[0][0] == 'o' && arr[1][1] == 'o' && arr[2][2] == 'o') ||
        (arr[2][0] == 'o' && arr[1][1] == 'o' && arr[0][2] == 'o')) {
        cout << "PC WIN !" << endl;
        game = false;
        play();
    }

    //nobody win
    if (sum == 9) {
        cout << "nobody win!" << endl;
        play();
    }
}

//pc turn
void PC() {
    srand(time(NULL));
    //st horizontal
    if (arr[0][0] == '.' && arr[0][1] == 'x' && arr[0][2] == 'x') {
        arr[0][0] = 'o';
        print();
    }

    else if (arr[0][0] == 'x' && arr[0][1] == '.' && arr[0][2] == 'x') {
        arr[0][1] = 'o';
        print();
    }

    else if (arr[0][0] == 'x' && arr[0][1] == 'x' && arr[0][2] == '.') {
        arr[0][2] = 'o';
        print();
    }


    //second horizontal
    else if (arr[1][0] == '.' && arr[1][1] == 'x' && arr[1][2] == 'x') {
        arr[1][0] = 'o';
        print();
    }

    else if (arr[1][0] == 'x' && arr[1][1] == '.' && arr[1][2] == 'x') {
        arr[1][1] = 'o';
        print();
    }

    else if (arr[1][0] == 'x' && arr[1][1] == 'x' && arr[1][2] == '.') {
        arr[1][2] = 'o';
        print();
    }


    //third horizontal
    else if (arr[2][0] == '.' && arr[2][1] == 'x' && arr[2][2] == 'x') {
        arr[2][0] = 'o';
        print();
    }

    else if (arr[2][0] == 'x' && arr[2][1] == '.' && arr[2][2] == 'x') {
        arr[2][1] = 'o';
        print();
    }

    else if (arr[2][0] == 'x' && arr[2][1] == 'x' && arr[2][2] == '.') {
        arr[2][2] = 'o';
        print();
    }


    //first vertically
    else if (arr[0][0] == '.' && arr[1][0] == 'x' && arr[2][0] == 'x') {
        arr[0][0] = 'o';
        print();
    }

    else if (arr[0][0] == 'x' && arr[1][0] == '.' && arr[2][0] == 'x') {
        arr[1][0] = 'o';
        print();
    }

    else if (arr[0][0] == 'x' && arr[1][0] == 'x' && arr[2][0] == '.') {
        arr[2][0] = 'o';
        print();
    }


    //second vertically
    else if (arr[0][1] == '.' && arr[1][1] == 'x' && arr[2][1] == 'x') {
        arr[0][1] = 'o';
        print();
    }

    else if (arr[0][1] == 'x' && arr[1][1] == '.' && arr[2][1] == 'x') {
        arr[1][1] = 'o';
        print();
    }

    else if (arr[0][1] == 'x' && arr[1][1] == 'x' && arr[2][1] == '.') {
        arr[2][1] = 'o';
        print();
    }


    //third vertically
    else if (arr[0][2] == '.' && arr[1][2] == 'x' && arr[2][2] == 'x') {
        arr[0][2] = 'o';
        print();
    }

    else if (arr[0][2] == 'x' && arr[1][2] == '.' && arr[2][2] == 'x') {
        arr[1][2] = 'o';
        print();
    }

    else if (arr[0][2] == 'x' && arr[1][2] == 'x' && arr[2][2] == '.') {
        arr[2][2] = 'o';
        print();
    }


    //diagonal 00 .. 22
    else if (arr[0][0] == '.' && arr[1][1] == 'x' && arr[2][2] == 'x') {
        arr[0][0] = 'o';
        print();
    }

    else if (arr[0][0] == 'x' && arr[1][1] == '.' && arr[2][2] == 'x') {
        arr[1][1] = 'o';
        print();
    }

    else if (arr[0][0] == 'x' && arr[1][1] == 'x' && arr[2][2] == '.') {
        arr[2][2] = 'o';
        print();
    }

    //diagonal 02..20
    else if (arr[0][2] == '.' && arr[1][1] == 'x' && arr[2][0] == 'x') {
        arr[0][2] = 'o';
        print();
    }

    else if (arr[0][2] == 'x' && arr[1][1] == '.' && arr[2][0] == 'x') {
        arr[1][1] = 'o';
        print();
    }

    else if (arr[0][2] == 'x' && arr[1][1] == 'x' && arr[2][0] == '.') {
        arr[2][0] = 'o';
        print();
    }

    //rand turn
    else {
        int randX = rand() % 3;
        int randY = rand() % 3;
        while (arr[randX][randY] == 'x' || arr[randX][randY] == 'o') {
            randX = rand() % 3;
            randY = rand() % 3;
        }
        arr[randX][randY] = 'o';
        print();
    }
    sum++;
}

int main() {
    while (true) {
        while (game == true) {
            table();
            player();

            while (sum != 9) {
                PC();
                Win();
                player();
                Win();
            }
        }
    }
}