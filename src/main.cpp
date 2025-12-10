// More info:
// https://youtu.be/z7wVUfnm7M0?si=r4mhUPNg2HY0gGp1

#include <iostream>
#include <cstdint>

using namespace std;

enum Selection {
  SET = 0,
  READ = 1,
  CLEAR = 2,
  TOGGLE = 3,
  CLEAR_BYTE = 4,
  SET_BYTE = 5,
};

void set(uint8_t *byte, int8_t n) {
  *byte |= (1 << n);
}

void clear(uint8_t *byte, int8_t n) {
  *byte &= ~(1 << n);
}

void toggle(uint8_t *byte, int8_t n) {
  *byte ^= (1 << n);
}

int8_t read(const uint8_t *byte, int8_t n) {
  return (*byte >> n) & 1;
}

void printbyte(const uint8_t *byte) {
  cout << "Byte: ";
  // Print bits from MSB → LSB
  for (int i = 7; i >= 0; i--) {
    cout << ((*byte >> i) & 1);
  }
  cout << endl;
  cout << endl;
}



int main() {
  uint8_t val = 0;   // initialize
  // set(&val, 4);      // set bit 4

  while (1) {
    printbyte(&val);

    cout << "Menu:" << endl;
    cout << "1) Set Bit" << endl;
    cout << "2) Read Bit" << endl;
    cout << "3) Clear Bit" << endl;
    cout << "4) Toggle Bit" << endl;
    cout << "5) Clear Byte" << endl;
    cout << "6) Set Byte" << endl;
    cout << endl;
    cout << "Enter number corresponding with choise: ";
    int input;
    cin >> input;
    input = input - 1;

    int n;
    switch (input) {
      case SET:
        cout << "Which bit would you like to set? (1-8) ";
        cin >> n;
        set(&val, (n - 1));
        break;

      case READ: 
        cout << "Which bit would you like to read? (1-8) ";
        cin >> n;
        // int8_t b = read(&val, (n - 1));
        // cout << b;
        break;

      case CLEAR: 
        cout << "Which bit would you like to clear? (1-8) ";
        cin >> n;
        clear(&val, (n - 1));
        break;

      case TOGGLE: 
        cout << "Which bit would you like to toggle? (1-8) ";
        cin >> n;
        toggle(&val, (n - 1));
        break;

      case CLEAR_BYTE:
        val = 0;
        break;

      case SET_BYTE:
        for (int i = 7; i >= 0; i--) { 
          toggle(&val, i);
        }
        break;

      default:
        return -1;
        break;
    }
  }
}

