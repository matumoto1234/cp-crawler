# detail: https://atcoder.jp/contests/abc250/submissions/39971996
def sieve(n):
    if n < 2:
        return []

    is_prime = [True for _ in range(n+1)]

    is_prime[0] = False
    is_prime[1] = False

    i = 2
    while i * i <= n:
        if not is_prime[i]:
            i += 1
            continue

        j = i*i
        while j <= n:
            is_prime[j] = False
            j += i

        i += 1

    prime_list = []
    for i in range(n+1):
        if is_prime[i]:
            prime_list.append(i)

    return prime_list


def main():
    n = int(input())

    prime_list = sieve(int(pow(n, 1/3)))

    ans = 0

    for p in prime_list:
        # p*p*p * x <= nかつ x < pなる最大のxを二分探索

        valid = 2
        invalid = p

        while abs(valid-invalid) > 1:
            m = (valid+invalid)//2
            if p*p*p * m <= n:
                valid = m
            else:
                invalid = m

        x = valid

        if not(p*p*p * x <= n and x < p):
            continue

        # x以下の素数の個数

        ok = 0
        ng = len(prime_list)+1

        while abs(ok-ng) > 1:
            m = (ok+ng)//2
            if prime_list[m] <= x:
                ok = m
            else:
                ng = m

        ans += ok

    print(ans)


main()
