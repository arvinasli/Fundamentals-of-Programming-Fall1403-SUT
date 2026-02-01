#line 1000
// Add Your Code under this
// Arvin Baghal Asl
// 403105793
#include <stdio.h>
#define start int main()
#define begin {
#define end }

#define FOR(n) for(int i=0; i<n; i++)

#define where_am_i printf("You are at %d\n",__LINE__)

char m='m'; char u='u'; char l='l'; char n='n'; char s='s';
#define execute(ch1,ch2,ch3,a,b) (ch1=='m' && ch2=='u') ? mul(a,b) : ((ch1=='m' && ch2=='n') ? mns(a,b) : sum(a,b))

#define execute2(operator,n1,n2) (n1) operator (n2)

// DO NOT CHANGE below
int sum(int a, int b){ return a + b; }
int mns(int a, int b){ return a - b; }
int mul(int a, int b){ return a * b; }
start {
    int tests;
    scanf("%d\n", &tests);
    where_am_i;
    where_am_i;

    where_am_i;
    FOR(tests) begin
        int a, b;
        scanf("%d%d", &a, &b);
        printf("first result is %d\n", execute(m,u,l, a, b));
        printf("second result is %d\n", execute(m,n,s, a, b));
        printf("third result is %d\n", execute(s,u,m, a, b));
        printf("fourth result is %d\n", execute2(*, execute2(+, a, b), execute2(-, a, b)));
    end
    where_am_i;
    return 0;
end