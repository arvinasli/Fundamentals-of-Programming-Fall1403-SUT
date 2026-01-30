// Arvin Baghal Asl
// 403105793

#include <stdio.h>
#include <math.h>

int main() {
    unsigned long long int num;
    scanf("%llu", &num);

    unsigned long long int a = pow(2,0) + pow(2,1); unsigned long long int b = pow(2,0) + pow(2,2); unsigned long long int c = pow(2,0) + pow(2,3); unsigned long long int d = pow(2,0) + pow(2,4); unsigned long long int e = pow(2,0) + pow(2,5); unsigned long long int f = pow(2,0) + pow(2,6); unsigned long long int g = pow(2,0) + pow(2,7);
    unsigned long long int h = pow(2,1) + pow(2,2); unsigned long long int i = pow(2,1) + pow(2,3); unsigned long long int j = pow(2,1) + pow(2,4); unsigned long long int k = pow(2,1) + pow(2,5); unsigned long long int l = pow(2,1) + pow(2,6); unsigned long long int m = pow(2,1) + pow(2,6);
    unsigned long long int n = pow(2,2) + pow(2,3); unsigned long long int o = pow(2,2) + pow(2,4); unsigned long long int p = pow(2,2) + pow(2,5); unsigned long long int q = pow(2,2) + pow(2,6); unsigned long long int r = pow(2,2) + pow(2,7);
    unsigned long long int s = pow(2,3) + pow(2,4); unsigned long long int t = pow(2,3) + pow(2,5); unsigned long long int u = pow(2,3) + pow(2,6); unsigned long long int v = pow(2,3) + pow(2,7);
    unsigned long long int w = pow(2,4) + pow(2,5); unsigned long long int x = pow(2,4) + pow(2,6); unsigned long long int y = pow(2,4) + pow(2,7);
    unsigned long long int z = pow(2,5) + pow(2,6); unsigned long long int aa = pow(2,5) + pow(2,7);
    unsigned long long int ab = pow(2,6) + pow(2,7);
        
    unsigned long long int A = pow(2,0) + pow(2,8); unsigned long long int B = pow(2,0) + pow(2,16); unsigned long long int C = pow(2,0) + pow(2,24); unsigned long long int D = pow(2,0) + pow(2,32); unsigned long long int E = pow(2,0) + pow(2,40); unsigned long long int F = pow(2,0) + pow(2,48); unsigned long long int G = pow(2,0) + pow(2,56);
    unsigned long long int H = pow(2,8) + pow(2,16); unsigned long long int I = pow(2,8) + pow(2,24); unsigned long long int J = pow(2,8) + pow(2,32); unsigned long long int K = pow(2,8) + pow(2,40); unsigned long long int L = pow(2,8) + pow(2,48); unsigned long long int M = pow(2,8) + pow(2,56);
    unsigned long long int N = pow(2,16) + pow(2,24); unsigned long long int O = pow(2,16) + pow(2,32); unsigned long long int P = pow(2,16) + pow(2,40); unsigned long long int Q = pow(2,16) + pow(2,48); unsigned long long int R = pow(2,16) + pow(2,56);
    unsigned long long int S = pow(2,24) + pow(2,32); unsigned long long int T = pow(2,24) + pow(2,40); unsigned long long int U = pow(2,24) + pow(2,48); unsigned long long int V = pow(2,24) + pow(2,56);
    unsigned long long int W = pow(2,32) + pow(2,40); unsigned long long int X = pow(2,32) + pow(2,48); unsigned long long int Y = pow(2,32) + pow(2,56);
    unsigned long long int Z = pow(2,40) + pow(2,48); unsigned long long int AA = pow(2,40) + pow(2,56);
    unsigned long long int AB = pow(2,48) + pow(2,56);

    unsigned long long int copy_num = num;

    if ((copy_num & a == a) || (copy_num & b == b) || (copy_num & c == c) || (copy_num & d == d) || (copy_num & e == e) || (copy_num & f == f) || (copy_num & g == g) || (copy_num & h == h) || (copy_num & i == i) || (copy_num & j == j) || (copy_num & k == k) || (copy_num & l == l) ||
    (copy_num & m == m) || (copy_num & n == n) || (copy_num & o == o) || (copy_num & p == p) || (copy_num & q == q) || (copy_num & r == r) || (copy_num & s == s) || (copy_num & t == t) || (copy_num & u == u) || (copy_num & v == v) || (copy_num & w == w) || (copy_num & x == x) ||
    (copy_num & y == y) || (copy_num & z == z) || (copy_num & aa == aa) || (copy_num & ab == ab)) {
        printf("YES");
    }
    else {
        copy_num = copy_num >> 8;
        printf("%llu", copy_num);
        if ((copy_num & a == a) || (copy_num & b == b) || (copy_num & c == c) || (copy_num & d == d) || (copy_num & e == e) || (copy_num & f == f) || (copy_num & g == g) || (copy_num & h == h) || (copy_num & i == i) || (copy_num & j == j) || (copy_num & k == k) || (copy_num & l == l) ||
        (copy_num & m == m) || (copy_num & n == n) || (copy_num & o == o) || (copy_num & p == p) || (copy_num & q == q) || (copy_num & r == r) || (copy_num & s == s) || (copy_num & t == t) || (copy_num & u == u) || (copy_num & v == v) || (copy_num & w == w) || (copy_num & x == x) ||
        (copy_num & y == y) || (copy_num & z == z) || (copy_num & aa == aa) || (copy_num & ab == ab)) {
            printf("YES");
        }
        else {
            printf("go fuck yourself");
        }
    }
    return 0;
}