MOD = 10**9+7


def multiplyTwoList(head1, head2):
    n1 = ''
    while head1:
        n1 += str(head1.data)
        head1 = head1.next

    n2 = ''
    while head2:
        n2 += str(head2.data)
        head2 = head2.next

    return ((int(n1) % MOD)*(int(n2) % MOD)) % MOD
