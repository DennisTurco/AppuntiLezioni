from null_division_frazione import NullDivisionFrazione

class Frazione:
    def __init__(self, numeratore: int, denominatore: int) -> None:
        if denominatore == 0:
            raise NullDivisionFrazione("Non mettermi 0 come denominatore daiiii")
        self.numeratore = numeratore
        self.denominatore = denominatore

    def to_float(self) -> float:
        return self.numeratore / self.denominatore

    def __str__(self) -> str:
        return f"{self.numeratore}/{self.denominatore}"