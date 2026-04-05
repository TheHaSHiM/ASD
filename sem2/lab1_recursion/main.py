from math import sqrt
x = 0.5
n = 5

def iterative_sum(x, n):
    total_sum = 1
    term = 1

    for i in range(1, n+1):
        if i == 1:
            F1 = x/2
            term = F1
        else:
            term = -term*x*((2*(i-1)-1)/(2*((i-1)+1)))

        total_sum += term

    return total_sum


def sum_descent(i, n, x, term, current_sum):
    
    if i>n:
        return current_sum
    else:
        next_term = -term*x*((2*i-1)/(2*(i+1)))

    new_sum = current_sum + term

    return sum_descent(i + 1, n, x, next_term, new_sum)

def sum_return(i, n, x, term):
    if i > n:
        return 0
    
    else: 
        next_term = -term*x*(2*i-1)/(2*(i+1))
    sum_from_below = sum_return(i+1, n, x, next_term)
    return term + sum_from_below

def sum_hybrid(i, n, x, term):
    if i == n:
        return term, term
    next_term = -term * x * (2 * i - 1) / (2 * (i + 1))
    last_term, accumulated_sum = sum_hybrid(i + 1, n, x, next_term)

    return term, term + accumulated_sum


print(sqrt(x+1))

print(iterative_sum(x, n))

print(sum_descent(1, n, x, x/2.0, 1.0))

print(1+sum_return(1, n, x, x/2.0))

res_tuple = sum_hybrid(1, n, x, x/2.0)
final_sum = 1.0 + res_tuple[1]
print(final_sum)