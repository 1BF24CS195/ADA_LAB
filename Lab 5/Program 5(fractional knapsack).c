#include <stdio.h>

struct Item {
    int value;
    int weight;
};

void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void sort(struct Item arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            float r1 = (float)arr[i].value / arr[i].weight;
            float r2 = (float)arr[j].value / arr[j].weight;

            if(r1 < r2) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

float fractionalKnapsack(int capacity, struct Item arr[], int n) {
    sort(arr, n);

    float totalValue = 0.0;

    for(int i = 0; i < n; i++) {
        if(capacity >= arr[i].weight) {
            capacity -= arr[i].weight;
            totalValue += arr[i].value;
        } else {            totalValue += arr[i].value * ((float)capacity / arr[i].weight);
            break;
        }
    }

    return totalValue;
}
int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    printf("Enter value and weight of each item:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    float maxValue = fractionalKnapsack(capacity, arr, n);

    printf("Maximum value = %.2f\n", maxValue);

    return 0;
}
