#include"TreeSet.h"
#include"stdio.h"
int main(){
    TreeSet * t=init_set();
    add(t, 7);
    // print_value(t);
    add(t, 1);
    // print_value(t);
    add(t, 2);
    // print_value(t);
    add(t,5);
    add(t,6);
    
    print_value(t);
    return 0;
}