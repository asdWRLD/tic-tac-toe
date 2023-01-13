#include "iostream"
#include "string"
#include "cstdlib"

using namespace std;

char arr[3][3];

void table () {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = '.';
        }
        cout << endl;
    }
}
void print() {
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << arr[i][j];
        }
        cout << endl;
    }
}

void Win(){
    int i = 0, j(0);

    if (((arr[i][j] == 'o') && (arr[i][j + 1] == 'o') && (arr[i][j + 2] == 'o')) || ((arr[i][j] == 'o') && (arr[i + 1][j] == 'o') && (arr[i + 2][j] == 'o')) || ((arr[i][j] == 'o') && (arr[i + 1][j + 1] == 'o') && (arr[i + 2][j + 2] == 'o')) || ((arr[i + 2][j] == 'o') && (arr[i + 1][j + 1] == 'o') && (arr[i][j + 2] == 'o')) || ((arr[i + 1][j] == 'o') && (arr[i + 1][j + 1] == 'o') && (arr[i + 1][j + 2] == 'o')) || ((arr[i + 2][j] == 'o') && (arr[i + 2][j + 1] == 'o') && (arr[i + 2][j + 2] == 'o')) || ((arr[i][j + 1] == 'o') && (arr[i + 1][j + 1] == 'o') && (arr[i + 2][j + 1] == 'o')) || ((arr[i][j + 2] == 'o') && (arr[i + 1][j + 2] == 'o') && (arr[i + 2][j + 2] == 'o')))
    {
        cout << "PC win";
        exit(0);
    }

    if (((arr[i][j] == 'x') && (arr[i][j + 1] == 'x') && (arr[i][j + 2] == 'x')) || ((arr[i][j] == 'x') && (arr[i + 1][j] == 'x') && (arr[i + 2][j] == 'x')) || ((arr[i][j] == 'x') && (arr[i + 1][j + 1] == 'x') && (arr[i + 2][j + 2] == 'x')) || ((arr[i + 2][j] == 'x') && (arr[i + 1][j + 1] == 'x') && (arr[i][j + 2] == 'x')) || ((arr[i + 1][j] == 'x') && (arr[i + 1][j + 1] == 'x') && (arr[i + 1][j + 2] == 'x')) || ((arr[i + 2][j] == 'x') && (arr[i + 2][j + 1] == 'x') && (arr[i + 2][j + 2] == 'x')) || ((arr[i][j + 1] == 'x') && (arr[i + 1][j + 1] == 'x') && (arr[i + 2][j + 1] == 'x')) || ((arr[i][j + 2] == 'x') && (arr[i + 1][j + 2] == 'x') && (arr[i + 2][j + 2] == 'x')))
    {
        cout << "you win!";
        exit(0);
    }
}

int main() {
    srand(time(NULL));
    int x, y = 0;
    cout << "enter coordinates: ";
    cin >> x >> y;
    while(x > 2 || x < 0 || y > 2 || y < 0) {
        cout << "wrong coordinates" << endl << "enter norm coordinates: ";
        cin >> x >> y;
    }

    table();
    arr[x][y] = 'x';
    print();
    cout << endl;
    int sum = 0;

    while (sum != 8) {
        int randX = rand() % 3;
        int randY = rand() % 3;
        while(arr[randX][randY] == 'x' || arr[randX][randY] == 'o' ) {
            randX = rand() % 3;
            randY = rand() % 3;
        }
        arr[randX][randY] = 'o';
        print();
        cout << endl;
        Win();
        sum++;

        cout << "input coordinates: ";
        cin >> x >> y;
        while(arr[x][y] == 'x' || arr[x][y] == 'o' || x > 2 || x < 0 || y > 2 || y < 0) {
            cout << "wrong coordinates" << endl << "enter norm coordinates: ";
            cin >> x >> y;
        }
        arr[x][y] = 'x';
        print();
        Win();
        cout << endl;
        sum++;
    }
}
