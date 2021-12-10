#include <stdio.h>

int IsPrime(int n) {
    if (n < 2) return 0;
    else {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count += 1;
            }
        }
        if (count == 2) return 1;
        else return 0;
    }


}

//Test cases
int main() {
    printf("%d\n", IsPrime(100)); //Not prime
    printf("%d\n", IsPrime(2)); //Prime
    printf("%d\n", IsPrime(13)); //Prime
    printf("%d\n", IsPrime(1)); //Not prime
    printf("%d\n", IsPrime(56)); //Not prime
    printf("%d\n", IsPrime(101)); //Not prime
    return 0;
}
