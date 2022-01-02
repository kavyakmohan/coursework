# Kavya Mohan 2001362917
from ctypes import sizeof
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn import linear_model
from sklearn.base import ClassifierMixin
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score
from sklearn.model_selection import train_test_split
from sklearn.linear_model import SGDClassifier
from sklearn.metrics import classification_report
from sklearn.metrics import confusion_matrix
from sklearn.metrics import ConfusionMatrixDisplay
from sklearn.metrics import log_loss

print('Kavya Mohan\nCS 422 Assignment 4')

#read data
df = pd.read_csv('Wholesale customers data.csv')

#load inputs and output
y = df.Channel
X= df[['Fresh', 'Milk', 'Grocery', 'Frozen', 'Detergents_Paper', 'Delicassen']]

#Split the data into training/testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, train_size=.8)

#logistic regression object
# eta0 = learning rate
LogRegr = linear_model.SGDClassifier(loss='log', learning_rate='constant', eta0=0.5, tol=1.E-30)

#fit the model
LogRegr.fit(X_train, y_train)
y_train_pred = LogRegr.predict(X_train)     #train w/ training set
y_test_pred = LogRegr.predict(X_test)       #train w/ testing set

target_names = ['class 1 (Hotel/Restaurant/Cafe)', 'class 2 (Retail)']

print('\nEvaluation metrics for training dataset:')
print(confusion_matrix(y_train, y_train_pred))
print("\nrecall of class 1 = “sensitivity” & recall of class 2 = “specificity”.\n")
print(classification_report(y_train, y_train_pred, target_names=target_names))
print("Log loss: ", log_loss(y_train, y_train_pred))
ConfusionMatrixDisplay.from_predictions( y_train, y_train_pred, display_labels=target_names)



print('\n\nEvaluation metrics for testing dataset:')
print(confusion_matrix(y_test, y_test_pred))
print(classification_report(y_test, y_test_pred, target_names=target_names))
print("Log loss: ", log_loss(y_test, y_test_pred))
ConfusionMatrixDisplay.from_predictions( y_test, y_test_pred, display_labels=target_names)

plt.show()


# solution w
print('\n\n\tCoefficients: ', LogRegr.coef_)

#  iterations it took for gradient descent to converge. 
print('\n\tIterations: ', LogRegr.n_iter_)

print('\n\tIntercept: ', LogRegr.intercept_)

print('\n\tLearning Rate: ', LogRegr.eta0)
