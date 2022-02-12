from itertools import groupby

class Solution:
    # can be done in single loop
    def say(self, s: str):
        return ''.join(f'{len(list(b))}{a}' for a, b in groupby(s))

    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'
        return self.say(self.countAndSay(n-1))
