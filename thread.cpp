#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <iomanip>   //setw..
#include <list>
#include <forward_list>
#include <typeinfo>
#include <string>
#include <ctime>
#include <algorithm>
#include <deque>
#include <functional>
#include <typeinfo>
#include <iterator>
#include <set>
#include <chrono>
#include <thread>
#include <future>
#include "numbers.h"

using namespace std;
using namespace chrono;

auto start = chrono::system_clock::now();



int letters(int a = 65){  //  literki alfabetu od a = 97 lub A = 65 mozna to zmienic w argumencie..

cout << "Startowy watek: " << this_thread::get_id() << " ==> " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;
int step = 0, i;
ostream_iterator<char> out(std::cout, " ");

do {
    step++;
    *out++ = i = rand() % 26 + a;
} while(i != a + 25 || step < 15);

return step;
}

void line(char z, unsigned n){ // funkcja wysweitla n znakow char z i przedstawia id watku..

    cout << endl;
    cout << endl;

cout << "Startowy watek drugi: " << this_thread::get_id() << " ==> " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;

while(n--){
cout << z;
this_thread::sleep_for(chrono::milliseconds(125));
}

cout << "Konczacy watek drugi: " << this_thread::get_id() << " ==> " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;

}


int main(){
    char z;
    unsigned n;

letters();
line(z,n);

return 0;
}