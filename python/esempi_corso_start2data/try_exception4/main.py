
from frazione import Frazione
from null_division_frazione import NullDivisionFrazione

frazione = Frazione(5, 4)
print(frazione.to_float())

try:
    frazione = Frazione(5, 0)
    print(frazione.to_float())
except NullDivisionFrazione as e:
    print(e)
