import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns

df = pd.read_csv("/home/pavel/Downloads/titanic.csv")
print(df.info(), df.head())

print(df.Survived)
plt.figure(figsize=(10, 5))
df["Survived"].hist()
plt.xlabel("survived")
plt.ylabel("count")
plt.suptitle("omg")
plt.savefig("10.png")
