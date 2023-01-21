#include "iostream"
#include "string"
#include "cstdlib"

using namespace std;

char arr[3][3];

void table() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = '.';
        }
        cout << endl;
    }
}
void print() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << arr[i][j];
        }
        cout << endl;
    }
}

void Win() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

        }

    }
}

//00 01 02
//10 11 12
//20 21 22

void PC() {

    //первая строка горизонтально
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


        //вторая строка горизонтально
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


        // третья строка горизонтально
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


        // первая строка вертикально
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


        // вторая строка вертикально
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


        //третья строка вертикально
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


        //крест 00 .. 22
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

        //крест 02 .. 20

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
}

int main() {
    srand(time(NULL));
    int x, y = 0;
    cout << "enter coordinates: ";
    cin >> x >> y;
    while (x > 2 || x < 0 || y > 2 || y < 0) {
        cout << "wrong coordinates" << endl << "enter norm coordinates: ";
        cin >> x >> y;
    }

    table();
    arr[x][y] = 'x';
    print();
    cout << endl;
    int sum = 0;

    while (sum != 8) {
        PC();
        cout << endl;
        Win();
        sum++;

        cout << "input coordinates: ";
        cin >> x >> y;
        while (arr[x][y] == 'x' || arr[x][y] == 'o' || x > 2 || x < 0 || y > 2 || y < 0) {
            cout << "wrong coordinates" << endl << "enter norm coordinates: ";
            cin >> x >> y;
        }
        arr[x][y] = 'x';
        print();
        Win();
        sum++;
    }
}
