def create_array_with_product_and_sum(target_product, target_sum):
    if target_product == 0:
        return []

    factors = []
    remaining_product = target_product

    # Factorization
    for candidate in range(2, int(remaining_product ** 0.5) + 1):
        while remaining_product % candidate == 0:
            factors.append(candidate)
            remaining_product //= candidate

    if remaining_product > 1:
        factors.append(remaining_product)

    # If the target sum is not possible, return -1
    if target_sum < len(factors):
        return -1

    # Create an array to meet the target sum
    array = [1] * target_sum

    # Distribute factors into the array
    for i in range(len(factors)):
        array[i % target_sum] *= factors[i]

    return array

def run():
    # Example usage:
    target_product = int(input())
    target_sum = 41
    result = create_array_with_product_and_sum(target_product, target_sum)
    if result == -1:
        return result
    else:
        return f"{len(result)} {' '.join(list(map(str,result)))}"


for _ in range(int(input())):
    print(f"Case #{_+1}: {run()}")
