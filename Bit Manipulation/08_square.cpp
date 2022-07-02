int calculateSquare(int num)
{
	// Doing something like num * (2^x1 + 2^x2 + 2^x3 ...)
	// e.g 15 -> 8 + 4 + 2 + 1 => 15*(8 + 4 + 2 + 1)
	num = abs(num);
	int x = 0;
	int n = num;
	int res = 0;
	while (n) {
		if (n & 1)
			res += num << x;
		n = n >> 1;
		x++;
	}
	return res;
}
