import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt('temp.dat')

plt.plot(data[:,0],data[:,1])
plt.plot(data[:,0],data[:,2])
plt.plot(data[:,0],data[:,3])
plt.xlabel('Length of string, N')
plt.ylabel('Average Time to Sort')
plt.legend(['BubbleSort()', 'InsertionSort()', 'YourSort()'])
plt.show()

#print(data)
