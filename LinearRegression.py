import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
import numpy as np
import os

path = "LPG_Availability_Karnataka.xlsx"

if not os.path.exists(path):
    print(f"Error: Could not find '{path}' in the current folder.")
else:
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
    
    print("Generating plot window...")
    plt.show()

    print(f"Regression Equation: y = {model.coef_[0][0]:.2f}x + {model.intercept_[0]:.2f}")

