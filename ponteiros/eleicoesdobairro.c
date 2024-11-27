#include <stdio.h>

// Lista de Ponteiros

void compute_votes(int n, int votes[n], int *most_voted, int *second_most_voted) {
    int count[11] = {0};

    for (int i = 0; i < n; i++) {
        count[votes[i]]++;
    }

    int max_votes = 0;
    int second_max_votes = 0;

    for (int i = 1; i <= 10; i++) {
        if (count[i] > max_votes) {
            second_max_votes = max_votes;
            *second_most_voted = *most_voted;
            max_votes = count[i];
            *most_voted = i;
        } else if (count[i] > second_max_votes) {
            second_max_votes = count[i];
            *second_most_voted = i;
        }
    }
}

int main() {
    int N;

    scanf("%d", &N);

    int votes[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &votes[i]);
    }

    int most_voted = 0;
    int second_most_voted = 0;

    compute_votes(N, votes, &most_voted, &second_most_voted);

    printf("%d ", most_voted);
    printf("%d", second_most_voted);

    return 0;
}
