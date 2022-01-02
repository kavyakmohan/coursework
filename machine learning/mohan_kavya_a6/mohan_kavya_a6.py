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
from sklearn.neural_network import MLPClassifier

print('Kavya Mohan\nCS 422 Assignment 6')

#read data
df = pd.read_csv('Wholesale customers data.csv')

#load inputs and output
y = df.Channel
X= df[['Fresh', 'Milk', 'Grocery', 'Frozen', 'Detergents_Paper', 'Delicassen']]

#Split the data into training/testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, train_size=.8)

target_names = ['class 1 (Hotel/Restaurant/Cafe)', 'class 2 (Retail)']

print("\n\n\nCOMBINATION 1")
clf = MLPClassifier(solver='lbfgs', alpha=1e-5,
                    hidden_layer_sizes=(5, 2), random_state=1)
clf.fit(X_train, y_train)
y_train_pred = clf.predict(X_train)
y_test_pred = clf.predict(X_test)
print('\n\tIterations: ', clf.n_iter_)

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

#########################################################################################################

print("\n\n\nCOMBINATION 2")
clf2 = MLPClassifier(activation='logistic',solver='lbfgs', batch_size="auto",
                    hidden_layer_sizes=(5, 2), random_state=1, max_iter=350)
clf2.fit(X_train, y_train)
y_train_pred = clf2.predict(X_train)
y_test_pred = clf2.predict(X_test)
print('\n\tIterations: ', clf2.n_iter_)

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

#########################################################################################################

print("\n\n\nCOMBINATION 3")
clf2 = MLPClassifier(activation='logistic',solver='sgd',
                   learning_rate="adaptive", max_iter = 300)
clf2.fit(X_train, y_train)
y_train_pred = clf2.predict(X_train)
y_test_pred = clf2.predict(X_test)
print('\n\tIterations: ', clf2.n_iter_)

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