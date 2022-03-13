# Kavya Mohan 2001362917
from ctypes import sizeof
import numpy as np
import pandas as pd
from sklearn import linear_model
from sklearn.base import ClassifierMixin
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score
from sklearn.model_selection import train_test_split

print('Kavya Mohan\nCS 422 Assignment 3')

#read data file
df = pd.read_csv('3D_spatial_network.txt', header=0, names=['OSM_ID', 'LONGITUDE', 'LATITUDE', 'ALTITUDE'])

#load dataset
y = df.LONGITUDE                                              #output(targets)
X = df[['OSM_ID', 'LATITUDE', 'ALTITUDE']]

#Split the data into training/testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, train_size=.8)

#########################################################################################
print('Implementing Ordinary Least Squares regression solution...')
# Create linear regression object
OLSregr = linear_model.LinearRegression()

# Train the model using the training set
OLSregr.fit(X_train, y_train)

# Make predictions after training
y_train_pred = OLSregr.predict(X_train)
# Make predictions using the testing set
y_test_pred = OLSregr.predict(X_test)

# MSE, MAE, R-squared for training dataset
print('\n\tEvaluation metrics for training dataset:')
print('\t- Mean squared error: %.2f' % mean_squared_error(y_train, y_train_pred))
print('\t- Mean absolute error: %.2f' % mean_absolute_error(y_train, y_train_pred))
print('\t- R-squared: %.2f' % r2_score(y_train, y_train_pred))
# MSE, MAE, R-squared for testing dataset
print('\n\tEvaluation metrics for testing dataset:')
print('\t- Mean squared error: %.2f' % mean_squared_error(y_test, y_test_pred))
print('\t- Mean absolute error: %.2f' % mean_absolute_error(y_test, y_test_pred))
print('\t- R-squared: %.2f' % r2_score(y_test, y_test_pred))
# print w aka coefficients of the model
print('\n\tCoefficients: ', OLSregr.coef_)

##########################################################################################
print('\nImplementing linear regression with gradient descent solution...')
GDregr = linear_model.SGDRegressor(eta0=1.E-300, max_iter=2000) # learning_rate='adaptive'
#GDregr = linear_model.Ridge(solver='sag', max_iter=2000)

GDregr.fit(X_train, y_train)
y_train_pred = GDregr.predict(X_train)
y_test_pred = GDregr.predict(X_test)

# MSE, MAE, R-squared for training dataset
print('\n\tEvaluation metrics for training dataset:')
print('\t- Mean squared error: %.2f' % mean_squared_error(y_train, y_train_pred))
print('\t- Mean absolute error: %.2f' % mean_absolute_error(y_train, y_train_pred))
print('\t- R-squared: %.2f' % r2_score(y_train, y_train_pred))
# MSE, MAE, R-squared for testing dataset
print('\n\tEvaluation metrics for testing dataset:')
print('\t- Mean squared error: %.2f' % mean_squared_error(y_test, y_test_pred))
print('\t- Mean absolute error: %.2f' % mean_absolute_error(y_test, y_test_pred))
print('\t- R-squared: %.2f' % r2_score(y_test, y_test_pred))
# print w aka coefficients of the model
print('\n\tCoefficients: ', GDregr.coef_)
print('\n\tIterations: ', GDregr.n_iter_)