#Linear Regression Algorithm is used to draw different conclusions form the data, for example here we get to know difference between the cylinder stocks of each district.
#The equation of linear regression is, y=mx+c where m=slope of the relational graph plotted and c is y intercept which gives us the base value of starting point of the graph.
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
import numpy as np

path = r"C:\Users\navaneeth\LPG_Availability_Karnataka.xlsx"
df = pd.read_excel(path, skiprows=3)
df = df.dropna(subset=['Available LPG Cylinders'])

X = np.arange(len(df)).reshape(-1, 1)
y = df['Available LPG Cylinders'].values.reshape(-1, 1)

model = LinearRegression()
model.fit(X, y)

y_pred = model.predict(X)

plt.figure(figsize=(12, 6))
plt.scatter(X, y, color='blue', label='Actual Data')
plt.plot(X, y_pred, color='red', linewidth=2, label='Regression Line')

plt.xticks(X.flatten(), df['District'], rotation=90)
plt.xlabel('Districts')
plt.ylabel('Available LPG Cylinders')
plt.title('Linear Regression: LPG Availability Trend in Karnataka')
plt.legend()
plt.tight_layout()
plt.show()

print(f"Regression Equation: y = {model.coef_[0][0]:.2f}x + {model.intercept_[0]:.2f}")
