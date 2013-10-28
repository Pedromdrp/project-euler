#include <stdio.h>

int number_ways(int value, int *coins, int number_coins) {
  int highest_coin = coins[number_coins - 1];
  int total = 0, i;
  if (value == 0) {
    return 1;
  }
  if (number_coins == 0) {
    return 0;
  }
  for (i = 0; i <= value; i += highest_coin) {
    total += number_ways(value - i, coins, number_coins - 1);
  }
  return total;
}

int main() {
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
  printf("%d\n", number_ways(200, coins, 8));
  return 0;
}
