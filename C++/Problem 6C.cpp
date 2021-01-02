#include <cstdio>

int main() {
    int 
        total_chocolate,
        consume_time[100001],
        alice_index = 0,
        alice_points = 0,
        bob_index = 0,
        bob_points = 0,
        sum_consume_time = 0;
    
    scanf("%d", &total_chocolate);

    bob_index = total_chocolate - 1;

    for (int i = 0; i < total_chocolate; i++) {
        scanf("%d", &consume_time[i]);
        sum_consume_time += consume_time[i];
    }

    if (alice_index != bob_index) {
        alice_points++;
        bob_points++;
    }

    if (alice_index == bob_index) {
        alice_points++;
    } else {
        for (int i = 0; i < sum_consume_time; i++) {
            if (bob_index - alice_index == 1)
                break;

            if (consume_time[alice_index] != 0)
                consume_time[alice_index] -= 1;
            else {
                alice_index++;
                alice_points++;
                consume_time[alice_index] -= 1;
            }

            if (consume_time[bob_index] != 0)
                consume_time[bob_index] -= 1;
            else {
                if (bob_index - 1 != alice_index) {
                    bob_index--;
                    bob_points++;
                    consume_time[bob_index] -= 1;
                }
            }
        }
    }
    printf("%d %d", alice_points, bob_points);
}