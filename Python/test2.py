def is_ascending(n : int) -> bool:
    if n < 10:
        return True
    if n % 10 <= (n // 10) % 10:
        return False
    return is_ascending(n // 10)


def test():
    assert(is_ascending(1234) == True)
    assert(is_ascending(999) == False)
    assert(is_ascending(102) == False)
    assert(is_ascending(1243) == False)
