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
this_thread::sleep_for(chrono::milliseconds(25)); //czas czekania na wywolanie tych znakow..
}

cout << "Konczacy watek drugi: " << this_thread::get_id() << " ==> " << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() << endl;

}

void setValue(int* a){
    *a = 100;   // dostep watkow do wspolnej pamieci....
}


int main(){
    char z;
    unsigned n;

letters();
line(z,n);

cout << endl;
cout << endl;

future<int> result1(async(launch::async,letters,65));
int s2 = letters(97);
cout << endl;
cout << "get() ==> brak uzycia watkow chyba ze uzjemy get jak tutaj ===========> " << result1.get() << endl;
cout << "ruszy jako oddzielny watek =========> " << s2 << endl;

// wywolanie .get() na obiekcie future, niszczy ten obiekt..
// wiec ponowne wywolanie, nie bedzie mozliwe..
// .valid() sprawdza czy obiekt result1 jeszcze jest wazny..

if(result1.valid()){
    cout << "mozna go uzywac .get()" << endl;
} else {
    cout << "nie mozna go uzywac .get()" << endl;
}

return 0;
}