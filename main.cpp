#include <iostream>
using namespace std;

bool running = true;
int r, c; // row and column values
int a;
string arr[3][3] = {
    {"_", "_", "_"},
    {"_", "_", "_"},
    {"_", "_", "_"},
};

string xr_win[3] = {"x", "x", "x"};
string xo_win[3] = {"o", "o", "o"};

bool is_row_equal(string arr1[], string arr2[]) {
  for (int i = 0; i < 3; i++) {
    if (arr1[i] != arr2[i])
      return false;
  }
  return true;
}

// checks if the block is empty before adding the value
int check_empty() {
  if (arr[r][c] == "_") {
    a = 1;
  } else {
    a = 0;
  }
  return 0;
}

int check_win() {
  // check win for row:
  for (int i = 0; i < 3; i++) {
    if (is_row_equal(arr[i], xr_win)) {
      cout << "X wins!" << endl;
      running = false;
    } else if (is_row_equal(arr[i], xo_win)) {
      cout << "O wins!" << endl;
      running = false;
    }
  }
  // check win for column:
  for (int k = 0; k < 3; k++) {
    if (arr[0][k] == arr[1][k] && arr[2][k] == arr[1][k] && "x" == arr[1][k]) {
      cout << "X wins!" << endl;
      running = false;
    } else if (arr[0][k] == arr[1][k] && arr[2][k] == arr[1][k] &&
               "o" == arr[1][k]) {
      cout << "O wins!" << endl;
      running = false;
    }
  }
  // check win for diagonal:
  if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] == "x") {
    cout << "X wins!" << endl;
    running = false;
  } else if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] &&
             arr[0][0] == "o") {
    cout << "O wins!" << endl;
    running = false;
  } else if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] &&
             arr[1][1] == "o") {
    cout << "O wins!" << endl;
    running = false;
  } else if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] &&
             arr[1][1] == "x") {
    cout << "X wins!" << endl;
    running = false;
  }

  return 0;
}

int main() {

  int flag = 0; // checks if x or O turn

  while (running) {

    cout << "Enter row: ";
    cin >> r;
    cout << "Enter column: ";
    cin >> c;
    check_empty();
    if (a == 1) {
      if (flag % 2 == 0) {
        arr[r][c] = 'x';
        flag++;
      } else if (flag % 2 != 0) {
        arr[r][c] = 'o';
        flag++;
      }
    } else {
      cout << "Error! please input value somewhere else as this block is taken"
           << endl;
      continue;
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }
    check_win();
  }
  return 0;
}
