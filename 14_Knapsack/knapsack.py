n = int(input())
val = list(map(int, input().split()))
weight = list(map(int, input().split()))
mx_weight = int(input())

def knapsack(i: int, mx_weight: int):
    if i < 0 or mx_weight <= 0:
        return 0
    if weight[i] <= mx_weight:
        op1 = knapsack(i - 1, mx_weight - weight[i]) + val[i]
        op2 = knapsack(i - 1, mx_weight)
        return max(op1, op2)
    else:
        return knapsack(i - 1, mx_weight)

print(knapsack(n - 1, mx_weight))
