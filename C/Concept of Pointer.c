#include <stdio.h>

int main(){

    int a=10;
    int b=20;
    const int *pa=&a;

    pa= &a;
    printf("%u\n", pa); //변수 a의 주소값 출력
    printf("%d\n", *pa); // 변수 a의 값 출력

    a=30;
    printf("%d\n", *pa); //바뀐 a의 값(30) 출력
/*
    *pa = 40; // *pa 가 const int 로 선언된다면, *pa가 가르키는 a의 값을 바꿀 수 없다.
    printf("%d\n", *pa); //바뀐 a의 값(40) 출력
*/
    pa = &b; //하지만, *pa 가 가르키는 주소값은 바뀔 수 있다.
    printf("%d\n", pa);
    printf("%d\n", *pa); // *pa가 가르키는 주소값이 b의 주소로 바뀌었으므로, *pa는 b의 값을 갖게 된다.
    
    
    return 0;
}
