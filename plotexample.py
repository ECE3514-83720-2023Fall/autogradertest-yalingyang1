import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt('temp.dat')

#plt.plot(data[:,0],data[:,1],'b+')
#plt.plot(data[:,0],data[:,2],'r+')
#plt.plot(data[:,0],data[:,3],'g+')
plt.semilogy(data[:,0],data[:,1],'b+')
plt.semilogy(data[:,0],data[:,2],'r+')
plt.semilogy(data[:,0],data[:,3],'g+')
plt.xlabel('Length of string, N')
plt.ylabel('Average Time to Sort')
plt.legend(['BubbleSort()', 'SelectionSort()', 'YourSort()'])
plt.show()

#print(data)
