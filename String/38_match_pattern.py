import re


def matches(pattern: str, s: str):
    pattern = pattern.replace('*', '.*').replace('?', '.')
    return bool(re.fullmatch(pattern, s))


if __name__ == '__main__':
    print(matches("g*ks", "geeks"))
    print(matches("ge?ks*", "geeksforgeeks"))
    print(matches("g*k", "gee"))
    print(matches("*pqrs", "pqrst"))
    print(matches("abc*bcd", "abcdhghgbcd"))
    print(matches("abc*c?d", "abcd"))
    print(matches("*c*d", "abcd"))
    print(matches("*?c*d", "abcd"))
