#include<bits/stdc++.h>
using namespace std;

#define ll long long

/* int fact( int x ){
    if ( x == 1 || x == 0 ){
        return 1;
    }
    return x * fact(x-1);
}

int main(){
    ll n = 5;
    cout << fact(n) << endl;
} */


/* void printFun( int x ){
    if ( x < 4 ){
        cout << x << " ";
        printFun(x+1);
        cout << x << " ";
    }
}

int main(){
    int x = 1;
    printFun(x);
} */


/* int fib( int x ){
    if ( x == 0 ){
        return 0;
    }
    if ( x == 1 || x == 2 ){
        return 1;
    }
    
    return fib(x-1)+fib(x-2);
    cout << x << endl;
    
}

int main(){
    for ( int i = 0; i <= 5; i++ )
        cout << fib(i) << " ";
        cout << endl;
    cout << fib(4) << endl;
} */


/* void reverseFib( int n, int a, int b ){
    if ( n > 0 ){
        reverseFib( n-1, b, a+b );
        cout << a << " ";
    }
} 

int main(){
    reverseFib(5, 0, 1);
} */

/* void towerOfHanoi( int n, char from_rod, char to_rod, char aux_rod ){
    if ( n == 0 ){
        return;
    }
    towerOfHanoi( n-1, from_rod, aux_rod, to_rod );
    cout << n << " " << from_rod << ' ' << to_rod << ' ' << endl;
    towerOfHanoi( n-1, aux_rod, to_rod, from_rod );
}

int main(){
    towerOfHanoi( 4, 'A', 'C', 'B' );
} */


/* int fun1(int x, int y)
{
    if (x == 0)
        return y;
    else
        return fun1(x - 1, x + y);
} 

int main(){
    cout << fun1( 5, 2 );
}
 */


/* int fun1(int x){
    if ( x == 1 ){
        return 0;
    } else {
        return 1 + fun1(x/2);
    }
}

int main(){
    cout << fun1(10);
} */


/* void fun1(int x){
    if ( x == 0 )
        return;
    fun1(x/2);
    cout << x % 2 << " ";
}

int main(){
    fun1(1);
}  */


/* void fun1(int n)
{
   int i = 0;  
   if (n > 1)
     fun1(n - 1);
   for (i = 0; i < n; i++)
     cout << " * ";
}
 
int main(){
    fun1(2);
} */


/* int fun(int i)
{
  if (i % 2) return (i++);
  else return fun(fun(i - 1));
}
  
int main()
{
  cout << " " << fun(200) << " ";
  getchar();
  return 0;
} */


/* // mcCarthy 91 function
int m(int x){
    if ( x > 100 )
        return x-10;
    return m(m(x+11));
}

int main(){
    cout << m(1110) << endl;
} */

/* 
void abc(char s[])
{
    if(s[0] == '\0')
        return;
 
    abc(s + 1);
    abc(s + 1);
    cout << s[0];
}
 
int main()
{
    abc("xyz");
} */


/* int fun(int count)
{
    cout << count << endl;
    if(count < 3)
    {
        fun(fun(fun(++count)));
    }
    return count;
}
 
int main()
{
    fun(1);
    return 0;
} */

