from fractions import Fraction
from sys import stdin
import re
for s in stdin:
    ans = eval(re.sub(r'([0-9]+)\/([0-9]+)', r'Fraction(\1,\2)', s))
    print(str(ans.numerator) + '/' + str(ans.denominator))
