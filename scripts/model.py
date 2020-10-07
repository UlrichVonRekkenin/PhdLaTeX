import sys
import pandas as pd
import numpy as np


def decompose(name, output):
    df = pd.read_excel(open(name, 'rb'),
                       sheet_name=0,
                       usecols='G:I',
                       skiprows=1,
                       nrows=9
                       )

    with open(output, "w", encoding="utf-8") as tex:
        tex.write(df.to_latex(
            label="tbl:model_anpa",
            multicolumn=True,
            multirow=True,
            escape=False,
            index=False,
            longtable=True
        ))


def matrix(name, output):
    a = pd.read_excel(open(name, 'rb'),
                      sheet_name=1,
                      usecols='C:R',
                      skiprows='1',
                      nrows=14,
                      index=False
                      )
    print(a.to_latex())

    b = pd.read_excel(open(name, 'rb'),
                      sheet_name=1,
                      usecols='C:H',
                      #    skiprows='19',
                      nrows=16,
                      index=False
                      )
    print(b.to_latex())


if __name__ == "__main__":
    name = sys.argv[1]
    output = sys.argv[2]

    decompose(name, output)

    # matrix(name, output)
